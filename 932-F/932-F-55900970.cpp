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
# define mx2 100005
# define mx 100005
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
vector <ll> adj[mx];
ll a[mx],b[mx],ans[mx];
LineContainer* line[mx];
pair<ll,ll> bg[mx];
ll sub[mx];
void addedge(ll u,ll v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfs1(ll u,ll par)
{
	sub[u]=1;
	ll mx1=-1;
	bg[u]={-1,-1};
	for(auto k:adj[u]){
		if(k==par)continue;
		dfs1(k,u);
		sub[u]+=sub[k];
		if(sub[k]>mx1)
		{
			bg[u]={sub[k],k};
			mx1=sub[k];
		}
	}
}
void dfs2(ll u,ll par)
{	
	for(auto k:adj[u]){
		if(k==par)continue;
		dfs2(k,u);
	}
	if(bg[u].ss!=-1)
		line[u]=line[bg[u].ss];
	else
		line[u]= new LineContainer;

	for(auto k:adj[u])
	{
		if(k==par || k==bg[u].ss)
			continue;
		for(auto l:(*line[k]))
			(*line[u]).add(l.k,l.m);
	}
	if(!(*line[u]).empty())
		ans[u]=(*line[u]).query(a[u]);
	(*line[u]).add(-b[u],ans[u]);
	
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	for(ll i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		addedge(u,v);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	for(ll i=1;i<=n;i++)
		cout<<-ans[i]<<" ";
	cout<<endl;
	

}