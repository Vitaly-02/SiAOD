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