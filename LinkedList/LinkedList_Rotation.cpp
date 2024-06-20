/**
  ******************************************************************************
  * @file    LinkedList_Ratation.cpp
  * @author  Pham Minh Tuan
  * @brief   Move part of a linked list from middle index to the end of the list to the head
  * @date    20/06/2024
  ******************************************************************************
*/
#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == nullptr) {
        cout << "Don't have enough memory.";
        return nullptr;
    }
    p->info = x;
    p->pNext = nullptr;
    return p;
}

void AddTail(LIST &L, NODE* p) {
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST &L) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        NODE* p = CreateNode(x);
        AddTail(L, p);
    }
}

void PrintList(NODE* pHead) {
    if (pHead == nullptr) {
        cout << "Empty List.";
        return;
    }
    NODE* p = pHead;
    while (p != nullptr) {
        cout << p->info;
        if (p->pNext != nullptr) cout << " ";
        p = p->pNext;
    }
    cout << endl;
}


void Function(LIST &L) {
    if (L.pHead == nullptr || L.pHead->pNext == nullptr) return;

    int count = 0;
    NODE* p = L.pHead;
    while (p != nullptr) {
        count++;
        p = p->pNext;
    }

    if (count < 3) return;
    // 1 2 3 4 5 6
    // 1 2 3 4 5


    // find mid element
    // mid element = new tail of first half
    int newHeadIdx = (count + 1)/ 2;
    p = L.pHead;
    for (int i = 1; i < newHeadIdx-1; ++i) {
        p = p->pNext;
    }

    NODE* newHead = p->pNext;
    p->pNext = nullptr;

    NODE* temp = newHead;
    while (temp->pNext != nullptr) {
        temp = temp->pNext;
    }

    temp->pNext = L.pHead;
    L.pHead = newHead;
}


int main() {
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    Function(L);
    PrintList(L.pHead);
    return 0;
}
