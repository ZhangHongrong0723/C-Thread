#include <iostream>
#include <thread>
using namespace std;
void printss(unique_ptr<int> ptr) {//智能指针
	cout << "子线程" <<ptr.get() << endl;
}
int main() {
	int(*p) = new int(1000);
	cout << *p << endl;
	unique_ptr <int> ptr(new int(1000));
	cout << "主线程" <<ptr.get() << endl;
	thread test1(printss,move(ptr));//使用移动语义的方式转换
	test1.join();
	cout<< this_thread::get_id() << endl;
	system("pause");
	return 0;
}