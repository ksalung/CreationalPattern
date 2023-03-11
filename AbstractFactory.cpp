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

//int main()
//{
//	ConcreteFactory1* f1 = new ConcreteFactory1();
//	ClientCode(*f1);
//	delete f1;
//}