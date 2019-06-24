#include<bits/stdc++.h>
using namespace std;
# define pb push_back
# define ff first
# define ss second

# define mod 1000000007
typedef int long long ll;
ll dp[10005][100],inv[150];
vector <pair<ll,ll> > vec;
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
	ll n,k,n1;
	cin>>n>>k;
	n1=n;
	for(ll i=1;i<=100;i++)
		inv[i]=pow1(i,mod-2);
	for(ll i=2;i*i<=n1;i++)
	{
		int flag=0;
		ll c=0;
		while(n%i==0)
			{c++;n/=i;flag=1;}		
		if(flag==1)
		vec.pb({c,i});c=0;
	}
	ll ans=1;
	if(n!=1)
		vec.pb({1,n});
	for(ll j=0;j<vec.size();j++) // dp[i][j] after i moves probablity that power is j
	{
		memset(dp,0,sizeof(dp));
		dp[0][vec[j].ff]=1;
		for(ll i=1;i<=k;i++) // i moves done
		{
			for(ll l=0;l<=vec[j].ff;l++)
			{
				for(ll  m=l;m<=vec[j].ff;m++)
				{
					dp[i][l]+=dp[i-1][m]*inv[m+1];
					dp[i][l]%=mod;
				}
			}
		}
		ll temp=0;
		for(ll l=0;l<=vec[j].ff;l++)
		{
			temp=(temp+(pow1(vec[j].ss,l)*dp[k][l])%mod)%mod;
			temp%=mod;
		}
		ans=(ans*temp)%mod;
	}
	cout<<ans%mod<<endl;
}