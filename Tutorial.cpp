#include <utility>
#include "Tutorial.h"
//#include <windows.h>
#include <sstream>
#include "Util.h"

using namespace std;

Tutorial::Tutorial()
{
	this->name = "";
	this->title = "";
	this->duration = "";
	this->link = "";
	this->likes = 0;
}

Tutorial::Tutorial(string const& title, string const& name, string const& duration, int likes, string const& link)
{
	this->title = title;;
	this->name = name;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
}

string Tutorial::GetTitle() const
{
	return this->title;
}

string Tutorial::GetName() const
{
	return this->name;
}

string Tutorial::GetDuration() const
{
	return this->duration;
}

int Tutorial::GetLikes() const
{
	return this->likes;
}

string Tutorial::GetLink() const
{
	return this->link;
}

Tutorial::~Tutorial() = default;


void Tutorial::SetDuration(string const& value)
{
	this->duration = value;
}


void Tutorial::SetLikes(int  value)
{
	this->likes = value;
}


void Tutorial::SetLink(string const& value)
{
	this->link = value;
}

Tutorial::Tutorial(const Tutorial& other)
{
	this->title = other.title;
	this->name = other.name;
	this->duration = other.duration;
	this->likes = other.likes;
	this->link = other.link;
}

string Tutorial::ToString() const
{
	auto str_likes = to_string(this->likes);
	return " Title: " + this->title + " Name: " + this->name + " Duration: " + this->duration + " Likes: " + str_likes + " Link: " + this->link;
}

//void Tutorial::play()
//{
	//ShellExecuteA(NULL, NULL, "chrome.exe", this->GetLink().c_str(), NULL, SW_SHOWMAXIMIZED);
//}

std::istream& operator>>(std::istream& inputStream, Tutorial& t) {
	string line;
	getline(inputStream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) {
		return inputStream;
	}
	t.title = tokens[0];
	t.name = tokens[1];
	t.duration = tokens[2];
	t.likes = std::stoi(tokens[3]);
	t.link = tokens[4];
	return inputStream;
}
std::ostream& operator<<(std::ostream& outputStream, const Tutorial& t)
{
	outputStream << t.title << "," << t.name << "," << t.duration << "," << std::to_string(t.likes) << "," << t.link;
	return outputStream;
}
