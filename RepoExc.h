#pragma once
#include <exception>
#include <string>


class FileExc : public std::exception
{
protected:
	std::string message;

public:
	FileExc(const std::string& msg);
	virtual const char* what();
};

class RepoExc : public std::exception
{
protected:
	std::string message;

public:
	RepoExc();
	RepoExc(const std::string& msg);
	virtual ~RepoExc() {}
	virtual const char* what();
};

class DuplicateSongException : public RepoExc
{
public:
	const char* what();
};

class InexistenSongException : public RepoExc
{
public:
	const char* what();
};

