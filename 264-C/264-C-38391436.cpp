#include<stdio.h>
#define X 100010
typedef long long ll;
ll c[X],v[X],dp[X];
ll max(ll a,ll b){
    return a>b?a:b;
}
int main(){
    int i,j,n,m,q,a,b,ca,cb;
    ll as;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)scanf("%I64d",&v[i]);
    for(i=1;i<=n;i++)scanf("%I64d",&c[i]);
    while(q--){
        scanf("%d%d",&a,&b);
        for(i=1;i<=n;i++)dp[i]=(ll)-1e15;
        ca=cb=0;
        for(i=1;i<=n;i++){
            as=max(dp[c[i]]+v[i]*a,dp[cb]+v[i]*b);
            if(ca!=c[i]) as=max(as,dp[ca]+v[i]*b);
            if(ca!=c[i]){
                if(dp[ca]<as)cb=ca,ca=c[i];
                else if(dp[cb]<as) cb=c[i];
            }
            dp[c[i]]=max(dp[c[i]],as);
        }
        printf("%I64d\n",dp[ca]);
    }
    return 0;
}