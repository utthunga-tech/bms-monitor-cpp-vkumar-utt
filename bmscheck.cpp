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
    if(value < min){
        statusMsg+= req + " value less than range!";
        batteryStatus = false;
        return false;
    }else if(value > max){
        statusMsg+= req +  " value more than range!";
        batteryStatus = false;
        return false;
    }
    statusMsg+= req + " value in range!";
    batteryStatus = true;

    return true;
}

bool BMSCheck::isValueInrange(string req, float value, float max)
{
    if(value > max) {
        statusMsg+= req + " value more than range!";
        batteryStatus = false;
        return false;
      }
    statusMsg+= req + " value in range!";
    batteryStatus = true;

    return true;
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
