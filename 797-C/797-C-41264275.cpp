// easy peasy lemon squeezy
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
stack <char> s;
int index1;
string str;
void solve(string str,char min1,int n)
{
	//cout<<str<<"***"<<n<<"****"<<min1<<endl;
	int count1=0,index1;
	for(int i=0;i<n;i++)
	{
		if(str[i]==min1)
			{
				index1=i;
				count1++;
			}
	}
	for(int i=0;i<index1;i++)
	{
		if(str[i]!=min1)
			{
				s.push(str[i]);
			}
	}
	for(int i=0;i<count1;i++)
		cout<<min1;
	min1='~';
	if(index1==n-1)
		return;
	for(int i=index1+1;i<n;i++)
		min1=min(str[i],min1);

if(!s.empty())
{
	while(s.top()<=min1 && !s.empty())
	{
		cout<<s.top();
		s.pop();
		if(s.empty())
			break;
	}
}
	
	
	string str2;
	str2=str.substr(index1+1,n-index1-1);
	solve(str2,min1,n-index1-1);


}
int main()
{
	
	cin>>str;
	int n=str.length();
	char min1='~';
	for(int i=0;i<n;i++)
		min1=min(str[i],min1);
	solve(str,min1,n);

	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	printf("\n");


}