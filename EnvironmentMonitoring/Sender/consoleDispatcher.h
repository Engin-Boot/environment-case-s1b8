#pragma once
#ifndef CONSOLEDISPATCHER_H
#define CONSOLEDISPATCHER_H

#include <iostream>
#include <string>
#include "iDispatcher.h"

using namespace std;

class consoleDispatcher : public iDispatcher
{
public:
	virtual void sendData(string message) override
	{
		cout << message << endl;
	}
};

#endif // !CONSOLEDISPATCHER_H