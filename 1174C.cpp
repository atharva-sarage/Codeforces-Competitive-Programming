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
# define mx 100005
int mark[mx];

int main()
{
	IOS;
	int n;
	cin>>n;
	int curr=1;
	for(int i=2;i<=n;i++)
	{
		int flag=0;
		for(int k=i;k<=n;k+=i)
		{
			if(!mark[k])
				{mark[k]=curr;flag=1;}
		}
		if(flag==1)
		curr++;
	}
	for(int i=2;i<=n;i++)
	{
		if(!mark[i])
			{mark[i]=curr;curr++;}
		cout<<mark[i]<<" ";
	}

}
