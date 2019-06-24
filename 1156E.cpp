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
# define mx 200005
int a[mx],lef[mx],righ[mx],pos[mx];
int n;
void pre()
{
	stack <pair<int,int>> s;
	stack <pair<int,int>> s2;
	lef[1]=0;
	s.push({a[1],1});
	for(int i=2;i<=n;i++)
	{
		while(!s.empty() && a[i]>s.top().ff)
			{righ[s.top().ss]=i;s.pop();}
		s.push({a[i],i});
	}
	while(!s.empty())
	{
		righ[s.top().ss]=n+1;
		s.pop();
	}
	/********************/
	s2.push({a[n],n});
	for(int i=n-1;i>=1;i--)
	{
		while(!s2.empty() && a[i]>s2.top().ff)
			{lef[s2.top().ss]=i;s2.pop();}
		s2.push({a[i],i});
	}
	while(!s2.empty())
	{
		lef[s2.top().ss]=0;
		s2.pop();
	}
}
int main()
{
	IOS;
	int final=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	pre();
	// for(int i=1;i<=n;i++)
	// 	cout<<lef[i]<<" "<<righ[i]<<endl;
	for(int i=1;i<=n;i++)
	{
		int l1=lef[i]+1;
		int r1=righ[i]-1;		
		if(i-l1>=r1-i)
		{
			for(int j=i+1;j<=r1;j++)
			{
				if(pos[a[i]-a[j]]<=i && pos[a[i]-a[j]]>=l1)
					final++;
			}
		}
		else
		{
			for(int j=l1;j<i;j++)
			{
				if(pos[a[i]-a[j]]<=r1 && pos[a[i]-a[j]]>=i)
					final++;
			}
		}
	}
	cout<<final<<endl;
	
}
