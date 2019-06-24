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
ll a[mx];
ll sum1=0,sum2=0;
int main()
{
	IOS;
	ll n;
	cin>>n;
	n=2*n;
	for(ll i=0;i<n;i++)
		{cin>>a[i];sum2+=a[i];}
	sort(a,a+n);
	for(ll i=0;i<n/2;i++)
		sum1+=a[i];
	if(sum1==sum2-sum1)
		{cout<<-1<<endl;return 0;}
	for(ll i=0;i<n;i++)
		cout<<a[i]<<" ";
	
}