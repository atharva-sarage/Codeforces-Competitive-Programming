#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,l;
	int long long sum=0;
	cin>>n>>k>>l;
	int a[100005];
	for(int i=0;i<n*k;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
	int size=n*k;
	sort(a,a+size);
	int maxmin=a[0]+l;
	int l1=upper_bound(a,a+size,maxmin)-a;
	
	int x;
	if(k==1)
	{
		if(a[size-1]-a[0]>l)
			printf("0\n");
		else
			printf("%lld\n",sum );
		return 0;
	}
	if(k!=1)
	//x=( size-l1)/(k-1);
	{
		if((size-l1)%(k-1)==0)
			x=(size-l1)/(k-1);
		else
			x=(size-l1)/(k-1) + 1 ;
	}	
	
	if(x<0 || x>n)
	{
		printf("0\n");
		return 0;
	}
	int y=n-x;
	int count=0;
	int i=0;
	int long long ans=0;
	while(count<n-x)
	{
		count++;
		ans+=a[i];
		i+=k;
	}
	//i+=k;
	count=0;
	if(x>0)
	ans=ans+a[i];
	i=l1-1;
	while(count<x-1)
	{
		ans+=a[i];
		i--;
		count++;
	}
	printf("%lld\n",ans );


}