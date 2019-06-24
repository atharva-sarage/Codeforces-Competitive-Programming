#include<bits/stdc++.h>
typedef double db;
using namespace std;
double grid[20][20];
double dp[1<<20];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	dp[0]=1;
	for(int i=0;i<(1<<n);i++) // mask
	{
		int count1=0;
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j))==0)
				{
				count1++;
				}
		}
		db c1=2/(db)(count1*(count1-1));
		for(int j=0;j<n-1;j++ )
		{
			if((i&(1<<j))==0)// first unset bit
			{
				for(int k=j+1;k<n;k++)
				{
					if((i&(1<<k))==0)
					{
					dp[(i|(1<<j))]+=dp[i]*(1-grid[j][k])*c1;// dies
					dp[i|(1<<k)]+=dp[i]*grid[j][k]*c1;// lives
					}
				}
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		//cout<<dp[(1<<n)-1-(1<<j)]<<endl;
		printf("%.8lf ",dp[(1<<n)-1-(1<<j)] );
	}
	printf("\n");
}