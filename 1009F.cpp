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
# define mx 1000005
vector <int> adj[mx];
unordered_map <int,int>* cnt[mx];
pair<int,int> bg[mx];
int sub[mx],ans[mx],val[mx],d[mx],depth[mx];
void addedge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfs1(int u,int par,int level)
{
	depth[u]=level;
	sub[u]=1;
	int mx1=-1;
	bg[u]={-1,-1};
	for(auto k:adj[u]){
		if(k==par)continue;
		dfs1(k,u,level+1);
		sub[u]+=sub[k];
		if(sub[k]>mx1)
		{
			bg[u]={sub[k],k};
			mx1=sub[k];
		}
	}
}
void merge(int u,int deep,int value)
{
	int temp=((*cnt[u])[deep]+=value);
	if(temp>val[u])
		{val[u]=temp;d[u]=deep-depth[u];}
	else if(temp==val[u])
		{d[u]=min(d[u],deep-depth[u]);}
}
void dfs2(int u,int par)
{	
	for(auto k:adj[u]){
		if(k==par)continue;
		dfs2(k,u);
	}
	if(bg[u].ss!=-1)
		{cnt[u]=cnt[bg[u].ss];d[u]=d[bg[u].ss]+1;val[u]=val[bg[u].ss];}
	else
		{cnt[u]= new unordered_map<int,int>();d[u]=inf;val[u]=-1;}
	merge(u,depth[u],1);
	for(auto k:adj[u]){
		if(k==par || k==bg[u].ss)continue;
		for(auto l:(*cnt[k]))
			merge(u,l.ff,l.ss);		
	}
}
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs1(1,-1,0);
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";

}
