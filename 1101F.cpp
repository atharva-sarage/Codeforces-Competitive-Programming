#include<bits/stdc++.h>
using namespace std;
# define ll long long
struct truck
{
	ll s,f,c,r;
};
struct truck t[250005];
ll a[405];
bool check(truck t1,ll val)
{
	ll curr=val,c=0;
	for(ll i=t1.s;i<t1.f;i++) // enough fuel to reach next station??
	{
		if(((a[i+1]-a[i])*t1.c)-val>0)
			return false;
		if(((a[i+1]-a[i])*t1.c)-curr<=0)
			curr-=(a[i+1]-a[i])*t1.c;
		else
			{curr=val;c++;i--;}
	}
	return(c<=t1.r);
}
int main()
{
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=0;i<m;i++)
	{
		ll p,q,r,s;
		cin>>p>>q>>r>>s;
		t[i]={p,q,r,s};
	}	
	random_shuffle(t,t+m);
	for(ll i=0;i<m;i++)
	{
		if(check(t[i],ans)) // check whether t[i] can reach in ans Liters
			continue;
		ll low=0;
		ll high=1e18;
		ll mid;
		while(high>=low)
		{
			mid=low+(high-low)/2;
			if(check(t[i],mid))
				high=mid-1;
			else
				low=mid+1;			
		}
		ans=low;
	}
	cout<<ans<<endl;

}