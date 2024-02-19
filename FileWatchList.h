#pragma once
#include "WatchList.h"
#include <string>
using namespace std;
class FileWatchList :public WatchList
{
protected:
	string fileName;
public:
	FileWatchList(const string& fileName)
	{
		this->fileName = fileName;
	}
	virtual ~FileWatchList() {};
	virtual void writeFile() = 0;
	//virtual void displayTutorial() = 0;

};

