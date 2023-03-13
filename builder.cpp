#include "builder.h"


void Clientcode(director& director)
{
	concrete_builder* builder = new concrete_builder();
	director.set_builder(builder);
	std::cout << "normal line : " << endl;
	director.buildviable_product();


	product1* product = builder->create_product();
	product->list_get();
	delete product;

	std::cout << "full function : " << endl;
	director.buildfull_product();

	product = builder->create_product();
	product->list_get();
	delete product;

	std::cout << "custom product : " << endl;
	builder->product_partA();
	builder->product_partB();
	builder->product_partC();
	product = builder->create_product();
	product->list_get();
	delete product;
}

//int main()
//{
//	director* director = new director();
//	Clientcode(*director);
//	delete director;
//	return 0;
//}