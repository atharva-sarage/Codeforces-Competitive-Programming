#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll  a[200005];
ll  l[200005];
ll  p[13];
ll  len(ll  a)
{
	ll  count=0;
	while(a>=1)
	{
		a/=10;
		count++;
	}
	return count;
}
int  main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int  n,k;
	scanf("%d %d",&n,&k);
	unordered_map <int ,int > m[11];
	for(ll  i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		l[i]=len(a[i]);
		ll  l1=l[i];
		if(m[l1].find(a[i]%k)==m[l1].end())
			m[l1].insert(make_pair(a[i]%k,1));
		else
			m[l1][a[i]%k]++;
		}
	ll  res=1LL;
	ll  final=0;
	for(ll  j=1;j<=11;j++)
	{
		p[j]=res;
		res*=10;
		res%=k;
	}
	for(ll  i=0;i<n;i++)
	{
		for(ll  j=1;j<=10;j++)
		{
			if(m[j].find((k-(a[i]*(p[j+1]))%k)%k)!=m[j].end())
			final+=m[j][(k-(a[i]*p[j+1])%k)%k];
		}
	}
	for(ll  i=0;i<n;i++)
	{
		if((a[i]+(p[l[i]+1]*a[i])%k)%k==0)
			{
				final--;
			}
	}
	cout<<final<<endl;

}