#pragma once
#include <iostream>
#include <string>

using namespace std;
class AbstractProductA
{
public:
	virtual std::string usefunction()const = 0;
};

class ConcreteA1 : AbstractProductA {
public:
	std::string usefunction() const = 0;
};

class ConcreteA2 : AbstractProductA {
public:
	std::string usefunction() const=0;
};


class AbstractProductB
{
public:
	virtual std::string usefunctionB() const = 0;
	virtual std::string usefunctionB_2(const AbstractProductA&col)const = 0;
};

class ConcreteB1:AbstractProductB
{
public:
	std::string usefunctionB() const = 0;
	std::string usefunctionB_2(const AbstractProductA& col) const = 0;
};

class AbstractFotory
{
public:
	virtual AbstractProductA* createProA() const = 0;
	virtual AbstractProductB* createProB() const = 0;
};