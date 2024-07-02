/**
  ******************************************************************************
  * @file    SearchInLL.cpp
  * @author  Pham Minh Tuan
  * @brief   Search a number X in the given Linked List and return true or false
  * @date    01/07/2024
  ******************************************************************************
*/
#include <iostream>

using namespace std;

struct NODE{
int value;
NODE *pnext;
};

struct LinkedList
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->value= x;
    p->pnext = NULL;
    return p;
}

void AddTail(LinkedList &L, int x)
{
    NODE *p = CreateNode(x);
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->pnext = p;
        L.pTail = p;
    }
}

void CreateList(NODE *&pHead)
{
    LinkedList L;
    L.pHead = pHead;
    int x;
    while (true)
    {
        cin >> x;
        if (x != -1)
        {
            AddTail(L, x);
        }
        else{
            break;
        }
    }
    pHead = L.pHead;
}

string searchX(NODE* pHead, int X)
{
    NODE *iteratorNode = pHead;
    while (iteratorNode != NULL)
    {
        if (iteratorNode->value == X)
        {
            return "true";
        }
        iteratorNode = iteratorNode->pnext;
    }
    return "false";
}

// don't change main function
int main() {
    NODE* pHead;
	int X;
	pHead=NULL;

	CreateList(pHead);
	std::cin >> X;
	cout << searchX(pHead, X);

    return 0;
}
