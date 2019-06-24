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
# define mx2 20
# define mx (1<<20)
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
ll f[(1<<22)]={};
int main()
{
	IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)	
		{
			ll x;
			cin>>x;
			f[x]++;
		}
	for(ll i=0;i<20;i++)
	{
		for(ll mask=0;mask<(1<<20);mask++)
		{
			if((mask&(1<<i)))continue;
			f[mask]+=f[mask|(1<<i)];
		}
	}
	ll ans=0;
	for(ll i=0;i<mx;i++)
	{
		ll t1=__builtin_popcount(i);
		if(t1%2==0)
			ans=(ans+pow1(2,f[i]))%mod;
		else
			ans=(ans-pow1(2,f[i])+mod)%mod;				
	}
	cout<<ans<<endl;

}