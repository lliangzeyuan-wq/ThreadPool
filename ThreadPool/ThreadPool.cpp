#include<iostream>
#include<thread>
#include<string>
void printHelloWorld(std::string msg) {
	std::cout << msg << std::endl;  
	return;
}
void printLZY(std::string msg) {
	for (int i = 0; i < 10000; i++) {
		std::cout << i;
	}
	std::cout << std::endl;
}
void test1() {
	std::thread thread1(printHelloWorld,"hejasiud dfsaj");
	//thread1.join();   //等子进程结束再结束main函数
	//thread1.detach();   //允许main函数结束，子进程在后台运行
	bool isJoin = thread1.joinable();
	if (isJoin) {
		thread1.join();
	}
}
void test2() {
	std::thread thread1(printLZY, "hejasiud dfsaj");
	//thread1.join();
	//thread1.detach();
	bool isJoin = thread1.joinable();
	if (isJoin) {
		thread1.join();
	}
	std::cout << "over" << std::endl;
}
int main() {
	test2();
	return 0;
}