#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, k, l, v1, v2, x;
    cin >> n >> l >> v1 >> v2 >> k;
    n = ceil(n / k);
    x = n / (v2 - v1) + (n - 1) / (v2 + v1);
    printf("%lf", l/(v1 + 1/x));
    return 0;
}