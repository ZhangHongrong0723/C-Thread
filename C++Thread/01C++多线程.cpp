/*
	1、并发、进程、线程的基本概念
		并发：
			两个或者多个独立的活动同时进行。
		并发假象：
			单核CPU的情况下，实际上是上下文切换的方式。
		
		进程：
			计算机中的程序关于某一个数据集合上的一次运行活动。
			（exe的运行状态 ）
		线程：
			一个进程由多个线程构成。每一个进程都有且只有一个主进程
			VS编译器中运行程序即为主线程
			线程可以为一个运行代码的通道，路径，我们可以自己创建多个线程
		并发的实现：
		1、多进程实现并发
			主要解决的问题是进程间通信的问题
			A、一个电脑上：通过管道、文件、消息队列、内存共享
			B、不同电脑通过Socket网络通信的套接字实现
		2、单个进程、多个线程实现并发、就是一个主线程多个子线实现并发
			一个进程中的所有线程共享的内存空间，例如：全局变量，指针引用
	
	
	2、线程的多种创建方式：
		C++ 线程创建的过程
		A、包含头文件#include<thread>
		B、创建线程：调用thread类去创建一个线程对象
			注意点：创建一个线程，不做处理，会调用abort函数终止程序
		//C、join函数可以加入，汇合线程、阻塞主函数，即子线程处理完毕之后，才会进行主线程
			（目前不报错的问题在于C++11更新优化了）
		D、detach（）函数，会将线程进行分离，主线程和子线程各自进行各自的，互不受影响。
		（当线程detach后，就不能join了）
		E、joinable（）函数，判断当前线程是否可以做join或者detach过程，可以返回true，不可以false


	3、其他创建线程的方式
		A、普通函数方式；
		B、通过类和对象创建线程
		C、通过C++lambda表达式创建
		D、带参的方式创建线程
		E、带智能指针的方式创建线程
		F、通过类的成员函数创建线程
		*/
#include <iostream>
//导入头文件
#include <thread>

#include <Windows.h>
using namespace std;

void prints() {
	Sleep(5000);//5000ms=5s
	cout << "子进程1调用。。。" << endl;
}

void ccs() {
	Sleep(5000);
	cout << "子线程2调用" << endl;
}
int main1() {

//创建线程
	thread test1(prints);
	thread test2(ccs);//一个线程只能join一次，不可以重复join，否则会中断
	test1.join();//阻塞主线程，等子线程结束再进行主线程

	test2.detach();//这两个线程是同时启动同时进行的，所以互不影响，5s的时间是同步的
	/*detach即会进行执行，但是会sleep5s，所以还没sleep完，主线程就已经结束了，自然看不到子线程
	可以理解为后台挂起状态。把子线程驻留后台
	*/
	cout << "主线程" << endl;

	if (test1.joinable()) {
		test1.join();
	}
	else {
		cout << "该进程已被处理" << endl;
	}
	system("pause");
	return 0;
}