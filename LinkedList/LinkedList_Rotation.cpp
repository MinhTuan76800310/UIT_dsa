
/**
  ******************************************************************************
  * @file    LinkedList_Rotation.cpp
  * @author  Pham Minh Tuan
  * @brief   Move the elements from the middle index to the last index of the LinkedList to the head
  * @date    19/06/2024
  */

#include <iostream>
#include <cmath>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

/////////////////////////
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE *CreateNode(int n)
{
    NODE *returnNode = new NODE;
    returnNode->info = n;
    returnNode->pNext = NULL;
    return returnNode;
}

void AddTail(LIST &L, NODE *node)
{
    if (L.pHead == NULL)
    {
        L.pHead = node;
        L.pTail = node;
    }
    L.pTail->pNext = node;
    L.pTail = node;
}

void CreateList(LIST &L)
{
    // Enter until -1
    int n;
    cin >> n;
    if (n == -1)
    {
        return;
    }
    while (n != -1)
    {
        AddTail(L, CreateNode(n));
        cin >> n;
        if (n == -10)
            {
                    break;
                return;
            }
    }
}

/*
In C++ (int) 5 / (int) 2 = 2.
Cut off from middle index then move to the head. Concatenating the part of to it
*/
void Function(LIST &L)
{
    if (L.pHead == NULL || L.pHead == L.pTail)
    {
        return;
    }

    int count = 0;
    NODE *current = L.pHead;
    while (current != NULL) {
        count++;
        current = current->pNext;
    }

    int middleIndex = (count + 1) / 2;

    current = L.pHead;
    for (int i = 1; i < middleIndex - 1; i++) {
        current = current->pNext;
    }

    NODE *newHead = current->pNext;

    current->pNext = NULL;

    L.pTail->pNext = L.pHead;
    L.pHead = newHead;
    L.pTail = current;
}


void PrintList(NODE *head)
{
    if (head == NULL)
    {
        cout << "Empty List.";
    }
    NODE *iteratorNode = head;
    while (iteratorNode != NULL)
    {
        cout << iteratorNode->info << " ";
        iteratorNode = iteratorNode->pNext;
    }
}

////////////////////////

int main() {
    LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Function(L);

	PrintList(L.pHead);

    return 0;
}

