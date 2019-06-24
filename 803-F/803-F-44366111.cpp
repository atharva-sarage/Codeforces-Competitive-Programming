#include<bits/stdc++.h>
# define mod 1000000007
# define mx 100005
# define IOS ios::sync_with_stdio(0),cin.tie(0)
# define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef int long long ll;
ll freq[mx],a[mx],final[mx];
ll pow1(ll a, ll b) 
{
  if (a==0)
    return 0;

    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod; 
        b /= 2;
    }
    return x%mod;
}
int main()
{
	IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		freq[a[i]]++;
	}
	for(ll i=100000;i>=1;i--)
	{
		ll c1=0;
		for(ll j=i;j<=100000;j=j+i)
		{
			c1=(c1+freq[j])%mod;
		}
		final[i]=(final[i]+pow1(2,c1)-1)%mod;
		for(ll j=2*i;j<=100000;j=j+i)
		{
			final[i]=(final[i]+mod-final[j])%mod;			
		}
	}
	cout<<final[1]<<endl;
}