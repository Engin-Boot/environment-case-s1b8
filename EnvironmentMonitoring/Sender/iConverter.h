#pragma once

#ifndef ICONVERTER_H
#define ICONVERTER_H

#include <vector>
#include "environmentParameter.h"

class iConverter
{
public:
	virtual std::string convert(std::vector<EnvironmentParameter>&) = 0;
};

#endif // !ICONVERTER_H
