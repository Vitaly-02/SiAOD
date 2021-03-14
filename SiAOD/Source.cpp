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