#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <pair<ll,ll> > vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	set <pair<ll,ll> > s;
	set <pair<ll,ll> > :: iterator itr1;
	set <pair<ll,ll> > :: iterator itr2;
	set <pair<ll,ll> > :: iterator itr3;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			ll y;
			cin>>y;
			s.insert(make_pair(y,i));
			
		}
	while(!s.empty())
	{
		itr1=s.begin();
		itr3=itr1;
		itr3++;
		itr2=itr3;
		if(itr1->first!=itr2->first)
		{
			vec.push_back(make_pair(itr1->second,itr1->first));
			s.erase(s.begin());
		}
		else
		{
			s.insert(make_pair(2*itr1->first,itr2->second));
			s.erase(s.begin());
			s.erase(itr2);
		}
	}
	sort(vec.begin(),vec.end());
	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();i++)
		cout<<vec[i].second<<" ";
	printf("\n");
}