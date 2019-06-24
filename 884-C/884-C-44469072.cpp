#include<bits/stdc++.h>
using namespace std;
# define mx 100005
typedef int long long ll;
ll visited[mx],a[mx];
vector <ll> vec;
ll n;
void dfs(ll u)
{
	ll c=1;
	visited[u]=true;
	ll u1=u;
	while(a[u]!=u1)
	{
		visited[a[u]]=true;
		c++;
		u=a[u];
	}
	vec.push_back(c);
}
void DFS()
{
	for(ll i=1;i<=n;i++)
		{
		if(!visited[i])
		dfs(i);
		}
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	DFS();
	sort(vec.begin(),vec.end());
	ll sum=0;
	if(vec.size()==1)
	{
		cout<<vec[0]*vec[0]<<endl;
		return 0;
	}
	for(ll i=0;i<vec.size()-2;i++)
	{
		sum+=vec[i]*vec[i];
	}
	sum+=(vec[vec.size()-2]+vec[vec.size()-1])*(vec[vec.size()-2]+vec[vec.size()-1]);
	cout<<sum<<endl;

}