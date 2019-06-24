#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
struct shot
{
	ll x,y,t;
	double p;
};
struct shot s[1005];
double dp[1005];
bool isvalid(ll i,ll j)
{
	return (s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y)<=(s[i].t-s[j].t)*(s[i].t-s[j].t);
}
bool compare(shot a,shot b)
{
	return a.t<b.t;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	double final=0.0;
	for(ll i=1;i<=n;i++)
	{
		ll x,y,t;
		double p;
		cin>>x>>y>>t>>p;
		s[i]={x,y,t,p};
		final=max(final,p);
	}
	sort(s+1,s+n+1,compare);
	for(ll i=1;i<=n;i++)
	{
		dp[i]=s[i].p;
		for(ll j=1;j<i;j++)
		{
			if(isvalid(i,j))
			{
				dp[i]=max(dp[j]+s[i].p,dp[i]);			
				final=max(final,dp[i]);
			}
		}
	}
	printf("%.9lf\n",final);

}