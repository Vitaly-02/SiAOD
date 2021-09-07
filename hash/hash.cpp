#include <iostream>
#include <time.h>
#include <cstring>

using namespace std;

int collision = 0;

void FillRand(int A[], int N) {
	srand(time(NULL));
	for (int i = 0; i < N; i++)
		A[i] = rand() % 10 + 1;
};

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

	bool is_there(int key) {
		node* q = head;
		bool is = 0;
		while (q) {
			if (q->data == key) {
				is = 1;
			}
			q = q->next;
		}
		return is;
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
		q->data = 0;
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

int getHashStr(const char str[], int tableSize) {
	int hash = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		hash = (hash * 256 + str[i]) % tableSize;
	}
	return hash;
}

int getHashInt(int data, int tableSize) {
	int hash = 0;
	hash = (data * 17) % tableSize;
	return hash;
}

// методом прямого связывания 
void hashIntMassive(stack table[], int data[], int tableSize) {
	for (int i = 0; i < tableSize; i++) {
		table[getHashInt(data[i], tableSize)].pushtop(data[i]);
	}
}

void findKey(stack table[], int key, int tableSize) {
	int hash = getHashInt(key, tableSize);
	if(table[hash].is_there(key)) {
		cout << "\nKey element = " << key << " must be there:\n";
		cout << hash << ": ";
		table[hash].print();
	}
	else {
		cout << "\nKey element = " << key << " dont exist\n";
	}
}

// методом открытой адресации
void hashIntMassive12(int table[], int data[], int sizeOfData,  bool type, int tableSize) {
	collision = 0;
	for (int i = 0; i < sizeOfData && i < tableSize; i++) {
		int hash = getHashInt(data[i], tableSize);
		if (table[hash] != -1) {
			switch (type) {
				// линейные пробы
				case 0: {
					while (table[hash] != -1) {
						collision++;
						hash = (hash + 1) % tableSize;
					}
					break;
				}
				// квадратичные пробы
				case 1: {
					int d = 1;
					while (table[hash] != -1) {
						collision++;
						hash += d;
						d += 2;
						if (hash > tableSize) {
							hash -= tableSize;
						}
						if (d >= tableSize) {
							// таблица заполнена
							return;
							break;
						}
					}
					break;
				}
				default: {
					cout << "\nhashing failed: choose type\n";
					break;
				}
			}
		}
		table[hash] = data[i];
	}
}

int main() {
	srand(time(NULL));
	// методом прямого связывания 
	const int tableSize = 13;
	stack table[tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i].pop_all();
	}

	int dataq[] = { 1, 2, 3, 4, 5, 61, 7, 8, 9, 10};
	
	hashIntMassive(table, dataq, tableSize);
	
	for (int i = 0; i < tableSize; i++) {
		cout << i << ": ";
		table[i].print();
		cout << "\n";
	}
	//
	findKey(table, 61, tableSize);
	//
	// методом открытой адресации
	// линейные
	cout << "\nМетод открытой адресации линейные пробы\n";
	int table12[tableSize];
	for (int i = 0; i < tableSize; i++) {
		table12[i] = -1;
	}
	hashIntMassive12(table12, dataq, size(dataq), 0, tableSize);

	for (int i = 0; i < tableSize; i++) {
		cout << i << ": " << table12[i] << "\n";
	}
	// квадратичные
	cout << "\nМетод открытой адресации квадратичные пробы\n";
	for (int i = 0; i < tableSize; i++) {
		table12[i] = -1;
	}
	table12[2] = 111111;
	hashIntMassive12(table12, dataq, size(dataq), 1, tableSize);

	for (int i = 0; i < tableSize; i++) {
		cout << i << ": " << table12[i] << "\n";
	}

	int* hashTables[5]; 
	int tablica[5][4];

	for (int i = 100; i <= 500; i += 100) {
		tablica[i / 100 - 1][0] = i;
		tablica[i / 100 - 1][1] = i;
		hashTables[i / 100 - 1] = new int[i];
		for (int j = 0; j < i; j++) {
			hashTables[i / 100 - 1][j] = -1;
		}
		
		int* P;
		P = new int[i];
		FillRand(P, i);
		// linear
		hashIntMassive12(hashTables[i / 100 - 1], P, i, 0, i);
		tablica[i / 100 - 1][2] = collision;
		// quadratic
		hashIntMassive12(hashTables[i / 100 - 1], P, i, 1, i);
		tablica[i / 100 - 1][3] = collision;
	}

	cout << "\nHashTable size \t Amount of sym \t Amount of coll: Linear \t Quadratic \n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << tablica[i][j] << "\t\t\t";
		}
		cout << "\n";
	}

	return 0;
}