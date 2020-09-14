#pragma once
#ifndef RANGECHECKER_H
#define RANGECHECKER_H

#include<iostream>
#include<vector>
#include "iAlerter.h"
#include "environmentParameter.h"
using namespace std;

class rangeChecker
{
private:
	iAlerter* alerter;
	bool CheckAndRaiseErrorAlert(EnvironmentParameter& param)
	{
		if (param.getCurrentValue() > param.getErrorHighLimit() || param.getCurrentValue() < param.getErrorLowLimit())
		{
			alerter->errorAlert(param.getParameterName(), param.getCurrentValue(), param.getErrorHighLimit(), param.getErrorLowLimit());
			return true;
		}
		return false;
	}

	bool CheckAndRaiseWarningAlert(EnvironmentParameter& param)
	{
		if (param.getCurrentValue() > param.getWarningHighLimit() || param.getCurrentValue() < param.getWarningLowLimit())
		{
			alerter->warningAlert(param.getParameterName(), param.getCurrentValue(), param.getWarningHighLimit(), param.getWarningLowLimit());
			return true;
		}
		return false;
	}

public:
	rangeChecker(iAlerter* a) : alerter(a) {}
	void checkForAlert(vector<EnvironmentParameter>params)
	{
		for (std::vector<EnvironmentParameter>::iterator it = params.begin(); it != params.end(); ++it)
		{
			if (!CheckAndRaiseErrorAlert(*it))
			{
				CheckAndRaiseWarningAlert(*it);
			}
		}
	}

};

#endif // RANGECHECKER_H


