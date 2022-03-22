#include <iostream>
#include <thread>
using namespace std;

class MM {
public:
	void operator()() {
	
		cout << "MM线程调用" << endl;
	}

};
int main2() {
	//MM(); 无名对象
	//正常写法：
	MM mm;
	thread test1(mm);
	test1.join();

	//第二种方法：
	thread test2((MM()));//不在MM（）中外面再加一个括号，会让线程将其解析为函数
	test2.join();
	system("pause");
	return 0;
}
