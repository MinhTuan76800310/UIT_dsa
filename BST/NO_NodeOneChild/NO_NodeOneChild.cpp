/**
  ******************************************************************************
  * @file    NO_NodeOneChild.cpp
  * @author  Pham Minh Tuan
  * @brief   Count the number of nodes in a binary tree that have only one child
  * @date    20/06/2024
  ******************************************************************************
*/

#include <iostream>
#include <fstream>
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
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void AddTail(TREE &T, int x)
{
    if (T == NULL)
    {
        T = CreateNode(x);
    }else if(x > T->key)
    {
        AddTail(T->pRight, x);
    }else{
    AddTail(T->pLeft, x);
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
        AddTail(T, x);
    }
}

void CreateTree_F(TREE &T, ifstream &InputFile)
{
    int x;
    while(true)
    {
        InputFile >> x;
        if (x == -1)
        {
            break;
        }
        AddTail(T, x);
    }
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

int CountNode_Have1Child(TREE T)
{
    int count = 0;
    if (T == NULL)
    {
        return 0;
    }
    if ((T->pLeft == NULL && T->pRight != NULL) || (T->pLeft != NULL && T->pRight == NULL))
    {
            count++;
    }
    count = count + CountNode_Have1Child(T->pLeft);
    count = count + CountNode_Have1Child(T->pRight);
    return count;
}

// end


int main() {

    //                          FILE
    ifstream inputFile("testcase2.txt");
    TREE T;
    T = NULL;
    CreateTree_F(T, inputFile);
    cout << CountNode_Have1Child(T);

    inputFile.close(); // Close the input file
    //                          END FILE

    /*
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode_Have1Child(T);
	*/
	return 0;
}
