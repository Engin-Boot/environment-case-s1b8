#pragma once
#ifndef IALERTER_H
#define IALERTER_H

#include<iostream>
using namespace std;

class iAlerter
{
public:
    virtual void errorAlert(string paramName, float cv, float high, float low) = 0;
    virtual void warningAlert(string paramName, float cv, float high, float low) = 0;
    
 };

#endif // IALERTER_H


