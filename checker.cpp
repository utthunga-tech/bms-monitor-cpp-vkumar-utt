#include <assert.h>
#include <iostream>
#include <string>

#define TEMP_MAX 45
#define TEMP_MIN 0

#define SOC_MAX 80
#define SOC_MIN 20

#define RATE_MAX 0.8

using namespace std;

auto inrangeCheck = [](double temp, double max, double min){

    if (temp < min || temp > max)
        return false;

    return true;
};

auto upperCheck = [](double val, double max){
    if(val > max)
        return true;
    return false;
};

auto valisOk = [](double val, double max, double min)
{
    if(inrangeCheck(val, max, min))
        return 1;
    else if(upperCheck(val, max))
        return 2;

    return 3;
};

auto ratevalisOk = [](double val, double max)
{
    if(upperCheck(val, max))
        return 2;

    return 1;
};

void showMsg(int val, string str)
{
    if(val == 1)
        cout<<str<<"Value in range\n";
    else if (val == 2)
        cout<<str<<"Value above max\n";
    else
        cout<<str<<"Value below min\n";
}

int tempOk(double temp)
{
    int ret = valisOk(temp, TEMP_MAX, TEMP_MIN);
    showMsg(ret, "Temp ");
    return ret;
}

int socOk(double soc)
{
    int ret = valisOk(soc, SOC_MAX, SOC_MIN);
    showMsg(ret, "Soc ");
    return ret;
}

int rateOk(double rate)
{
    int ret = ratevalisOk(rate, RATE_MAX);
    showMsg(ret, "Rate ");
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
        return true;
    else
        return false;

}

int main()
{
    //1. battery<0 , soc true, rate true,
    cout<<"Test 1\n";
    assert(batteryIsOk(-1, 70, 0.7)==false);

    //2. battery>45, soc true, rate true,
    cout<<"Test 2\n";
    assert(batteryIsOk(50, 85, 0)==false);

    //3. battery between 0 & 45, soc true, chargeRate true,
    cout<<"Test 3\n";
    assert(batteryIsOk(25, 70, 0.7)==true);

    //4. battery true , soc < 20, rate true
    cout<<"Test 4\n";
    assert(batteryIsOk(25, 10, 0.7)==false);

    //5. battery true , soc > 80, rate true,
    cout<<"Test 5\n";
    assert(batteryIsOk(25, 90, 0.7)==false);

    //6. battery true, soc true, chargeRate > 0.8
    cout<<"Test 6\n";
    assert(batteryIsOk(25, 70, 0.9)==false);

    //7. battery upper limit , soc between 20 & 80, chargeRate true
    cout<<"Test 7\n";
    assert(batteryIsOk(45, 70, 0.7)==true);

    //8. battery lower limit , soc between 20 & 80, chargeRate true
    cout<<"Test 8\n";
    assert(batteryIsOk(0, 70, 0.7)==true);

    //9. battery true, soc upper limit, chargeRate true
    cout<<"Test 9\n";
    assert(batteryIsOk(25, 80, 0.7)==true);

    //10. battery true, soc lower limit, chargeRate true
    cout<<"Test 10\n";
    assert(batteryIsOk(25, 20, 0.7)==true);

    //11. battery true, soc true, chargeRate uper limit
    cout<<"Test 11\n";
    assert(batteryIsOk(25, 70, 0.8)==true);
}

