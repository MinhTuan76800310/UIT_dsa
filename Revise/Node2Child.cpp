/**
  ******************************************************************************
  * @file    Node2Child.cpp
  * @author  Pham Minh Tuan
  * @brief   Count the number of node in tree have 2 childs
  * @date    02/07/2024
  ******************************************************************************
*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
// Start code
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

void CountNode_Have2Child(TREE T, int &cnt)
{
    if (T == NULL)
    {
        return;
    }
    if (T->pLeft != NULL && T->pRight != NULL)
    {
        cnt++;
    }
    CountNode_Have2Child(T->pLeft, cnt);
    CountNode_Have2Child(T->pRight, cnt);

}
// End code

int main() {
	int count=0;
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	CountNode_Have2Child(T, count);
	cout << count;
	return 0;
}
