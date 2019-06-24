#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long int ull;
ull pre[200005];
ull a[200005];
map <ull,ull> m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);
	ull n;
	ld ans1=0,ans2=0;
	cin>>n;
	for(ull i=0;i<n;i++)
	{
		cin>>a[i];
		if(m.find(a[i]-1)!=m.end())
		ans2+=m[a[i]-1];
		if(m.find(a[i]+1)!=m.end())
		ans1+=m[a[i]+1];
		if(m.find(a[i])==m.end())
			m.insert(make_pair(a[i],1));
		else
			m[a[i]]++;
		if(i!=0)
		{
		pre[i]=pre[i-1]+a[i];
		}
		else
			pre[i]=a[i];	
	}
	for(ull i=1;i<n;i++)
		{
		ans1+=a[i]*(i);
		ans2+=pre[i-1];
		}
	cout<<fixed<<setprecision(0)<<ans1-ans2<<endl;
	

}