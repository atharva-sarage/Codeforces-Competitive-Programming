#include<bits/stdc++.h>
#define mx 200005
using namespace std;
int arr[mx];
int next1[mx];
int ans[mx];
int n;
int getnext1(int p,int x)
{
	if(p>n)
		return p;
	if(x+ans[p]>arr[p])
	{
		next1[p]=getnext1(p+1,x+ans[p]-arr[p]);
		ans[p]=arr[p];
	}
	else
	{
		ans[p]+=x;
	}
	return next1[p];
}
int main()
{
	int m,t,p,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		next1[i]=i;
		cin>>arr[i];
	}
	cin>>m;
	while(m--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>p>>x;
			next1[p]=getnext1(next1[p],x);
		}
		else
		{
			cin>>p;
			cout<<ans[p]<<endl;
		}
	}
}