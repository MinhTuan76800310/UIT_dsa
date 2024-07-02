/**
  ******************************************************************************
  * @file    InsertInBST.cpp
  * @author  Pham Minh Tuan
  * @brief   Insert a number X in sorted array using binary search.
  * @date    01/07/2024
  ******************************************************************************
*/

#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
//
void ChenTang(int x, int A[], int &N)
{
    int leftIdx, rightIdx, midIdx;
    leftIdx = 0;
    rightIdx = N-1;
    while (leftIdx <= rightIdx)
    {
        midIdx = leftIdx + (rightIdx - leftIdx) / 2;
        if (x == A[midIdx])
        {
            leftIdx = midIdx;
            break;
        } else if (x >= A[midIdx])
        {
            leftIdx = midIdx + 1;
        }
        else{
            rightIdx = midIdx -1;
        }
    }
    // shift right before insert
    for (int i = N; i > leftIdx; i--)
    {
        A[i] = A[i-1];
    }

    // insert at leftIdx
    A[leftIdx] = x;
    // increase N
    N++;
}
//
void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x; // the number is inserted.
    int n; cin >> n; // the number of element in array.

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

