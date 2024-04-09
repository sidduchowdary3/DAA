#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits> 
using namespace std;

#define v 5

void tsp(int graph[][v], int s)
{
    int mp = INT_MAX;
    vector<int> arr;
    for (int i = 0; i < v; i++)
    {
        if (i != s)
        {
            arr.push_back(i);
        }
    }
    do
    {
        int cpw = 0;
        int k = s;
        for (int i = 0; i < arr.size(); i++)
        {
            cpw += graph[k][arr[i]]; 
            k = arr[i]; 
        }
        cpw += graph[k][s];
        mp = min(cpw, mp);
    } while (next_permutation(arr.begin(), arr.end()));
    cout << mp; 
}

int main()
{
    int graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
        }
    }
    int s = 0;
    tsp(graph, s); 
    return 0; 
}
