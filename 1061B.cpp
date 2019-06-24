#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int a[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	long long final=0,excess=0,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	final+=a[0]-1;
	for(int i=0;i<n;i++)
	{
		while(a[i]==a[i+1] && i<n-1)
		{
			if(final>0)
			{final--;excess--;}
			i++;
		}
		final+=max(0,a[i+1]-a[i]-1);		
	}
	cout<<sum-(final+n)<<endl;
}

