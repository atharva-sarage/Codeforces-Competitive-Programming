#include<bits/stdc++.h>
#define mp make_pair
# define pb push_back
# define ff first
# define ss second
# define mod 1000000007
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
# define mod 1000000007
typedef int long long ll;
using namespace std;
multiset <pair<ll,ll>> s;
multiset <pair<ll,ll> > :: iterator it;
vector <pair<ll,ll> > vec;
int main()
{
    IOS;
	ll n,x1,y1,final=0;
	cin>>n>>x1>>y1;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		vec.pb(mp(x,y));		
	}
	ll c1=x1/y1;
	sort(vec.begin(),vec.end());
	s.insert(mp(vec[0].ss,vec[0].ff));
	for(ll i=1;i<n;i++)
	{
		//it=lower_bound(s.begin(),s.end(),mp(vec[i].ff,0LL));
		it=s.lower_bound(mp(vec[i].ff,0LL));
		if(it==s.begin())
		{
			s.insert(mp(vec[i].ss,vec[i].ff));	
			continue;
		}
		--it;
		if(vec[i].ff-it->ff<=c1)
		{
			ll temp=it->ss;
			s.erase(it);
			s.insert(mp(vec[i].ss,temp));
		}
		else
		{
			s.insert(mp(vec[i].ss,vec[i].ff));
		}
	}
	for(it=s.begin();it!=s.end();++it)
	{
		final+=(x1+y1*(it->ff-it->ss));
		final%=mod;
	}
	cout<<final<<endl;
}
