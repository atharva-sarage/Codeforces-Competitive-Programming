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
# define inf 1e9
# define mx2 100005
# define mx 100005
ll s[mx];
ll pre[mx],d[mx];
int main()
{
	
	IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	ll q;
	cin>>q;
	for(ll i=1;i<n;i++)
		d[i-1]=s[i]-s[i-1];
	sort(d,d+n-1);
	pre[0]=d[0];
	for(ll i=1;i<n-1;i++)
		pre[i]=pre[i-1]+d[i];
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		ll k=r-l;
		ll ans=(r-l)+1;
		ll t=upper_bound(d,d+n-1,k)-d;
		// if difference is less than k then take difference
		// 0-(t-1)
		ans+=(k+1)*(n-t-1);
		ans+=pre[t-1];
		cout<<ans<<" ";
	}
}


