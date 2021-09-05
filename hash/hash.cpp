#include <iostream>
#include <time.h>

using namespace std;

#define tableSize 13
struct node {
	node* next;
	int data;

	node(int datA) : data(datA), next(nullptr) {}
};

struct stack {
	node* head;
	node* tail;

	stack() : head(nullptr), tail(nullptr) {}

	bool is_empty() {
		return (head == nullptr);
	}

	void print() {
		node* q = head;
		while (q) {
			cout << q->data << " ";
			q = q->next;
		}
		cout << endl;
	}

	void pushtop(int D) {
		node* q;
		q = new node(D);
		if (head == nullptr) {
			head = q;
		}
		else {
			q->next = head;
			head = q;
		}
	}

	void fill_inc(int N) {
		for (int i = 1; i <= N; i++) {
			pushtop(i);
		}
	}

	void fill_dec(int N) {
		for (int i = N; i >= 1; i--) {
			pushtop(i);
		}
	}

	void fill_rand(int N) {
		srand(time(NULL));
		for (int i = 1; i <= N; i++)
			pushtop(rand() % 10 + 1);
	};

	int check_sum() {
		int z = 0;
		node* q = head;
		while (q) {
			z += q->data;
			q = q->next;
		}
		return z;
	};

	int run_number(int N) {
		int count = 0;
		node* q = head;
		while (q->next) {
			if (q->data > q->next->data) {
				count += 1;
			}
			q = q->next;
		}
		return count + 1;
	};

	void pop_top() {
		node* q = head;
		head = q->next;
		q->data = NULL;
		q->next = nullptr;
		delete q;
	}

	void pop_all() {
		node* q = head;
		while (q) {
			q = q->next;
			pop_top();
		}
	}

};

int getHashStr(const char str[]) {
	int hash = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		hash = (hash * 256 + str[i]) % tableSize;
	}
	return hash;
}

int getHashInt(int data) {
	int hash = 0;
	hash = (data * rand()) % tableSize;
	return hash;
}

// методом прямого связывания 
void hashIntMassive(stack table[], int data[]) {
	for (int i = 0; i < tableSize; i++) {
		table[getHashInt(data[i])].pushtop(data[i]);
	}
	cout << "\nhashing completed\n";
}


int main() {
	srand(time(NULL));
	//cout << hashInt(11);
	// методом прямого связывания 
	stack table[tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i].pop_all();
	}

	int dataq[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	
	hashIntMassive(table, dataq);
	
	for (int i = 0; i < tableSize; i++) {
		cout << i << ": ";
		table[i].print();
		cout << "\n";
	}
	return 0;
}