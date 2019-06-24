/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 300005
# define mx 200050
int dp[mx],pre[mx],freq[mx];
int getsum(int l,int r)
{
	return pre[r]-pre[l-1];
}
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	
		{int x;cin>>x;freq[x]++;}
	pre[0]=0;
	for(int i=1;i<mx;i++)
		pre[i]=pre[i-1]+freq[i];	
	for(int i=mx-1;i>=1;i--)
	{
		if(freq[i]>=2)
			dp[i]=1+dp[i+1];
		else
			dp[i]=0;
	}
	int final=0;
	pair <int,int> ans;
	for(int i=1;i<mx;i++)
	{
		int t1=dp[i];
		if(final<getsum(i,i+t1)+freq[i-1])
		{
			final=getsum(i,i+t1)+freq[i-1];
			ans={i-1,i+t1};
		}
	}
	cout<<final<<endl;
	for(int t=ans.ff;t<=ans.ss;t++)
	{
		for(int k=0;k<freq[t]-1;k++)
			cout<<t<<" ";
	}
	for(int t=ans.ss;t>=ans.ff;t--)
	{
		if(freq[t])
			cout<<t<<" ";
		
	}
}
