#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
# define mod 1000000007
using namespace std;
typedef int long long ll;
vector<ll> fac[1000005];
ll dp[1000005];
void pre()
{
    int i,j;
    for(i = 1;i*i <= 1000000;i++)
    {
    	for(j = i*i;j <= 1000000; j += i)
       	{
            fac[j].push_back(i);
        }
    }
    for(int i=1;i<=1000000;i++)
    {
    	int SIZE=fac[i].size();
    	for(int j=0;j<SIZE;j++)
    	{
    		int v=fac[i][j];
    		if(v != i/v)
    			fac[i].push_back(i/v);
    	}
    }
}
int main()
{
	IOS;
	memset(dp,0,sizeof(dp));
	ll n,ans=0;
	dp[0]=1;
	cin>>n;
	pre();
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		for(ll j=fac[x].size()-1;j>=0;j--)
		{
			ll u=fac[x][j];
			dp[u]+=dp[u-1];
			dp[u]%=mod;
		}
	}
	for(ll i=1;i<=n;i++)
		ans=(ans+dp[i])%mod;
	cout<<ans<<endl;	
}