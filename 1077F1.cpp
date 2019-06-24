#include<bits/stdc++.h>
using namespace std;
# define mx 5005
# define mp make_pair
typedef int long long ll;
ll dp[mx][mx],a[mx];
set <pair<ll,ll> > s[mx];
set <pair<ll,ll> > :: iterator itr;
int main()
{
	ll n,k,x,flag=0;
	cin>>n>>k>>x;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	memset(dp,0,sizeof(dp));
	s[1].insert(mp(a[0],0));
	dp[0][1]=a[0];
	for(ll i=1;i<n;i++)
	{	
		for(ll j=1;j<=min(i+1,x);j++)
		{
			flag=0;
			if(j==1 && i<k)
			{
				dp[i][1]=a[i];
				continue;
			}
			//cout<<i<<endl;
			if(s[j-1].empty())
				{
					flag=1;
					continue;
				}
			itr=--(s[j-1].end());
			while(itr->second<i-k)
				{
				//cout<<itr->second<<" "<<j<<" "<<i<<endl;
				s[j-1].erase(itr);
				if(s[j-1].empty())
				{
					flag=1;
					break;
				}
				itr=--(s[j-1].end());
				//cout<<itr->second<<" "<<j<<" "<<i<<endl;
				}
			if(flag==1)continue;
			dp[i][j]=a[i]+itr->first;
		}
		for(ll j=1;j<=min(i+1,x);j++)
		{
			if(j==1 && i>=k)
				continue;
			if(dp[i][j]==0)continue;
			s[j].insert(mp(dp[i][j],i));
		}
	}
	ll ans=0;
	for(ll i=n-1;i>=n-1-k+1;i--)
		ans=max(ans,dp[i][x]);
	if(ans==0)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}