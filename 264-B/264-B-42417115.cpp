#include<bits/stdc++.h>
using namespace std;
int gcd1[100005];
int a[100005],n;
set <int> s;
set <int> :: iterator itr;
void primefac(int x)
{
	int flag=0;
	while(x%2==0)
	{
		s.insert(2);
		x=x/2;
	}
	for(int i=3;i*i<=x;i++)
	{
		while(x%i==0)
		{
			s.insert(i);
			x=x/i;
		}
	}
	if(x>2)
		s.insert(x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(gcd1,0,sizeof(gcd1));
	cin>>n;
	int flag1=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		    flag1=1;
	}
	if(flag1==0)
	{
	    cout<<1<<endl;
	    return 0;
	}
	primefac(a[n-1]);
	for(itr=s.begin();itr!=s.end();++itr)
	{
		gcd1[*itr]=1;
	}
	s.clear();
	for(int i=n-2;i>=0;i--)
	{
		primefac(a[i]);
		int max1=0;
		for(itr=s.begin();itr!=s.end();++itr)
			{
				gcd1[*itr]++;
				max1=max(max1,gcd1[*itr]);
			}
		for(itr=s.begin();itr!=s.end();++itr)
			{
				gcd1[*itr]=max1;
			}
		s.clear();
	}
	int final=0;
	for(int i=2;i<=100005;i++)
	{
		final=max(final,gcd1[i]);
	}
	cout<<final<<endl;

}