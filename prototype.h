#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

enum type
{
	TYPEA = 0,
	TYPEB
};

class prototype
{
protected:
	string name;
	int field;

public:
	prototype(string _name) : name(_name)
	{
	}
	virtual prototype* clone() const = 0;
	virtual void method(int fileld)
	{
		this->field = fileld;
		cout << "call method from " << name << " with field : " << fileld << endl;
	}
};

class concrete_prototype1 : public prototype {
private:
	int field1;
public:
	concrete_prototype1(string _name, int _field) : prototype(_name), field1(_field)
	{
	}
	prototype* clone() const override
	{
		return new concrete_prototype1(*this);
	}
};


class concrete_prototype2 : public prototype {
private:
	int field2;
public:
	concrete_prototype2(string _name, int _field) : prototype(_name), field2(_field)
	{
	}
	prototype* clone() const override
	{
		return new concrete_prototype2(*this);
	}
};


class prototype_factory
{
private :
	std::unordered_map<type, prototype*, std::hash<int>> prototypes;

public:
	prototype_factory()
	{
		prototypes[type::TYPEA] = new concrete_prototype1("TYPEA", 50);
		prototypes[type::TYPEB] = new concrete_prototype2("TYPEB", 30);
	}
	~prototype_factory()
	{
		delete prototypes[type::TYPEA];
		delete prototypes[type::TYPEB];
	}

	prototype* create_prototype(type _type)
	{
		return prototypes[_type]->clone();
	}
};
