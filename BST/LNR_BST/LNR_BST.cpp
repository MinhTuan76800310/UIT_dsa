/**
  ******************************************************************************
  * @file    LNR_BST.cpp
  * @author  Pham Minh Tuan
  * @brief   Create a binary search tree (BST) from a given array and print the tree in LNR order using stack
  * @date    20/06/2024
  ******************************************************************************
*/
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

// start
TNODE* CreateNode(int x)
{
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
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

void CreateTree_F(TREE &T, ifstream &inputFile)
{
    int x;
    while(true)
    {
        inputFile >> x;
        if (x == -1)
        {
            return;
        }
        AddNode(T, x);
    }
}

void PrintLNR_stack(TREE T)
{
    stack<TNODE *> st;
    TNODE *iteratorNode = T;
    while(iteratorNode != NULL || !st.empty())
    {
        // reach the leftmost node
        while(iteratorNode != NULL)
        {
            st.push(iteratorNode);
            iteratorNode = iteratorNode->pLeft;
        }

        iteratorNode = st.top();
        st.pop();

        cout << iteratorNode->key << " ";
        iteratorNode = iteratorNode->pRight;
    }
}
// end

int main() {
    //                  INPUT FILE
    ifstream inputFile("testcase2.txt");
    TREE T = NULL;
    CreateTree_F(T, inputFile);
    PrintLNR_stack(T);

    /*                  INPUT by type
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	*/
	return 0;
}
