/**************************
*	Author-Atharva Sarage *
*	IIT HYDERABAD     *
**************************/

#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 100005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool mark[mx];
vector <int> adj[mx];
int ans[mx],dp[mx];
void addedge(ll u,ll v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
bool Dfs(int u,int par)
{
	mark[u]?dp[u]=0:dp[u]=-1;
	for(auto k:adj[u])
	{
		if(k==par)continue;
		if(Dfs(k,u))
			dp[u]=max(dp[k]+1,dp[u]);
	}
	if(dp[u]!=-1)
		return true;
	return false;
}
void dfs(int u,int par,int outside,bool keep)
{
	//cout<<u<<" "<<outside<<endl;
	ans[u]=max(outside,dp[u]);
	if(mark[u])
		{keep=true;outside=max(outside,0);}
	vector<pair<int,int>>vec;
	for(auto k:adj[u])
	{
		if(k==par)continue;
		if(dp[k]!=-1)
			vec.pb({dp[k],k});
	}
	if(!vec.empty())
		sort(vec.begin(),vec.end(),greater<pair<int,int> >());
	if(!keep)
		outside=-2;
	for(auto k:adj[u])	
	{
		if(k==par)continue;
		if(vec.empty() && keep==false)
			dfs(k,u,-2,false);
		if(vec.empty() && keep==true)
			dfs(k,u,outside+1,true);
		else if(vec[0].ss==k)
			dfs(k,u,max(outside+1,(vec.size()>1)?vec[1].ff+2:0),vec.size()>1||keep);
		else
			dfs(k,u,max(outside+1,vec[0].ff+2),true);
	}
	vec.clear();
}	
int main()
{
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
		{int x;cin>>x;mark[x]=true;}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	Dfs(1,-1);
	dfs(1,-1,0,false);
	int count1=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<ans[i]<<" ";
		if(ans[i]<=d)
			count1++;
	}

	cout<<count1<<endl;
}