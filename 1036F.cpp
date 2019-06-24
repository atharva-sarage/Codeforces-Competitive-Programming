#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
vector <ll> vec[65];
vector <ll> fac[65];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
ll m[65];
void mobius()
{
	m[1]=1;
	for(ll i=0;i<18;i++)
	{
		for(ll j=prime[i];j<=61;j+=prime[i])
		{
			vec[j].push_back(prime[i]);
			if(j%(prime[i]*prime[i])==0)
				m[j]=0;
		}
	}
	for(ll i=2;i<=61;i++)
	{
		if(m[i]!=0)
		{
			if(vec[i].size()%2==0)
				m[i]=1;
			else
				m[i]=-1;
		}
	}
}
void pre()
{
	for(ll i=2;i<=1000000;i++)
	{
		ll x=i*i,c=3;
		while(i<=1e18/x)
		{
			fac[c++].push_back(x*i);
			x=x*i;
		}
	}
}
int main()
{
	memset(m,1,sizeof(m));
	pre();
	mobius();
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,ans;
		cin>>n;
		ans=n-(ll)sqrt(n);
		for(ll i=3;i<=61;i++)
		{
			ans+=m[i]*(upper_bound(fac[i].begin(),fac[i].end(),n)-fac[i].begin());			
		}
		cout<<ans<<endl;

	}
}
