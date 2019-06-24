#include <bits/stdc++.h>
using namespace std;
int p[3005];
int solve(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return 4+solve(n-2);
}
int main() 
    {
    int n;
    cin >> n;    
    for(int i=0;i<n;i++) 
    {
        cin >> p[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans+=(p[i]>p[j]);
        }
    }   
    cout<<solve(ans)<<endl;
}