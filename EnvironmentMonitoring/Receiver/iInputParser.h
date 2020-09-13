#pragma once
#ifndef IINPUTPARSER_H
#define IINPUTPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include "environmentParameter.h"

using namespace std;

class iInputParser 
{
public:
	virtual vector<EnvironmentParameter> parseInputMessage(string message) = 0;
};

#endif //!IINPUTPARSER_H