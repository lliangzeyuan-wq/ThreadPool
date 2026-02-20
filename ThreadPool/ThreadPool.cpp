#include<iostream>
using namespace std;
#include<mutex>
once_flag m_flag;

class TaskQueue {
	friend void init();
public:
	TaskQueue(const TaskQueue& t) = delete;
	TaskQueue& operator=(const TaskQueue& t) = delete;
	static TaskQueue* getInstance() {
		call_once(m_flag, [&] {
			m_taskQ = new TaskQueue;
			});
		return m_taskQ;
	}
	void print() {
		cout << "我是单例对象的一个成员函数..." << endl;
	}
private:
	//TaskQueue() {};
	//TaskQueue(const TaskQueue& t) {};
	//TaskQueue& operator=(const TaskQueue& t) {};

	TaskQueue() = default;
	//TaskQueue(const TaskQueue& t) = default;
	//TaskQueue& operator=(const TaskQueue& t) = default;

	//只能通过类名访问静态属性或方法
	static TaskQueue* m_taskQ;
};
TaskQueue* TaskQueue::m_taskQ = nullptr;



int main() {
	TaskQueue* taskQ = TaskQueue::getInstance();
	taskQ->print();
	return 0;
}