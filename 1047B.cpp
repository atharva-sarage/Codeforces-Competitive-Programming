#include<bits/stdc++.h>
using namespace std;
int main()
{
	int long long n,x,y,max1=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		max1=max(max1,x+y);
	}
	cout<<max1<<endl;

}