#include<iostream>
using namespace std;
#include <thread>
void  ssc(int &number) {
	number++;
	cout << "���߳����" << endl;
}

int main4() {
	int num = 3;
	//std::ref ���ڰ�װ���ô���ֵ
	thread test1(ssc,std::ref(num));
	test1.join();
	cout << "���߳�" <<num<< endl;
	system("pause");
	return 0;
}