#include <assert.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//Multilanguage support & Warning support

struct DataBoundary{

    double low;
    double upper;
    string message;
};

//SOC data set
static DataBoundary dataBSOCLowBreach;
static DataBoundary dataBSOCLowWarn;
static DataBoundary dataBSOCNormal;
static DataBoundary dataBSOCHighWarn;
static DataBoundary dataBSOCHighBreach;

//Temp data set
static DataBoundary dataBTEMPLowBreach;
static DataBoundary dataBTEMPLowWarn;
static DataBoundary dataBTEMPNormal;
static DataBoundary dataBTEMPHighWarn;
static DataBoundary dataBTEMPHighBreach;

//Rate data set
static DataBoundary dataBRATENormal;
static DataBoundary dataBRATEHighWarn;
static DataBoundary dataBRATEHighBreach;

static map<string, string> messageMap;

static string BATTERY_OK = "BATTERY_OK";
static string BATTERY_NOTOK = "BATTERY_NOTOK";

static string LOW_SOC_BREACH = "LOW_SOC_BREACH";
static string LOW_SOC_WARNING = "LOW_SOC_WARNING";
static string SOC_NORMAL = "SOC_NORMAL";
static string HIGH_SOC_WARNING = "HIGH_SOC_WARNING";
static string HIGH_SOC_BREACH = "HIGH_SOC_BREACH";

static string LOW_TEMP_BREACH = "LOW_TEMP_BREACH";
static string LOW_TEMP_WARNING = "LOW_TEMP_WARNING";
static string TEMP_NORMAL = "TEMP_NORMAL";
static string HIGH_TEMP_WARNING = "HIGH_TEMP_WARNING";
static string HIGH_TEMP_BREACH = "HIGH_TEMP_BREACH";

static string RATE_NORMAL = "RATE_NORMAL";
static string HIGH_RATE_WARNING = "HIGH_RATE_WARNING";
static string HIGH_RATE_BREACH = "HIGH_RATE_BREACH";


void loadEnglishMessages()
{
    messageMap[BATTERY_OK] = "Battery is OK";
    messageMap[BATTERY_NOTOK] = "Battery is not OK";

    //soc messages
    messageMap[LOW_SOC_BREACH] = "BREACH : SOC Value is below range";
    messageMap[LOW_SOC_WARNING] = "WARNING : SOC Value is below range";
    messageMap[SOC_NORMAL] = "SOC Value is in range";
    messageMap[HIGH_SOC_WARNING] = "WARNING : SOC Value is above range";
    messageMap[HIGH_SOC_BREACH] = "BREACH : SOC Value is above range";

    //temperature messages
    messageMap[LOW_TEMP_BREACH] = "BREACH : temperature Value is below range";
    messageMap[LOW_TEMP_WARNING] = "WARNING : temperature Value is below range";
    messageMap[TEMP_NORMAL] = "temperature Value is in range";
    messageMap[HIGH_TEMP_WARNING] = "WARNING : temperature Value is above range";
    messageMap[HIGH_TEMP_BREACH] = "BREACH : temperature Value is above range";

    //rate message
    messageMap[RATE_NORMAL] = "Rate Value is in range";
    messageMap[HIGH_RATE_WARNING] = "WARNING : Rate Value is above range";
    messageMap[HIGH_RATE_BREACH] = "BREACH : Rate Value is above range";

}

void loadGermanMessages()
{
    messageMap[BATTERY_OK] = "Batterie ist in Ordnung";
    messageMap[BATTERY_NOTOK] = "Batterie ist nicht in Ordnung";

    //soc messages
    messageMap[LOW_SOC_BREACH] = "BREACH : SOC-Wert liegt unter dem Bereich";
    messageMap[LOW_SOC_WARNING] = "WARNING : SOC-Wert liegt unter dem Bereich";
    messageMap[SOC_NORMAL] = "SOC-Wert liegt im Bereich";
    messageMap[HIGH_SOC_WARNING] = "WARNING : SOC-Wert liegt über dem Bereich";
    messageMap[HIGH_SOC_BREACH] = "BREACH : SOC-Wert liegt über dem Bereich";

    //temperature messages
    messageMap[LOW_TEMP_BREACH] = "BREACH : temperature-Wert liegt unter dem Bereich";
    messageMap[LOW_TEMP_WARNING] = "WARNING : temperature-Wert liegt unter dem Bereich";
    messageMap[TEMP_NORMAL] = "temperature-Wert liegt im Bereich";
    messageMap[HIGH_TEMP_WARNING] = "WARNING : temperature-Wert liegt über dem Bereich";
    messageMap[HIGH_TEMP_BREACH] = "BREACH : temperature-Wert liegt über dem Bereich";

    //rate message
    messageMap[RATE_NORMAL] = "Preiswert liegt im Bereich";
    messageMap[HIGH_RATE_WARNING] = "WARNING : Der Preiswert liegt über dem Bereich";
    messageMap[HIGH_RATE_BREACH] = "BREACH : Der Preiswert liegt über dem Bereich";
}

