#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll a[200005],b[200005],v[200005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		{
			cin>>b[i];
			v[b[i]]=i;
		}
	for(int i=0;i<n;i++)
		a[i]=v[a[i]];
	
	int i1=0;
	while(a[i1]<a[i1+1])
		i1++;
	cout<<n-i1-1<<endl;

}