#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 20;
int A[N];

void FillInc() {
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
};

void FillDec() {
    int k = N;
    for (int i = 0; i < N; i++) {
        A[i] = k;
        k--;
    }
};

void FillRand() {
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

void SelectSort(int Massive[], int size) {
    int Moves = 0, Compares = 0;
    for (int i = 0; i < N-1; i++) {
        int min = i; 
        if (RunNumber() != 1) {
            for (int j = i + 1; j < N; j++) {
                Compares++;
                if (Massive[j] < Massive[min]) {
                    min = j;
                }
            }
            if ((i != min) && (min > i)) {
                swap(Massive[i], Massive[min]);
                Moves += 3;
            }
        }
    }
    cout << "\nM = " << Moves << " C = " << Compares << endl;
};

int main() {
    cout << "RANDOM MASSIVE\n";
    FillRand();
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    SelectSort(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3*(N - 1) << " C = " << (N*N - N)/2;

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