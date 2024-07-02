/**
  ******************************************************************************
  * @file    SumAllNode.cpp
  * @author  Pham Minh Tuan
  * @brief   Calculate total of key of node in tree.
  * @date    02/07/2024
  ****************************************************************************
*/
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
// Start
TNODE* CreateNode(int x)
{
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void AddNode(TREE &T, int x)
{
    TNODE *p = CreateNode(x);
    if (T == NULL)
    {
        T = p;
        return;
    }
    TNODE *iteratorNode = T;
    while(true)
    {
        if (x <= iteratorNode->key)
        {
            if (iteratorNode->pLeft == NULL)
            {
                iteratorNode->pLeft = p;
                break;
            }
            iteratorNode = iteratorNode->pLeft;
        }else{
        if (iteratorNode->pRight == NULL)
            {
                iteratorNode->pRight = p;
                break;
            }
            iteratorNode = iteratorNode->pRight;
        }
    }
}

void CreateTree(TREE &T)
{
    int x;
    while(true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        AddNode(T, x);
    }
}

int SumNode(TREE T)
{
    if (T == NULL)
    {
        return 0;
    }
    return T->key + SumNode(T->pLeft) + SumNode(T->pRight);
}

// end
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

