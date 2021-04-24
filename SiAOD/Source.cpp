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
    // �������� ��������� Heap �� ����������� ����
        Heap(Massive, i, 0);
    }
}
*/

/*

struct stack { //��������� � ������ stack
    int Data; //����� �� ������(����� ���� ������, � ������� ����� �������� int key; char Data; ��� �������� ��� ����� �� ������)
    stack* next;//��������� ���� stack �� ��������� ��������
};

void s_push(stack** top, int D) { //������� ���� void(������ �� ����������) ������� ��������� �������� �� ������� ����� � ���������� ������� ����� ������������ � ������
    stack* q; //������� ����� ��������� q, ������� ������������ � ������� �����. �� ���� ��� � ���� ��� ����� �������
    q = new stack(); //�������� ������ ��� ������ ��������
    q->Data = D; //���������� D � Data ��������
    if (top == NULL) { //���� ������� ���, ������ ���� ������
        *top = q; //�������� ����� ����� ����� �������
    }
    else //���� ���� �� ������
    {
        q->next = *top; //�������� ����� �� ������ ��������, � �������. ������ ������ ������ �� ������� ������.
        *top = q; //�����, ��� �������� ������ �������� ����� �������
    }
}

void s_delete_key(stack** top, int N) {//������� ������� ��������� ������� top � ����� ������� ����� �������
    stack* q = *top; //������� ��������� ���� stack � ������������(������) ��� �� ������� �����
    stack* prev = NULL;//������� ��������� �� ���������� �������, � ������ �� ����� ������
    while (q != NULL) {//���� ��������� q �� �����, �� ��� ����� ���������, ���� �� ��� �� ����� ���� �������������
        if (q->Data == N) {//���� Data �������� ����� �����, ������� ��� ����� �������
            if (q == *top) {//���� ����� ��������� ����� �������, �� ���� �������, ������� ��� ����� ������� - �������
                *top = q->next;//����������� ������� �� ��������� �������
                //free(q);//������� ������
                //delete q;
                //q->Data = NULL; //����� �� ��������� ������ �� �������� ���������� � ��������� ������, ��� ��� � ��������� ������������ ��������� ������ ����� ���������� �� NULL ��������, � �������� "����� ������ ����������" ��� �����  "-2738568384" ��� ������, � ����������� �� �����������.
                //q->next = NULL;
            }
            else//���� ������� ��������� ��� ��������� ����� ����� ������� ����������
            {
                prev->next = q->next;//�������� ����� �� ����������� �������� � ����������
                //free(q);//������� ������
                //delete q;
                //q->Data = NULL;//�������� ����������
                //q->next = NULL;

            }
        }// ���� Data �������� �� ����� �����, ������� ��� ����� �������
        prev = q; //���������� ������� ������ ��� ����������
        q = q->next;//���������� ��������� q �� ��������� �������
    }
}

void print(stack* top) { //��������� ��������� �� ������� �����
    stack* q = top; //������������� q �� �������
    while (q) { //���� q �� ������ (while(q) ������������ while(q != NULL))
        printf_s("%i", q->Data);//������� �� ����� ������ ������ �����
        q = q->next;//����� ���� ��� ������ ����������� q �� ��������� �������(������)
    }
}

int main() {
    stack* top = NULL; //� ������ ��������� � ��� ��� �������, �������������� ������� ���, ���� �� �������� NULL
    //������ �������� ��������� ����� �� 1 �� 5 � ��� ����
    s_push(&top, 1);
    s_push(&top, 2);
    s_push(&top, 3);
    s_push(&top, 4);
    s_push(&top, 5);
    //����� ���������� ������� � ����� � ��� ����� 54321
    print(top);//�������
    s_delete_key(&top, 4); //����� ������� 4, � ����� ���������� 5321
    printf_s("\n");//��������� �� ����� ������
    print(top);//�������
    system("pause");//������ �� �����
    return 0;
}
*/