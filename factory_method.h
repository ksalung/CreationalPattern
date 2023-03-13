#pragma once
#include <iostream>
#include <string>

using namespace std;
class _product
{
public:
	virtual string Operation() const = 0;
};

class concrete_product3 : public _product
{
public:
	string Operation() const override
	{
		return "result of concrete_product[3].";
	}
};

class concrete_product4 : public _product
{
public:
	string Operation() const override
	{
		return "result of concrete_product[4].";
	}
};

class creator
{
public:
	virtual _product* factory_method() const = 0;
	string some_operation() const
	{
		_product* pro = this->factory_method();
		string result = "creator : same creator's code worked." + pro->Operation();
		
		delete pro;
		return result;
	}
};

class concrete_creator3 : public creator
{
public:
	_product* factory_method() const override
	{
		return new concrete_product3();
	}
};

class concrete_creator4 : public creator
{
public:
	_product* factory_method() const override
	{
		return new concrete_product4();
	}
};