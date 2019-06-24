#include<bits/stdc++.h>
# define ff first
# define ss second
# define pb push_back
# define mp make_pair
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,d;
		cin>>l>>r>>d;
		int temp1=l/d;
		int temp2=r/d;
		if(temp1>=1 && d!=l)
			cout<<d<<endl;
		else
		{
			cout<<(r/d+1)*d<<endl;
		}
	}
}