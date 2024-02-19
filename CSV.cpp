#include "CSV.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include "Tutorial.h"
//#include <windows.h>
using namespace std;

void CSV::writeFile()
{
	std::ofstream f(this->fileName);
	if (!f.is_open())
		throw exception("The file can not be open");
	Tutorial t;
	for (auto t : this->tutorials)
		f << t.ToString();
	f.close();
}

//void CSV::displayTutorial()
//{
	//ShellExecuteA(NULL, NULL, "C:\\ProgramData\Microsoft\\Windows\\Start Menu\\Programs\\Excel.lnk", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
//}