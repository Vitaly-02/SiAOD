#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int Moves = 0;
int Compares = 0;

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

void Split(node* head, queue& a, queue& b) {
	node* h = head;
	while (h) {
		a.pushback(h->data);
		if (h->next) {
			h = h->next;
			b.pushback(h->data);
			
		}
		else {
			break;
		}
		if (h->next) {
			h = h->next;
		}
		else {
			break;
		}
	}
}

void Merge(queue a, queue b, queue& c) {
	Moves = Compares = 0;
	node* a_node = a.head;
	node* b_node = b.head;
	node* c_node = c.head;
	int a_size = get_size(a.head);
	int b_size = get_size(b.head);
	while ((a_size != 0) && (b_size != 0)) {
		Compares++;
		if (a_node->data <= b_node->data) {
			//c_node = a_node;
			Moves++;
			c.pushback(a_node->data);
			a_size--; 
			a_node = a_node->next;
			//c_node = c_node->next;
		}
		else {
			//c_node = b_node;
			Moves++;
			c.pushback(b_node->data);
			b_size--;
			b_node = b_node->next;
			//c_node = c_node->next;
		}
	}

	while (a_size > 0) {
		//c_node = a_node;
		Moves++;
		c.pushback(a_node->data);
		a_size--;
		a_node = a_node->next;
	//	c_node = c_node->next;
	}
	while (b_size > 0) {
	//	c_node = b_node;
		Moves++;
		c.pushback(b_node->data);
		b_size--;
		b_node = b_node->next;
	//	c_node = c_node->next;
	}
}

void MergeSort(queue& S) {
	queue a; queue b;
	queue c0; queue c1;
	Split(S.head, a, b);
	int p = 1;
	int n = get_size(S.head);
	while (p < n) {
		//
		
		//

		int i = 0;
		int m = n;
		int q, r;
		while (m > 0) {
			if (m >= p) {	////
				q = p;
			}
			else {
				q = m;
			}
			m -= q;
			if (m >= p) {
				r = p;
			}
			else {
				r = m;
			}
			m -= r;			////
			if (i == 0) {
				Merge(a, b, c0);
			}
			else {
				Merge(a, b, c1);
			}
			i = 1 - i;
		}
		a = c0; b = c1; 
		p = 2 * p;
	}
	c0.tail->next = nullptr; 
	S.head = c0.head;
}


int main() {
	queue t;
	t.fill_dec(10);
	t.print();
	cout << "Runnumber = " << t.run_number(10) << endl;
	cout << "Sum = " << t.check_sum() << endl;
	
	queue y;
	y.fill_dec(10);
	y.print();
	cout << "Runnumber = " << y.run_number(10) << endl;
	cout << "Sum = " << y.check_sum() << endl;

	queue c;
	Merge(t, y, c);
	cout << "After merge: \n";
	c.print();
	cout << "Runnumber = " << c.run_number(20) << endl;
	cout << "Sum = " << c.check_sum() << endl;
	cout << "Moves = " << Moves << " Compares = " << Compares << endl;

	t.pop_all();
	y.pop_all();
	c.pop_all();

	t.fill_inc(10);
	t.print();
	cout << "Runnumber = " << t.run_number(10) << endl;
	cout << "Sum = " << t.check_sum() << endl;

	y.fill_inc(10);
	y.print();
	cout << "Runnumber = " << y.run_number(10) << endl;
	cout << "Sum = " << y.check_sum() << endl;

	Merge(t, y, c);
	cout << "After merge: \n";
	c.print();
	cout << "Runnumber = " << c.run_number(20) << endl;
	cout << "Sum = " << c.check_sum() << endl;
	cout << "Moves = " << Moves << " Compares = " << Compares << endl;
/*
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

//	queue a; queue b; t.fill_dec(10);  Split(t.head, a, b);
//	cout << "a " << endl; a.print(); cout << "b " << endl; b.print();
//	queue c; Merge(a, b, c); cout << "c " << endl; c.print();
//	cout << c.is_empty();
//	queue q; q.fill_dec(10); q.print(); MergeSort(q); cout << "after sort\n"; q.print();
//	cout << get_size(q.head) << endl;
	
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
	*/
	return 0;
}