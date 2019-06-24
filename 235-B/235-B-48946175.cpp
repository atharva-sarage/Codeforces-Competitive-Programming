#include<bits/stdc++.h>
using namespace std;
double ans[100005],a[100005];
double final=0.0,sum1=0.0;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		{cin>>a[i];sum1+=a[i];}
	final=ans[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		ans[i]=ans[i-1]*a[i]+a[i];
		final+=ans[i];
	}
	printf("%.12lf\n",2.0*final-sum1);
}