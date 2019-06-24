#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
vector <double> vec;

int  main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a[1000006];
		int mark[10005]={0};
		int n,a1,a2,flag=0,ans;
		cin>>n;
		double min1=1e12;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(mark[a[i]]==1)
				vec.push_back(a[i]);
			if(mark[a[i]]==3)
			    {
			        flag=1;
			        ans=a[i];
			    }
			mark[a[i]]++;
		}
		if(flag==1)
		{
		    cout<<ans<<" "<<ans<<" "<<ans<<" "<<ans<<endl;
		    vec.clear();
		    continue;
		}
		sort(vec.begin(),vec.end());

		for(int i=1;i<vec.size();i++)
		{
			//cout<<vec[i]/vec[i-1]+vec[i-1]/vec[i]<<endl;
			if(vec[i]/vec[i-1]+vec[i-1]/vec[i] <min1)
			{
				a1=vec[i];
				a2=vec[i-1];
				min1=vec[i]/vec[i-1]+vec[i-1]/vec[i];
			}
			if(i==vec.size()-1)
				continue;
			if(vec[i]/vec[i+1]+vec[i+1]/vec[i]<min1)
			{
				a1=vec[i];
				a2=vec[i+1];
				min1=vec[i]/vec[i+1]+vec[i+1]/vec[i];
			}
		}	
		vec.clear();
		cout<<a1<<" "<<a1<<" "<<a2<<" "<<a2<<endl;
	}
}