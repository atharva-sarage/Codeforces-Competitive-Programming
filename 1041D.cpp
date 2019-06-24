#include<bits/stdc++.h>
# define mx 200005
typedef int long long ll;
using namespace std;
ll rough[mx];
ll zone[mx];
ll final=0;
vector <pair<ll,ll> > vec;
int main()
{
	ll n,h;
	cin>>n>>h;
	vec.push_back(make_pair(0LL,0LL));
	for(ll i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		vec.push_back(make_pair(x,y));
	}
	rough[0]=0;
	zone[0]=0;
	rough[1]=0;
	zone[1]=vec[1].second-vec[1].first;
	for(ll i=2;i<vec.size();i++)
	{
		rough[i]=rough[i-1]+vec[i].first-vec[i-1].second;
		zone[i]=zone[i-1]+vec[i].second-vec[i].first;
	}
	for(ll i=1;i<=n;i++)
	{
		ll low=i;
		ll high=n;
		ll mid;
		while(high>=low)
		{
			mid=low+(high-low)/2;
			if(rough[mid]-rough[i]>=h)
				high=mid-1;
			else
				low=mid+1;
		}
		final=max(final,h+zone[high]-zone[i-1]);
	}
	cout<<final<<endl;
}