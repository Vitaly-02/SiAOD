#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 10;
int A[N];
int Moves = 0, Compares = 0;
int Ksorts = 0;

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
    Moves = 0, Compares = 0;
    int max = 0, temp = size;
    while (temp >= 2) {
        temp /= 2;
        max++;
    }
    max-=1;
    //cout << max << " ";
    int* Steps;
    Steps = new int[max];
    Steps[0] = 1;
    for (int k = 1; k < max; k++) {
        Steps[k] = 2 * Steps[k - 1] + 1;
    //    cout << Steps[k] << ' ';
    }
    for (int i = max - 1, t; i >= 0; i--) {
        int k = Steps[i];
        for (int j = k ; j < size; j++) {                
            temp = Massive[j];
            Moves++;
            t = j - k;
            Compares++;
            while ((t >= 0) && (temp < Massive[t])) {
                Massive[t + k] = Massive[t];
                Moves++;
                t -= k;
            }
            Massive[t + k] = temp;
            Moves++;
        }
    
    }
    Steps = NULL;
    Ksorts = max;
}

void Heap(int Massive[], int size, int left) {
    int l = left;
    Moves++;
    int x = Massive[l];
    int j;
    while (1) {
        j = 2 * l;
        if (j > size) {
            break;
        }
        Compares++;
        if ((j < size) && (Massive[j + 1] <= Massive[j])) {
            j = j + 1;
        }
        Compares++;
        if (x <= Massive[j]) {
            break;
        }
        Moves++;
        Massive[l] = Massive[j];
        l = j;
    }
    Moves++;
    Massive[l] = x;
}

void HeapSort(int Massive[], int size) {
    Moves = 0; Compares = 0;
    int L = size / 2;
    while (L >= 0) {
        Heap(Massive, size, L);
        L = L - 1;
    }
    int R = size - 1;
    while (R >= 1) {
        Moves+=3;
        swap(Massive[0], Massive[R]);
        R = R - 1;
        Heap(Massive, R, 0);
    }
}
    
void QuickSort(int Massive[], int size, int left) {
     // PrintMas(); cout << "R=" << size - 1 << " L=" << left << endl;
    Moves++;
    int temp = Massive[left + 1]; //[left+1] //(left + size)/2
    int i, j;
    i = left;
    j = size-1;
    while (i <= j) {
        Compares++;
        while (Massive[i] < temp) {
            Compares++;
            i++;
        }
        Compares++;
        while (Massive[j] > temp) {
            Compares++;
            j--;
        }
        if (i <= j) {
            Moves += 3;
            swap(Massive[i], Massive[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        QuickSort(Massive, j, left);
    }
    if (i < size-1 ) {
        QuickSort(Massive, size, i);
    }
    
}


void BSearch1(int Massive[], int size, int search) {
    Compares = 0;
    int left = 0, right = size - 1, medium = 0;
    bool end = 0;
    
        while (left <= right) {
            medium = (left + right) / 2;
            Compares++;
            if (Massive[medium] == search) {
                end = 1;
            }
            Compares++;
            if (Massive[medium] < search) {
                left = medium + 1;
            }
            else {
                right = medium - 1;
            }
        }
              // cout << end << " " << left << " " << endl;
    
}

void BSearch2(int Massive[], int size, int search) {
    Compares = 0;
    int left = 0, right = size - 1, medium = 0;
    bool end = 0;
    
        while (left < right) {
            medium = (left + right) / 2;
            Compares++;
            if (Massive[medium] < search) {
                left = medium + 1;
            }
            else {
                right = medium;
            }
        }
        Compares++;
        if (Massive[right] == search) {
            end = 1;
        }
    
    //cout << end << " " << left << " " << endl;
}
    
int main() {
    cout << "RANDOM MASSIVE\n";
    FillRand(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    Moves = 0; Compares = 0;
    QuickSort(A, N, 0);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3*N - 1 << " C = " << (N * N + 5 * N + 4) / 2;

    cout << "\n\nINCREASING MASSIVE\n";
    FillInc(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    Moves = 0; Compares = 0;
    QuickSort(A, N, 0);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * N - 1 << " C = " << (N * N + 5 * N + 4) / 2;

    cout << "\n\nDECREASING MASSIVE\n";
    FillDec(A, N);
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    Moves = 0; Compares = 0;
    QuickSort(A, N, 0);
    cout << "\nM = " << Moves << " C = " << Compares << endl;
    PrintMas();
    cout << CheckSum() << endl << RunNumber() << endl;
    cout << "Theoretical: M = " << 3 * N  << " C = " << (N*N + 5*N + 4) /2;

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
        FillInc(P, i); Moves = 0; Compares = 0;
        QuickSort(P, i, 0);
        Tab[t] = Moves+Compares; t++;
        FillDec(P, i); Moves = 0; Compares = 0;
        QuickSort(P, i, 0);
        Tab[t] = Moves + Compares; t++;
        FillRand(P, i); Moves = 0; Compares = 0;
        QuickSort(P, i, 0);
        Tab[t] = Moves + Compares; t++;
        P = NULL;
    }
    
    cout << "      QuickSort M+C" << endl;
    cout << "\n n      Inc         Dec       Rand\n";
    for (int i = 0; i < 20; i++) {
        if ((i % 4 == 0) && (i != 0)) { 
            cout << endl; 
        }
        cout << Tab[i] << "      ";        
    }
 
    cout << endl;
}