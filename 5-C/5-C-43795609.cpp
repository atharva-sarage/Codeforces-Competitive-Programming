//easy peasy lemon squeezy
#include<bits/stdc++.h>
# define mx 1000000
# define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int main()
{
	IOS;
	string str;
	vector <int> vec;
	cin>>str;
	int dp[mx+5];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	int update[mx+5];
	memset(update,0,sizeof(update));
	int n=str.length(),max1=0,c=0,i=0,count1=0,sum=0;
	while(i<n)
	{	
		if(str[i]==')' && sum>0)
		{
			sum--;			
			if(update[sum+1]-1>=0)
			dp[i]=(i-update[sum+1]+1+dp[update[sum+1]-1]);
			else
			dp[i]=i-update[sum+1]+1;
			
		}
		if(str[i]=='(' )
		{
			sum++;
			update[sum]=i;
		}
		i++;
	}	
	
	for(int i=0;i<n;i++)
	{
		max1=max(max1,dp[i]);
	}

	for(int i=0;i<n;i++)
	{
		if(dp[i]==max1)
			count1++;
	}
	if(max1==0)
		cout<<0<<" "<<1<<endl;
	else
		cout<<max1<<" "<<count1<<endl;
}