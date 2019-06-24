#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
# define IOS ios::sync_with_stdio(0),cin.tie(0)
int main()
{
    IOS;
	ll n,q,count1=0,n1,c1;	
	cin>>n>>q;
	n1=n;
	while(n1>=1)
	{
		n1/=2;
		count1++;
	}
	c1=1LL<<(count1-1);
	while(q--)
	{
		ll m;
		cin>>m;
		string str;
		cin>>str;
		for(ll i=0;i<str.length();i++)
		{
			if(str[i]=='L' && m%2==0)
				m-=((m&-m))>>1;
			else if(str[i]=='R' && m%2==0)
				m+=((m&-m))>>1;
			else if(str[i]=='U')
				{
				if(m==c1)
					continue;
				if(m%((m&-m)<<2)>((m&-m)<<1))
					m-=((m&-m));
				else
					m+=((m&-m));
				}
		}
		cout<<m<<endl;

	}
}