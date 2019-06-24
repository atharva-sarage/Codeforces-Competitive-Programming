#include<bits/stdc++.h>
# define mx 1000006
typedef int long long ll;
using namespace std;
vector <int> vec;
vector<int> vec1;
ll table[mx];
ll a[mx];
ll b[mx];
ll c1[mx];
ll greater1[mx];
ll less1[mx];
void update(ll i,ll delta)
{

	while(i<=mx)
	{
		
		table[i]+=delta;
		i+=(i&-i);
	}
}
ll sum(ll i)
{
	ll ans=0;
	while(i>0)
	{
		ans+=table[i];
		i-=(i&-i);
	}
	return ans;
}
ll rangesum(ll i,ll j)
{
	return sum(j)-sum(i-1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(table,0,sizeof(table));
	ll n,ans=0;
	cin>>n;
	for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			vec.push_back(a[i]);
			b[i]=a[i];
		}
	sort(b,b+n);
	map <ll,ll> c;
	for(ll i=0;i<n;i++)
	{
		c.insert(make_pair(b[i],i+1));
	}
	for(ll i=0;i<n;i++)
	{
		update(c[a[i]],1);
		greater1[i]=rangesum(c[a[i]]+1,n);
	}
	
	memset(table,0,sizeof(table));

	reverse(vec.begin(),vec.end());

	for(ll i=0;i<n;i++)
	{
		update(c[vec[i]],1);
		less1[n-i-1]=rangesum(1,c[vec[i]]-1);
	}

	for(ll i=1;i<n-1;i++)
		ans+=less1[i]*greater1[i];

	cout<<ans<<endl;


}