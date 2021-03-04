#include <iostream>
#include<queue>
#include<map>
using namespace std;
void printbfs(int **arr,int v,int  v1,int v2, bool *visited)
{
    queue<int> q;
    map<int,int> m;
    visited[v1]=1;
    q.push(v1);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        if(f==v2) break;
        
        for(int i=0;i<v;i++)
        { if(!visited[i] && arr[f][i]==1 && i!=f)
            {visited[i]=1;
            q.push(i);
            //stores the parent of i.
            m[i]=f;
            }
        }
        if (q.empty())
		{
			return;
		}
    }
   
    int a=v2;
    cout<<v2<<" ";
    while(a!=v1)
    {
        cout<<m[a]<<" ";
        a=m[a];
    }
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
	int v1, v2;
	cin >> v1 >> v2;
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	printbfs(arr, v, v1, v2, visited);
}
