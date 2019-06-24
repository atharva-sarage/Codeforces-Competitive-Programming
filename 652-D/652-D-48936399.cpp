#include<bits/stdc++.h>
using namespace std;
# define mx 200010
# define pb push_back
# define ff first
# define ss second
# define offset 1e9+5
# define ll long long
ll table[2*mx];
ll ans1[mx];
pair<pair<ll,ll>,ll> p[mx];
map <ll,ll> m;
void update(ll i,ll delta)
{
	while(i<=mx)
	{		
		table[i]+=delta;
		i+=(i&-i);
	}
}
ll sum(ll i)
{
	ll ans=0;
	while(i>0)
	{
		ans+=table[i];
		i-=(i&-i);
	}
	return ans;
}
ll rangesum(ll i,ll j)
{
	return sum(j)-sum(i-1);
}
bool comp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
	return a.ff.ff<b.ff.ff;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	vector <ll>vec;
	for(ll i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		p[i]={{y,x},i};
		vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	ll i=1;
	for(auto k:vec)
	{
		m[offset+k]=i++;
	}
	sort(p+1,p+n+1,comp);
	for(ll i=1;i<=n;i++)
	{
		ll temp=m[offset+p[i].ff.ss];
		ans1[p[i].ss]=rangesum(temp+1,n);
		update(temp,1);
	}
	for(ll i=1;i<=n;i++)
		cout<<ans1[i]<<endl;

	

}