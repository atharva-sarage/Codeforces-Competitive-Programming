#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
int main()
{
	set <ll> s,s2;
	set<ll> :: iterator itr;
	ll n,m,n1,m1,flag=0;
	cin>>n>>m;
	if(n>m)
		{
		flag=1;
		swap(n,m);
		}
	n1=n;
	m1=m;	
	ll i=1,sum=0;
	if(n1!=0)
	{
	while(1)
	{
		if(n1-i<0)
		{
			if(s.find(sum+i-n)!=s.end())
			{
				s.erase(sum+i-n);
				s.insert(i);
				break;
			}
		}
		else
			{
			s.insert(i);
			n1-=i;
			sum+=i;
			if(n1==0)
				break;
			}
		i++;
	}
	}
	i=1;
	sum=0;
	if(m1!=0)
	{
	while(1)
	{
		if(s.find(i)==s.end())
		{
		if(i>m1)
			break;
			if(m1-i<0)
		{
			if(s2.find(sum+i-m)!=s2.end())
			{
				s2.erase(sum+i-m);
				s2.insert(i);
				break;
			}
		}
		else
			{
			s2.insert(i);
			m1-=i;
			sum+=i;
			if(m1==0)
				break;
			}
		}
		i++;
	}
}
	if(flag==1)
	{
		cout<<s2.size()<<endl;
		for(itr=s2.begin();itr!=s2.end();++itr)
		{
			cout<<*itr<<" ";
		}
		printf("\n");
		cout<<s.size()<<endl;
		for(itr=s.begin();itr!=s.end();++itr)
		{
			cout<<*itr<<" ";
		}
	}
	else
	{
		cout<<s.size()<<endl;
		for(itr=s.begin();itr!=s.end();++itr)
		{
			cout<<*itr<<" ";
		}
		printf("\n");
		cout<<s2.size()<<endl;
		for(itr=s2.begin();itr!=s2.end();++itr)
		{
			cout<<*itr<<" ";
		}
	}
	cout<<endl;

}