#include<bits/stdc++.h>
using namespace std;
	vector <int long long > vec1;
	vector <int long long > vec;
	int long long s[3005];
	int long long c[3005];
int main()
{
	int n,i,j;
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>c[i];

	vec.push_back(LONG_MAX);
	for(i=1;i<n;i++)
	{
		int long long ans=LONG_MAX;
		int flag=0;
		for(j=0;j<i;j++)
		{
			if(s[i]>s[j] && c[j]<ans )
				{
					ans=c[j];
					flag=1;
				}

		}
		if(flag==0)
			vec.push_back(LONG_MAX);
		else
		vec.push_back(ans+c[i]);
	}
	vec1.push_back(LONG_MAX);
	/*for(int i=1;i<n;i++)
		printf("%lld\n",vec[i] );*/
	for(int i=1;i<n-1;i++)
	{
		int long long ans=LONG_MAX;
		int flag1=0;
		for(int j=i+1;j<n;j++)
		{
			if(s[j]>s[i] && c[j]<ans)
				{
					flag1=1;
					ans=c[j];
				}
		}
		vec[i]=vec[i]+ans;
		if(flag1==0)
			vec1.push_back(LONG_MAX);
		else
		vec1.push_back(vec[i]);
	}

	/*for(int i=1;i<n-1;i++)
		printf("%lld\n",vec1[i] );*/
	
	int long long ans=LONG_MAX;
	for(int i=1;i<n-1;i++)
		{
			if(vec1[i]<ans)
				ans=vec1[i];
		}
	if(ans==LONG_MAX)
		printf("-1\n");
	else
		printf("%lld\n",ans);

}