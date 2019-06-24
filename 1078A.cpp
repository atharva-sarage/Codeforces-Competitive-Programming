#include<bits/stdc++.h>
# define inf 1e12
using namespace std;
double a,b,c;
struct point
{
	double x,y;
};
double getx(int y)
{
	if(a==0)return inf;
	return (-c-b*y)/(double)a;
}
double gety(int x)
{
	if(b==0)return inf;
	return (-c-a*x)/(double)b;
}
double getdist(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
	double x1,y1,x2,y2;
	cin>>a>>b>>c>>x1>>y1>>x2>>y2;

	struct point p[10];
	double dist[5],dist1[5];
	p[0].x=x1;
	p[0].y=gety(x1);
	dist[0]=abs(gety(x1)-y1);
	p[1].x=getx(y1);
	p[1].y=y1;
	dist[1]=abs(getx(y1)-x1);
	p[2].x=x2;
	p[2].y=gety(x2);
	dist[2]=abs(gety(x2)-y2);
	p[3].x=getx(y2);
	p[3].y=y2;
	dist[3]=abs(getx(y2)-x2);

	dist1[0]=getdist(p[0],p[2])+dist[0]+dist[2];
	dist1[1]=getdist(p[0],p[3])+dist[0]+dist[3];
	dist1[2]=getdist(p[1],p[2])+dist[1]+dist[2];
	dist1[3]=getdist(p[1],p[3])+dist[1]+dist[3];

	sort(dist1,dist1+4);
	//cout<<min(dist1[0],abs(x1-x2)+abs(y1-y2))<<endl;
	printf("%.9lf\n",min(dist1[0],abs(x1-x2)+abs(y1-y2)) );

}