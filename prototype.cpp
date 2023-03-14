#include "prototype.h"

void client(prototype_factory& factory)
{
	cout << "create a prototype 1" << endl;

	prototype* proto_type = factory.create_prototype(type::TYPEA);
	proto_type->method(90);
	delete proto_type;

	cout << "create a protype 2 " << endl;
	proto_type = factory.create_prototype(type::TYPEB);
	proto_type->method(10);

	delete proto_type;
}

int main()
{
	prototype_factory* factory = new prototype_factory();
	client(*factory);
	delete factory;

	return 0;
}