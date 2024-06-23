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
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    int vertex, edge;

    //          FILE
    ifstream inputFile("testcase1.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file !";
        return 1;
    }

    inputFile >> vertex;
    inputFile >> edge;
    inputFile.ignore();
    vector<vector<int>> AdjacentMatrix(vertex, vector<int>(vertex, 0));
	unordered_map<string, int> vertexIdx(vertex);
	vector<string> vertexName(vertex);

    // Read vector vertex
    for (int i = 0; i < vertex; i++)
    {
        inputFile >> vertexName[i];
        vertexIdx[vertexName[i]] = i;
    }


    // read weight
    // v v w
    string startVer, endVer;
    int startIdx, endIdx;
    int weight;
    for (int i = 0; i < edge; i++)
    {
        inputFile >> startVer;
        inputFile >> endVer;
        inputFile >> weight;
        startIdx = vertexIdx[startVer];
        endIdx = vertexIdx[endVer];

        AdjacentMatrix[startIdx][endIdx] = weight;
    }
    inputFile.close();

    /*
    //                     TYPE
	cin >> vertex >> edge;
	cin.ignore();
	for (int i = 0; i < vertex; i++)
    {
        getline(cin, vertexName[i]);
        vertexIdx[vertexName[i]] = i;
    }


	Input(v, v_index, e, G);
	Output(v, v_index, e, G);
    */
    //              PRINT
    for (int i =0; i < vertex; i++)
    {
        for (int j= 0; j < vertex; j++)
        {
            cout << AdjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
