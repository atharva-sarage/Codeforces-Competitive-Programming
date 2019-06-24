#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
int parent[100005];


int find(int e)
{
	if(parent[e]==e)
		return e;
	return parent[e]=find(parent[e]);
}
void merge(int e1,int e2)
{
	int p1=find(e1);
	int p2=find(e2);
	if(p1==p2)
		return ;
	parent[p2]=p1;
	
}

int main()
{
	int n;
	cin>>n;
	int a[100005];
	vector <int> vec;
	vector <long long > final;
	long long ans[100005];
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			parent[i]=i;
		
		}
		//vec.push_back(0);
	for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			vec.push_back(x);
		}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	vec.push_back(0);
	reverse(vec.begin(),vec.end());
	
	final.push_back(0);
	final.push_back(a[vec[1]]);
	long long max1=a[vec[1]];
	visited[vec[1]]=true;
	ans[vec[1]]=a[vec[1]];
	
	for(int i=2;i<n;i++)
	{
		ans[vec[i]]=a[vec[i]];
		visited[vec[i]]=true;

		int flag=0;
		
		if(visited[vec[i]-1] && vec[i]>1)
			{
			
				long long c1=ans[find(vec[i])];
				merge(vec[i]-1,vec[i]);
				ans[find(vec[i])]+=c1;
				
				flag=1;
			}
		if(visited[vec[i]+1] && vec[i]<n)
			{
				long long c1=ans[find(vec[i])];
				//cout<<c1<<endl;
				merge(vec[i]+1,vec[i]);	
			
				ans[find(vec[i])]+=c1;
				flag=1;
			}
	
		//cout<<find(vec[i])<<"****"<<endl;

		max1=max(max1,ans[find(vec[i])]);
		//cout<<max1<<endl;
		final.push_back(max1);
	}	
	reverse(final.begin(),final.end());
	for(int i=0;i<final.size();i++)
		cout<<final[i]<<endl;



}