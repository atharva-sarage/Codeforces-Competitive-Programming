#include<bits/stdc++.h>
using namespace std;
# define mx 200005
# define ff first
# define ss second
# define pb push_back
# define mp make_pair
# define D 25
typedef int long long ll;
ll inf=1e15;
vector <pair<ll,ll> > adj[mx];
ll dist[30][mx],par[30][mx],a[mx],val[mx],parent[mx],final[mx],deg[mx];
void addedge(ll u,ll v,ll w)
{
	adj[u].pb(mp(v,w));
	adj[v].pb(mp(u,w));
}
void dfs(ll u,ll p)
{
	par[0][u]=p;
	parent[u]=p;
	for(auto v:adj[u])
	{
		if(v.ff==p)continue;	
		dist[0][v.ff]=v.ss;
		dfs(v.ff,u);
	}
}
ll  walk(ll  i,ll  k)
{
    for(ll  d=0;d<=D;d++)
    {
        if((k & 1<<d )>0)
            i=par[d][i];
    }
    return i;
}
ll  walk_dist(ll  i,ll  k)
{
	ll temp=0;
    for(ll  d=0;d<=D;d++)
    {
        if((k & 1<<d )>0)
        	{temp+=dist[d][i];
            i=par[d][i];}
        if(i==-1)
        	return inf;
    }
    return temp;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=2;i<=n;i++)
	{
		ll x,w;
		cin>>x>>w;
		addedge(i,x,w);
		deg[i]++;
		deg[x]++;
	}
	memset(par,-1,sizeof(par));
	memset(dist,-1,sizeof(dist));
	dfs(1,-1);
	for(ll  d=1;d<=D;d++)
       {
            for(ll i=1;i<=n;i++)
            { 
                ll  mid=par[d-1][i];
                if(mid!=-1)
             	 {
             	 	par[d][i]=par[d-1][mid];
             	 	if(dist[d-1][mid]!=-1)
            		dist[d][i]=dist[d-1][i]+dist[d-1][mid];
            	 }
       		}
       }    
   	for(ll i=1;i<=n;i++)
   	{
   		ll low=0;
   		ll high=n-1;
   		ll mid;
   		while(high>=low)
   		{
   			mid=low+(high-low)/2;   			
   			if(walk_dist(i,mid)<=a[i])
   				low=mid+1;
   			else
   				high=mid-1;  			
   		}
   		if(parent[walk(i,high)]!=-1)
   		val[parent[walk(i,high)]]-=1;
   		if(parent[i]!=-1)
   		val[parent[i]]+=1;
   		//cout<<i<<" "<<walk(i,high)<<endl;   		
   	}
   	queue<ll>q;
   	for(ll i=1;i<=n;i++)
   	{
   		if(deg[i]==1 && i!=1)
   			q.push(i);
   	}
   	
   	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		if(v==1)continue;		
		val[parent[v]]+=val[v];
		deg[parent[v]]--;
		if(deg[parent[v]]==1)
			q.push(parent[v]);
	}
	for(ll i=1;i<=n;i++)
	{
		cout<<val[i]<<" ";
	}
}