#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0,sum=0;
	cin>>n;
	int a[105];
	for(int i=0;i<n;i++)
	{
		
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	if(sum>=4.5*n)
		{
			cout<<0<<endl;
			return 0;
		}

	int count=0;
	for(int i=0;i<n;i++)
	{
		int diff=5-a[i];
		count++;
		
		if(sum+diff>=4.5*n)
			break;
		sum=sum+diff;
		
	}
	cout<<count<<endl;
}