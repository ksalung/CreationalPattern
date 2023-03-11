#pragma once
#include <iostream>
#include <string>

using namespace std;
class AbstractProductA
{
public:
	virtual std::string usefunction()const = 0;
};

class ConcreteA1 :public AbstractProductA {
	std::string usefunction() const override
	{
		return "Concrete1:usefunction()";
	}
};

class ConcreteA2 :public AbstractProductA {
	std::string usefunction() const override
	{
		return "Concrete2:usefunction()";
	}
};

class AbstractProductB
{
public:
	virtual std::string usefunctionB() const = 0;
	virtual std::string usefunctionB_2(const AbstractProductA&col)const = 0;
};

class ConcreteB1 :public AbstractProductB {

	std::string usefunctionB() const override
	{
		return "result product 2";
	}

	std::string usefunctionB_2(const AbstractProductA& col) const override
	{
		const std::string ret = col.usefunction();
		return "B1 result is " + ret;
	}
};

class AbstractFotory
{
public:
	virtual AbstractProductA* createProA() const = 0;
	virtual AbstractProductB* createProB() const = 0;
};

class ConcreteFactory1 :public AbstractFotory
{
	AbstractProductA* createProA() const override {
		return new ConcreteA1();
	}
	AbstractProductB* createProB() const override {
		return new ConcreteB1();
	}
};