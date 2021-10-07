#include "bmscheck.h"

void BMSCheck::setTemperatureRange(float tMax, float tMin)
{
    tempMax = tMax;
    tempMin = tMin;
}

void BMSCheck::setSocRange(float sMax, float sMin)
{
    socMax = sMax;
    socMin = sMin;
}

void BMSCheck::setChargerateMax(float rMax)
{
    rateMax = rMax;
}

bool BMSCheck::isValueInrange(string req, float value, float min, float max)
{
    bool retVal = false;

    if(value < min){
        statusMsg+= req + " value less than range!\n";
        retVal = false;
    }else if(value > max){
        statusMsg+= req +  " value less than range!\n";
        retVal = false;
    }else{
        statusMsg+= req + " value in range!\n";
        retVal = true;
    }

    return retVal;
}

bool BMSCheck::isValueInrange(string req, float value, float max)
{
    bool retVal = true;

    if(value > max) {
        statusMsg+= req + " value more than range!\n";
        retVal = false;
      }
    else{
        statusMsg+= req + " value in range!\n";
        retVal = true;
    }

    return retVal;
}

void BMSCheck::checkBatteryParam(float temperature, float soc, float chargeRate)
{
    statusMsg = "";
    bool tempcheck = isValueInrange(TEMP_FUNC, temperature, tempMin, tempMax);
    bool soccheck = isValueInrange(SOC_FUNC, soc, socMin, socMax);
    bool ratecheck = isValueInrange(RATE_FUNC, chargeRate, rateMax);

    if(tempcheck == true && soccheck == true && ratecheck == true){
        statusMsg += "*Battery is OK*\n";
        batteryStatus = true;
        return;
    }
    
        statusMsg += "-Battery NOT OK-\n";
        batteryStatus = false;
    
}

bool BMSCheck::isbatteryOk()
{
    return batteryStatus;
}

void BMSCheck::getMsg()
{
    cout<<statusMsg<<"\n";
}
