#include<bits/stdc++.h>
using namespace std;
# define ff first
# define ss second
# define mp make_pair
# define pb push_back
bool cmp(pair<pair<int,int>,int>p1,pair<pair<int,int> ,int>p2)
{
	if(p1.ff.ff==p2.ff.ff)
	{
		return p1.ff.ss>p2.ff.ss;
	}
	return p1.ff.ff<p2.ff.ff;
}
vector <pair<pair<int,int>,int>>vec;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,flag=0;
		cin>>n;
		int final[n+5];
		for(int i=0;i<n;i++)
			final[i]=0;
		for(int i=0;i<n;i++)
		{
			int l,r;
			cin>>l>>r;
			vec.pb({{l,1},i});
			vec.pb({{r,-1},i});
		}
		sort(vec.begin(),vec.end(),cmp);
		int c=1;
		int ans=0;
		for(int i=0;i<vec.size();i++)
		{
			ans+=vec[i].ff.ss;
			final[vec[i].ss]=c;
			if(ans==0)
				{c=c^1;}
		}
		for(int i=0;i<n;i++)
		{
			if(final[i]==0)
				flag=1;
		}
		if(flag==0)
			{cout<<-1<<endl;vec.clear();continue;}
		for(int i=0;i<n;i++)
		{
			if(final[i]==0)
				cout<<2<<" ";
			else
				cout<<1<<" ";
		}
		printf("\n");
		vec.clear();

	}
}