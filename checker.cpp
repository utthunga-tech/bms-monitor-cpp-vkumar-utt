#include <assert.h>
#include <iostream>
#include <string>
#include "bmscheck.h"

int main() {

    BMSCheck bmsCheck;
    bmsCheck.setTemperatureRange(TEMP_MAX, TEMP_MIN);
    bmsCheck.setSocRange(SOC_MAX, SOC_MIN);
    bmsCheck.setChargerateMax(RATE_MAX);

    //battery<0 , soc true, rate true,
    bmsCheck.checkBatteryParam(-1, 70, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == false);

    //battery>45, soc true, rate true,
    bmsCheck.checkBatteryParam(50, 85, 0);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == false);

    //battery between 0 & 45, soc true, chargeRate true,
    bmsCheck.checkBatteryParam(25, 70, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);

    //battery true , soc < 20, rate true,
    bmsCheck.checkBatteryParam(25, 10, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == false);

    //battery true , soc > 80, rate true,
    bmsCheck.checkBatteryParam(25, 90, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == false);

    //battery true, soc true, chargeRate > 0.8 -
    bmsCheck.checkBatteryParam(25, 70, 0.9f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == false);

    //battery upper limit , soc between 20 & 80, chargeRate true,
    bmsCheck.checkBatteryParam(45, 70, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);

    //battery lower limit , soc between 20 & 80, chargeRate true,
    bmsCheck.checkBatteryParam(0, 70, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);

    //battery true, soc upper limit, chargeRate true
    bmsCheck.checkBatteryParam(25, 80, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);

   //battery true, soc lower limit, chargeRate true
    bmsCheck.checkBatteryParam(25, 20, 0.7f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);

  //battery true, soc true, chargeRate uper limit
    bmsCheck.checkBatteryParam(25, 70, 0.8f);
    bmsCheck.getMsg();
    assert(bmsCheck.isbatteryOk() == true);
}
