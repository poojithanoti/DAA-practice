#include <stdio.h>

int min(int a,int b){ return a<b?a:b; }
int main(){
    int n,i,j,k,l,q;
    int p[10],m[10][10];
    printf("Enter number of matrices: ");
    scanf("%d",&n);
    printf("Enter dimensions:\n");
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=9999;
            for(k=i;k<j;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    printf("Minimum number of multiplications = %d",m[1][n]);
    return 0;
}
