/**
  ******************************************************************************
  * @file    HeightMatrix.cpp
  * @author  Pham Minh Tuan
  * @brief   Find the height of a node in a binary search tree
  * @date    23/06/2024
  ******************************************************************************
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    int edge, vertex;
    cin >> edge >> vertex;
    vector<vector<int>> AdjacentMatrix(vertex, vector<int>(vertex, 0));
    map<string, int> vertexIdx;
    string vertexName;

    for (int i = 0; i < vertex; i++)
    {
        cin >> vertexName;
        vertexIdx[vertexName] = i;
    }

    string startVer, endVer;
    int startIdx, endIdx, weight;
    for (int i = 0; i < edge; i++)
    {
        cin >> startVer >> endVer >> weight;
        startIdx = vertexIdx[startVer];
        endIdx = vertexIdx[endVer];
        AdjacentMatrix[startIdx][endIdx] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
