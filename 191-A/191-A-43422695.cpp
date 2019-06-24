#include<bits/stdc++.h>
using namespace std;
int dp[27][27];
int main()
{
    memset(dp,0,sizeof(dp));
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		int x=str.length();
		if(i==0)
		dp[str.back()-'a'][str.front()-'a']=x;
		if(i>0)
		{
			for(int j=0;j<26;j++)
			if(dp[str.front()-'a'][j]!=0)
				dp[str.back()-'a'][j]=max(dp[str.back()-'a'][j],x+dp[str.front()-'a'][j]);
			
			dp[str.back()-'a'][str.front()-'a']=max(x,dp[str.back()-'a'][str.front()-'a']);			
		}		
	}
	int final=0;
	for(int j=0;j<26;j++)
			final=max(final,dp[j][j]);
	
	cout<<final<<endl;


}