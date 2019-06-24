#include<bits/stdc++.h>
using namespace std;
# define mx 2005
typedef int long long ll;
ll n,m;
ll a[mx],b[mx],leasty[mx],leastx[mx],prex[mx]={0},prey[mx]={0};
ll final[mx*mx];
void pre()
{
	ll i;
	for(ll i=1;i<=n;i++)
		prex[i]=prex[i-1]+a[i];	
	for(ll i=1;i<=m;i++)
		prey[i]=prey[i-1]+b[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n-i+1;j++)
		{
			leastx[i]=min(leastx[i],prex[i+j-1]-prex[j-1]);
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=m-i+1;j++)
		{
			leasty[i]=min(leasty[i],prey[i+j-1]-prey[j-1]);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			final[i*j]=min(final[i*j],leastx[i]*leasty[j]);
		}
	}
}

int main()
{
	for(ll i=0;i<mx;i++)
	{
		leasty[i]=INT_MAX;
		leastx[i]=INT_MAX;
	}
	for(ll i=0;i<mx*mx;i++)
	{
		final[i]=INT_MAX;
	}
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll j=1;j<=m;j++)
		cin>>b[j];
	ll x;
	cin>>x;

	pre();
	ll k;
	for(k=n*m;k>=1;k--)
	{
		if(final[k]<=x)
		{
			break;
		}
	}
	cout<<k<<endl;


}