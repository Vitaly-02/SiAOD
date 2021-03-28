#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 4;
int A[N];
int Moves = 0, Compares = 0;

struct user {
	char fam[10];
	char name[15];
	char otch[15];
	char tel[12];
};

void Create_Index(int Massive[], int size) {
	for (int i = 0; i < size; i++) {
		Massive[i] = i;
	}
}

int CompareFam(user one, user two) {
    for (int i = 0; i < 10; i++) {
        if (one.fam[i] > two.fam[i]) {
            return 2;
        }
        else if (one.fam[i] < two.fam[i]) {
            return 1;
        }
    }
    return 0; //esli ravno
}

void InsertSortFam(user Massive[], int Index[], int size) {
    Moves = 0, Compares = 0;
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = Index[i];
        Moves++;
        j = i - 1;
        Compares++;
        while ((j >= 0) && (CompareFam(Massive[temp], Massive[j]) == 1)) {
            Index[j + 1] = Index[j];
            if (j == i - 1) {
                Compares--;
            }
            Moves++;
            Compares++;
            j = j - 1;
        }
        Index[j + 1] = temp;
        Moves++;
    }
}

int CompareName(user one, user two) {
    for (int i = 0; i < 15; i++) {
        if (one.name[i] > two.name[i]) {
            return 2;
        }
        else if (one.name[i] < two.name[i]) {
            return 1;
        }
    }
    return 0; //esli ravno
}

void InsertSortName(user Massive[], int Index[], int size) {
    Moves = 0, Compares = 0;
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = Index[i];
        Moves++;
        j = i - 1;
        Compares++;
        while ((j >= 0) && (CompareName(Massive[temp], Massive[j]) == 1)) {
            Index[j + 1] = Index[j];
            if (j == i - 1) {
                Compares--;
            }
            Moves++;
            Compares++;
            j = j - 1;
        }
        Index[j + 1] = temp;
        Moves++;
    }
}

int main() {
	user Sprav[N];
	Sprav[0] = {"Pupkin", "Grigory", "Alekseevich", "89871234523"};
	Sprav[1] = {"Utkina", "Anna", "Andreevna", "89882281142"};
	Sprav[2] = {"Petrov", "Mihail", "Sergeevich", "89871289351"};
	Sprav[3] = {"Andreev", "Vasily", "Ivanovich", "89814885578"};

	int Index1[N], Index2[N];
	Create_Index(Index1, N);
	Create_Index(Index2, N);

    InsertSortFam(Sprav, Index1, N);

    for (int i = 0; i < N; i++) {
        cout << Sprav[Index1[i]].fam << " " << Sprav[Index1[i]].name << " " << Sprav[Index1[i]].otch << " " << Sprav[Index1[i]].tel << endl;
    }
    cout << endl;

    InsertSortName(Sprav, Index2, N);

    for (int i = 0; i < N; i++) {
        cout << Sprav[Index2[i]].fam << " " << Sprav[Index2[i]].name << " " << Sprav[Index2[i]].otch << " " << Sprav[Index2[i]].tel << endl;
    }
    cout << endl;

  
}