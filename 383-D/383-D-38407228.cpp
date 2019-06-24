#include<bits/stdc++.h>
using namespace std;
int dp[1005][20005];
int a[100005];
int main()
{
	int n;
	int M=1000000007;
	int long sum=0,final=0;
	cin>>n;
	vector <int> v;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=2*sum;j++)
			dp[i][j]=0;
	}
	dp[0][sum+a[0]]=1;
	dp[0][sum-a[0]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=2*sum;j++)
		{
			if(dp[i-1][j]!=0)
			{
				v.push_back(j);
			}
		}
		//printf("\n");
		//cout<< v.size()<<"**"<<endl;
		for(int j=0;j<v.size();j++)
		{

			dp[i][v[j]+a[i]]=(dp[i][v[j]+a[i]]+dp[i-1][v[j]])%M;
			dp[i][v[j]-a[i]]=(dp[i][v[j]-a[i]]+dp[i-1][v[j]])%M;
		}
		dp[i][a[i]+sum]+=1;
		dp[i][-a[i]+sum]+=1;
		v.clear();
	}
	
		for(int i=0;i<n;i++)
		{
			final=(final+dp[i][sum])%M;
			//printf("%d\n",dp[i][sum] );
		}

	cout<<final<<endl;
}