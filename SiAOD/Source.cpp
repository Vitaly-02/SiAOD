//main for SelectSort
/*
int main() {
    cout << "RANDOM MASSIVE\n";
    FillRand();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * (N - 1) << " C = " << (N * N - N) / 2;
}
*/

/*
    cout << "RANDOM MASSIVE\n";
    FillRand();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << (3*((N*N - N)/2))/2 << " C = " << (N*N - N)/2;

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 0 << " C = " << (N*N - N)/2;

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    BubbleSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3*((N*N - N)/2) << " C = " << (N*N - N)/2;
*/

/*
int main() {
    cout << "RANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShakerSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << (3 * ((N * N - N) / 2)) / 2 << " C = " << (N * N - N) / 2;

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShakerSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 0 << " C = " << (N * N - N) / 2;

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShakerSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * ((N * N - N) / 2) << " C = " << (N * N - N) / 2;

    //tablica
    int B[100];
    cout << "\nN        Dec        Rand       Inc        Dec        Rand       Inc\n";
    FillDec(B, 100);
    BubbleSort(B, 100);
    cout << "100      " << Moves + Compares;
    FillRand(B, 100);
    BubbleSort(B, 100);
    cout << "      " << Moves + Compares;
    FillInc(B, 100);
    BubbleSort(B, 100);
    cout << "      " << Moves + Compares;
    FillDec(B, 100);
    ShakerSort(B, 100);
    cout << "      " << Moves + Compares;
    FillRand(B, 100);
    ShakerSort(B, 100);
    cout << "      " << Moves + Compares;
    FillInc(B, 100);
    ShakerSort(B, 100);
    cout << "      " << Moves + Compares;
    cout << endl;
    int C[200];
    FillDec(C, 200);
    BubbleSort(C, 200);
    cout << "200      " << Moves + Compares;
    FillRand(C, 200);
    BubbleSort(C, 200);
    cout << "      " << Moves + Compares;
    FillInc(C, 200);
    BubbleSort(C, 200);
    cout << "      " << Moves + Compares;
    FillDec(C, 200);
    ShakerSort(C, 200);
    cout << "      " << Moves + Compares;
    FillRand(C, 200);
    ShakerSort(C, 200);
    cout << "      " << Moves + Compares;
    FillInc(C, 200);
    ShakerSort(C, 200);
    cout << "      " << Moves + Compares;
    cout << endl;
    int D[300];
    FillDec(D, 300);
    BubbleSort(D, 300);
    cout << "300      " << Moves + Compares;
    FillRand(D, 300);
    BubbleSort(D, 300);
    cout << "      " << Moves + Compares;
    FillInc(D, 300);
    BubbleSort(D, 300);
    cout << "      " << Moves + Compares;
    FillDec(D, 300);
    ShakerSort(D, 300);
    cout << "      " << Moves + Compares;
    FillRand(D, 300);
    ShakerSort(D, 300);
    cout << "      " << Moves + Compares;
    FillInc(D, 300);
    ShakerSort(D, 300);
    cout << "      " << Moves + Compares;
    cout << endl;
    int E[400];
    FillDec(E, 400);
    BubbleSort(E, 400);
    cout << "400      " << Moves + Compares;
    FillRand(E, 400);
    BubbleSort(E, 400);
    cout << "      " << Moves + Compares;
    FillInc(E, 400);
    BubbleSort(E, 400);
    cout << "      " << Moves + Compares;
    FillDec(E, 400);
    ShakerSort(E, 400);
    cout << "      " << Moves + Compares;
    FillRand(E, 400);
    ShakerSort(E, 400);
    cout << "      " << Moves + Compares;
    FillInc(E, 400);
    ShakerSort(E, 400);
    cout << "      " << Moves + Compares;
    cout << endl;
    int F[500];
    FillDec(F, 500);
    BubbleSort(F, 500);
    cout << "500      " << Moves + Compares;
    FillRand(F, 500);
    BubbleSort(F, 500);
    cout << "      " << Moves + Compares;
    FillInc(F, 500);
    BubbleSort(F, 500);
    cout << "      " << Moves + Compares;
    FillDec(F, 500);
    ShakerSort(F, 500);
    cout << "      " << Moves + Compares;
    FillRand(F, 500);
    ShakerSort(F, 500);
    cout << "      " << Moves + Compares;
    FillInc(F, 500);
    ShakerSort(F, 500);
    cout << "      " << Moves + Compares;
}
*/

