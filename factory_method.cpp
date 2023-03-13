#include "factory_method.h"

void clientcode(const creator& creator)
{
	cout << "client : not creator class, but worked." << creator.some_operation() << endl;
}

int main()
{
	cout << "run concrete_creator3" << endl;
	creator* _creator = new concrete_creator3();
	clientcode(*_creator);

	cout << "run concrete_creator4" << endl;
	creator* _creator2 = new concrete_creator4();
	clientcode(*_creator2);

	delete _creator;
	delete _creator2;
	return 0;
}