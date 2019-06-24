#include<bits/stdc++.h>
using namespace std;
# define mx 2005
# define mod 1000000007
# define ll long long 
ll dp[mx][mx],a[mx];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,h;
	cin>>n>>h;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	// dp[i][j] is no of j unfinshed brackets upto i
	memset(dp,0,sizeof(dp));
	if(h==a[1])
		dp[1][0]=1;
	if(h==a[1]+1)
		{dp[1][0]=1;dp[1][1]=1;}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			// increased by open
			if(a[i]+j==h)
			{
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=mod;
				if(j!=0)
				{dp[i][j]+=dp[i-1][j-1];
				dp[i][j]%=mod;}
			}
			// increased by open +1
			else if(a[i]+j+1==h)
			{
				dp[i][j]+=dp[i-1][j+1]*(j+1); // close
				dp[i][j]%=mod;
				dp[i][j]+=dp[i-1][j]; // make pair
				dp[i][j]%=mod;
				if(j!=0)
				{dp[i][j]+=dp[i-1][j]*(j); // close open
				dp[i][j]%=mod;}
			}
		}
	}
	cout<<dp[n][0]<<endl;
}