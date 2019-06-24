#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int flag=0;
		cin>>n;
		char str[105];
		cin>>str;
		for(int i=0;i<n/2;i++)
		{
			if(str[i]-1==str[n-1-i]+1 || str[i]+1==str[n-i-1]+1 || str[i]-1==str[n-i-1]-1 || str[i]+1==str[n-i-1]-1)
				continue;
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}
}