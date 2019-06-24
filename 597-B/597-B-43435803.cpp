#include<bits/stdc++.h>
using namespace std;
struct inter{int s,e;};
struct inter j[500005];
int dp[500005];
vector <int> str;
vector <int> end1; 
int n;
bool compare(struct inter a,struct inter b)
{
	if(a.s==b.s)
		return a.e<b.e;
	return a.s<b.s;
}
int calc(int u,int val)
{
	int it=upper_bound(str.begin()+u,str.end(),val)-str.begin();
	return it;
}
int solve(int u)
{
	if(u==n)
		return 0;
	int &w=dp[u];
	if(w!=-1)
		return w;
	w=max(solve(u+1),1+solve(calc(u,end1[u])));
	return w;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>j[i].s>>j[i].e;
	}
	sort(j,j+n,compare);
	end1.push_back(j[0].e);
	str.push_back(j[0].s);
	for(int i=1;i<n;i++)
	{
		if(j[i-1].s==j[i].s)
			continue;
		end1.push_back(j[i].e);
		str.push_back(j[i].s);
	}
	n=end1.size();
	cout<<solve(0)<<endl;

}