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
# define mx 200005
ll a[mx];
ll n,z;
ll check(ll k)
{
	ll j=k;
	for(ll i=n;i>=n-k+1;i--)
	{
		if(a[i]-a[j]<z)
			return 0;
		j--;
	}
	return 1;
}
int main()
{
	IOS;
	cin>>n>>z;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll low=0;
	ll high=n/2;
	ll mid;
	while(high>=low)
	{
		mid=low+(high-low)/2;
		if(check(mid))
			low=mid+1;
		else
			high=mid-1;
	}
	cout<<high<<endl;
}