#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define mp make_pair
# define IOS ios::sync_with_stdio(0),cin.tie(0)
typedef int long long ll;	
ll pre[mx],suff[mx],a[mx];
struct point 
{
	ll l,r;
};
int main()
{
    IOS;
	ll n,flag=0;
	cin>>n;
	map <ll,struct point> m;
	for(ll i=0;i<n;i++)
		{
		cin>>a[i];
		if(m.find(a[i])==m.end())
			{
				struct point p;
				p.l=i;
				p.r=i;
				m.insert(mp(a[i],p));
			}
		else
			{
				m[a[i]].r=i;
			}
		}
	pre[0]=a[0];
	suff[n-1]=a[n-1];
	for(ll i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i];
	for(ll i=n-2;i>=0;i--)
		suff[i]=suff[i+1]+a[i];
	for(ll i=1;i<n;i++)
	{
		if(pre[i-1]>suff[i])
		{
			ll d=pre[i-1]-suff[i];
			if(d%2==1)
				continue;
			if(m.find(d/2)!=m.end())
			{
				if(m[d/2].l<=i-1)
				{
					flag=1;
					break;
				}
			}
		}
		else if(pre[i-1]<suff[i])
		{
			ll d=-pre[i-1]+suff[i];
			if(d%2==1)
				continue;
			if(m.find(d/2)!=m.end())
			{
				if(m[d/2].r>=i)
				{
					flag=1;
					break;
				}
			}
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(pre[n-1]%2==0)
	{
		if(m.find(pre[n-1]/2)!=m.end())
			flag=1;
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;

}