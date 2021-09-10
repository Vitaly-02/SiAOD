﻿#include <iostream>
#include <time.h>

using namespace std;

class Vertex {
private:
    int Data;
    int Index = 0;
    Vertex* Left = nullptr;
    Vertex* Right = nullptr;

public:
    void setData(int D) {
        Data = D;
    }
    void printData() {
        cout /*<< "Lvl: " << Index  << "-"*/ << Data << " ||";
    }
    void setLeft(Vertex* ptr) {
        Left = ptr;
    }
    void setRight(Vertex* ptr) {
        Right = ptr;
    }
    void initLeft() {
        Vertex* left = new Vertex;
        Left = left;
        Left->Index = Index + 1;
    }
    void initRight() {
        Vertex* right = new Vertex;
        Right = right;
        Right->Index = Index + 1;
    }
    void makeTree1(Vertex* Root) {
        //Vertex* ptr = Root;
        Root->initLeft(); 
        Root->initRight();
        Vertex* ptr = Root;
        ptr = ptr->Right;
        ptr->initLeft(); 
        ptr->initRight(); 
        ptr = ptr->Right;
        ptr->initLeft();
    }
    int i = 0;
    void LeftToRight(Vertex* ptr) {
        
        if (ptr != nullptr) {
            LeftToRight(ptr->Left);
            
            ptr->Data = i;
            i++;               // zapolnenie
            ptr->printData();  // po poruadku
            
            LeftToRight(ptr->Right);
        }
    }
    void UpToDown(Vertex* ptr) {
        if (ptr != nullptr) {
            ptr->printData();
            UpToDown(ptr->Left);
            UpToDown(ptr->Right);
        }
    }
    void DownToUp(Vertex* ptr) {
        if (ptr != nullptr) {
            DownToUp(ptr->Left);
            DownToUp(ptr->Right);
            ptr->printData();
        }
    }

    int Size(Vertex* ptr) {
        int size = 0;
        if (ptr == nullptr) {
            return size;
        }
        else {
            size = 1 + Size(ptr->Left) + Size(ptr->Right);
        }
        return size;
    }
    int Sum(Vertex* ptr) {
        int sum = 0;
        if (ptr == nullptr) {
            return sum;
        }
        else {
            sum = ptr->Data + Sum(ptr->Left) + Sum(ptr->Right);
        }
        return sum;
    }
    int Height(Vertex* ptr) {
        int height = 0;
        if (ptr == nullptr) {
            return height;
        }
        else {
            height = 1 + max(Height(ptr->Left), Height(ptr->Right));
        }
        return height;
    }
    int Path(Vertex* ptr) {
        int path = 0;
        if(ptr == nullptr) {
            return path;
        }
        else {
            path = 1 + ptr->Index + Path(ptr->Left) + Path(ptr->Right);
        }
        return path;
    }
    double midHeight(Vertex* ptr) {
        return (double)Path(ptr) / (double)Size(ptr);
    }
};

int main() {
    Vertex* Root = new Vertex;
    Root->makeTree1(Root);
    Root->LeftToRight(Root);
    cout << endl;
    Root->UpToDown(Root);
    cout << endl;
    Root->DownToUp(Root);
    cout << endl << "Size = " << Root->Size(Root);
    cout << endl << "Sum = " << Root->Sum(Root);
    cout << endl << "Height = " << Root->Height(Root);
    cout << endl << "Mid Height = " << Root->midHeight(Root);
    return 0;
}