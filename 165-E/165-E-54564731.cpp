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
# define mx2 23
# define mx (1<<23)
pair<int,int> f[(1<<24)];
int a[mx];
int main()
{
	IOS;
	int n,max1=0;
	cin>>n;
	for(int i=0;i<=4000000;i++)
		f[i]={0,-1};
	for(int i=0;i<n;i++)	
	{
		cin>>a[i];
		max1=max(max1,a[i]);
		f[a[i]]={1,i};		
	}
	// check whether any of the inverted element's subset is a valid subset
	for(int i=0;i<mx2;i++)
	{
		for(int mask=0;mask<mx;mask++)
		{
			if(mask&(1<<i))continue;
			if(f[(mask|(1<<i))].ff==0 && f[mask].ff!=0)
				f[(mask|(1<<i))]=f[mask];				
		}
	}
	for(int i=0;i<n;i++)
	{
		int x=(((1LL<<23)-1)^a[i]);
		if(f[x].ff == 0)
			cout<<-1<<" ";
		else
			{
				cout<<a[f[x].ss]<<" ";
				assert((a[f[x].ss]&a[i])==0);
			}
	}
}