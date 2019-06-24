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
# define mx 300005
ll n,m;
ll a[mx];
bool check(ll k)
{
	ll prev=0;
	for(ll i=1;i<=n;i++)
	{
		ll c1=a[i]+k;
		ll c2=(a[i]+k)%m;
		if(c1>=m && c2<prev)
		{
			prev=max(prev,a[i]);
		}
		else if(c1<m && prev>a[i]) 
		{
			if(min(prev,c1)==c1 && c1!=prev)
				return 0;
		}
		else if(c1<m && prev<=a[i])
		{
			prev=a[i];
		}
		//cout<<i<<" "<<prev<<endl;
	}
	return 1;
}
int main()
{
	IOS;
	cin>>n>>m;
	a[0]=0;
	int flag=0;
	for(ll i=1;i<=n;i++)	
		{
			cin>>a[i];
			if(a[i]<a[i-1])
				flag=1;
		}
	if(flag==0)
		{cout<<0<<endl;return 0;}
	ll low=0;
	ll high=1e18;
	ll mid;
	while(high>=low)
	{
		mid=low+(high-low)/2;
		if(check(mid))
			high=mid-1;
		else
			low=mid+1;
	}
	cout<<low<<endl;
}
