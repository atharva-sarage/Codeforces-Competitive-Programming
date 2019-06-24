#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll b[200005];
ll final1[200005];
vector <pair<ll,ll> > a;
int main()
{
	ll n,m,d;
	cin>>n>>m>>d;
	for(ll i=0;i<n;i++)
		{
		cin>>b[i];
		a.push_back(make_pair(b[i],i));
		}
	sort(a.begin(),a.end());
	queue <pair<ll,ll> > q;
	ll ans=1;
	q.push(make_pair(a[0].first,ans));
	final1[a[0].second]=1;
	for(ll i=1;i<n;i++)
	{
		ll v=q.front().first;
		ll w=q.front().second;
		if(a[i].first-v<=d)
			{
			ans++;
			q.push(make_pair(a[i].first,ans));
			final1[a[i].second]=ans;
			}
		else 
		{
			q.pop();
			q.push(make_pair(a[i].first,w));			
			final1[a[i].second]=w;
		}
	}
	cout<<q.size()<<endl;
	for(int i=0;i<n;i++)
		cout<<final1[i]<<" ";
	printf("\n");
}