#include<bits/stdc++.h>
using namespace std;
vector <int> vec;
vector <int> vec1;
vector <int> vec2;
string store[1005];
string inters(string a,string b)
{
	if(b.length()==0)
		return a;
	string res1;
	int freq[27]={0};
	int freq1[27]={0};
	for(int i=0;i<a.length();i++)
	{
		freq[a[i]-'a']++;
	}
	for(int i=0;i<b.length();i++)
	{
		freq1[b[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		int k=min(freq[i],freq1[i]);
		for(int j=0;j<k;j++)
			res1+='a'+i;
	}
	return res1;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	string str;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='*')
			vec.push_back(i);
		else
			vec1.push_back(i);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string str2;
		cin>>str2;
		int mark[30];
		int flag=0;
		memset(mark,0,sizeof(mark));
		for(int j=0;j<vec1.size();j++)
		{
			if(str2[vec1[j]]!=str[vec1[j]])
				flag=1;
			mark[str2[vec1[j]]-'a']=1;
		}
		if(flag==1)
			continue;
		for(int j=0;j<vec.size();j++)
		{
			if(mark[str2[vec[j]]-'a']==0)
			{
				store[i]+=str2[vec[j]];
				mark[str2[vec[j]]-'a']==1;
			}
			else
			{
				store[i].clear();
				break;
			}
			sort(store[i].begin(),store[i].end());
		}	
	}
	int i=0;
	while(store[i].length()==0)
		i++;
	string	res=store[i];
	i++;
	for(int i=1;i<m;i++)
	{
		res=inters(res,store[i]);
	}
	int final[27]={0};
	for(int i=0;i<res.size();i++)
	{
		final[res[i]-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(final[i]>0)
			ans++;
	}
	cout<<ans<<endl;

}