#pragma once
#ifndef ALERTWITHNOTIFICATION_H
#define ALERTWITHNOTIFICATION_H

#include<iostream>
#include "iAlerter.h"

using namespace std;

class alertWithNotification : public iAlerter
{
public:
    virtual void errorAlert(string paramName, float currentValue , float errorHighLimit, float errorLowLimit)override
    {
        cout << "ErrorNotification: The current " << paramName << " is " << to_string(currentValue) << ", but the sustainable range is " << to_string(errorLowLimit) << " - " << to_string(errorHighLimit) << endl;
    }
    virtual void warningAlert(string paramName, float currentValue, float warningHighLimit, float warningLowLimit)override
    {
        cout << "WarningNotification: The current " << paramName << " is " << to_string(currentValue) << ", but the sustainable range is " << to_string(warningLowLimit) << " - " << to_string(warningHighLimit) << endl;
    }
};


#endif // ALERTWITHNOTIFICATION_H


