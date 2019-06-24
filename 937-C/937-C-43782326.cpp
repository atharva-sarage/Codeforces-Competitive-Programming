#include<bits/stdc++.h>
# define ll unsigned long long
# define db double
using namespace std;
db k,d,t;
double c1=0.000000001;
double c2=0.000000001;
db calc(db a)
{
	return (db)((ll)a/(ll)d) *((d+k)/(2.0*t))+((a-(db)((ll)a/(ll)d)*d))/t;
}
db calc2(db a)
{
	return (db)((ll)a/(ll)d) *((d+k)/(2.0*t))+((a-k-(db)((ll)a/(ll)d)*d))/(2.0*t) +k/t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>k>>d>>t;
	if(d<=k)
		{if((ll)k%(ll)d==0)
			d=k;
		else
		d=d*((ll)k/(ll)d +1);}

			db low=1;
			db high=2e18;
			db prev=-1;
			db mid;

			while(high-low>c2)
			{
				db mid=(high+low)/2.0;	
				
				if(mid-d*(db)((ll)mid/(ll)d)<=k)
				{
					if(calc(mid)<1.0)
						low=mid+c1;
					else
						high=mid-c1;
				}
				else
				{
					if(calc2(mid)<1.0)
						low=mid+c1;
					else
						high=mid-c1;
				}
					
				if(abs(mid-prev)<c1)			
					break;
				prev=mid;
			}
			cout<<endl;
			cout<<fixed<<setprecision(9)<<high<<endl;		
			
		}