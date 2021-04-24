#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
/*
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

    void pushback(info student) {
        node* p = new node(student);
        if (is_empty()) {
            head = p;
            tail = p;
            return;
        }
        tail->next = p;
        tail = p;
    }

    void print_stack() {
        if (is_empty()) {
            return;
        }
        node* p = head;
        while (p) {
            cout << p->data.name << " " << p->data.rate_1 << " " << p->data.rate_2 << " " << p->data.rate_3 << " " << p->data.rate_4 << endl;
            p = p->next;
        }
        cout << endl;
    }
*/
///////////////////

struct node {
	node* next;
	int data;

	node(int datA) : data(datA), next(nullptr) {}
};

struct stack { //ахуеть ебать его в рот, это же stack собственной персоной!
	node* head; 
	node* tail;

	stack() : head(nullptr), tail(nullptr) {}

	bool is_empty() {
		return (head == nullptr);
	}

	void print() { //принимает указатель на вершину стека		
		node* q = head; //устанавливаем q на вершину
		while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
			cout << q->data << " ";
					//printf_s("%i", q->data);//выводим на экран данные ячейки стека
			q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
		}
		cout << endl;
	}

	void pushtop(int D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
		node* q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
		q = new node(D); //выделяем память для нового элемента
	//..	q->data = D; //Записываем D в Data элемента
		if (head == nullptr) { //Если вершины нет, тоесть стек пустой
			head = q; //вершиной стека будет новый элемент
		}
		else //если стек не пустой
		{
			q->next = head; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
			head = q; //Пишем, что вершиной теперь является новый элемент
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
		while (q->next) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
			if (q->data > q->next->data) {
				count += 1;
			}
			q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
		}
		return count+1;
	};

	void pop_top() {//функция которая принимает вершину top и число которое нужно удалить
		node* q = head;
		head = q->next;
		q->data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, а дословно "Чение памяти невозможно" или числа  "-2738568384" или других, в зависимости от компилятора.
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
struct queue { //ахуеть ебать его в рот, это же queue собственной персоной!
	node* head;
	node* tail;

	queue() : head(nullptr), tail(nullptr) {}

	bool is_empty() {
		return (head == nullptr);
	}

	void print() { //принимает указатель на вершину стека		
		node* q = head; //устанавливаем q на вершину
		while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
			cout << q->data << " ";
			//printf_s("%i", q->data);//выводим на экран данные ячейки стека
			q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
		}
		cout << endl;
	}

	void pushback(int D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
		node* q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
		q = new node(D); //выделяем память для нового элемента
		//q->data = D; //Записываем D в Data элемента
		if (head == nullptr) { //Если вершины нет, тоесть стек пустой
			head = q;
			tail = q;
		}
		else //если стек не пустой
		{
			tail->next = q; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
			tail = q; //Пишем, что вершиной теперь является новый элемент
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
		while (q->next) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
			if (q->data > q->next->data) {
				count += 1;
			}
			q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
		}
		return count + 1;
	};

	void pop_top() {//функция которая принимает вершину top и число которое нужно удалить
		node* q = head;
		head = q->next;
		q->data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, а дословно "Чение памяти невозможно" или числа  "-2738568384" или других, в зависимости от компилятора.
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



int main() {

	stack t;
	t.fill_dec(10);
	cout << t.check_sum() << endl;
	t.print();
	t.pop_all();
	cout << t.check_sum() << endl;
	t.print();
	t.pushtop(12);
	t.print();

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