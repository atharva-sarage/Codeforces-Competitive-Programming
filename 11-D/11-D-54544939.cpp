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
# define mx (1<<19)
ll dp[mx][20];
bool edge[21][21];
ll final=0;
// no of hamiltonian walks
int main()
{
	IOS;
	ll n,m;
	cin>>n>>m;

	for(ll i=0;i<m;i++)	
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		edge[x][y]=edge[y][x]=1;
	}
	ll c1=1<<n;
	for(ll i=0;i<c1;i++)
	{
		ll t1=__builtin_ctz(i&(-i));
		ll t2=__builtin_popcount(i);
		for(ll j=0;j<n;j++)
		{
			if((i&(1<<j)))continue;
			if(t2==32)
				{dp[i|(1<<j)][j]=1;continue;}
			if(t2==1)
			{
				if(edge[t1][j])
					dp[(i|(1<<j))][j]=1;
				continue;
			}
			for(ll k=0;k<n;k++)
			{
				if((i&(1<<k))==0)continue;
				if(edge[j][k] && t1!=k)
					dp[i|(1<<j)][j]+=dp[i][k];						
			}			
			//cout<<i<<" "<<j<<" "<<t1<<" "<<t2<<" "<<dp[i|(1<<j)][j]<<endl;
		}
	}
	for(ll i=0;i<c1;i++)
	{
		for(ll j=0;j<n;j++)
		{
			ll t1=__builtin_ctz(i&(-i));
			if(edge[j][t1])
				final+=dp[i][j];			
		}
	}
	cout<<(final-m)/2<<endl;

}