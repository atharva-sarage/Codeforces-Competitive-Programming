#include<bits/stdc++.h>
using namespace std;
int ans[28];
int main()
{
	int n,k,max1=0;
	cin>>n>>k;
	string str;
	cin>>str;
	int c=1;
	for(int i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
			c++;
		else
			{
				if(i==0)
					{ans[str[i]-'a']+=c/k;c=1;}
				else
					ans[str[i-1]-'a']+=c/k;c=1;
			}
	}
	ans[str[n-1]-'a']+=c/k;
	for(int i=0;i<26;i++)
		max1=max(max1,ans[i]);
	cout<<max1<<endl;
}