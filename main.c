#include <stdio.h>
#include <stdlib.h>
const int n=3;

int main()
{
    int a[n][n+1], i, j, k, p, c;
    printf("enter extended system matrix\n");
    for (i=0; i<n; i++)
        for (j=0; j<n+1; j++) scanf("%d", &a[i][j]);
    for (k=0; k<n-1; k++)
    {
        if (a[k][k]==0)
        {
            p=k+1;
            while (a[p][k]==0) p++;
            for (j=p; j<n+1; j++)
            {
                c=a[p][k];
                a[p][k]=a[k][k];
                a[k][k]=c;
            }
        }
        for (i=k+1; i<n; i++)
            for (j=n; j>=k; j--) a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];
    }
for (j=n-1; j>0; j--)
    {
    for (i=j-1; i>=0; i--)
    {
        a[i][n]=a[i][n]-a[i][j]*a[j][n]/a[j][j];
        a[i][j]=0;
    }
    }
for (i=0; i<n; i++) printf("%f ", (float)a[i][n]/a[i][i]);

    return 0;
}
