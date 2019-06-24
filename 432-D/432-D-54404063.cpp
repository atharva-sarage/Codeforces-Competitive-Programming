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
# define mx 1000005
int z[mx],zz[mx];
void zalgo(string str,int n)
{
	int l=0,r=0;
	z[0]=n;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			int j=0,k=i;
			while(k<n && str[k]==str[j])
				{k++;j++;}
			k--;z[i]=j;
			if(k>r)	{r=k;l=i;}
		}
		else
		{
			int k=i;
			int k1=k-l;
			int b=r-k+1;
			if(z[k1]<b)
				z[k]=z[k1];
			else if(z[k1]>b)
				z[k]=b;
			else
			{
				k=r+1;				
				while(k<n && str[k]==str[b])
					{k++;b++;}
				k--;
				if(k>r)
					{r=k;l=i;}
				z[i]=b+r-k;
			}
		}
	}
}
bool mark[mx];
int main()
{
	IOS;
	string str;
	cin>>str;
	int n=str.length();
	zalgo(str,n);
	for(int i=0;i<n;i++)
		zz[i]=z[i];
	sort(zz,zz+n);
	vector <pair<int,int>> vec;
	for(int i=n-1;i>=0;i--)
	{
		int t=z[i];
		if(z[i]==n-i && mark[t]==false)
			{vec.pb({t,n-(lower_bound(zz,zz+n,t)-zz)});mark[t]=true;}
	}
	cout<<vec.size()<<endl;
	sort(vec.begin(),vec.end());
	for(auto k:vec)
		cout<<k.ff<<" "<<k.ss<<endl;

		
}