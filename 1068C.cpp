#include<bits/stdc++.h>
using namespace std;
# define mx 105
# define mx2 1000000000
# define pb push_back
# define ff first
# define ss second
# define mp make_pair
vector <int> adj[mx];
vector <pair<int,int> > vec[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;		
		addedge(x,y);
	}
	int c1=1;
	for(int i=1;i<=n;i++)
	{
	    vec[i].pb(mp(i,mx2-i));
	    for(int j=0;j<adj[i].size();j++)
		{
			int v=adj[i][j];
			vec[i].pb(mp(i,c1));
			vec[v].pb(mp(v,c1));
			c1++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<vec[i].size()<<endl;
		for(auto k:vec[i])
			cout<<k.first<<" "<<k.second<<endl;
	}
}
