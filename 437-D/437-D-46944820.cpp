#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define pb push_back
# define mp make_pair
# define ff first
# define ss second
# define ll long long
vector <ll> adj[mx];
ll ranks[mx],parent[mx],a[mx],mark[mx];
ll find(ll a)
    {
    	if(a==parent[a])
    		return a;
    	ll x=find(parent[a]);
    	parent[a]=x;
    	
    	return x;
    }
     
void merge(ll a, ll b)
    {
    	ll x=find(a),y=find(b);
    	
    	if(x==y)	return ;
    	
    	if(ranks[x]>ranks[y])
    		swap(x,y);
    	
    	parent[x]=y;
    	ranks[y]+=ranks[x];
    	return ;    	
    }
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
bool compare(pair<ll,ll>a,pair<ll,ll> b)
{
	if(a.ff==b.ff)
		return a>b;
	return a.ff>b.ff;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll> > vec;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		vec.pb(mp(x,i));
		ranks[i]=1;
		parent[i]=i;
	}
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	sort(vec.begin(),vec.end(),compare);
	ll final=0;
	mark[vec[0].ss]=true;
	for(ll j=1;j<vec.size();j++)
	{
		ll i=vec[j].ss;
		unordered_set<ll>s;
		unordered_set<ll>::iterator itr;
		ll sum=0,diff=0;
		for(auto k:adj[i])
		{
			if(mark[k])
			{
				s.insert(find(k));
			}
		}
		for(itr=s.begin();itr!=s.end();++itr)
		{
			sum+=ranks[*itr];
			diff+=ranks[*itr]*ranks[*itr];
			merge(i,*itr);
		}
		mark[i]=true;
		final+=vec[j].ff*((sum*sum)-diff+2*sum);
	}
	printf("%.9lf\n",final/(double)(n*(n-1)) );
}