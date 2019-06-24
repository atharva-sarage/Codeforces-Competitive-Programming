#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,flag=0;
	cin>>n;
	string str,str2;
	cin>>str;
	i=0;j=n-1;
	while(str[i]!='G' && i<n)
		i++;
	while(str[j]!='G' && j>=0)
		j--;
	for(int k=i;k<=j;k++)
		str2+=str[k];
	for(int i=0;i<str2.length();i++)
	{
		if(str2[i]=='S')
			flag=1;
	}
	
		int ans=0;
		char s[]={'G','S'};
		vector <int> vec;
		int c=0;
		for(int i=0;i<str2.length();)
		{
			int c1=0;
			while(str2[i]==s[c] && i<str2.length())
			{
				c1++;
				i++;
			}
			if(c==0)
				ans=max(ans,c1+1);
			vec.push_back(c1);
			c=c^1;
		}
		if(flag==0)
		{
			cout<<max(0,ans-1)<<endl;
			return 0;
		}
		
		for(int i=1;i<vec.size()-1;i=i+2)
		{
			if(vec[i]==1 && vec.size()>4)
				ans=max(vec[i-1]+vec[i+1]+1,ans);
			else if(vec[i]==1)
				ans=max(vec[i-1]+vec[i+1],ans);
		}
	
	cout<<ans<<endl;

}