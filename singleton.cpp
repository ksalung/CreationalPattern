#include "singleton.h"



singleton* singleton::_getInstance(const string& value)
{
	if (_singleton == nullptr)
	{
		_singleton = new singleton(value);
	}
	return _singleton;
}

void threadrun()
{
	singleton* s_ton = singleton::_getInstance("start");
	cout << s_ton->value() << endl;
}


int main()
{
	std::thread _run(threadrun);
	_run.join();

	return 0;
}