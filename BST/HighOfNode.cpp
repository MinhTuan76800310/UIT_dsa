/**
  ******************************************************************************
  * @file    HighOfNode.cpp
  * @author  Pham Minh Tuan
  * @brief   Find the height of a node in a binary search tree
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

// Start



// End


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
