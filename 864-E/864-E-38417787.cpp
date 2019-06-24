#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> ans2,s[2001]; int ans1=0,f[2001];
struct item{
	int savetime;
	int deadtime;
	int value;
	int id;
};
bool mysort(item a,item b)
{
	return a.deadtime<b.deadtime;
}
main()
{
	int n,i,j; cin>>n; item lit[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>lit[i].savetime>>lit[i].deadtime>>lit[i].value;
		lit[i].id=i;
	}
	sort(lit+1,lit+n+1,mysort);
	for (i=1;i<=n;i++)
	{
		for (j=lit[i].deadtime-1;j>=lit[i].savetime;j--)
		{
			if (f[j]<f[j-lit[i].savetime]+lit[i].value)
			{
				f[j]=f[j-lit[i].savetime]+lit[i].value;
				s[j]=s[j-lit[i].savetime];
				s[j].push_back(lit[i].id);
			}
		}
	}
	for (i=1;i<=2000;i++)
	{
		if (f[i]>ans1)
		{
			ans1=f[i];
			ans2=s[i];
		}
	}
	cout<<ans1<<"\n"<<ans2.size()<<"\n";
	for (i=0;i<ans2.size();i++) cout<<ans2[i]<<" ";
}