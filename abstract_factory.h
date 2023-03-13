#pragma once
#include <iostream>
#include <string>

using namespace std;
class abstract_product_A
{
public:
	virtual std::string usefunction()const = 0;
};

class productA1 :public abstract_product_A {
	std::string usefunction() const override
	{
		return "Concrete1:usefunction()";
	}
};

class productA2 :public abstract_product_A {
	std::string usefunction() const override
	{
		return "Concrete2:usefunction()";
	}
};

class abstract_product_B
{
public:
	virtual std::string usefunctionB() const = 0;
	virtual std::string usefunctionB_2(const abstract_product_A&col)const = 0;
};

class ProductB1 :public abstract_product_B {

	std::string usefunctionB() const override
	{
		return "result product 2";
	}

	std::string usefunctionB_2(const abstract_product_A& col) const override
	{
		const std::string ret = col.usefunction();
		return "B1 result is " + ret;
	}
};

class abstract_fotory
{
public:
	virtual abstract_product_A* create_productA() const = 0;
	virtual abstract_product_B* create_productB() const = 0;
};

class concrete_factory1 :public abstract_fotory
{
	abstract_product_A* create_productA() const override {
		return new productA1();
	}
	abstract_product_B* create_productB() const override {
		return new ProductB1();
	}
};