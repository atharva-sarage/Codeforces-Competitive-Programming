// faltu
#include<bits/stdc++.h>
# define mod 1000000007
# define ll long long
using namespace std;
ll l,r;
ll dp[200005][4];
int main()
{
	ll n,p,q,rr;
	p=q=r=0;
	cin>>n>>l>>rr;
	ll l1=l;
	ll r1=rr;
	if(rr-l==0 && l%3!=0)
	{	
		r=0;
		if(l%3==1)
			{p=1;q=0;}
		else
			{q=1;p=0;}
		goto lll;
	}
	if(rr-l==1)
	{
		if(l%3==0)
			{r=1;p=1;q=0;}
		else if(l%3==1)
			{p=1;q=1;r=0;}
		else
			{p=0;q=1;r=1;}
		goto lll;
	}
	if(l1%3==1)
		{l1+=2;p++;q++;}
	else if(l1%3==2)
		{l1+=1;q++;}
	if(r1%3==1)
		{r1-=1;p++;}
	else if(r1%3==2)
		{r1-=2;p++;q++;}
	if(l1<=r1)
	{
		p+=(r1-l1)/3;
		q+=(r1-l1)/3;
		r+=(r1-l1)/3+1;
	}
	lll:
	//cout<<p<<" "<<q<<" "<<r<<endl;
	dp[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		dp[i][0]+=((dp[i-1][0]*r)%mod+(dp[i-1][1]*q)%mod+(dp[i-1][2]*p)%mod)%mod;
		dp[i][0]%=mod;
		dp[i][1]+=((dp[i-1][1]*r)%mod+(dp[i-1][2]*q)%mod+(dp[i-1][0]*p)%mod)%mod;
		dp[i][1]%=mod;
		dp[i][2]+=((dp[i-1][2]*r)%mod+(dp[i-1][0]*q)%mod+(dp[i-1][1]*p)%mod)%mod;
	}
	cout<<dp[n][0]<<endl;
}