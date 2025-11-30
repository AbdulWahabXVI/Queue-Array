#include <iostream>
using namespace std;

class Queue {
	int queue_size;
	int ifront;
	int iback;
	int array_capacity;
	int* array;
public:
	Queue(int n = 0) : queue_size(0), iback(-1), ifront(0), array_capacity(n), array( new int[array_capacity]) {}
	bool empty() const {
		return (queue_size == 0);
	}
	int top() const {
		if (!empty()) {
			array[ifront];
		}
		else {
			throw std::runtime_error("Empty");
		}
	}
	void push(int n) {
		if (queue_size == array_capacity) {
			throw std::runtime_error("Full");
		}
		iback++;
		array[iback] = n;
		queue_size++;
	}
	int pop() {
		if (empty()) {
			throw std::runtime_error("Empty");
		}
		queue_size--;
		return array[ifront++];
	}
	~Queue() {
		delete[] array;
	}
};

int main() {
	Queue q;

	q.push(6);
	q.push(7);
	cout << q.top() << endl;
	cout << q.pop() << endl;
	cout << q.top() << endl;
	cout << q.pop() << endl;
}
