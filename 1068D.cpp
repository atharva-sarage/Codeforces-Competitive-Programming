#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mod 998244353
typedef int  ll;
ll dp[3][202][mx];
ll pre[3][202][mx];
ll a[mx];
int main()
{
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
	ll n,final=0;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	if(a[0]==-1)
	{
		for(ll j=1;j<=200;j++)
			dp[1][j][0]=1;		
	}
	else
	{
		ll j=a[0];
		dp[1][j][0]=1;
	}
	for(ll j=1;j<=200;j++)
		{
			pre[2][j][0]=(pre[2][j-1][0]+dp[2][j][0])%mod;
			pre[1][j][0]=(pre[1][j-1][0]+dp[1][j][0])%mod;
			pre[0][j][0]=(pre[0][j-1][0]+dp[0][j][0])%mod;
		}
	for(ll i=1;i<n;i++)
	{
		if(a[i]==-1)
		{
			for(ll j=1;j<=200;j++)
			{
				dp[2][j][i]=(dp[2][j][i]+((pre[2][j-1][i-1]+pre[1][j-1][i-1])%mod+pre[0][j-1][i-1])%mod)%mod;
				dp[2][j][i]%=mod;
				if(i!=1)
				{dp[0][j][i]=(dp[0][j][i]+((pre[0][200][i-1]-pre[0][j][i-1]+mod)%mod + (pre[1][200][i-1]-pre[1][j][i-1]+mod)%mod)%mod)%mod;
				dp[0][j][i]%=mod;}

				dp[1][j][i]=(dp[1][j][i]+(dp[2][j][i-1]+(dp[0][j][i-1]+dp[1][j][i-1])%mod)%mod)%mod;
				dp[1][j][i]%=mod;
			}
		}
		else
		{
			dp[2][a[i]][i]=(dp[2][a[i]][i]+((pre[2][a[i]-1][i-1]+pre[1][a[i]-1][i-1])%mod +pre[0][a[i]-1][i-1])%mod)%mod;
			dp[2][a[i]][i]%=mod;
			if(i!=1)
			{dp[0][a[i]][i]=(dp[0][a[i]][i]+((pre[0][200][i-1]-pre[0][a[i]][i-1]+mod)%mod+(pre[1][200][i-1]-pre[1][a[i]][i-1]+mod)%mod)%mod)%mod ;
			dp[0][a[i]][i]%=mod;}

			dp[1][a[i]][i]=(dp[1][a[i]][i]+((dp[2][a[i]][i-1]+dp[0][a[i]][i-1])%mod+dp[1][a[i]][i-1])%mod)%mod;
			dp[1][a[i]][i]%=mod;		
		}
		for(ll j=1;j<=200;j++)
		{
			pre[2][j][i]=(pre[2][j-1][i]+dp[2][j][i])%mod;
			pre[1][j][i]=(pre[1][j-1][i]+dp[1][j][i])%mod;
			pre[0][j][i]=(pre[0][j-1][i]+dp[0][j][i])%mod;
		}
	}
	for(ll j=1;j<=200;j++)
	{
		final=(final+(dp[0][j][n-1]+dp[1][j][n-1])%mod)%mod;
		final%=mod;
	}
	cout<<final<<endl;
}