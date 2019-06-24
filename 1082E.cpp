#include<bits/stdc++.h>
using namespace std;
# define mx 500005
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
# define mp make_pair
int a[mx],pre[mx],suff[mx];
int dp[2*mx];
int offset=5e5;
set <pair<int,int> > s;
set <pair<int,int> >:: iterator itr;
int main()
{
	IOS;
	memset(dp,0,sizeof(dp));
	int n,c,final=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]+=pre[i-1];
		if(a[i]==c)
			pre[i]++;
	}
	for(int i=n;i>=1;i--)
	{
		suff[i]+=suff[i+1];
		if(a[i]==c)
			suff[i]++;
	}
	for(int i=1;i<=n;i++)
	{

		if(a[i]==c)
		{
			if(!s.empty())
			{
				final=max(final,(--s.end())->first+suff[i]);				
			}
		}
		else
		{
			int fac=c-a[i]+offset;
			//cout<<fac<<endl;
			if(dp[fac]==0)
			{
				dp[fac]=1+pre[i];
				s.insert(mp(dp[fac],fac));
				final=max(final,dp[fac]);
			}
			else
			{
				itr=s.find(mp(dp[fac],fac));
				s.erase(itr);
				dp[fac]=max(dp[fac]+1,pre[i]+1);
				s.insert(mp(dp[fac],fac));
				final=max(final,dp[fac]);
			}
		}
	}
	cout<<max(pre[n],final)<<endl;
}