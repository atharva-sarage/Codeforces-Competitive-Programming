#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int visited[mx];
int colour[mx];
vector<pair<int,int> > vec;
vector <int> adj[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(int u,int par)
{
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!visited[v] && v!=par)
		{
			if(colour[u]!=colour[v])
				vec.push_back(make_pair(u,v));
			dfs(v,u);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	for(int i=1;i<=n;i++)
		cin>>colour[i];
	dfs(1,-1);
	int flag=0,flag1=0;
	if(vec.size()==0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].first!=vec[0].first && vec[i].second!=vec[0].first)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"YES"<<endl;
		cout<<vec[0].first<<endl;
		return 0;
	}

	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].first!=vec[0].second && vec[i].second!=vec[0].second)
		{
			flag1=1;
			break;
		}
	}
	if(flag1==0)
	{
		cout<<"YES"<<endl;
		cout<<vec[0].second<<endl;
		return 0;
	}
	cout<<"NO"<<endl;

}