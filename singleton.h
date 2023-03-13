#pragma once
#include <iostream>
#include <string>
#include <thread>

using namespace std;

class singleton
{
protected:
	singleton(const string value) : _value(value)
	{
		cout << "make singleton." << endl;
	}
	static singleton* _singleton;
	string _value;

public:
	singleton(singleton& other) = delete;
	void operator= (const singleton&) = delete;

	static singleton* _getInstance(const string& value);

	void logic()
	{
		cout << "run code" << endl;
	}
	string value() const
	{
		return _value;
	}
};



