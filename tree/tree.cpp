#include <iostream>
#include <time.h>

using namespace std;


class Vertex {
protected:
    int Data;
    int Index;
    int Level;
    Vertex* Left;
    Vertex* Right;

public:
    Vertex() : Data(-1), Index(-1), Level(-1), Left(nullptr), Right(nullptr) {}

    Vertex(int key) : Data(key), Index(-1), Level(-1), Left(nullptr), Right(nullptr) {}



    void setData(int D) {
        this->Data = D;
    };
    void printData() {
        cout << "Index: " << this->Index << " Data: " << this->Data << " \n ";
    };
    void setLeft(Vertex* ptr) {
        Left = ptr;
    };
    void setRight(Vertex* ptr) {
        Right = ptr;
    };
    void initLeft() {
        Vertex* left = new Vertex;
        Left = left;
        Left->Level = Level + 1;
    };
    void initRight() {
        Vertex* right = new Vertex;
        Right = right;
        Right->Level = Level + 1;
    };

    void makeIdeal(Vertex* ptr, int n) {
        int nl, nr;
        nl = n / 2;
        nr = n - nl - 1;
        if ((nl == 0) && (nr == 0)) {
            return;
        }
        else
            if (nl == 0) {
                ptr->initRight();
                return;
            }
            else if (nr == 0) {
                ptr->initLeft();
                return;
            }
            else {
                ptr->initLeft();
                makeIdeal(ptr->Left, nl);
                ptr->initRight();
                makeIdeal(ptr->Right, nr);
            }
    };
    int i = 0;
    void LeftToRight(Vertex* ptr) {
        i = 0;
        if (ptr != nullptr) {
            LeftToRight(ptr->Left);
            //ptr->Data = i;
            //i++;               // zapolnenie
            ptr->printData();    // po poruadku

            LeftToRight(ptr->Right);
        }
    };
    void AssignIndexes(Vertex* ptr) {
        if (ptr != nullptr) {
            ptr->Index = i;
            i++;
            AssignIndexes(ptr->Left);
            AssignIndexes(ptr->Right);

        }
    }
    void UpToDown(Vertex* ptr) {
        if (ptr != nullptr) {
            
            ptr->printData();
            UpToDown(ptr->Left);
            UpToDown(ptr->Right);

        }
    };
    void DownToUp(Vertex* ptr) {
        if (ptr != nullptr) {
            DownToUp(ptr->Left);
            DownToUp(ptr->Right);
            ptr->printData();
        }
    };

    int Size(Vertex* ptr) {
        int size = 0;
        if (ptr == nullptr) {
            return size;
        }
        else {
            size = 1 + Size(ptr->Left) + Size(ptr->Right);
        }
        return size;
    };
    int Sum(Vertex* ptr) {
        int sum = 0;
        if (ptr == nullptr) {
            return sum;
        }
        else {
            sum = ptr->Data + Sum(ptr->Left) + Sum(ptr->Right);
        }
        return sum;
    };
    int Height(Vertex* ptr) {
        int height = 0;
        if (ptr == nullptr) {
            return height;
        }
        else {
            height = 1 + max(Height(ptr->Left), Height(ptr->Right));
        }
        return height;
    };
    int Path(Vertex* ptr) {
        int path = 0;
        if (ptr == nullptr) {
            return path;
        }
        else {
            path = 1 + ptr->Level + Path(ptr->Left) + Path(ptr->Right);
        }
        return path;
    };
    double midHeight(Vertex* ptr) {
        return (double)Path(ptr) / (double)Size(ptr);
    };

    Vertex* AddSDP(Vertex* ptr, int data) {
        Vertex* temp = ptr;
        bool side = false; //0 - left 1 - right
        while (temp != nullptr) {
            if (data < temp->Data) {
                if (temp->Left == nullptr) {
                    side = false;
                    break;
                }
                else {
                    temp = temp->Left;
                }
            }
            else if (data > temp->Data) {
                if (temp->Right == nullptr) {
                    side = true;
                    break;
                }
                else {
                    temp = temp->Right;
                }
            }
            else {
                //cout << "This element is already exists.";
                return nullptr;
            }
        }
        if (temp == nullptr) {
            temp = new Vertex(data);
        }
        if (side) {
            temp->initRight();
            temp->Right->Data = data;
        }
        else {
            temp->initLeft();
            temp->Left->Data = data;
        }
        
        return temp;
    }

    void DeleteSDP(Vertex* ptr, int data) {
        Vertex** temp = &ptr;
        // search
        while (*temp != nullptr) {
            if (data < (*temp)->Data) {
                temp = &((*temp)->Left);
            }
            else if (data > (*temp)->Data) {
                temp = &((*temp)->Right);
            }
            else {
                cout << "\ndata found and deleted\n";
                break;
            }
        }
        // p == temp // q == var
        if (temp != nullptr) {
            Vertex* var = *temp;
            if (var->Left == nullptr) {
                *temp = var->Right;
            }
            else if (var->Right == nullptr) {
                *temp = var->Left;
            }
            else {
                Vertex* r = var->Left;
                Vertex* s = var;
                if (r->Right == nullptr) {
                    r->Right = var->Right;
                    *temp = r;
                }
                else {
                    while (r->Right != nullptr) {
                        s = r;
                        r = r->Right;
                    }
                    s->Right = r->Left;
                    r->Left = var->Left;
                    r->Right = var->Right;
                    *temp = r;

                }
            }
            delete var;
        }
    }

};

int main() {
    Vertex* sdp = new Vertex(rand() % 100);
    while (sdp->Size(sdp) < 100) {
        sdp->AddSDP(sdp, rand() % 100);
    }
    cout << "Start SDP with 100 random elements:\n";
    sdp->AssignIndexes(sdp);
    sdp->LeftToRight(sdp);
    
    for (int i = 0; i < 10; i++) {
        cout << "\nEnter element you want to delete:\n";
        int elem;
        cin >> elem;
        sdp->DeleteSDP(sdp, elem);
        cout << "\nResult:\n";
        sdp->AssignIndexes(sdp);
        sdp->LeftToRight(sdp);
    }
    return 0;
}