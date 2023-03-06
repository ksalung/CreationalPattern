#include "AbstractFactory.h"

void ClientCode(const AbstractFotory& factory)
{
	const AbstractProductA* product_A = factory.createProA();
	const AbstractProductB* product_B = factory.createProB();

	cout << product_B->usefunctionB() << endl;
	cout << product_B->usefunctionB_2(*product_A) << endl;
	delete product_A;
	delete product_B;
}

class Concrete1 : AbstractProductA {
	std::string usefunction() const override
	{
		return "Concrete1:usefunction()";
	}
};

class Concrete2 : AbstractProductA {
std::string usefunction() const override
{
	return "Concrete2:usefunction()";
}
};

class ConcreteB1 :AbstractProductB {
	std::string usefunctionB() const override
	{
		return "result product 2";
	}

	std::string usefunctionB_2(const AbstractProductA & col) const override 
	{
	const std::string ret = col.usefunction();
	return "B1 result is " + ret;
	}
};

	class ConcreteFactory1 : AbstractFotory
	{
		AbstractProductA* createProA() const override {
			return new ConcreteA1();
		}
		AbstractProductB* createProB() const override {
			return new ConcreteB1();
		}
	};

	int main()
	{
		ConcreteA1* f1 = new ConcreteA1();
		ClientCode(*f1);
		delete f1;
	}