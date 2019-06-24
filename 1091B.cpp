#include<bits/stdc++.h>
using namespace std;
# define mx 1005
# define mp make_pair
struct point
{
	int x,y;
};
point p[mx];
point c[mx];
map<pair<int,int>,int> m;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i]={x,y};
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		c[i]={x,y};
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{

			if(m.find(mp(p[i].x+c[j].x,p[i].y+c[j].y))==m.end())
				m.insert(mp(mp(p[i].x+c[j].x,p[i].y+c[j].y),1));
			else
				m[mp(p[i].x+c[j].x,p[i].y+c[j].y)]++;
			if(m[mp(p[i].x+c[j].x,p[i].y+c[j].y)]==n)
				{cout<<p[i].x+c[j].x<<" "<<p[i].y+c[j].y<<endl;flag=1;break;}
		}
		if(flag==1)
			break;
	}

}