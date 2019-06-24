/**************************
*	Author-Atharva Sarage *
*		IIT HYDERABAD     *
**************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 500005
# define ll long long 
# define db double
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long inf=1e16;
ll tree[4*mx+1],lo[4*mx+1],hi[4*mx+1],a[mx],delta[4*mx+1],dist[mx],rright[mx],lleft[mx],ans[mx],n;
vector<pair<pair<ll,ll>,ll> >q[mx];
vector<pair<ll,ll>>adj[mx];
void init(ll i,ll a,ll b)
{
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	ll m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}
void merge(ll i0,ll i1,ll i2)
{
	tree[i0]=min(tree[i1]+delta[i1],tree[i2]+delta[i2]);
}
void build(ll i)
{
	ll l=lo[i];
	ll r=hi[i];
	if(l==r)
	{
		tree[i]=dist[l];
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(ll i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}
void increment(ll i,ll a,ll b,ll val) // INCREMENT ALL VALUES IN RANGE A TO B
{
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
		delta[i]+=val;
		return ;
		}
	prop(i);
	increment(2*i,a,b,val);
	increment(2*i+1,a,b,val);
	merge(i,2*i,2*i+1);
}
ll query(ll i,ll l,ll r)
{
	if(r<lo[i] || hi[i]<l)
	{
		return inf;
	}
	if(l<=lo[i] && hi[i]<=r)
	{
		return tree[i]+delta[i];
	}
	prop(i);
	ll minr=query(2*i,l,r);
	ll minl=query(2*i+1,l,r);
	merge(i,2*i,2*i+1);
	return min(minr,minl);
}
void dfs1(ll u,ll dis)
{
	lleft[u]=inf;
	if(adj[u].empty())
		{dist[u]=dis;lleft[u]=u;rright[u]=u;return;}
	for(auto k:adj[u])
	{
		dfs1(k.ff,dis+k.ss);
		lleft[u]=min(lleft[u],lleft[k.ff]);
		rright[u]=max(rright[u],rright[k.ff]);
	}

}
void calc(ll u)
{
	for(auto k:q[u])
	{
		ans[k.ss]=query(1,k.ff.ff,k.ff.ss);
	}
	for(auto k:adj[u])
	{
		increment(1,lleft[k.ff],rright[k.ff],-2*k.ss);
		increment(1,1,n,k.ss);
		calc(k.ff);
		increment(1,lleft[k.ff],rright[k.ff],+2*k.ss);
		increment(1,1,n,-k.ss);
	}
}
int main()
{
    IOS;
	ll Q;
	cin>>n>>Q;
	for(ll i=2;i<=n;i++)
	{
		ll x,w;
		cin>>x>>w;
		adj[x].pb({i,w});
	}
	for(ll i=0;i<Q;i++)
	{
		ll l1,r1,v;
		cin>>v>>l1>>r1;
		q[v].pb({{l1,r1},i});
	}
	dfs1(1,0);
	for(ll i=1;i<=n;i++)
		{if(!dist[i])dist[i]=inf;}
	init(1,1,n);build(1);
	calc(1);
	for(ll i=0;i<Q;i++)
		cout<<ans[i]<<"\n";
}