#include<bits/stdc++.h>
using namespace std;
int dp[505][5050];

int main()
{
	int n,k;
	cin>>n>>k;
	int c[5000];
	int f[5000];
	int h[5000];
	vector<int> vec;
	for(int i=0;i<n*k;i++)
		{
			cin>>c[i];			
		}
	for(int i=0;i<n;i++)
		{
			cin>>f[i];
			vec.push_back(f[i]);
		}

	for(int i=0;i<k;i++)
		cin>>h[i+1];
	memset(dp,0,sizeof(dp));
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n*k;j++)
		{
			for(int l=1;l<=k;l++)
			{
				if(j>=l)
				dp[i][j]=max(dp[i-1][j-l]+h[l],dp[i][j]);
			}
		}
	}
		long final=0;
		int freq[100005];
		int freq1[100005];
		memset(freq1,0,sizeof(freq1));
		memset (freq,0,sizeof(freq));
		for(int j=0;j<n*k;j++)
		{
			freq[c[j]]++;
		}
		for(int i=0;i<n;i++)
		{
			freq1[f[i]]++;
		}
		
		sort(vec.begin(),vec.end());
		vector<int> ::iterator itr;
		itr=unique(vec.begin(),vec.end());
		vec.resize(distance(vec.begin(),itr));
		
		for(int i=0;i<vec.size();i++)
		{
			final+=dp[freq1[vec[i]]][freq[vec[i]]];
		}
		cout<<final<<endl;


	/*for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n*k;j++)
		{
			cout<< dp[i][j]<<" ";
		}
		printf("\n");
	}*/

}