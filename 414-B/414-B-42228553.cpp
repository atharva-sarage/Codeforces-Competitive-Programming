#include<bits/stdc++.h>
using namespace std;
# define M 1000000007
typedef int long long ll;
ll dp[2005][2005];
int main()
{
	ll n,k;
	cin>>n;
	cin>>k;
	for(ll l=0;l<=k;l++)
		dp[n][l]=1;
	for(ll i=1;i<=n-1;i++)
		dp[i][1]=1;
	
	for(ll l=2;l<=k;l++)
	{
	for(ll i=n-1;i>0;i--)
	{
		for(ll j=i;j<=n;j=j+i)
		{
			
			dp[i][l]+=dp[j][l-1];
			dp[i][l]%=M;
			
		}
	}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		//cout<<dp[i][k]<<endl;
		ans+=dp[i][k];
		ans%=M;
	}
	cout<<ans<<endl;

}