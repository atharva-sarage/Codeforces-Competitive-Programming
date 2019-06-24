#include<bits/stdc++.h>
using namespace std;
const int N=502;
int a[N];
int dp[2][N][N];
int main()
{
	int n,l,bugs,mod;
	cin>>n>>l>>bugs>>mod;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0][0][0]=1;
	for(int it=1;it<=n;it++)
	{
		int i=it&1;
		for(int j=0;j<=l;j++){
			for(int k=0;k<=bugs;k++){
			dp[i][j][k]=dp[i^1][j][k];
		if(j>0 && k-a[it-1]>=0)
			dp[i][j][k]+=dp[i][j-1][k-a[it-1]];
		dp[i][j][k]=dp[i][j][k]%mod;
	}
		}
	}
	int ans=0;
	for(int i=0;i<=bugs;i++)
	{
		ans= ans+dp[n&1][l][i];
		ans=ans%mod;
	}
	cout<<ans<<endl;
}