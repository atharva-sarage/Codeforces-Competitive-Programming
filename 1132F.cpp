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
# define mx2 100005
# define mx 1005
int dp[mx][mx];
string str;
int solve(int s,int e)
{
	if(s>e)
		return 0;
	int &w=dp[s][e];
	if(w!=-1)
		return w;
	w=1+solve(s+1,e);
	for(int i=s+1;i<=e;i++)
	{
		if(str[i]==str[s])
			w=min(w,solve(s+1,i-1)+solve(i,e));
	}
	return w;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	IOS;
	int n;
	cin>>n;
	cin>>str;
	cout<<solve(0,n-1)<<endl;
}
