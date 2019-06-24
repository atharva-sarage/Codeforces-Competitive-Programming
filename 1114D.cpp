/**************************
*	Author-Atharva Sarage *
*		IIT HYDERABAD     *
**************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 5005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[mx][mx][2];
int c[mx];
vector<int>a;
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i];
	c[n]=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]!=c[i-1])
			a.pb(c[i]);
	}
	for(int i = 0; i != n; ++i)
        {
	        for(int j = 0; j != n; ++j)
	         {
	            dp[i][j][0] = ( (i == j) ? 0 : inf);
	        	dp[i][j][1]=dp[i][j][0];
	         }
        }
	for(int r=0;r<a.size();r++)
	{
		for(int l=r;l>=0;l--)
		{
			if(r!=0)
				dp[l][r][1]=min(dp[l][r-1][1]+((a[r]==a[r-1])?0:1) ,dp[l][r-1][0]+((a[r]==a[l])?0:1));
			if(l!=0)
				dp[l-1][r][0]=min(dp[l][r][0]+((a[l]==a[l-1])?0:1),dp[l][r][1]+((a[l-1]==a[r])?0:1));
		}
	}
	cout<<min(dp[0][a.size()-1][0],dp[0][a.size()-1][1])<<endl;
}
