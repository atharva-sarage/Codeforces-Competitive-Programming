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
int final=0;
string str;
int z[2][mx],pre[mx];
void zalgo(string str,int n,int t)
{
	int l=0,r=0;
	z[t][0]=n;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			int j=0,k=i;
			while(k<n && str[k]==str[j])
				{k++;j++;}
			k--;z[t][i]=j;
			if(k>r)	{r=k;l=i;}
		}
		else
		{
			int k=i;
			int k1=k-l;
			int b=r-k+1;
			if(z[t][k1]<b)
				z[t][k]=z[t][k1];
			else if(z[t][k1]>b)
				z[t][k]=b;
			else
			{
				k=r+1;				
				while(k<n && str[k]==str[b])
					{k++;b++;}
				k--;
				if(k>r)
					{r=k;l=i;}
				z[t][i]=b+r-k;
			}
		}
	}
}
bool check(string a)
{
	int c1=a.length();
	string b=a,str2=str;
	reverse(b.begin(),b.end());
	reverse(str2.begin(),str2.end());
	a+='$';
	int resume1=a.length();
	a+=str;
	b+='$';
	int resume2=b.length();
	b+=str2;
	zalgo(a,a.length(),0);
	zalgo(b,b.length(),1);
	pre[resume2]=z[1][resume2];
	for(int i=resume2+1;i<b.length();i++)
		pre[i]=max(pre[i-1],z[1][i]);
	for(int i=resume1;i<a.length();i++)
	{
		int t1=i+z[0][i]-resume1;
		//cout<<t1<<" "<<b.length()-t1-1-c1+z[0][i]<<endl;
		if(c1-z[0][i]<=pre[b.length()-t1-1-c1+z[0][i]])
			return 1;
	}
	return 0;
}
int main()
{
	IOS;
	cin>>str;
	int m;
	cin>>m;
	while(m--)
	{
		string a;
		cin>>a;
		if(a.length()==1)continue;
		if(check(a))
			final++;
	}
	
	cout<<final<<endl;
}