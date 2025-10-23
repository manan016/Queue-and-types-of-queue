#include<iostream>
using namespace std;
class cirQ {
	int arr[5];
	int rear, front;
public:
	cirQ() {
		rear = -1;
		front = -1;
	}
	bool isempty() {
		return rear == -1;
	}
	bool isfull() {
		return (front == (rear + 1) % 5);
	}
	void enqueue(int x) {
		if (isfull()) {
			cout << "circular Queue is full : " << endl;
			return;
		}
		rear = (rear + 1) % 5;
		if (front == -1)
			front = 0;
		arr[rear] = x;
		cout << "Element add in Queue is : " << x << endl;

	}
	void dequeue() {
		if (isempty()) {
			cout << "Queue is eempty :" << endl;
			return;
		}
		cout << " Remove Element in Queue is : " << arr[front] << endl;
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = (front + 1) % 5;
		}
	}

	void peek() {
		if (isempty()) {
			cout << "Queue is eempty :" << endl;
			return;
		}
		cout << " Top Element in Queue is : " << arr[front] << endl;
	}

	void display() {
		if (isempty()) {
			cout << "Queue is eempty :" << endl;
			return;
		}
		cout << "elements of Queue is : " << endl;
		int i = front;
		while (true) {
			cout << arr[i] << " ";
			if (i == rear) 
				break;
			i = (i + 1) % 5;
		}
		cout << endl;
	}
};
int main() {
	cirQ Q;
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);

	Q.peek();
	Q.dequeue();
	Q.peek();
	Q.display();
	

}