#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int val,final=0;
vector<int> adj[mx];
vector <int> vec;
int visited[mx];
int par[mx];
int mark[mx];
int a[mx];
int c[mx];
int n;
void addedge(int u,int v)
{
	adj[u].push_back(v);
}
void dfs(int u,int parent)
{
	visited[u]=true;
	par[u]=parent;
	vec.push_back(u);
	if(a[u]==u)
	{
		final+=c[u];
		mark[u]=1;
		return; 
	}
	if(visited[a[u]])
	{
		int v=a[u];
		if(mark[a[u]])
			return;
		int min1=c[u];
		while(u!=v)
		{
			min1=min(min1,c[u]);
			u=par[u];			
		}
		min1=min(min1,c[v]);
		final+=min1;
	}
	else
	dfs(a[u],u);
	
}

void DFS()
{
	for(int i=1;i<=n;i++)
	{
		
		if(!visited[i])
			{
			dfs(i,-1);
			for(int j=0;j<vec.size();j++)
				mark[vec[j]]=1;
				vec.clear();
			}
	}
}
int main()
{
	memset(visited,false,sizeof(false));
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];

	
	DFS();
	
	cout<<final<<endl;
}

