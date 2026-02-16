#include<iostream>
#include<thread>
int a = 0;
void func() {
	for (int i = 0; i < 10000; i++)
	{
		a += 1;
	}
}
int main() {
	std::thread t1(func);
	std::thread t2(func);
	
	t1.join();
	t2.join();
	
	std::cout << a << std::endl;
	return 0;
}
