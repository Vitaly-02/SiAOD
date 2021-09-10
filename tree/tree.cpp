#include <iostream>
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
        cout << "Lvl: " << Index << "-" << Data << " ||";
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
            i++;               //
            ptr->printData(); //
            
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
};

int main() {
    Vertex* Root = new Vertex;
    Root->makeTree1(Root);
    Root->LeftToRight(Root);
    cout << endl;
    Root->UpToDown(Root);
    cout << endl;
    Root->DownToUp(Root);
    return 0;
}