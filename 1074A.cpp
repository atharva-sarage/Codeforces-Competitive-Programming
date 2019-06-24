#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	vector <int> vec;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		{
			int x,y,z;
		cin>>x>>y>>z;
		if(x==1)
			vec.push_back(y);
		}
	int ans=300005;
	a[n]=1e9;
	sort(a,a+n+1);
	sort(vec.begin(),vec.end());
	for(int i=0;i<n+1;i++)
	{
		int it=upper_bound(vec.begin(),vec.end(),a[i]-1)-vec.begin();
		ans=min(ans,i+(int)vec.size()-it);		
	}
	cout<<ans<<endl;

}