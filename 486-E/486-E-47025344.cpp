#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define inf 100005
int a[mx],b[mx],b2[mx],e[mx],s[mx],rev_a[mx],lis=1,freq[mx],l[mx];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		rev_a[n-i+1]=a[i];
	}
	// b[i] stores smallest possible ending of length i
	for(int i=1;i<=n;i++)
	{
		b[i]=inf;
		b2[i]=0;
	}
	b[0]=0;
	b[1]=a[1];
	e[1]=1;
	for(int i=2;i<=n;i++)
	{
		int low=0;
		int high=n;
		int mid;
		while(high>=low)
		{
			mid=low+(high-low)/2;
			if(b[mid]<a[i])
				low=mid+1;
			else
				high=mid-1;
		}
		e[i]=high+1;		
		b[high+1]=min(b[high+1],a[i]);		
		lis=max(lis,e[i]);
	}	
	// in reverse array lds ending at this point
	b2[0]=inf;
	b2[1]=rev_a[1];	
	s[n]=1;	
	for(int i=2;i<=n;i++)
	{
		int low=0;
		int high=n-1;
		int mid;
		while(high>=low)
		{
			mid=low+(high-low)/2;
			if(b2[mid]>rev_a[i])
				low=mid+1;
			else
				high=mid-1;
		}		
		s[n-i+1]=high+1;
		b2[high+1]=max(b2[high+1],rev_a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		l[i]=s[i]+e[i]-1;
		if(l[i]==lis)
			freq[e[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i]!=lis)
			cout<<1;
		else if(l[i]==lis && freq[e[i]]>1)
			cout<<2;
		else
			cout<<3;
	}
	
}