#include "TutorialVal.h"
using namespace std;

TutorialExc::TutorialExc(vector<string> _errors) :errors{ _errors }
{
}

vector<string> TutorialExc::GetErr() const
{
	return this->errors;
}

void TutorialVal::val(const Tutorial& t)
{
	vector<string> errors;
	if (t.GetTitle().size() < 3)
		errors.push_back("The title can not have less then 3 letters!\n");
	if (!isupper(t.GetName()[0]))
		errors.push_back("The name has to start with a capital letter!\n");
	if (t.GetLikes() < 0)
		errors.push_back("The number of likes can not be negativ!\n");
	size_t posWww = t.GetLink().find("www");
	size_t posHttp = t.GetLink().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw TutorialExc(errors);
}
