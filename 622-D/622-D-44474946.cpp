#include <cstdio>

int a[1200000];
int i,j,k,n;

int main() {
	scanf("%d",&n);
	for (i=1,j=n,k=1;i<j;i++,j--,k=k+2)
		a[i]=a[j]=k;
	for (i=n+2,j=2*n,k=2;i<j;i++,j--,k=k+2)
		a[i]=a[j]=k;
	for (i=1;i<=2*n;i++)
		if (!a[i])
			printf("%d ",n);
		else
			printf("%d ",a[i]);
}