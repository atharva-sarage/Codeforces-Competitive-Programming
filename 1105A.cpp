#include<bits/stdc++.h>
#define ff first
# define ss second
# define pb push_back
# define mp make_pair
# define mod 1000000007
using namespace std;
int a[5005],n;
int calc(int x)
{
	int final=0;
	for(int i=1;i<=n;i++)
	{
		final+=min(min(abs(a[i]-x),abs(a[i]-x-1)),abs(a[i]-x+1));
	}
	return final;
}
int main()
{	
	int mini=100000000,ans;
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=1;i<=100;i++)
	{
		if(calc(i)<mini)
		{
			ans=i;
			mini=calc(i);
		}
	}
	cout<<ans<<" "<<mini<<endl;
}