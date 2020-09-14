#pragma once
#ifndef IALERTER_H
#define IALERTER_H

#include<iostream>
using namespace std;

class iAlerter
{
public:
    virtual void errorAlert(const string& paramName, float cv, float high, float low) = 0;
    virtual void warningAlert(const string& paramName, float cv, float high, float low) = 0;
    
 };

#endif // IALERTER_H


