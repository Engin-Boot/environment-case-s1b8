#include "stringInputParser.h"
#include "iAlerter.h"
#include"rangeChecker.h"
#include"alertWithLight.h"
#include"alertWithNotification.h"
#include"Receiver.h"


int main()
{

	
	iInputParser* stringInputparserObj=new(nothrow)stringInputParser;
	iAlerter* alerterObj = new(nothrow)alertWithNotification;
	rangeChecker rangeCheckerObj(alerterObj);

	Receiver r(stringInputparserObj,&rangeCheckerObj);
	r.processReceivedDataAndCheckForAlert();
	
}