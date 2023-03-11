#include "builder.h"


void Clientcode(Director& director)
{
	ConcreteBuilder* builder = new ConcreteBuilder();
	director.set_builder(builder);
	std::cout << "normal line : " << endl;
	director.buildviableProduct();


	Product1* product = builder->createProduct();
	product->Listget();
	delete product;

	std::cout << "full function : " << endl;
	director.buildFullProduct();

	product = builder->createProduct();
	product->Listget();
	delete product;

	std::cout << "custom product : " << endl;
	builder->ProcutPartA();
	builder->ProcutPartB();
	builder->ProcutPartC();
	product = builder->createProduct();
	product->Listget();
	delete product;
}

int main()
{
	Director* director = new Director();
	Clientcode(*director);
	delete director;
	return 0;
}