void loadMessage(int lang)
{
    if(lang == 1)
        loadEnglishMessages();
    else
        loadGermanMessages();
}

//soc data
void createSOCDataset()
{
    dataBSOCLowBreach.low = 0;
    dataBSOCLowBreach.upper = 20;
    dataBSOCLowBreach.message = LOW_SOC_BREACH;

    dataBSOCLowWarn.low = 21;
    dataBSOCLowWarn.upper = 24;
    dataBSOCLowWarn.message = LOW_SOC_WARNING;

    dataBSOCNormal.low = 25;
    dataBSOCNormal.upper = 75;
    dataBSOCNormal.message = SOC_NORMAL;

    dataBSOCHighWarn.low = 76;
    dataBSOCHighWarn.upper = 80;
    dataBSOCHighWarn.message = HIGH_SOC_WARNING;

    dataBSOCHighBreach.low = 81;
    dataBSOCHighBreach.upper = 100;
    dataBSOCHighBreach.message = HIGH_SOC_BREACH;
}

//temp data
void createTEMPDataset()
{
    dataBTEMPLowBreach.low = -10;
    dataBTEMPLowBreach.upper = 0;
    dataBTEMPLowBreach.message = LOW_TEMP_BREACH;

    dataBTEMPLowWarn.low = 1;
    dataBTEMPLowWarn.upper = 2.25;
    dataBTEMPLowWarn.message = LOW_TEMP_WARNING;

    dataBTEMPNormal.low = 2.26;
    dataBTEMPNormal.upper = 42.25;
    dataBTEMPNormal.message = TEMP_NORMAL;

    dataBTEMPHighWarn.low = 42.26;
    dataBTEMPHighWarn.upper = 45;
    dataBTEMPHighWarn.message = HIGH_TEMP_WARNING;

    dataBTEMPHighBreach.low = 46;
    dataBTEMPHighBreach.upper = 100;
    dataBTEMPHighBreach.message = HIGH_TEMP_BREACH;
}

//rate data
void createRATEDataset()
{
    dataBRATENormal.low = 0;
    dataBRATENormal.upper = 0.75;
    dataBRATENormal.message = RATE_NORMAL;

    dataBRATEHighWarn.low = 0.76;
    dataBRATEHighWarn.upper = 0.8;
    dataBRATEHighWarn.message = HIGH_RATE_WARNING;

    dataBRATEHighBreach.low = 0.9;
    dataBRATEHighBreach.upper = 1;
    dataBRATEHighBreach.message = HIGH_RATE_BREACH;
}
void printMessage(string message)
{
    cout<<messageMap[message]<<"\n";
}

bool checkDataBoundry(double val, DataBoundary dataset)
{
    if(val >= dataset.low && val <= dataset.upper)
    {
        printMessage(dataset.message);
        return true;
    }

    return false;
}

//SOC functions
bool socCheckLowBreach(double val)
{
    return checkDataBoundry(val, dataBSOCLowBreach);
}

bool socCheckLowWarn(double val)
{
    return checkDataBoundry(val, dataBSOCLowWarn);
}

bool socCheckNormal(double val)
{
    return checkDataBoundry(val, dataBSOCNormal);
}

bool socCheckHighWarn(double val)
{
    return checkDataBoundry(val, dataBSOCHighWarn);
}

bool socCheckHighBreach(double val)
{
    return checkDataBoundry(val, dataBSOCHighBreach);
}

bool socCheckHigh(double val)
{
    if ((socCheckHighWarn(val)) || (socCheckHighBreach(val)))
        return true;

    return false;
}
bool socCheckLow(double val)
{
    if ((socCheckLowWarn(val)) || (socCheckLowBreach(val)))
        return true;

    return false;
}


bool socCheck(double val)
{

    if(socCheckHigh(val) || socCheckLow(val))
        return false;

    socCheckNormal(val);
    return true;
}


//Temperature functions
bool tempCheckLowBreach(double val)
{
    return checkDataBoundry(val, dataBTEMPLowBreach);
}

bool tempCheckLowWarn(double val)
{
    return checkDataBoundry(val, dataBTEMPLowWarn);
}

bool tempCheckNormal(double val)
{
    return checkDataBoundry(val, dataBTEMPNormal);
}

bool tempCheckHighWarn(double val)
{
    return checkDataBoundry(val, dataBTEMPHighWarn);
}

bool tempCheckHighBreach(double val)
{
    return checkDataBoundry(val, dataBTEMPHighBreach);
}

