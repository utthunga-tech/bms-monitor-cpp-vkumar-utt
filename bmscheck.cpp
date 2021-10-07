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
        batteryStatus = false;
    }else if(value > max){
        statusMsg+= req +  " value more than range!\n";
        retVal = false;
        batteryStatus = false;
    }else{
        statusMsg+= req + " value in range!\n";
        retVal = true;
        batteryStatus = true;
    }

    return retVal;
}

bool BMSCheck::isValueInrange(string req, float value, float max)
{
    bool retVal = true;

    if(value > max) {
        statusMsg+= req + " value more than range!\n";
        retVal = false;
        batteryStatus = false;
      }
    else{
        statusMsg+= req + " value in range!\n";
        retVal = true;
        batteryStatus = true;
    }

    return retVal;
}

void BMSCheck::checkBatteryParam(float temperature, float soc, float chargeRate)
{
    statusMsg = "";
        
    if(isValueInrange(TEMP_FUNC, temperature, tempMin, tempMax))
    {
        if(isValueInrange(SOC_FUNC, soc, socMin, socMax))
            isValueInrange(RATE_FUNC, chargeRate, rateMax);
    }
    
}

bool BMSCheck::isbatteryOk()
{
    return batteryStatus;
}

void BMSCheck::getMsg()
{
    cout<<statusMsg<<"\n";
}
