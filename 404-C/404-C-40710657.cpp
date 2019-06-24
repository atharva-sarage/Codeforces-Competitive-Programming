#include<bits/stdc++.h>
typedef int long long ll;
using namespace std;
int main()
{
	ll n,k,maxlevel=0,flag_1=0,flag=0;
	cin>>n>>k;
	vector <ll> level[n];
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		if(x==0 && flag_1==1)
			flag=1;
		if(x==0)
			flag_1=1;
		maxlevel=max(maxlevel,x);
		level[x].push_back(i+1);
	}
	ll ans=0;
	if(level[0].size()*(k)<level[1].size())
		{
			flag=1;			
		}
	else
		ans+=level[1].size();
	
	for(ll i=1;i<=maxlevel-1;i++)
	{
		ll x1=level[i].size();
		if((k-1)*x1<level[i+1].size())
		{
			flag=1;
			break;
		}
		ans+=level[i+1].size();
	}
	if(flag==1)
		{
			printf("-1 \n");
			return 0;
		}
	cout<<ans<<endl;
	for(ll i=0;i<=maxlevel-1;i++)
	{
		ll count=0,l=0,k1=0;
		while(count<level[i+1].size())
		{	
			printf("%lld %lld\n",level[i][l],level[i+1][count]);
			count++;
			k1++;
			if(k1==k && i==0 )
				{
					k1=0;
					l++;
				}
			else if(k1==k-1 && i!=0 )
			{
				k1=0;l++;
			}
		}
	}
}