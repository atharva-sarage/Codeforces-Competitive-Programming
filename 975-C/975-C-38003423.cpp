#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	int long long sum=0;
	cin>>n>>q;
	int a[200005]={0};
	int long long k[200005]={0};
	int long long pre[200005]={0};
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			
		}
	for(int i=0;i<q;i++)
		cin>>k[i];
	pre[0]=a[0];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i];
	int i=0;
	while(i<q)
	{
		sum=sum+k[i];
		
		int l1=upper_bound(pre,pre+n,sum)-pre;
		if(l1==n)
			{
				l1=0;
				sum=0;
			}
		
		printf("%d\n",n-l1 );
		i++;
	}
}