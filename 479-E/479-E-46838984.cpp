#include<bits/stdc++.h>
using namespace std;
# define mx 5005
# define mod 1000000007
typedef int long long ll;
ll dp[mx][mx]; // dp[i][j] i index j moves
int main()
{
	memset(dp,0,sizeof(dp));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	ll c=0;
	dp[a][0]=1LL;
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(dp[j][i-1]!=0)
			{
				ll diff=abs(b-j);
				if(diff==1)continue;
				dp[min(j+1,n+1)][i]=(dp[min(j+1,n+1)][i]+dp[j][i-1])%mod;
				dp[min(j+diff,n+1)][i]=(dp[min(j+diff,n+1)][i]-dp[j][i-1]+mod)%mod;
				dp[j][i]=(dp[j][i]-dp[j][i-1]+mod)%mod;
				dp[max(0LL,j-diff+1)][i]=(dp[max(0LL,j-diff+1)][i]+dp[j][i-1])%mod;
			}
		}
		for(ll j=1;j<=n;j++)
			{
			dp[j][i]=(dp[j][i]+dp[j-1][i])%mod;
			dp[j][i]%=mod;
			}					
	}
	ll final=0LL;
	
	for(ll i=1;i<=n;i++)
	{

		final+=dp[i][k];
		final%=mod;
	}
	cout<<final<<endl;
}