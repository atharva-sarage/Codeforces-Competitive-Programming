#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int calc(int i)
{
	int ans=0;
	for(int j=1;j<=n;j++)
	{
		ans+=((abs(i-j)+j-1+(i-1))*2)*a[j];
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int final=1e9;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<calc<<endl;
		final=min(final,calc(i));
	}
	cout<<final<<endl;
}