/*
cout << "RANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << (N * N - N)/2 + 2 * N - 2 << " C = " << (N * N - N) / 2;

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 2 * (N - 1) << " C = " << N - 1;

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    InsertSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << (N * N - N) / 2 + 2 * N - 2 << " C = " << (N * N - N) / 2;

    //new tablica
    int Tab[25];
    for (int i = 0; i < 25; i += 5) {
        Tab[i] = 100 + (20 * i);
    }
    cout << endl;
    int t = 0;
    for (int i = 100; i <= 500; i += 100) {
        int* P;
        P = new int[i];
        if (P == NULL) {
            printf(" Error pamati ");
            return 1;
        }
        t++;
        FillRand(P, i);
        SelectSort(P, i);
        Tab[t] = Moves + Compares; t++;
        FillRand(P, i);
        BubbleSort(P, i);
        Tab[t] = Moves + Compares; t++;
        FillRand(P, i);
        ShakerSort(P, i);
        Tab[t] = Moves + Compares; t++;
        FillRand(P, i);
        InsertSort(P, i);
        Tab[t] = Moves + Compares; t++;
        P = NULL;
    }

    cout << "\n n      Select      Bubble      Shaker      Insert\n";
    for (int i = 0; i < 25; i++) {
        if ((i % 5 == 0) && (i != 0)) {
            cout << endl;
        }
        cout << Tab[i] << "      ";
    }
*/

/*
int main() {
    cout << "RANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << pow(N, 1.2) << " C = " << pow(N, 1.2);

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << pow(N, 1.2) << " C = " << pow(N, 1.2);

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    ShellSort(A, N);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << pow(N, 1.2) << " C = " << pow(N, 1.2);

    //new tablica
    int Tab[20];
    for (int i = 0; i < 20; i += 4) {
        Tab[i] = 100 + (100 * (i/4));
    }
    cout << endl;
    int t = 0;
    for (int i = 100; i <= 500; i += 100) {
        int* P;
        P = new int[i];
        if (P == NULL) {
            printf(" Error pamati ");
            return 1;
        }
        t++;
        FillRand(P, i);
        ShellSort(P, i);
        Tab[t] = Ksorts; t++;

        Tab[t] = Moves + Compares; t++;
        FillRand(P, i);
        InsertSort(P, i);
        Tab[t] = Moves + Compares; t++;

        P = NULL;
    }

    cout << "\n n      K-sorts      Shell      Insert\n";
    for (int i = 0; i < 20; i++) {
        if ((i % 4 == 0) && (i != 0)) {
            cout << endl;
        }
        cout << Tab[i] << "      ";
    }

    cout << endl;

    int Tab1[30];
    for (int i = 0; i < 30; i += 3) {
        Tab1[i] = 100 + (100 * (i / 3));
    }
    cout << endl;
    int t1 = 0;
    for (int i = 100; i <= 1000; i += 100) {
        int* P;
        P = new int[i];
        if (P == NULL) {
            printf(" Error pamati ");
            return 1;
        }
        t1++;
        FillInc(P, i);
        BSearch1(P, i, 1);
        Tab1[t1] = Compares; t1++;
        BSearch2(P, i, 1);
        Tab1[t1] = Compares; t1++;
        P = NULL;
    }

    cout << "\n n      Bsearch1     Bsearch2\n";
    for (int i = 0; i < 30; i++) {
        if ((i % 3 == 0) && (i != 0)) {
            cout << endl;
        }
        cout << Tab1[i] << "         ";
    }

    cout << endl;
    FillInc(A, N);
    BSearch1(A, N, 100);
}
*/
/*
void Heap(int Massive[], int size, int left) {
    int max = left;
    int l = 2 * left + 1;
    int r = 2 * left + 2;
    Compares++;
    if ((l < size) && (Massive[l] > Massive[max])) {
        max = l;
    }
    Compares++;
    if ((r < size) && (Massive[r] > Massive[max])) {
        max = r;
    }
    if (max != left) {
        Moves += 3;
        swap(Massive[left], Massive[max]);
        Heap(Massive, size, max);
    }

}

void HeapSort(int Massive[], int size) {
    Moves = 0; Compares = 0;
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heap(Massive, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        Moves += 3;
        swap(Massive[0], Massive[i]);
    // вызываем процедуру Heap на уменьшенной куче
        Heap(Massive, i, 0);
    }
}
*/

