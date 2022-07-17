#include <iostream> 
#include <string>
using namespace std; 

int q[100000];
int front = -1;
int rear = -1;

void push(int data) {
	++rear;
	q[rear] = data;
}

int empty() {
	return front == rear;
}

int pop() {
	if (empty()) return -1;

	int tmp;
	tmp = q[front + 1];
	front++;
	return tmp;
}

int size() { return rear - front; }

int main() {
	int number;
	cin >> number;
	// scanf("%d", &number);

	for (int i = 0; i < number; i++) {
		// char check[10];
		// scanf("%s", check);

		string check;
		cin >> check;

		if (check[0] == 'p' && check[1] == 'o') {
			cout << pop() << "\n";
		}
		else if (check[0] == 's') {
			cout << size() << "\n";
		}
		else if (check[0] == 'e') {
			cout << empty() << "\n";
		}
		else if (check[0] == 'f') {
			if (empty()) cout << "-1\n";
			else cout << q[front + 1] << "\n";
		}
		else if (check[0] == 'b') {
			if (empty()) cout << "-1\n";
			else cout << q[rear] << "\n";
		}
		else {
			int num;
			cin >> num;
			push(num);
		}
	}

	return 0;
}