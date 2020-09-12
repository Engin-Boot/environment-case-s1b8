#include <iostream>
#include "csvReaderAndParser.h"
#include "stringConverter.h"
#include "consoleDispatcher.h"
#include "Sender.h"

using namespace std;

int main() 
{
	iReaderAndParser* csvReaderAndParserObj = new(nothrow) csvReaderAndParser;
	iConverter* stringConverterObj = new(nothrow) stringConverter;
	iDispatcher* consoleDispatcherObj = new(nothrow) consoleDispatcher;

	Sender s(csvReaderAndParserObj, stringConverterObj, consoleDispatcherObj);
	s.sendInfoToReceiver();
}