#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	string str,str2,str3,str4;
	cin>>str;
	int valid=0;
	for(int i=1;i<n;i++)
	{
		int l=i;
		int j=0;
		int flag=0;
		while(l<n)
		{
			if(str[j]!=str[l])
			{
				flag=1;
				break;
			}
			j++;l++;
		}
		if(flag==0)
		{
			valid=1;
			for(int j=i;j<n;j++)
				str3+=str[j];
			for(int j=n-i;j<n;j++)
				str4+=str[j];
			break;
		}

	}
	if(valid==0)
	{
		for(int i=0;i<k;i++)
			cout<<str;
		printf("\n");
		return 0;
	}
			cout<<str3;
		for(int i=0;i<k;i++)
			cout<<str4;
		printf("\n");
}