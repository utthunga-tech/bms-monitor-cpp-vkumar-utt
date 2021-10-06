#ifndef BMSCHECK_H
#define BMSCHECK_H
#include <iostream>
#include <string>

using namespace std;

#define TEMP_MAX 45
#define TEMP_MIN 0

#define SOC_MAX 80
#define SOC_MIN 20

#define RATE_MAX 0.8f

#define TEMP_FUNC "Temperature"
#define SOC_FUNC "Soc"
#define RATE_FUNC "Rate"

class BMSCheck
{
    float tempMax;
    float tempMin;

    float socMax;
    float socMin;

    float rateMax;

    bool batteryStatus;
    string statusMsg;

    bool isValueInrange(string req, float value, float min, float max);
    bool isValueInrange(string req, float value, float max);
    bool isChargeRateOk(float chargeRate);

    void logMsg(string msg);

public:
    BMSCheck(): tempMax(0), tempMin(0),
        socMax(0), socMin(0), rateMax(0)
    {
        batteryStatus = false;
        statusMsg = "";
    }

    void setTemperatureRange(float tMax, float tMin);
    void setSocRange(float sMax, float sMin);
    void setChargerateMax(float rMax);

    void checkBatteryParam(float temperature, float soc, float chargeRate);
    bool isbatteryOk();

    void getMsg();
};

#endif // BMSCHECK_H
