#include<bits/stdc++.h>
using namespace std;

int check(int mid,int n,int m,int a,int b[],int p[])
{
	int k=n-mid;
	int long long excess=0;
	for(int i=k;i<n;i++)
		excess=excess+max(p[i-k]-b[i],0);

	if(excess>a)
		return 0;
	else
		return 1;

}
int main()
{
	int n,m,a;
	int long long ans=0;
	cin>>n>>m>>a;
	int b[100005];
	int p[100005];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<m;i++)
		cin>>p[i];
	sort(b,b+n);
	sort(p,p+m);
	int low=0;
	int high=min(n,m);
	int mid;
	//printf("%d**\n",check(2,n,m,a,b,p) );
	while(high>=low)
	{
		mid=low+(high-low)/2;
		if(check(mid,n,m,a,b,p) && low==high)
			break;
		if(check(mid,n,m,a,b,p))
		low=mid+1;
		else
		high=mid-1;
	}
	for(int i=0;i<high;i++)
		ans+=p[i];
	ans=ans-a;
	if(ans<0)
		ans=0;
	printf("%d %lld\n",high,ans );
}