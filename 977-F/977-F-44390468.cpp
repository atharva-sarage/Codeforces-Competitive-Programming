#include<bits/stdc++.h>
using namespace std;
# define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
# define mx 200005
# define mp make_pair
int dp[mx],a[mx],jump[mx];
map <int,int> m;
int solve(int u)
{
	int &w=dp[u];
	if(w!=-1)
		return w;
	w=0;
	if(jump[u]!=-1)
		w=1+solve(jump[u]);
	return w;
}
int main()
{
    IOS;
	memset(dp,-1,sizeof(dp));
	memset(jump,-1,sizeof(jump));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];		
	}
	m[a[n-1]]=n-1;
	for(int i=n-2;i>=0;i--)
	{
		if(m.find(a[i]+1)!=m.end())
			jump[i]=m[a[i]+1];
		if(m.find(a[i])==m.end())
			m.insert(mp(a[i],i));
		else
			m[a[i]]=i;
	}

	for(int i=0;i<n;i++)
		solve(i);
	int ans=0,index1;
	for(int i=0;i<n;i++)
		{
			if(dp[i]>=ans)
			{
				ans=dp[i];
				index1=i;
			}
		}
	cout<<ans+1<<endl;
	while(jump[index1]!=-1)
	{
		cout<<index1+1<<" ";
		index1=jump[index1];
	}
	cout<<index1+1<<endl;

}