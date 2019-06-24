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
int a[mx];
int main()
{
	IOS;
	int n;
	cin>>n;
	bool mark1=false,mark2=false;
	for(int i=1;i<=n;i++)	
	{
		cin>>a[i];
		if(a[i]%2==0)
			mark1=true;
		else
			mark2=true;
	}
	if(mark1==true && mark2==true)
	{
		sort(a+1,a+n+1);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
