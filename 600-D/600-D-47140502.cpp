#include<bits/stdc++.h>
#include<cmath>
using namespace std;
# define db long double
db PI=3.14159265358979323846;
struct point 
{
	db x,y;
};
struct circle
{
	point p;
	db r;
};
db dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	db x1,y1,r1,x2,y2,r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	point p1={x1,y1};
	point p2={x2,y2};
	circle c[3];
	c[1]={p1,r1};
	c[2]={p2,r2};
	if(dist(c[1].p,c[2].p)>=(r1+r2))
		{cout<<0<<endl;return 0;}
	if(dist(c[1].p,c[2].p)<=abs(r1-r2))
	{
		db ans=PI*min(c[1].r,c[2].r)*min(c[1].r,c[2].r);
		cout.precision(100);
		cout << fixed << ans << endl;return 0;
	}
	db final=0.0;
	db temp=acos(((c[1].r)*(c[1].r)+(dist(c[1].p,c[2].p)*dist(c[1].p,c[2].p))-(c[2].r)*(c[2].r))/(db)(2LL*(dist(c[1].p,c[2].p)*c[1].r)));
	db a1= temp*(db)c[1].r*(db)c[1].r;
	db a2=c[1].r*c[1].r*sin(temp)*cos(temp);
	final+=a1-a2;
	temp=acos(((c[2].r)*(c[2].r)+(dist(c[1].p,c[2].p)*dist(c[1].p,c[2].p))-(c[1].r)*(c[1].r))/(db)(2LL*(dist(c[1].p,c[2].p)*c[2].r)));
	a1= temp*(db)c[2].r*c[2].r;
	a2=	c[2].r*c[2].r*sin(temp)*cos(temp);
	final+=a1-a2;
	cout.precision(100);
	cout << fixed << final << endl;
}