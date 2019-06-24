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
# define mx 205
# define mx2 1005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[mx][mx][mx2],a[mx],n,k;
int solve(ll i,ll open,ll rem)
{
	if(rem<0)
		return 0;
	if(i>n)
	{
    	return (open==0);
	}
	int &w=dp[i][open][rem];
	if(w!=-1)
		return w;
	w=0;
	rem-=(open*(a[i]-a[i-1]));
	if(open>0) 
	{
		w=(w+(1LL*open*(solve(i+1,open-1,rem)))%mod)%mod;// you close
		w=(w+(1LL*open*(solve(i+1,open,rem)))%mod)%mod; // do nothing
	} 
	{w=(w+1LL*solve(i+1,open+1,rem))%mod;} // open new
	{w=(w+1LL*solve(i+1,open,rem))%mod;} // open close
	return w%mod;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	IOS;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	a[0]=0;
	sort(a+1,a+n+1);
	cout<<solve(1,0,k)<<endl;
}