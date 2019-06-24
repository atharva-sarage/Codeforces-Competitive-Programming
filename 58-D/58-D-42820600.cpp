#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,ans=0;
	cin>>n;
	char c;
	set <string> s[10005];
	set	<string> s2;
	set <string> s3;

	for(int i=0;i<n;i++)	
	{
		string str;
		cin>>str;
		int m=str.length();
		s[m].insert(str);
		s2.insert(str);
		ans+=m;
	}		
	set <string> :: iterator itr,itr1,itr2,itr4,itr3;
	cin>>c;
	for(itr4=s2.begin();itr4!=s2.end();++itr4)
	{
		string res1;
		res1=*itr4;
		res1+=c;
		s3.insert(res1);
	}
	ans=2*ans/n;
	ans++;
	while(!s3.empty())
	{
		itr=s3.begin();
		string res=*itr;		
		int k=res.length();
		s[k-1].erase(s[k-1].begin());
		itr2=s[ans-k].begin();
		cout<<*itr<<*itr2<<endl;
		string temp=*itr2;
		temp+=c;
		itr1=s3.find(temp);
		s[ans-k].erase(itr2);
		s3.erase(itr);
		s3.erase(itr1);
	}

}