bool tempCheckHigh(double val)
{
    if ((tempCheckHighWarn(val)) || (tempCheckHighBreach(val)))
        return true;

    return false;
}
bool tempCheckLow(double val)
{
    if ((tempCheckLowWarn(val)) || (tempCheckLowBreach(val)))
        return true;

    return false;
}

bool tempCheck(double val)
{
    if(tempCheckHigh(val) || tempCheckLow(val))
        return false;

    tempCheckNormal(val);
    return true;
}

//BOTH Temp & SOC

bool tempSOCCheck(double temp, double soc)
{
    bool t = tempCheck(temp);
    bool s = socCheck(soc);
    if(t && s)
        return true;

    return false;
}

//Rate check
bool rateCheckNormal(double val)
{
    return checkDataBoundry(val, dataBRATENormal);
}

bool rateCheckHighWarn(double val)
{
    return checkDataBoundry(val, dataBRATEHighWarn);
}

bool rateCheckHighBreach(double val)
{
    return checkDataBoundry(val, dataBRATEHighBreach);
}

bool rateCheckHigh(double val)
{
    if ((rateCheckHighWarn(val)) || (rateCheckHighBreach(val)))
        return true;

    return false;
}

bool rateCheck(double val)
{
    if(rateCheckHigh(val))
        return false;

    rateCheckNormal(val);
    return true;
}

bool batteryCheck(double temp, double soc, double rate)
{

    bool t = tempSOCCheck(temp, soc);
    bool r = rateCheck(rate);
    if(t && r){
        printMessage(BATTERY_OK);
        return true;
    }
    printMessage(BATTERY_NOTOK);
    return false;
}

int main()
{
    int lang;
    cout<<"Select the language (1 - English, 2 - German) : ";
    cin>>lang;

    loadMessage(lang);

    createSOCDataset();
    createTEMPDataset();
    createRATEDataset();

    assert(batteryCheck(-10, 0, 0)==false);
    batteryCheck(0, 0, 0);
    batteryCheck(21, 0, 0);
    batteryCheck(25, 0, 0);
    batteryCheck(76, 0, 0);
    batteryCheck(81, 0, 0);

    return 0;
}




//#define TEMP_MAX 45
//#define TEMP_MIN 0

//#define SOC_MAX 80
//#define SOC_MIN 20

//#define RATE_MAX 0.8



//enum LANG
//{
//    ENGLISH = 0,
//    GERMAN
//};

//enum UNIT
//{
//    CELSIUS = 0,
//    FAHRENHEIT,
//    KELVIN
//};

//const int selected_lan = ENGLISH; //GERMAN; //;
//const int selected_unit = CELSIUS;

//using namespace std;

//string getTempUnit()
//{
//    if(selected_unit == CELSIUS)
//        return "CELSIUS";
//    else if(selected_unit == FAHRENHEIT)
//        return "FAHRENHEIT";

//    return "KELVIN";
//}

//double getTempMax()
//{
//    if(selected_unit == CELSIUS)
//        return 45;
//    else if(selected_unit == FAHRENHEIT)
//        return 113;

//    return 318.15;
//}

//double getTempMin()
//{
//    if(selected_unit == CELSIUS)
//        return 0;
//    else if(selected_unit == FAHRENHEIT)
//        return 32;

//    return 273.15;
//}

//string tempmsgabove()
//{
//    if(selected_lan==ENGLISH)
//        return "Temperature Value is above range";
//    return "Temperaturwert liegt über dem Bereich";
//}

//string tempmsglow()
//{
//    if(selected_lan==ENGLISH)
//        return "Temperature Value is below range";
//    return "Temperaturwert liegt unter dem Bereich";
//}

//string tempmsginrange()
//{
//    if(selected_lan==ENGLISH)
//        return "Temperature Value is in range";
//    return "Temperaturwert liegt im Bereich";
//}

//string socmsgabove()
//{
//    if(selected_lan==ENGLISH)
//        return  "SOC Value is above range";
//    return "SOC-Wert liegt über dem Bereich";
//}

//string socmsglow()
//{
//    if(selected_lan==ENGLISH)
//        return "SOC Value is below range";
//    return "SOC-Wert liegt unter dem Bereich";
//}

//string socmsginrange()
//{
//    if(selected_lan==ENGLISH)
//        return "SOC Value is in range";
//    return "SOC-Wert liegt im Bereich";
//}

//string ratemsgabove()
//{
//    if(selected_lan==ENGLISH)
//        return "Rate Value is above range";
//    return "Der Preiswert liegt über dem Bereich";
//}

//string ratemsginrange()
//{
//    if(selected_lan==ENGLISH)
//        return "Rate Value is in range";
//    return "Preiswert liegt im Bereich";
//}

//string batteryokmsg()
//{
//    if(selected_lan==ENGLISH)
//        return "Battery is OK";
//    return "Batterie ist in Ordnung";
//}

