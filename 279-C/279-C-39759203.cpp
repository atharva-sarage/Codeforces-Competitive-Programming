#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int a[100005];
	int dp[100005];
	int bp[100005];
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0]=1;
	bp[0]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=a[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i-1])
			bp[i]=bp[i-1]+1;
		else
			bp[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int x,y,flag=0;
		cin>>x>>y;
		x--;
		y--;
		//int interval=y-x+1;
		int index2=y+1-bp[y];
		//cout<<index2<<endl;
		if(index2-dp[index2]<x)
			flag=1;

		if(flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

		
	}
}