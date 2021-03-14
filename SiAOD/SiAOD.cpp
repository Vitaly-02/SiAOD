#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 10;
int A[N];
int Moves = 0, Compares = 0;

void FillInc(int A[], int N) {
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
};

void FillDec(int A[], int N) {
    int k = N;
    for (int i = 0; i < N; i++) {
        A[i] = k;
        k--;
    }
};

void FillRand(int A[], int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        A[i] = rand() % 10 + 1;
};

void PrintMas() {
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
};

int CheckSum() {
    int z = 0;
    for (int i = 0; i < N; i++)
        z += A[i];
    return z;
};

int RunNumber() {
    int count = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] > A[i + 1]) {
            count += 1;
        }
    }
    count += 1;
    return count;
};

void SelectSort(int Massive[], int size) {  //upgrade commented
    Moves = 0, Compares = 0;
    for (int i = 0; i < size-1; i++) {
        int min = i;        
            for (int j = i + 1; j < size; j++) {
                Compares++;
                if (Massive[j] < Massive[min]) {
                    min = j;
                }
            }
//            if ((i != min) && (min > i)) {
                swap(Massive[i], Massive[min]);
                Moves += 3;
//            }
    }
//    cout << "\nM = " << Moves << " C = " << Compares << endl;
};

void BubbleSort(int Massive[], int size) { 
    Moves = 0, Compares = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = size-1; j > i ; j--) {
            Compares++;
            if (Massive[j] < Massive[j - 1]) {
                swap(Massive[j], Massive[j - 1]);
                Moves += 3;
            }
        }
    }
    //cout << "\nM = " << Moves << " C = " << Compares << endl;
}

void ShakerSort(int Massive[], int size) {
    Moves = 0, Compares = 0;
    int Left = 0, Right = size-1, k = size-1;
    do {
        for (int j = Right; j > Left; j--) {
            Compares++;
            if (Massive[j] < Massive[j - 1]) {
                swap(Massive[j], Massive[j - 1]);
                Moves += 3;
                k = j;
            }
        }
        Left = k;
        for (int j = Left; j < Right; j++) {
            Compares++;
            if (Massive[j] > Massive[j + 1]) {
                swap(Massive[j], Massive[j + 1]);
                Moves += 3;
                k = j;
            }
        }
        Right = k;
    } while (Left < Right);
    //cout << "\nM = " << Moves << " C = " << Compares << endl;
}

void InsertSort(int Massive[], int size) {
    Moves = 0, Compares = 0;
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = Massive[i]; 
        Moves++;
        j = i - 1;
        Compares++;
        while ((j >= 0) && (temp < Massive[j])) {
            Massive[j + 1] = Massive[j];
            if (j == i - 1) {
                Compares--;
            }
            Moves++; 
            Compares++;
            j = j - 1;
        }
        Massive[j + 1] = temp; 
        Moves++;
    }
}


void ShellSort(int Massive[], int size) {
    int max = 0;
    max = pow(2, N / 2 + 1) -1 ;
    for (int k = max; k >= 1; k = (k - 1) / 2) {
        cout << k << ' ';
    }
}

int main() {
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
    
    cout << endl;
    
}