#pragma once
#ifndef ALERTWITHLIGHT_H
#define ALERTWITHLIGHT_H

#include<iostream>
#include "environmentParameter.h"
#include "iAlerter.h"

using namespace std;

class alertWithLight : public iAlerter
{
public:
    virtual void errorAlert(const string& paramName, float currentValue, float errorHighLimit, float errorLowLimit) override
    {
        cout << " YELLOW LIGHT " << endl; 
        cout << "ErrorNotificationWithLight: The current " << paramName << " is " << to_string(currentValue) << ", but the sustainable range is " << to_string(errorLowLimit) << " - " << to_string(errorHighLimit) << endl;
       
    }
    virtual void warningAlert(const string& paramName, float currentValue, float warningHighLimit, float warningLowLimit) override
    {
        cout << " RED LIGHT " << endl; 
        cout << "WarningNotificationWithLight: The current " << paramName << " is " << to_string(currentValue) << ", but the sustainable range is " << to_string(warningLowLimit) << " - " << to_string(warningHighLimit) << endl;
    }
};

#endif // ALERTWITHLIGHT_H



