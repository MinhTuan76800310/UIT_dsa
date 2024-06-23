 /**
  ******************************************************************************
  * @file    AdjacentVertex.cpp
  * @author  Pham Minh Tuan
  * @brief   Find adjacent vertex.
  * @date    23/06/2024
  ******************************************************************************
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void Input(int vertex, map<string, int> &v_index, int edge, vector<vector<int>> &G)
{
    string vertexName;
    for (int i = 0; i < vertex; i++)
    {
        cin >> vertexName;
        v_index[vertexName] = i;
    }

    // read weight
    // v v w
    string startVertex, endVertex;
    int weight, startIdx, endIdx;
    for (int i = 0; i < edge; i++)
    {
        cin >> startVertex;
        cin >> endVertex;
        cin >> weight;
        startIdx = v_index[startVertex];
        endIdx = v_index[endVertex];
        G[startIdx][endIdx] = weight;
    }
}

void PrintAdjacentVertex(string verU, int edge, map<string, int> v_index, vector<vector<int>> G)
{
    int indexU = v_index[verU];
    bool check = false;
    for (int i =0; i < G.size(); i++)
    {
        if (G[indexU][i] != 0)
        {
            for (auto &pair_ : v_index)
            {
                if (pair_.second == i)
                {
                    check = true;
                    cout << pair_.first << " ";
                    break;
                }
            }
        }
    }
    if (!check)
    {
        cout << "No find.";
    }
}
int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;

	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);

	string queryVertex;
	cin >> queryVertex;
	PrintAdjacentVertex(queryVertex, e, v_index, G);
	return 0;
}

