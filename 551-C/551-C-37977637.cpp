#include<bits/stdc++.h>
using namespace std;
int check(int long long mid1,int n,int m,int a[])
{
	int j;
	int long long mid;
	int b[100005]={0};
	for(int i=0;i<n;i++)
		b[i]=a[i];
	j=n-1;
	for(int i=0;i<m;i++)	
	{
		mid=mid1;

		while(b[j]==0 && j>=0)
			j--;
		if(j==-1)
			break;
		mid=mid-(j+1);
		while(mid>=0 && j>=0)
		{
			if(b[j]<=mid)
				{
					mid=mid-b[j];
					b[j]=0;					
					j--;
					
				}
			else
				{
					b[j]=b[j]-mid;
					break;
				}
		}
	}
	if(j==-1)
		return 1;
	else
		return 0;

}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[100005]={0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int long long high=1e15;
	int long long low=1;
	int long long mid;
	//printf("%d  \n",check(4,n,m,a) );
	while(high>=low)
	{
		mid=low+(high-low)/2;
		int x=check(mid,n,m,a);
		if( x==1 && low==high)
			break;
		if(x==1)
			high=mid-1;
		else
			low=mid+1;
	}
	printf("%lld\n",low );
}