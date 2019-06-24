#include<bits/stdc++.h>
# define M 1000000007
using namespace std;
int dp[100010][2];
int pre[100010][2];
int main()
{
	int t,k;
	cin>>t>>k;

	dp[0][0]=1;
	dp[0][1]=0;
	dp[1][0]=1;
	for(int i=1;i<k;i++)
		dp[i][1]=0;
	if(k==1)
	dp[1][1]=1;
	for(int i=2;i<=100005;i++)
	{
		if(i>=k)
			dp[i][1]=(dp[i-k][0]+dp[i-k][1])%M;
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
	}

	pre[1][0]=dp[1][0];
	pre[1][1]=dp[1][1];
	for(int i=2;i<=100005;i++)
	{
		pre[i][1]=(pre[i-1][1]+dp[i][1])%M;
		pre[i][0]=(pre[i-1][0]+dp[i][0])%M;
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;

		cout<<((pre[b][1]+pre[b][0])%M-(pre[a-1][0]+pre[a-1][1])%M+M)%M<<endl;

	}
}