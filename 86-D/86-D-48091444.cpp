#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mp make_pair
# define ll long long 
ll freq[1000006],a[200006];
ll final[200006];
vector <pair<pair<ll,ll>,ll>> q;
ll size1;
ll ans=0;
bool cmp(pair<pair<ll,ll>,ll>&p1,pair<pair<ll,ll>,ll>&p2)
{
	ll x1=p1.ff.ff/size1;
	ll x2=p2.ff.ff/size1;
	if(x1!=x2)
		return x1<x2;
	return p1.ff.ss<p2.ff.ss;
}
inline void add(ll x)
{
	ans-=freq[x]*freq[x]*x;
	freq[x]++;
	ans+=freq[x]*freq[x]*x;
}
inline void remov(ll x)
{
	ans-=freq[x]*freq[x]*x;
	freq[x]--;
	ans+=freq[x]*freq[x]*x;
}
int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	size1=(sqrt(n));
	for(ll i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(ll i=0;i<m;i++)
	{
		ll l,r;
		scanf("%lld %lld",&l,&r);
		q.pb({{l-1,r-1},i});
	}
	sort(q.begin(),q.end(),cmp);
	ll mleft=0;ll mright=-1;
	for(ll i=0;i<m;i++)
	{
		ll l1=q[i].ff.ff;
		ll r1=q[i].ff.ss;
		while(mright<r1)
		{
			mright++;
			add(a[mright]);
		}
		while(mright>r1)
		{
			remov(a[mright]);
			mright--;
		}
		while(mleft<l1)
		{
			remov(a[mleft]);
			mleft++;
		}
		while(mleft>l1)
		{
			mleft--;
			add(a[mleft]);
		}
		final[q[i].ss]=ans;
	}

	for(ll i=0;i<m;i++)
		printf("%lld\n",final[i] );

}