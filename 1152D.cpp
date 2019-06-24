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
ll n;
ll dp[mx][2*mx+5][3];
ll dfs(ll open,ll taken,ll depth)
{
	ll close=depth-open;
	//cout<<open<<" "<<taken<<" "<<depth<<endl;
	if(depth==2LL*n)
		return 0LL;
	if(open>n || open<0 || close>n || close<0 || close>open)
		return -2LL;
	ll &w=dp[open][depth][taken];
	if(w!=-1)
		return w%mod;
	w=0LL;
	if(taken==0)
	{
		ll a1=dfs(open+1,1,depth+1);
		ll a2=dfs(open+1,0,depth+1);
		ll a3=dfs(open,1,depth+1);
		ll a4=dfs(open,0,depth+1);
		//cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
		ll ans1=0,ans2=0,ans3=0;
		if(a1!=-2 && a4!=-2)
			ans1=((1LL+a1)+a4);
		else if(a1!=-2)
			ans1=(1LL+a1);	
		else if(a4!=-2)
			ans1=a4;


		if(a2!=-2 && a3!=-2)
			ans2=((1LL+a2)+a3);
		else if(a3!=-2)
			ans2=(1LL+a3);
		else if(a2!=-2)
			ans2=a2;

		if(a2!=-2 && a4!=-2)
			ans3=(a2+a4);
		else if(a2!=-2)
			ans3=a2;
		else if(a4!=-2)
			ans3=a4;

		w=max({w,ans1,ans2,ans3});
		w%=mod;
		//cout<<w<<endl;
	}
	else
	{
		ll a2=dfs(open+1,0,depth+1);
		ll a4=dfs(open,0,depth+1);		
		w=max({w,(a2+a4),a2,a4});
		w%=mod;
	}	
	//cout<<w<<endl;
	return w;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	IOS;
	cin>>n;
	cout<<dfs(0,0,0)<<endl;
}
