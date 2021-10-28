#include <assert.h>
#include <iostream>
#include <string>

#define TEMP_MAX 45
#define TEMP_MIN 0

#define SOC_MAX 80
#define SOC_MIN 20

#define RATE_MAX 0.8

using namespace std;

enum LANG
{
    ENGLISH = 0,
    GERMAN
};

enum UNIT
{
    CELSIUS = 0,
    FAHRENHEIT,
    KELVIN
};

const int selected_lan = ENGLISH; //GERMAN; //;
const int selected_unit = CELSIUS;

using namespace std;

string getTempUnit()
{
    if(selected_unit == CELSIUS)
        return "CELSIUS";
    else if(selected_unit == FAHRENHEIT)
        return "FAHRENHEIT";

    return "KELVIN";
}

double getTempMax()
{
    if(selected_unit == CELSIUS)
        return 45;
    else if(selected_unit == FAHRENHEIT)
        return 113;

    return 318.15;
}

double getTempMin()
{
    if(selected_unit == CELSIUS)
        return 0;
    else if(selected_unit == FAHRENHEIT)
        return 32;

    return 273.15;
}

string tempmsgabove()
{
    if(selected_lan==ENGLISH)
        return "Temperature Value is above range";
    return "Temperaturwert liegt über dem Bereich";
}

string tempmsglow()
{
    if(selected_lan==ENGLISH)
        return "Temperature Value is below range";
    return "Temperaturwert liegt unter dem Bereich";
}

string tempmsginrange()
{
    if(selected_lan==ENGLISH)
        return "Temperature Value is in range";
    return "Temperaturwert liegt im Bereich";
}

string socmsgabove()
{
    if(selected_lan==ENGLISH)
        return  "SOC Value is above range";
    return "SOC-Wert liegt über dem Bereich";
}

string socmsglow()
{
    if(selected_lan==ENGLISH)
        return "SOC Value is below range";
    return "SOC-Wert liegt unter dem Bereich";
}

string socmsginrange()
{
    if(selected_lan==ENGLISH)
        return "SOC Value is in range";
    return "SOC-Wert liegt im Bereich";
}

string ratemsgabove()
{
    if(selected_lan==ENGLISH)
        return "Rate Value is above range";
    return "Der Preiswert liegt über dem Bereich";
}

string ratemsginrange()
{
    if(selected_lan==ENGLISH)
        return "Rate Value is in range";
    return "Preiswert liegt im Bereich";
}

string batteryokmsg()
{
    if(selected_lan==ENGLISH)
        return "Battery is OK";
    return "Batterie ist in Ordnung";
}

string batterynotokmsg()
{
    if(selected_lan==ENGLISH)
        return "Battery is Not OK";

    return "Batterie ist nicht in Ordnung";
}


void showMsg(string str)
{
    cout<<str<<"\n";
}

bool inrangeCheck(double temp, double max, double min)
{
    if (temp < min || temp > max)
        return false;
    return true;
}

bool upperCheck (double val, double max)
{
    if(val > max)
        return true;
    return false;
}

int valisOk(double val, double max, double min)
{
    if(inrangeCheck(val, max, min))
    {
        return 1;
    }
    else if(upperCheck(val, max))
    {
        return 2;
    }

    return 3;
};

int ratevalisOk(double val, double max)
{
    if(upperCheck(val, max))
    {
        return 2;
    }

    return 1;
};

int tempOk(double temp)
{
    //int ret = valisOk(temp, TEMP_MAX, TEMP_MIN);

    int ret = valisOk(temp, getTempMax(), getTempMin());
    if(ret == 1)
    {
        showMsg(tempmsginrange());
        return ret;
    }
    else if(ret == 2)
    {
        showMsg(tempmsgabove());
        return ret;
    }
    showMsg(tempmsglow());
    return ret;
}

int socOk(double soc)
{
    int ret = valisOk(soc, SOC_MAX, SOC_MIN);
    if(ret == 1)
    {
        showMsg(socmsginrange());
        return ret;
    }
    else if(ret == 2)
    {
        showMsg(socmsgabove());
        return ret;
    }

    showMsg(socmsglow());
    return ret;
}

int rateOk(double rate)
{
    int ret = ratevalisOk(rate, RATE_MAX);
    return ret;
}

bool tempsocOk(double temp, double soc)
{
    if(tempOk(temp) == 1 && socOk(soc)==1)
        return true;

    return false;
}

bool batteryIsOk(double temp, double soc, double rate)
{
     if(tempsocOk(temp, soc) && rateOk(rate)==1)
     {
         showMsg(batteryokmsg());
        return true;
     }
    showMsg(batterynotokmsg());
        return false;
}

int main()
{
    cout<<"Current Temperature Unit : "<<getTempUnit()<<"\n";

    //1. battery<0 , soc true, rate true
    cout<<"\nTest 1. battery<0 , soc true, rate true,\n";
    assert(batteryIsOk(-1, 70, 0.7)==false);

    //2. battery>45, soc true, rate true
    cout<<"\nTest 2. battery>45, soc true, rate true\n";
    assert(batteryIsOk(50, 85, 0)==false);

    //3. battery between 0 & 45, soc true, chargeRate true
    cout<<"\nTest 3. battery between 0 & 45, soc true, chargeRate true\n";
    assert(batteryIsOk(25, 70, 0.7)==true);

    //4. battery true , soc < 20, rate true
    cout<<"\nTest 4. battery true , soc < 20, rate true\n";
    assert(batteryIsOk(25, 10, 0.7)==false);

    //5. battery true , soc > 80, rate true
    cout<<"\nTest 5. battery true , soc > 80, rate true\n";
    assert(batteryIsOk(25, 90, 0.7)==false);

    //6. battery true, soc true, chargeRate > 0.8
    cout<<"\nTest 6. battery true, soc true, chargeRate > 0.8\n";
    assert(batteryIsOk(25, 70, 0.9)==false);

    //7. battery upper limit , soc between 20 & 80, chargeRate true
    cout<<"\nTest 7. battery upper limit , soc between 20 & 80, chargeRate true\n";
    assert(batteryIsOk(45, 70, 0.7)==true);

    //8. battery lower limit , soc between 20 & 80, chargeRate true
    cout<<"\nTest 8. battery lower limit , soc between 20 & 80, chargeRate true\n";
    assert(batteryIsOk(0, 70, 0.7)==true);

    //9. battery true, soc upper limit, chargeRate true
    cout<<"\nTest 9. battery true, soc upper limit, chargeRate true\n";
    assert(batteryIsOk(25, 80, 0.7)==true);

    //10. battery true, soc lower limit, chargeRate true
    cout<<"\nTest 10. battery true, soc lower limit, chargeRate true\n";
    assert(batteryIsOk(25, 20, 0.7)==true);

    //11. battery true, soc true, chargeRate uper limit
    cout<<"\nTest 11. battery true, soc true, chargeRate uper limit\n";
    assert(batteryIsOk(25, 70, 0.8)==true);
}
