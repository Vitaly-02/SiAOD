#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

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
			pushtop( rand() % 10 + 1 );
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
		return count+1;
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

/////////
struct queue { 
	node* head;
	node* tail;

	queue() : head(nullptr), tail(nullptr) {}

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

	void pushback(int D) { 
		node* q; 
		q = new node(D);
		if (head == nullptr) { 
			head = q;
			tail = q;
		}
		else {
			tail->next = q; 
			tail = q;
		}
	}

	void fill_inc(int N) {
		for (int i = 1; i <= N; i++) {
			pushback(i);
		}
	}

	void fill_dec(int N) {
		for (int i = N; i >= 1; i--) {
			pushback(i);
		}
	}
	
	void fill_rand(int N) {
		srand(time(NULL));
		for (int i = 1; i <= N; i++)
			pushback(rand() % 10 + 1);
	}

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
/////////
int get_size(node* head) {
	int size = 0;
	node* q = head;
	while (q) {
		size++;
		q = q->next;
	}
	return size;
}

queue Split(node* head) {
	queue a, b;
	node* h = head;
	while (h) {
		a.pushback(h->data);
		h = h->next;
		b.pushback(h->data);
		h = h->next;
	}
	return a, b;
}

void Merge(queue a, queue b, queue c) {
	node* a_node = a.head;
	node* b_node = b.head;
	node* c_node = c.head;
	int a_size = get_size(a.head);
	int b_size = get_size(b.head);
	while (a_size != 0 && b_size != 0) {
		if (a_node->data <= b_node->data) {
			c_node = a_node;
			a_size--; 
			a_node = a_node->next;
			c_node = c_node->next;
		}
		else {
			c_node = b_node;
			b_size--;
			b_node = b_node->next;
			c_node = c_node->next;
		}
	}

	while (a_size > 0) {
		c_node = a_node;
		a_size--;
		a_node = a_node->next;
		c_node = c_node->next;
	}
	while (b_size > 0) {
		c_node = b_node;
		b_size--;
		b_node = b_node->next;
		c_node = c_node->next;
	}
}

void MergeSort(queue S) {
	
}


int main() {

	stack t;
	t.fill_dec(10);
	cout << get_size(t.head) << endl;
	cout << t.check_sum() << endl;
	t.print();
	t.pop_all();
	cout << t.check_sum() << endl;
	t.print();
	t.pushtop(12);
	cout << get_size(t.head) << endl;
	t.print();
	//MergeSort(t.head);
			
	
	queue r;
	r.fill_dec(10);
	cout << r.check_sum() << endl;
	r.print();
	r.pop_all();
	cout << r.check_sum() << endl;
	r.print();
	r.pushback(12);
	r.pop_top();
	r.print();
	return 0;
}