#include <iostream>
#include <thread>
using namespace std;

int main3() {
	int (*pmax)(int a, int b) {};
	pmax = [](int a, int b) { return a > b ? a : b; };
	cout << pmax(3, 6) << endl;
	thread test1([] {cout << "子线程1调用" << endl; });
	test1.join();
	system("pause");
	return 0;
}