#include "builder.h"


void Clientcode(Director& director)
{
	concrete_builder* builder = new concrete_builder();
	director.set_builder(builder);
	std::cout << "normal line : " << endl;
	director.buildviable_product();


	product1* product = builder->create_product();
	product->Listget();
	delete product;

	std::cout << "full function : " << endl;
	director.buildFull_product();

	product = builder->create_product();
	product->Listget();
	delete product;

	std::cout << "custom product : " << endl;
	builder->product_partA();
	builder->product_partB();
	builder->product_partC();
	product = builder->create_productA();
	product->Listget();
	delete product;
}

//int main()
//{
//	Director* director = new Director();
//	Clientcode(*director);
//	delete director;
//	return 0;
//}