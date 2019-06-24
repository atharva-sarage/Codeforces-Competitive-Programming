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
# define mx 300005
int val[mx],low[mx];
int timer=1;
int n,m,cmp=0;
unordered_set<int> bridge;
bool visited[mx];
vector <pair<int,int> > adj[mx];
vector <int> bridge_tree[mx],vec[mx];
queue <int> q[mx];
void addedge(int u,int v,int id)
{
	adj[u].pb({v,id});
	adj[v].pb({u,id});
}
int dfs1(int u,int par)
{
	if(val[u]!=-1) // back edge par-u update low link of par
	{
		low[par]=min(low[par],val[u]);
		return low[par];
	}
	val[u]=low[u]=timer++;
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		if(dfs1(k.ff,u)<0)
		{
			low[u]=min(low[u],low[k.ff]);
			if(low[k.ff]==val[k.ff])
				bridge.insert(k.ss);
		}
	}
	return -1;
}
void dfs2(int u) 
{
	int curr=cmp;
	vec[curr].pb(u);
	q[curr].push(u);
	visited[u]=true;
	while(!q[curr].empty())
	{
		int x=q[curr].front();
		q[curr].pop();
		for(auto k:adj[x])
		{
			if(visited[k.ff])continue;
			if(bridge.find(k.ss)!=bridge.end())
			{	
				cmp++;
				bridge_tree[cmp].push_back(curr);
				bridge_tree[curr].push_back(cmp);
				dfs2(k.ff);
			}
			else
			{
				vec[curr].pb(k.ff);
				q[curr].push(k.ff);visited[k.ff]=true;
			}
		}
	}
}
void DFS()
{
	for(int i=1;i<=n;i++)
		if(val[i]==-1)
			dfs1(i,-1);
	for(int i=1;i<=n;i++)
		if(!visited[i])
			dfs2(i);
}
int diameter=0;
int dp[mx],ans[mx];
void dia(int u,int par,int depth)
{
	vector <int> g;
	for(auto k:bridge_tree[u])
	{
		if(k==par)continue;
		dia(k,u,depth+1);
		dp[u]=max(dp[u],1+dp[k]);
		g.pb(dp[k]);
	}
	sort(g.begin(),g.end(),greater<int>());
	//cout<<g.size()<<endl;
	ans[u]=((g.size()>0)?(1+g[0]):0)+((g.size()>1)?(1+g[1]):0);
	diameter=max(diameter,ans[u]);
}
int main()
{
	IOS;
	cin>>n>>m;
	memset(val,-1,sizeof(val));
	for(int i=0;i<m;i++)	
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y,i);
	}
	DFS();
	// for(int i=0;i<=cmp;i++)
	// {
	// 	for(auto k:bridge_tree[i])
	// 		cout<<i<<" "<<k<<endl;
	// }
	// printf("*********************\n");
	dia(0,-1,0);
	cout<<diameter<<endl;
	
}
