#include<bits/stdc++.h>
using namespace std;
#define mx 105
int memo[mx][mx][27];
vector<pair<int,char> > adj[mx];
void addedge(int u,int v,char c)
{
	adj[u].push_back(make_pair(v,c));
}
int solve(int a,int b,int c)
{
	int&me=memo[a][b][c];
	if(me!=-1)
		return me;
	me=0;
	for(int i=0;i<adj[a].size();i++)
	{
		int u=adj[a][i].first;
		char v=adj[a][i].second;
		if(v-'a'>=c)
		{
			if(solve(b,u,v-'a')==0)
			{
				me=1;
				break;
			}
		}
	}
	return me;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(memo,-1,sizeof(memo));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		char c;
		cin>>x>>y>>c;
		x--;y--;
		addedge(x,y,c);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(solve(i,j,0))
				cout<<"A";
			else
				cout<<"B";
		}
		cout<<"\n";
	}

}