//string batterynotokmsg()
//{
//    if(selected_lan==ENGLISH)
//        return "Battery is Not OK";

//    return "Batterie ist nicht in Ordnung";
//}


//void showMsg(string str)
//{
//    cout<<str<<"\n";
//}

//bool inrangeCheck(double temp, double max, double min)
//{
//    if (temp < min || temp > max)
//        return false;
//    return true;
//}

//bool upperCheck (double val, double max)
//{
//    if(val > max)
//        return true;
//    return false;
//}

//int valisOk(double val, double max, double min)
//{
//    if(inrangeCheck(val, max, min))
//    {
//        return 1;
//    }
//    else if(upperCheck(val, max))
//    {
//        return 2;
//    }

//    return 3;
//};

//int ratevalisOk(double val, double max)
//{
//    if(upperCheck(val, max))
//    {
//        return 2;
//    }

//    return 1;
//};

//int tempOk(double temp)
//{
//    //int ret = valisOk(temp, TEMP_MAX, TEMP_MIN);

//    int ret = valisOk(temp, getTempMax(), getTempMin());
//    if(ret == 1)
//    {
//        showMsg(tempmsginrange());
//        return ret;
//    }
//    else if(ret == 2)
//    {
//        showMsg(tempmsgabove());
//        return ret;
//    }
//    showMsg(tempmsglow());
//    return ret;
//}

//int socOk(double soc)
//{
//    int ret = valisOk(soc, SOC_MAX, SOC_MIN);
//    if(ret == 1)
//    {
//        showMsg(socmsginrange());
//        return ret;
//    }
//    else if(ret == 2)
//    {
//        showMsg(socmsgabove());
//        return ret;
//    }

//    showMsg(socmsglow());
//    return ret;
//}

//int rateOk(double rate)
//{
//    int ret = ratevalisOk(rate, RATE_MAX);
//    return ret;
//}

//bool tempsocOk(double temp, double soc)
//{
//    if(tempOk(temp) == 1 && socOk(soc)==1)
//        return true;

//    return false;
//}

//bool batteryIsOk(double temp, double soc, double rate)
//{
//     if(tempsocOk(temp, soc) && rateOk(rate)==1)
//     {
//         showMsg(batteryokmsg());
//        return true;
//     }
//    showMsg(batterynotokmsg());
//        return false;
//}

//int main()
//{
//    cout<<"Current Temperature Unit : "<<getTempUnit()<<"\n";

//    //1. battery<0 , soc true, rate true
//    cout<<"\nTest 1. battery<0 , soc true, rate true,\n";
//    assert(batteryIsOk(-1, 70, 0.7)==false);

//    //2. battery>45, soc true, rate true
//    cout<<"\nTest 2. battery>45, soc true, rate true\n";
//    assert(batteryIsOk(50, 85, 0)==false);

//    //3. battery between 0 & 45, soc true, chargeRate true
//    cout<<"\nTest 3. battery between 0 & 45, soc true, chargeRate true\n";
//    assert(batteryIsOk(25, 70, 0.7)==true);

//    //4. battery true , soc < 20, rate true
//    cout<<"\nTest 4. battery true , soc < 20, rate true\n";
//    assert(batteryIsOk(25, 10, 0.7)==false);

//    //5. battery true , soc > 80, rate true
//    cout<<"\nTest 5. battery true , soc > 80, rate true\n";
//    assert(batteryIsOk(25, 90, 0.7)==false);

//    //6. battery true, soc true, chargeRate > 0.8
//    cout<<"\nTest 6. battery true, soc true, chargeRate > 0.8\n";
//    assert(batteryIsOk(25, 70, 0.9)==false);

//    //7. battery upper limit , soc between 20 & 80, chargeRate true
//    cout<<"\nTest 7. battery upper limit , soc between 20 & 80, chargeRate true\n";
//    assert(batteryIsOk(45, 70, 0.7)==true);

//    //8. battery lower limit , soc between 20 & 80, chargeRate true
//    cout<<"\nTest 8. battery lower limit , soc between 20 & 80, chargeRate true\n";
//    assert(batteryIsOk(0, 70, 0.7)==true);

//    //9. battery true, soc upper limit, chargeRate true
//    cout<<"\nTest 9. battery true, soc upper limit, chargeRate true\n";
//    assert(batteryIsOk(25, 80, 0.7)==true);

//    //10. battery true, soc lower limit, chargeRate true
//    cout<<"\nTest 10. battery true, soc lower limit, chargeRate true\n";
//    assert(batteryIsOk(25, 20, 0.7)==true);

//    //11. battery true, soc true, chargeRate uper limit
//    cout<<"\nTest 11. battery true, soc true, chargeRate uper limit\n";
//    assert(batteryIsOk(25, 70, 0.8)==true);
//}
