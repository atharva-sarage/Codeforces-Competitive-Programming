/**************************
*	Author-Atharva Sarage *
*		IIT HYDERABAD     *
**************************/
#include<bits/stdc++.h>
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 400005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct data
{
	ll ans,ff,ss;
};
vector<ll> vec[4];
data dp[mx];
int main()
{
	IOS
	ll n,m;
	cin>>n>>m; // total weight less than m
	for(ll i=0;i<n;i++)
	{
		ll w,c;cin>>w>>c;
		vec[w].pb(c);
	}
	for(ll i=1;i<=3;i++)
		sort(vec[i].begin(),vec[i].end(),greater<ll>());
	dp[0]={0,0,0};
	if(vec[1].size()>0)
		dp[1]={vec[1][0],1,0};
	for(ll i=2;i<=m;i++)
	{
		if(vec[1].size()<=dp[i-1].ff && vec[2].size()<=dp[i-2].ss)
			break;
		else if(vec[2].size()<=dp[i-2].ss)
			{dp[i].ans=dp[i-1].ans+vec[1][dp[i-1].ff];dp[i].ff=dp[i-1].ff+1;dp[i].ss=dp[i-1].ss;}
		else if(vec[1].size()<=dp[i-1].ff)
			{dp[i].ans=dp[i-2].ans+vec[2][dp[i-2].ss];dp[i].ff=dp[i-2].ff;dp[i].ss=1+dp[i-2].ss;}
		else if(dp[i-1].ans+vec[1][dp[i-1].ff]<dp[i-2].ans+vec[2][dp[i-2].ss])
			{dp[i].ans=dp[i-2].ans+vec[2][dp[i-2].ss];dp[i].ff=dp[i-2].ff;dp[i].ss=1+dp[i-2].ss;}
		else
			{dp[i].ans=dp[i-1].ans+vec[1][dp[i-1].ff];dp[i].ff=dp[i-1].ff+1;dp[i].ss=dp[i-1].ss;}
	}
	for(ll i=1;i<=m;i++)
		dp[i].ans=max(dp[i].ans,dp[i-1].ans);	
	/*for(ll i=0;i<=m;i++)
		cout<<dp[i].ans<<endl;*/	
	ll final=0,prev=0;
	for(ll i=0;i<vec[3].size();i++)
	{
		if(m-(i+1)*3<0)
			break;
		prev+=vec[3][i];
		final=max(final,prev+dp[m-(i+1)*3].ans);
	}
	cout<<max(dp[m].ans,final)<<endl;
	
	
}