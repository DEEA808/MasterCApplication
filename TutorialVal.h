#pragma once
#include <string>
#include "Tutorial.h"
#include <vector>
using namespace std;

class TutorialExc
{
private:
	vector<string> errors;
public:
	TutorialExc(vector<string> _errors);
	vector<string> GetErr() const;
};

class TutorialVal
{
public:
	TutorialVal() {};
	static void val(const Tutorial& t);
};
