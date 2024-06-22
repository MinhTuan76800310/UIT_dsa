/**
  ******************************************************************************
  * @file    HighOfNode.cpp
  * @author  Pham Minh Tuan
  * @brief   Find the height of a node in a binary search tree
  * @date    20/06/2024
  ******************************************************************************
*/

/*
Problem:
- Find the height of a node in a binary search tree.
	+ If the node is not found, return -1.
	+ If the node is the root, return 0.
	+ If the tree is empty, print "Empty Tree."
*/
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateNode(int x)
{
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void PrintLNR(TREE T)
{
    if (T == NULL)
    {
        return;
    }
    PrintLNR(T->pLeft);
    cout << T->key << " ";
    PrintLNR(T->pRight);
}

void AddNode(TREE &T, int x)
{
    if (T == NULL) {
        T = CreateNode(x);
    } else if (x < T->key) {
        AddNode(T->pLeft, x);
    } else {
        AddNode(T->pRight, x);
    }
}

void CreateTree(TREE &T)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        AddNode(T, x);
    }
}

int HeightOfNode(TREE T, int x)
{
    int height = 0;
    TNODE *iteratorNode = T;
    while (iteratorNode != NULL)
    {
        if (x == iteratorNode->key)
        {
            return height;
        }
        else if (x > iteratorNode->key)
        {
            iteratorNode = iteratorNode->pRight;
        }
        else
        {
            iteratorNode = iteratorNode->pLeft;
        }
        height++;
    }
    return -1;
}


int main() {
	TREE T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << HeightOfNode(T, x);

	return 0;
}
