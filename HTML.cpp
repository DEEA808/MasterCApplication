#include "HTML.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include "Tutorial.h"
//#include <windows.h>
using namespace std;

void HTML::writeFile()
{
	ofstream f(this->fileName);
	if (!f.is_open()) {
		throw exception("No file");
	}
	f << "<!DOCTYPE html>\n";
	f << "<html>\n";
	f << "<head>\n";
	f << "\t<title>WatchList</title\n";
	f << "</head>\n";
	f << "<body>\n";
	f << "table border='1>'\n";
	int index = 0;
	f << "\t<tr>\n";
	for (auto t : this->tutorials) {
		f << "\t\t" << "<td>Title</td>" << t.GetTitle() << "\",\n";
		f << "\t\t" << "<td>Name</td>" << t.GetName() << "\",\n";
		f << "\t\t" << "<td>Duration</td>" << t.GetDuration() << "\",\n";
		f << "\t\t" << "<td>Likes</td>" << t.GetLikes() << "\",\n";
		f << "\t\t" << "<td>Link</td>" << t.GetLink() << "\"\n";
		if (index != this->tutorials.size() - 1) {
			f << "\t</tr>\n";
			f << "\t<tr>\n";
		}
		else
		{
			f << "\t</tr>\n";
		}
		index++;
	}
	f << "</table>\n";
	f << "</body>\n";
	f << "</html>\n";
	f.close();
}

//void HTML::displayTutorial()
//{
	//ShellExecuteA(NULL, NULL, "C:\\Users\\deear\\OneDrive\\Documents\\deea_asc\\asm_tools\\npp\\notepad++.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
//}