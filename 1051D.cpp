// Avoid Silly errors
#include<bits/stdc++.h>
using namespace std;
# define mx 1005
# define mod 998244353
typedef unsigned long long ll;
ll dp[mx][2*mx][2];
int main()
{
	memset(dp,0,sizeof(dp));
	ll n,k;
	cin>>n>>k;
	dp[0][1][1]=1LL;
	dp[0][1][0]=0LL;
	dp[0][2][0]=1LL;
	dp[0][2][1]=0LL;
	for(unsigned int i=0;i<n;i++)
		{
		dp[i][1][1]=1;
		}
	for(ll i=0;i<n-1;i++)
	{
		for(ll j=1;j<=2*(i+2);j++)
		{
			dp[i+1][j][1]=((dp[i][j][1]+dp[i][j-1][1])%mod+(dp[i][j][0]+dp[i][j][0])%mod)%mod;
			dp[i+1][j][0]=((dp[i][j-1][1]+dp[i][j-1][1])%mod+(dp[i][j][0]+dp[i][j-2][0])%mod)%mod;
		}
	}
	cout<<((dp[n-1][k][0]+dp[n-1][k][1])%mod+(dp[n-1][k][0]+dp[n-1][k][1])%mod)%mod<<endl;
}