#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
struct point{
	ll x;
	ll y;
};

int  main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	ll n,m;
	cin>>n>>m;
	vector<point> vec;
	vector <ll> final;
	vector<pair<pair<ll,ll>,ll> > bridge;
	set <pair<ll,ll> > s;
	set <pair<ll,ll> > :: iterator itr;
	int ans[500005];
	vector<pair<ll,ll> > length;
	for(ll i=0;i<n;i++)
	{
		ll x1,y1;
		cin>>x1>>y1;
		point p;
		p.x=x1;p.y=y1;
		vec.push_back(p);
	}
	for(ll i=0;i<m;i++)
		{
			ll x;cin>>x;
			length.push_back(make_pair(x,i));
		}
	sort(length.begin(),length.end());
	for(ll i=0;i<n-1;i++)
	{
		bridge.push_back(make_pair(make_pair(vec[i+1].x-vec[i].y,vec[i+1].y-vec[i].x),i));
	}
	ll flag=0,count1=0;
	memset(ans,-1,sizeof(ans));

	sort(bridge.begin(),bridge.end());
	int j=0;
	for(int i=0;i<m;i++)
	{		
			
		while(length[i].first>=bridge[j].first.first && j<n-1)
			{
				s.insert(make_pair(bridge[j].first.second,bridge[j].second));
				j++;
			}
			if(!s.empty())
			{
				pair<ll,ll> top=*s.begin();
				if(length[i].first<=top.first)
					ans[top.second]=length[i].second;
				s.erase(top);
			}
		
	}
	for(int i=0;i<n-1;i++)
	{
		if(ans[i]==-1)
			{
				printf("No\n");
				return 0;
			}
	}
cout<<"Yes"<<endl;
	for(int i=0;i<n-1;i++)
	{

		cout<<ans[i]+1<<" ";
	}
	printf("\n");
}