/*

struct stack { //Структура с именем stack
    int Data; //Кикие то данные(могут быть любими, к примеру можно написать int key; char Data; или добавить еще какие то данные)
    stack* next;//Указатель типа stack на следующий эелемент
};

void s_push(stack** top, int D) { //функция типа void(ничего не возвращает) которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
    stack* q; //Создаем новый указатель q, который приравниваем к вершине стека. По сути это и есть наш новый элемент
    q = new stack(); //выделяем память для нового элемента
    q->Data = D; //Записываем D в Data элемента
    if (top == NULL) { //Если вершины нет, тоесть стек пустой
        *top = q; //вершиной стека будет новый элемент
    }
    else //если стек не пустой
    {
        q->next = *top; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
        *top = q; //Пишем, что вершиной теперь является новый элемент
    }
}

void s_delete_key(stack** top, int N) {//функция которая принимает вершину top и число которое нужно удалить
    stack* q = *top; //создаем указатель типа stack и приравниваем(ставим) его на вершину стека
    stack* prev = NULL;//создаем указатель на предыдуший элемент, с начала он будет пустым
    while (q != NULL) {//пока указатель q не путой, мы его будем проверять, если он все же пусть цикл заканчивается
        if (q->Data == N) {//если Data элемента равна числу, которое нам нужно удалить
            if (q == *top) {//если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
                *top = q->next;//передвигаем вершину на следующий элемент
                //free(q);//очищаем ячейку
                //delete q;
                //q->Data = NULL; //Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения, а дословно "Чение памяти невозможно" или числа  "-2738568384" или других, в зависимости от компилятора.
                //q->next = NULL;
            }
            else//если элемент последний или находится между двумя другими элементами
            {
                prev->next = q->next;//Проводим связь от предыдущего элемента к следующему
                //free(q);//очищаем ячейку
                //delete q;
                //q->Data = NULL;//обнуляем переменные
                //q->next = NULL;

            }
        }// если Data элемента НЕ равна числу, которое нам нужно удалить
        prev = q; //запоминаем текущую ячейку как предыдущую
        q = q->next;//перемещаем указатель q на следующий элемент
    }
}

void print(stack* top) { //принимает указатель на вершину стека
    stack* q = top; //устанавливаем q на вершину
    while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
        printf_s("%i", q->Data);//выводим на экран данные ячейки стека
        q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
    }
}

int main() {
    stack* top = NULL; //в начале программы у нас нет очереди, соответственно вершины нет, даем ей значение NULL
    //Дальше начинаем добавлять цифры от 1 до 5 в наш стек
    s_push(&top, 1);
    s_push(&top, 2);
    s_push(&top, 3);
    s_push(&top, 4);
    s_push(&top, 5);
    //после выполнения функций в стеке у нас будет 54321
    print(top);//выводим
    s_delete_key(&top, 4); //Затем удаляем 4, в стеке получается 5321
    printf_s("\n");//переводим на новую строку
    print(top);//выводим
    system("pause");//ставим на паузу
    return 0;
}
*/