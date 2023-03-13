#pragma once
#include <iostream>
#include <vector>

using namespace std;
class product1
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

class _builder
{
public:
	virtual void product_partA() const = 0;
	virtual void product_partB() const = 0;
	virtual void product_partC() const = 0;
};

class concrete_builder : public _builder {
private:
	product1* product;
public:
	concrete_builder()
	{
		this->reset();
	}
	~concrete_builder()
	{
		delete product;
	}
	void reset()
	{
		this->product = new product1();
	}

	void product_partA() const override
	{
		this->product->vector.push_back(1);
	}
	void product_partB() const override
	{
		this->product->vector.push_back(2);
	}
	void product_partC() const override
	{
		this->product->vector.push_back(3);
	}

	product1* create_product()
	{
		product1* result = this->product;
		this->reset();
		return result;
	}
};

class Director 
{
private:
	_builder* builder;
public:
	void set_builder(_builder* builder)
	{
		this->builder = builder;
	}

	void buildviable_product()
	{
		this->builder->product_partA();
	}

	void buildFull_product()
	{
		this->builder->product_partA();
		this->builder->product_partB();
		this->builder->product_partC();
	}
};

