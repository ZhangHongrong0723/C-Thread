#include <iostream>
#include <thread>
using namespace std;
void printss(unique_ptr<int> ptr) {//����ָ��
	cout << "���߳�" <<ptr.get() << endl;
}
int main() {
	int(*p) = new int(1000);
	cout << *p << endl;
	unique_ptr <int> ptr(new int(1000));
	cout << "���߳�" <<ptr.get() << endl;
	thread test1(printss,move(ptr));//ʹ���ƶ�����ķ�ʽת��
	test1.join();
	cout<< this_thread::get_id() << endl;
	system("pause");
	return 0;
}