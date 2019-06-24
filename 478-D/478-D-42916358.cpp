#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
# define mod 1000000007
ll dp[200020][2];
int main()
{
	ll r,g;
	cin>>r>>g;
	ll h=sqrt(8*(r+g)+1);
	h=(h-1)/2;
	ll total=r+g;	
	if(r>g)
		swap(r,g);
	//cout<<h<<endl;
	dp[0][0]=1;
	dp[1][0]=1;
	ll c=0;
	for(ll i=2;i<=h;i++)
	{
		c=1^c;
		for(ll j=0;j<=r;j++)
		{
			dp[j][c]=dp[j][c^1];
		}
		for(ll j=i;j<=r;j++)
		{
			dp[j][c]+=dp[j-i][c^1];
			dp[j][c]%=mod;
		}
	}
	ll ans=dp[r][c];
	if(total!=(h*(h+1))/2)
	{
		for(ll i=r-1;i>=max(0LL,(h*(h+1))/2-g);i--)
			{
			ans+=dp[i][c];
			ans%=mod;
			}
	}
	cout<<ans<<endl;
}