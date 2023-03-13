#include "abstract_factory.h"

void ClientCode(const abstract_fotory& factory)
{
	const abstract_product_A* product_A = factory.create_productA();
	const abstract_product_B* product_B = factory.create_productB();

	cout << product_B->usefunctionB() << endl;
	cout << product_B->usefunctionB_2(*product_A) << endl;
	delete product_A;
	delete product_B;
}

//int main()
//{
//	concrete_factory1* f1 = new concrete_factory1();
//	ClientCode(*f1);
//	delete f1;
//}