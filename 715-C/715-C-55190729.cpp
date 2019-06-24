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
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100005
# define D 23
set <pair<ll,ll>> adj[mx];
ll msb[mx],lsb[mx];
ll mod,root;
ll par[25][mx],depth[mx],sub[mx],p[mx],n,pw[mx],pre_inv[mx];
vector <pair<ll,ll> > vec[mx];
unordered_map <ll,ll> m[mx];
vector<ll>ctree[mx];
ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod)y%=mod;
        b /= 2;
    }
    return x%mod;
}
ll modInverse(ll a, ll m) 
{ 
	ll m0 = m; 
	ll y = 0, x = 1;
	if (m == 1) 
	return 0; 
	while (a > 1) 
	{ 
		ll q = a / m; 
		ll t = m; 
		m = a % m, a = t; 
		t = y; 
		y = x - q * y; 
		x = t; 
	} 
	if (x < 0) 
	x += m0; 
	return x; 
} 
void addedge(ll u,ll v,ll wt)
{
	adj[u].insert({v,wt});
	adj[v].insert({u,wt});
}
void dfs1(ll u,ll parent,ll level)
{
	par[0][u]=parent;
	depth[u]=level;
	for(auto k:adj[u])
	{
		if(k.ff==parent)continue;
		msb[k.ff]=(((k.ss*pw[level])%mod)+msb[u])%mod;
		lsb[k.ff]=((k.ss+(10*lsb[u])%mod))%mod;
		dfs1(k.ff,u,level+1);
	}
}
void preprocess()
{
	pw[0]=1;
	for(int i=1;i<mx;i++)
		pw[i]=(pw[i-1]*10)%mod;
	for(int i=0;i<mx;i++)
		pre_inv[i]=modInverse(pw[i],mod);
	dfs1(0,-1,0);
	for(ll  d=1;d<=D;d++)
		for(ll i=0;i<n;i++)
			{ 
				ll  mid=par[d-1][i];
				if(mid!=-1)
				par[d][i]=par[d-1][mid];
			}		
}
ll walk(ll  i,ll  k)
{
	for(ll  d=0;d<=D;d++)
	{
		if((k & 1<<d )>0)
			i=par[d][i];
	}
	return i;
}
ll  lca(ll  i,ll  j)
{
	if(depth[i]>depth[j])
		i=walk(i,depth[i]-depth[j]);
	if(depth[i]<depth[j])
		j=walk(j,depth[j]-depth[i]);
	if(i==j)
		return i;
	for(ll  d=D;d>=0;d--)
	{
		if(par[d][i]!=par[d][j])
		{
			i=par[d][i];
			j=par[d][j];
		}
	}
	return par[0][i];
}
ll dist(ll  i,ll  j)
{
	return depth[i]+depth[j]-2*depth[lca(i,j)];
}
ll scale(ll i,ll factor)
{
	if(factor>=0)
		return (i*pw[factor])%mod;
	else
		return (i*(pre_inv[abs(factor)])%mod)%mod;
}
ll modval(ll i,ll j)
{
	ll l1=lca(i,j);
	ll t1=msb[l1];
	ll req=depth[j]-depth[l1];
	ll have=depth[l1];
	ll a1=(scale(msb[i]-t1,req-have)+mod)%mod;
	ll a2=(lsb[j]-((lsb[l1]*pw[req]%mod)+mod)%mod)%mod;
	return (a1+a2+mod)%mod;
}
ll nn=0;
void getsub(ll u,ll par)
{
	sub[u]=1;nn++;
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		getsub(k.ff,u);
		sub[u]+=sub[k.ff];
	}
	//cout<<u<<" "<<sub[u]<<endl;
}
ll getcentroid(ll u,ll par)
{
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		if(sub[k.ff]>nn/2)
			return getcentroid(k.ff,u);
	}
	return u;
}
void decompose(ll u,ll parent)
{
	nn=0;
	getsub(u,-1);
	ll centroid=getcentroid(u,parent);
	//cout<<centroid<<"?"<<endl;
	if(parent!=-1)
		{ctree[parent].pb(centroid);}
	else
		root=centroid;

	p[centroid]=parent;
	for(auto k:adj[centroid])
		{
			adj[k.ff].erase({centroid,k.ss});
			decompose(k.ff,centroid);
		}
	adj[centroid].clear();
}
// first store for entire subtree information in each centroid
// keep lsb vector for all vertices in its subtree
// compute independetly for each one nlogn paths
void dfs2(int i,int u,int par)
{
	if(par!=-1)
	{
		//cout<<modval(u,i)<<"?"<<endl;
		vec[i].pb({modval(i,u),dist(i,u)});
		m[i][(modval(u,i)+mod)%mod]++;
	}
	for(auto k:ctree[u])
		dfs2(i,k,u);	
	
}
void DFS2()
{
	for(int i=0;i<n;i++)
		dfs2(i,i,-1);	
}
ll ans=0;
vector <pair<int,int>>temp;
void dfs4(int from,int u,int par,int keep)
{
	temp.pb({modval(from,u),dist(from,u)});
	m[from][modval(u,from)]+=keep;	
	for(auto k:ctree[u])
		dfs4(from,k,u,keep);	
}

void remove_compute_add(int i,int from)
{
	temp.clear();
	dfs4(from,i,-1,-1);	
	for(auto k:temp)
	{
		ll c1=(mod-k.ff+mod)%mod;
		ll inv=pre_inv[k.ss];
		ans+=m[from][(inv*c1)%mod];
		//cout<<i<<" "<<from<<" "<<k.ff<<" "<<(inv*c1)%mod<<" "<<m[from][(inv*c1)%mod]<<" "<<ans<<endl;
	}
	temp.clear();
	dfs4(from,i,-1,1);

}
void dfs3(ll u,ll par)
{
	for(auto k:ctree[u])
	{
		// edges in centroid tree makes no sense to remove contribution 
		// remove for each node in subtree O(n*logn*logn);
		//cout<<k<<" "<<u<<"?"<<endl;
		remove_compute_add(k,u);
		//cout<<k<<" "<<u<<"$"<<endl;
		dfs3(k,u);
		// add contribution of k in u
	}	
}
int main()
{
	//cin>>n>>mod;
	scanf("%lld %lld",&n,&mod);
	for(ll i=0;i<n-1;i++)	
	{
		ll x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		addedge(x,y,z);		
	}
	memset(par,-1,sizeof(par));
	preprocess();
	// checkopoll 1 get value between 2 vertices
	// checkpoll 2 construct centroid tree
	decompose(1,-1);
	DFS2();	
	ll single_count=0;
	dfs3(root,-1);
	for(int i=0;i<n;i++)
		single_count+=m[i][0];
	for(ll i=0;i<n;i++)
		for(auto k:vec[i])
			if(k.ff==0)
				single_count++;
	//cout<<single_count<<" "<<ans<<endl;
	printf("%lld\n",ans+single_count);
	//cout<<ans+single_count<<endl;

}