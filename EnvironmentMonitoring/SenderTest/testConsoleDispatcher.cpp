#include <iostream>
#include <string>
#include <sstream>

#include "pch.h"
#include "../Sender/consoleDispatcher.h"

using namespace std;

TEST(ConsoleDispatcher, SendData) {
	iDispatcher* consoleDispatcherObj = new(nothrow) consoleDispatcher;
	string testString = "Hello World!";
	string expectedString = "Hello World!\n";
	stringstream buffer;

	streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
	
	consoleDispatcherObj->sendData(testString);

	string callOutput = buffer.str();

	delete consoleDispatcherObj;

	ASSERT_EQ(expectedString, callOutput);
}