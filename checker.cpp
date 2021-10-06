#include <assert.h>
#include <iostream>
using namespace std;
#define TEMP_MAX 45
#define TEMP_MIN 0

#define SOC_MAX 80
#define SOC_MIN 20

#define TEMP_FUNC "Temperature"
#define SOC_FUNC "Soc"

bool isValueInrage(string req, float value, float min, float max)
{
    bool retVal = false;

    if(value < min)
    {
        cout <<req<< " value less than range!\n";
        retVal = false;
    }
    else if(value > max)
    {
        cout <<req<< " value more than range!\n";
        retVal = false;
    }
    else
    {
        cout <<req<< " value in range!\n";
        retVal = true;
    }

    return retVal;
}

bool isChargeRateOk(float chargeRate)
{
    if(chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return false;
      }

    cout << "Charge Rate in range!\n";
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
    bool tempcheck = isValueInrage(TEMP_FUNC, temperature, TEMP_MIN, TEMP_MAX);
    bool soccheck = isValueInrage(SOC_FUNC, soc, SOC_MIN, SOC_MAX);
    bool ratecheck = isChargeRateOk(chargeRate);

    if(tempcheck == true && soccheck == true && ratecheck == true)
    {
        cout << "*Battery is OK*\n";
        return true;
    }
    else
    {
        cout << "-Battery NOT OK-\n";
        return false;
    }
}


int main() {

    //battery<0 , soc true, rate true,
      assert(batteryIsOk(-1, 70, 0.7) == false);

    //battery>45, soc true, rate true,
      assert(batteryIsOk(50, 85, 0) == false);

    //battery between 0 & 45, soc true, chargeRate true,
      assert(batteryIsOk(25, 70, 0.7) == true);

    //battery true , soc < 20, rate true,
      assert(batteryIsOk(25, 10, 0.7) == false);

    //battery true , soc > 80, rate true,
      assert(batteryIsOk(25, 90, 0.7) == false);

    //battery true, soc true, chargeRate > 0.8 -
      assert(batteryIsOk(25, 70, 0.9) == false);

    //battery upper limit , soc between 20 & 80, chargeRate true,
      assert(batteryIsOk(45, 70, 0.7) == true);

    //battery lower limit , soc between 20 & 80, chargeRate true,
      assert(batteryIsOk(0, 70, 0.7) == true);

    //battery true, soc upper limit, chargeRate true
       assert(batteryIsOk(25, 80, 0.7) == true);

   //battery true, soc lower limit, chargeRate true
      assert(batteryIsOk(25, 20, 0.7) == true);

  //battery true, soc true, chargeRate uper limit
     assert(batteryIsOk(25, 70, 0.8) == true);

}
