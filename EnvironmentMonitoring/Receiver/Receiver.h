#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "iAlerter.h"
#include "iInputParser.h"
#include "rangeChecker.h"

class Receiver
{
private:
    iInputParser* iInputParserObj;
    rangeChecker* rangeCheckerObj;
    
public:
    Receiver(iInputParser* ic,rangeChecker* b) : iInputParserObj(ic), rangeCheckerObj(b) {}
    Receiver(const Receiver& ob) : iInputParserObj(ob.iInputParserObj), rangeCheckerObj(ob.rangeCheckerObj) {}

    Receiver& operator =(const Receiver& ob) {
        this->iInputParserObj = ob.iInputParserObj;
        this->rangeCheckerObj = ob.rangeCheckerObj;
        return *this;
    }

    void processReceivedDataAndCheckForAlert() {
        // string message = "Temperature{CurrentValue:42.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:75.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000};";
        string message;
        getline(cin, message);
        vector<EnvironmentParameter> params = iInputParserObj->parseInputMessage(message);
        rangeCheckerObj->checkForAlert(params);

    }
};
