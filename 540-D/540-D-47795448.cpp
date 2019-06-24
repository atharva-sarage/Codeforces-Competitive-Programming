#include<bits/stdc++.h>
using namespace std;
double dp[105][105][105];
void solve(int r,int s,int p)
{
	for(int i=r;i>=0;i--)
		for(int j=s;j>=0;j--)
			for(int k=p;k>=0;k--)
			{
				if(i and j)
					{dp[i][j-1][k]+=((double)(i*j)/(double)(i*j+j*k+k*i))*dp[i][j][k];}
				if(j and k)
					{dp[i][j][k-1]+=((double)(j*k)/(double)(i*j+j*k+k*i))*dp[i][j][k];}
				if(k and i)
					{dp[i-1][j][k]+=((double)(i*k)/(double)(i*j+j*k+k*i))*dp[i][j][k];}
			}
}
int main()
{
	memset(dp,0,sizeof(dp));
	int r,s,p;
	cin>>r>>s>>p;
	dp[r][s][p]=1.0;	
	solve(r,s,p);
	double ans1=0.0,ans2=0.0,ans3=0.0;
	for(int i=1;i<=r;i++)
		ans1+=dp[i][0][0];
	for(int i=1;i<=s;i++)
		ans2+=dp[0][i][0];
	for(int i=1;i<=p;i++)
		ans3+=dp[0][0][i];	
	printf("%.12lf %.12lf %.12lf\n",ans1,ans2,ans3);
}