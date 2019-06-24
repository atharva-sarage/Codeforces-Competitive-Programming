#include<bits/stdc++.h>
using namespace std;
int dp[100]={0};
int main()
{
	int n,m,c,d,k;
	cin>>c>>d>>n>>m>>k;
	int rem=n*m-k;
	rem=max(0,rem);
	for(int i=1;i<=n;i++)
		dp[i]=min(c,i*d);
	
	int ans=min(rem/n * c+dp[rem%n],d*rem);
	cout<<ans<<endl;
}