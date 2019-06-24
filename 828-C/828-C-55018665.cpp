/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 10000005
char final[mx];
vector <pair<int,pair<int,int>>> temp;
vector <string> store;
bool cmp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
	if(a.ff==b.ff)
		return a.ss.ff>b.ss.ff;
	return a.ff<b.ff;
}
int main()
{
	IOS;
	int n,len=0;
	cin>>n;
	store.pb(" ");
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		int k;
		cin>>k;
		store.pb(str);
		while(k--)
		{
			int j;cin>>j;
			temp.pb({j,{str.length(),i}});
			len=max(len,j+(int)str.length()-1);
		}
	}
	sort(temp.begin(),temp.end(),cmp);
	// for(auto k:temp)
	// 	cout<<k.ff<<" "<<" "<<k.ss.ff<<" "<<k.ss.ss<<endl;
	int p=0;
	for(int i=0;i<len;i++)
		final[i]='a';
	for(auto k:temp)
	{
		if(p<k.ff+k.ss.ff-1)
		{
			for(int j=max(p+1,k.ff);j<k.ff+k.ss.ff;j++)
				final[j-1]=store[k.ss.ss][j-k.ff];
				//cout<<store[k.ss.ss][j-k.ff]<<" "<<j<<" "<<k.ff<<" "<<k.ss.ss<<endl;
			p=k.ff+k.ss.ff-1;
		}
	}
	for(int i=0;i<len;i++)
		cout<<final[i];


}