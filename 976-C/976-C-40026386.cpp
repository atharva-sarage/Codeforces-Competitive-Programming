#include<bits/stdc++.h>
//# define first first
//# define second second

using namespace std;

typedef pair<int,int> p;
int n;
pair<p,int> a[300005];
bool compare(pair<p,int> a, pair<p,int> b)
{
	if(a.first.first!=b.first.first)
		return a.first.first<b.first.first;
	else
		return a.first.second>b.first.second;
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first.first>>a[i].first.second;
		a[i].second=i+1;
	}
	sort(a,a+n,compare);
	set <p> cur;
	for(int i=0;i<n;i++)
	{
		while(!cur.empty() && cur.begin()->first<a[i].first.first)
			cur.erase(cur.begin());
		if(!cur.empty() && (--cur.end())->first>=a[i].first.second)
		{
			cout<<a[i].second<<" "<<(--cur.end())->second<<endl;
			return 0;
		}
		cur.insert({a[i].first.second,a[i].second});
	}
	cout<<-1<<" "<<-1<<endl;

}