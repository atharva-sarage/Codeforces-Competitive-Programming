#include<bits/stdc++.h>
#define mx 105
using namespace std;
int flag=0;
vector<int> adj[mx];
vector <int> mat[mx][mx];
int visited[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(int u,int end,int col,int parent)
{
	if(u==end)
	{
		flag=1;
		return;
	}
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++)
	{
		int x=adj[u][i];
		int valid=0;
		for(int k=0;k<mat[u][x].size();k++)
			{
				if(mat[u][x][k]==col)
					valid=1;
			}
		if(valid==1 && x!=parent && !visited[x])
			dfs(x,end,col,u);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		addedge(x,y);
		mat[x][y].push_back(c);
		mat[y][x].push_back(c);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		int count=0;
		for(int j=1;j<=m;j++)
		{
			flag=0;
			memset(visited,false,sizeof(visited));
			dfs(u,v,j,-1);
			if(flag==1)
				count++;
		}
		cout<<count<<endl;
	}
}