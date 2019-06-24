#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mp make_pair
# define pb push_back
# define ff first
# define ss second
typedef int long long ll;
# define ipair pair<ll,ll> 
ll ranks[mx],parent[mx],freq[mx];
vector <ipair> adj[mx];
void addedge(ll u,ll v,ll w)
{
	adj[u].pb(mp(v,w));
	adj[v].pb(mp(u,w));
}
ll find(ll a)
    {
    	if(a==parent[a])
    		return a;
    	ll x=find(parent[a]);
    	parent[a]=x;    	
    	return x;
    }
     
void unite(ll a, ll b)
    {
    	ll x=find(a),y=find(b);
    	
    	if(x==y)	return ;
    	
    	if(ranks[x]>ranks[y])
    		swap(x,y);
    	
    	parent[x]=y;
    	ranks[y]+=ranks[x];
    	return ;
    	
    }
bool islucky(ll wt)
{
	while(wt>=1)
	{
		if(wt%10!=4 && wt%10!=7)
			return 0;
		wt/=10;
	}
	return 1;
}
void dfs(ll u,ll parent)
{
	for(ll i=0;i<adj[u].size();i++)
	{
		ll v=adj[u][i].ff;
		ll wt=adj[u][i].ss;
		if(v==parent)continue;
		//cout<<wt<<" "<<islucky(wt)<<endl;
		if(!islucky(wt))
			unite(v,u);
		dfs(v,u);
	}
}
int main()
{
	ll n,ans=0;
	cin>>n;
	for(ll i=0;i<n;i++)
		{ranks[i]=1;parent[i]=i;}
	for(ll i=0;i<n-1;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		addedge(x,y,w);
	}
	dfs(1,-1);
	for(ll i=0;i<n;i++)
	{
		freq[find(i)]++;
	}
	for(ll i=0;i<n;i++)
	{
		ans+=freq[i]*((n-freq[i])*(n-freq[i]-1));
	}
	cout<<ans<<endl;
}