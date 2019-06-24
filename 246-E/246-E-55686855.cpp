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
vector <int> adj[mx];
unordered_map <int,set<string>>* cnt[mx];
pair<int,int> bg[mx];
vector <pair<int,int>> query[mx];
ll sub[mx],depth[mx],ans[mx],n;
string str[mx];
bool visited[mx];
void addedge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfs1(int u,int level)
{
	visited[u]=true;
	sub[u]=1;
	depth[u]=level;
	int mx1=-1;
	bg[u]={-1,-1};
	for(auto k:adj[u])
	{
		dfs1(k,level+1);
		sub[u]+=sub[k];
		if(sub[k]>mx1)
		{
			bg[u]={sub[k],k};
			mx1=sub[k];
		}
	}
}
void merge(int u,int depth,set<string> &value)
{
	for(auto k:value)
		(*cnt[u])[depth].insert(k);
}
void dfs2(int u)
{
	visited[u]=true;
	for(auto k:adj[u]){
		dfs2(k);
	}
	if(bg[u].ss!=-1)
		{cnt[u]=cnt[bg[u].ss];}
	else
		{cnt[u]= new unordered_map<int,set<string>>();}

	(*cnt[u])[depth[u]].insert(str[u]);
	for(auto k:adj[u]){
		if(k==bg[u].ss)continue;
		for(auto l:(*cnt[k]))
			merge(u,l.ff,l.ss);		
	}
	for(auto k:query[u])
		ans[k.ss]=(*cnt[u])[k.ff+depth[u]].size();		
}
void DFS()
{
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs1(i,0);
	}
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs2(i);
	}
}
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>str[i];
		cin>>x;	
		adj[x].pb(i);
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int v,k;
		cin>>v>>k;
		query[v].pb({k,i});
	}
	DFS();
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
}