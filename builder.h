#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Product1
{
public:
	vector<int> vector;
	void Listget() const {
		std::cout << "Product get :";
		for (int i = 0; i < vector.size(); i++)
		{
			if (vector[i] == vector.back())
				std::cout << vector[i];
			else
				std::cout << vector[i] << ", ";
		}
		std::cout << "\n" << endl;
	}
};

class Builder
{
public:
	virtual void ProcutPartA() const = 0;
	virtual void ProcutPartB() const = 0;
	virtual void ProcutPartC() const = 0;
};

class ConcreteBuilder : public Builder {
private:
	Product1* product;
public:
	ConcreteBuilder()
	{
		this->reset();
	}
	~ConcreteBuilder()
	{
		delete product;
	}
	void reset()
	{
		this->product = new Product1();
	}

	void ProcutPartA() const override
	{
		this->product->vector.push_back(1);
	}
	void ProcutPartB() const override
	{
		this->product->vector.push_back(2);
	}
	void ProcutPartC() const override
	{
		this->product->vector.push_back(3);
	}

	Product1* createProduct()
	{
		Product1* result = this->product;
		this->reset();
		return result;
	}
};

class Director 
{
private:
	Builder* builder;
public:
	void set_builder(Builder* builder)
	{
		this->builder = builder;
	}

	void buildviableProduct()
	{
		this->builder->ProcutPartA();
	}

	void buildFullProduct()
	{
		this->builder->ProcutPartA();
		this->builder->ProcutPartB();
		this->builder->ProcutPartC();
	}
};

