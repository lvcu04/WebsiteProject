#include<iostream>
using namespace std;

struct node{
   int data;
   struct node* pLeft;
   struct node* pRight;
};
typedef struct node Node;
typedef Node* TREE;


TREE CreateTree(int x){
    TREE NewTree = new node();
    NewTree->data = x;
    NewTree->pLeft=nullptr;
    NewTree->pRight = nullptr;
    return NewTree;
}

TREE addNodeInTree(TREE &t,int x){
    if(t == nullptr){
        t = CreateTree(x);
    }
    else{
        if(t->data > x){
            t->pLeft = addNodeInTree(t->pLeft,x);
        }
        else if(t->data < x){
            t->pRight = addNodeInTree(t->pRight,x);
        }
    }
} 
// TREE addNodeInTree(TREE &t,int x){
//     if(t == nullptr){
//         t = CreateTree(x);
//     }
//     else{
//         if(t->data > x){
//             t->pLeft = addNodeInTree(t->pLeft,x);
//         }
//         else if(t->data < x){
//             t->pRight = addNodeInTree(t->pRight,x);
//         }
//     }
//     return t;
// } 
void NLR(TREE t){
    if(t != nullptr){
        cout<<t->data<<" ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
int main() {
    TREE t = nullptr;
    int choice;

    do {
        cout << "\n\n\t\t ===============MENU==========";
        cout << "\n 1. Nhap du lieu";
        cout << "\n 2. Xuat du lieu cay theo NLR";
        cout << "\n 0. Ket thuc chuong trinh";
        cout << "\n\n\t\t ===========================";

        cout << "\n Nhap lua chon: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Nhap so nguyen: ";
            cin >> x;
            t = addNodeInTree(t, x);
        } else if (choice == 2) {
            cout << "\n\t\t Duyet cay theo NLR \n";
            NLR(t);
            cout << endl;
        } else if (choice == 0) {
            break;
        } else {
            cout << "Lua chon khong hop le !";
        }

    } while (choice != 0);

    return 0;
}
