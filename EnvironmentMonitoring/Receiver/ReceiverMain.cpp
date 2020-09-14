#include "stringInputParser.h"
#include "iAlerter.h"
#include"rangeChecker.h"
#include"alertWithLight.h"
#include"alertWithNotification.h"


int main()
{
	string message = "Temperature{CurrentValue:42.199028,ErrorHighLimit:40.000000,ErrorLowLimit:0.000000,WarningHighLimit:37.000000,WarningLowLimit:4.000000};Humidity{CurrentValue:75S.000000,ErrorHighLimit:90.000000,ErrorLowLimit:0.000000,WarningHighLimit:70.000000,WarningLowLimit:0.000000};";
	stringInputParser stringInputParserObj;
	vector<EnvironmentParameter>params= stringInputParserObj.parseInputMessage(message);

	alertWithNotification alerter;
	rangeChecker rangeChecker(&alerter);
	rangeChecker.checkForAlert(params);
	
}