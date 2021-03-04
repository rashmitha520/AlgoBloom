
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vector_creator(int** arr, int n, int s, bool* visited)
{
	vector<int>temp;
	queue<int> q;
	q.push(s);
    visited[s]=1;
    while(!q.empty())
    {   temp.push_back(q.front());
             int c=q.front();
          q.pop();
        for(int i=1;i<n;i++)
        {
            if(i==c) continue;
            if(!visited[i] && arr[i][c]==1)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return temp;
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	vector<vector<int> >super;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			super.push_back(vector_creator(arr, v, i, visited));
		}
	}
	for (int i = 0; i < super.size(); i++)
	{
		sort(super[i].begin(), super[i].end());
		for (int j = 0; j < super[i].size(); j++)
		{
			cout << super[i][j]<<" ";
		}
		cout << endl;
	}
}
