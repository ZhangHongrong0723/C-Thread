#include <iostream>
#include <thread>
using namespace std;

class MM {
public:
	void operator()() {
	
		cout << "MM�̵߳���" << endl;
	}

};
int main2() {
	//MM(); ��������
	//����д����
	MM mm;
	thread test1(mm);
	test1.join();

	//�ڶ��ַ�����
	thread test2((MM()));//����MM�����������ټ�һ�����ţ������߳̽������Ϊ����
	test2.join();
	system("pause");
	return 0;
}
