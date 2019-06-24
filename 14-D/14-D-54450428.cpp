/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100005
int dp[mx],dp2[mx],dp3[mx],parent[mx]; // deepest node subtree rooted at i
// longest path subtree rooted at i
// longest path leaving the subtree rooted at i
vector <int> adj[mx];
int fullyfinal=0;
void dfs(int u,int par)
{
	vector <int> vec;
	parent[u]=par;
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs(k,u);
		vec.pb(dp[k]);
		dp[u]=max(dp[u],1+dp[k]);
		dp2[u]=max(dp2[u],dp2[k]);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	if(vec.size()==0)return;
	if(vec.size()==1)
		dp2[u]=max(dp2[u],1+vec[0]);
	else
		dp2[u]=max(dp2[u],2+vec[0]+vec[1]);
}

void dfs1(int u,int par)
{
	int max1=0;
	vector <int> vec;
	vector <int> vec2;
	vec.pb(0);vec.pb(0);
	vec2.pb(0);
	if(par!=-1)
	{
		for(auto k:adj[par])
		{
			if(k==u || k==parent[par])continue;
			max1=max(max1,dp[k]);
			vec.pb(dp[k]+1);
			vec2.pb(dp2[k]);
			dp3[u]=max(max1+2,1+dp3[par]);
		}
		dp3[u]=max(dp3[u],1+dp3[par]);

		vec.pb(dp3[par]);
		sort(vec.begin(),vec.end(),greater<int>());
		sort(vec2.begin(),vec2.end(),greater<int>());
		//cout<<u<<" "<<" "<<dp3[par]<<" "<<dp2[u]<<" "<<vec[0]<<" "<<vec[1]<<endl;
		fullyfinal=max({fullyfinal,dp2[u]*(vec[0]+vec[1]),dp2[u]*vec2[0]});
	}
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs1(k,u);
	}
}
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,-1);
	dfs1(1,-1);
	cout<<fullyfinal<<endl;
	
}

/*
12
1 2
1 3
3 4
2 5
2 6
5 7
3 8
4 9
8 10
6 11
10 12

*/