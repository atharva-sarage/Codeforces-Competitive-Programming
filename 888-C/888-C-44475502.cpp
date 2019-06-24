#include<bits/stdc++.h>
using namespace std;
string str;
int n;
int check(int k)
{
	for(int i=0;i<26;i++)	
	{
		int c=0;
		int valid=0;
		for(int j=0;j<k;j++)
			{
				if(str[j]-'a'==i)c++;
			}
		if(c>0)
			valid=1;
		for(int j=k;j<n;j++)
		{
			if(!valid)break;
			if(str[j-k]-'a'==i)c--;
			if(str[j]-'a'==i)c++;
			if(c<=0)
				valid=0;
		}
		if(valid==1)
			return 1;
	}	
	return 0;
}
int main()
{
	cin>>str;
	n=str.length();
	int low=1;
	int high=n;
	int mid;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(check(mid))
			high=mid-1;
		else
			low=mid+1;
	}
	cout<<low<<endl;
}