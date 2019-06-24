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
# define inf 1e17
# define mx2 100005
# define mx 100005
ll get(ll i,ll j)
{
	return (i)/(__gcd(i,j));
}
int main()
{
	ll n,k,a,b,x,l,maxi=0,mini=inf;
	cin>>n>>k>>a>>b;
	l=(b-a+k)%k;
	for(ll i=0;i<n;i++)
	{
		mini=min(mini,get(n*k,k*i+l));
		maxi=max(maxi,get(n*k,k*i+l));
	}

	l=b+a;
	for(ll i=0;i<n;i++)
	{
		mini=min(mini,get(n*k,k*i+l));
		maxi=max(maxi,get(n*k,k*i+l));
	}

	l=(-b-a+k)%k;
	for(ll i=0;i<n;i++)
	{
		mini=min(mini,get(n*k,k*i+l));
		maxi=max(maxi,get(n*k,k*i+l));
	}

	l=(a-b+k)%k;
	for(ll i=0;i<n;i++)
	{
		mini=min(mini,get(n*k,k*i+l));
		maxi=max(maxi,get(n*k,k*i+l));
	}

	
	cout<<mini<<" "<<maxi<<endl;
}
