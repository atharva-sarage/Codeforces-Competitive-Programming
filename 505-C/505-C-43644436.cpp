#include<bits/stdc++.h>
using namespace std;
# define mx 30005
# define IOS ios::sync_with_stdio(0),cin.tie(0)
int dp[mx][600],d;
int mark[mx],a[mx];
int solve(int i,int k)
{
	if(i>30000)
		return 0;

	int &w=dp[i][k+300];
	if(w!=-1)
		return w;
	
	w=0;
	if(k+d==1)
		w=mark[i]+max(solve(i+k+d,k),solve(i+k+1+d,k+1));
	else
		w=mark[i]+max(solve(i+k+d,k),max(solve(i+k-1+d,k-1),solve(i+k+1+d,k+1)));
	return w;
}
int main()
{
	IOS;
	memset(dp,-1,sizeof(dp));
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		{
		cin>>a[i];mark[a[i]]++;
		}
	cout<<solve(d,0)<<endl;
}