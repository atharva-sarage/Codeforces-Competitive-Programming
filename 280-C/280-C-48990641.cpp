#include<bits/stdc++.h>
using namespace std;
double ans=0.0;
vector <int> adj[100005];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(int u,int par,int level)
{
	ans+=1.0/level;
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs(k,u,level+1);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs(1,-1,1);
	printf("%.12lf\n",ans );
}