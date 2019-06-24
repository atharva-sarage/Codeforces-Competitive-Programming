#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll b[300005];
ll a[300005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll final1=0;
	ll final2=0;
	ll n,sum1,sum2,m,count1=0,i,j;
	cin>>n;
	for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			final1+=a[i];
		}
	cin>>m;
	for(ll j=0;j<m;j++)
		{
		cin>>b[j];
		final2+=b[j];
		}
	if(final1!=final2)
	{
		cout<<-1<<endl;
		return 0;
	}
	i=0,j=0;
	sum1=a[0];
	sum2=b[0];

	while(i<n && j<m)
	{
		if(sum1==sum2)
		{
			count1++;
			i++;j++;
			sum1=a[i];
			sum2=b[j];			
		}
		while(sum1>sum2 && j<m)
		{
			j++;
			sum2+=b[j];
		}
		while(sum1<sum2 && i<n)
		{
			i++;
			sum1+=a[i];
		}
	}

	cout<<count1<<endl;
}