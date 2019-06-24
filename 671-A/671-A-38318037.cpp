#include<bits/stdc++.h>
using namespace std;
const int N=100005;
double x[N],y[N];  
double ax,ay,bx,by,tx,ty;  
double f(double xx, double yy, int id)
{  
    return sqrt((xx-x[id])*(xx-x[id])+(yy-y[id])*(yy-y[id]));  
}  
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);  
    int n;scanf("%d",&n);  
    double sum = 0;  
    double ma=1E12,mb=1E12,mab=1E12;  
    for(int i=0;i<n;i++)
    {
    	scanf("%lf %lf",&x[i],&y[i]);
    	double dt=f(tx,ty,i);
    	double da=f(ax,ay,i)-dt;
    	double db=f(bx,by,i)-dt;

    	sum+=dt*2;
    	mab=min(mab,min(ma+db,mb+da));
    	ma=min(ma,da);
    	mb=min(mb,db);
    }
    printf("%.12lf\n",sum+min(mab,min(ma,mb)) );
}