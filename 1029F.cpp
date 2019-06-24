// easy pesasy lemon squeezy

#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
vector<ll > vec2;
vector<ll > vec3;
vector <pair<ll ,ll > > vec;
int  main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll  a,b;
	cin>>a>>b;
	ll  c=a+b;
	for(ll  i=1;i*i<=c;i++)
	{
		if(c%i==0)
		{
			vec.push_back(make_pair(i,c/i));
		}
	}
	for(ll  j=1;j*j<=min(a,b);j++)
	{
		if(min(a,b)%j==0)
			{
				if(j==min(a,b)/j)
					vec2.push_back(j);
				else
				{
					vec2.push_back(j);
					vec2.push_back(min(a,b)/j);
				}
			}
	}
	for(ll  j=1;j*j<=max(a,b);j++)
	{
		if(max(a,b)%j==0)
			{
				if(j==max(a,b)/j)
					vec3.push_back(j);
				else
				{
					vec3.push_back(j);
					vec3.push_back(max(a,b)/j);
				}
			}
	}
	sort(vec3.begin(),vec3.end());
	sort(vec2.begin(),vec2.end());
	if(a==1 || b==1)	
	{
		int size=vec.size();
		cout<<2*(vec[size-1].first+vec[size-1].second)<<endl;
		return 0;
	}
	ll l1,high;
	for(int i=vec.size()-1;i>=0;i--)
	{
		
		ll  mid=i;
		if(min(a,b)%vec[mid].first==0)
			l1=min(a,b)/vec[mid].first;
		else
			l1=min(a,b)/vec[mid].first+1;

		ll  l2=vec[mid].second;

		vector <ll> :: iterator it;
		it=upper_bound(vec2.begin(),vec2.end(),l2);
		it--;
		//cout<<*it<<endl;
		if(*it>=l1)
			{
			high=mid;
			break;
			}
	}
	ll final=2*(vec[high].first+vec[high].second);
	//cout<<final<<endl;
	for(int i=vec.size()-1;i>=0;i--)
	{
		ll mid=i;
		if(max(a,b)%vec[mid].first==0)
			l1=max(a,b)/vec[mid].first;
		else
			l1=max(a,b)/vec[mid].first+1;
		ll l2=vec[mid].second;

		vector <ll> :: iterator it;
		it=upper_bound(vec3.begin(),vec3.end(),l2);
		it--;
		//cout<<*it<<endl;
		if(*it>=l1)
			{
			high=mid;
			break;
			}

		//cout<<low<<"**"<<high<<endl;
	}

	cout<<min(final,2*(vec[high].first+vec[high].second))<<endl;
}