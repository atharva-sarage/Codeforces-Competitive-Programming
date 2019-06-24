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
# define mx 1000005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[mx][3][3],n,m,a[mx],freq[mx];
int solve(int l,int t1,int t2)
{
	if(t1+t2>freq[l])
		return -inf;
	int &w=dp[l][t1][t2];
	if(l>m)
		return 0;
	if(w!=-1)
		return w;
	w=-inf;
	for(int k=0;k<3;k++)
		{
			if(t1+t2+k>freq[l])break;
			w=max(w,k+(freq[l]-t1-t2-k)/3+solve(l+1,t2,k));
		}
	return w;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		{cin>>a[i];freq[a[i]]++;}
	cout<<solve(1,0,0)<<endl;
}
