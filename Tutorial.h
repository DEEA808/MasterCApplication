#pragma once
#pragma once
#include <string>

using namespace std;

class Tutorial {

private:
	string title;
	string name;
	int likes;
	string link;
	string duration;

public:
	Tutorial();
	Tutorial(string const& title, string const& name, string const& duration, int likes, string const& link);
	string GetTitle() const;
	string GetName() const;
	string GetDuration() const;
	int GetLikes() const;
	string GetLink() const;
	~Tutorial();
	Tutorial(const Tutorial& other);
	void SetDuration(string const& value);
	void SetLikes(int value);
	void SetLink(string const& value);
	//void play();
	friend std::istream& operator>>(std::istream& inputStream, Tutorial& t);
	friend std::ostream& operator<<(std::ostream& outputStream, const Tutorial& t);

	string ToString() const;



};

