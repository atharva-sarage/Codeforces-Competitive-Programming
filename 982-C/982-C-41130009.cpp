#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int below[mx];

int visited[mx];
vector <int> adj[mx];

void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int solve(int u,int parent)
{
	int ans=0;
	if(adj[u].size()==1 && parent!=-1) // leaf
		{
			below[u]=1;
			return 1;
		}
	for(int i=0;i<adj[u].size();i++)
	{
		int x=adj[u][i];
		if(x!=parent)
			ans+=solve(x,u);
	}
	below[u]=ans+1;
	return below[u];
}
int final=0;
void get(int u,int par)
{
	//cout<<u<<endl;
	if(below[u]<=2)
		return;

	for(int i=0;i<adj[u].size();i++)
	{
		int x=adj[u][i];
		if(below[x]==1)
			continue ;
		if(x!=par)
		{
			if(below[x]%2==0)
			{
				final++;
				get(x,u);
			}
		
		
		else
		{
			for(int j=0;j<adj[x].size();j++)
			{
				int y=adj[x][j];
				if(below[y]==1 || y==u)
					{
						continue;	
					}	
					if(below[y]%2==0)		
					final++;
					get(y,x);				
			}
		}

		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(visited,false,sizeof(visited));
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		addedge(u,v);
	}
	
	int t=solve(0,-1);
	if(t%2==1)
		cout<<-1<<endl;
	else
	{
		get(0,-1);
		cout<<final<<endl;
	}
}