/**
  ******************************************************************************
  * @file    LNR_BST.cpp
  * @author  Pham Minh Tuan
  * @brief   Create a binary search tree (BST) from a given array and print the tree in LNR order
  * @date    20/06/2024
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

// start

// end

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
