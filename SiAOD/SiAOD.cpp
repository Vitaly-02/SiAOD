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
    int Moves = 0, Compares = 0;
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
    cout << "\nM = " << Moves << " C = " << Compares << endl;
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