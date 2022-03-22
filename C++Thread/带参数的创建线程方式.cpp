#include<iostream>
using namespace std;
#include <thread>
void  ssc(int &number) {
	number++;
	cout << "子线程输出" << endl;
}

int main4() {
	int num = 3;
	//std::ref 用于包装引用传递值
	thread test1(ssc,std::ref(num));
	test1.join();
	cout << "主线程" <<num<< endl;
	system("pause");
	return 0;
}