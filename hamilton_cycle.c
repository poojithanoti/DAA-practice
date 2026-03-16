#include <stdio.h>

int x[10],g[10][10],n;
int place(int k,int v){
    if(g[x[k-1]][v]==0) return 0;
    for(int i=1;i<k;i++)
        if(x[i]==v) return 0;
    if(k<n || (k==n && g[v][x[1]]==1))
        return 1;
    return 0;
}
void hamiltonian(int k){
    for(int v=2;v<=n;v++){
        if(place(k,v)){
            x[k]=v;
            if(k==n){
                for(int i=1;i<=n;i++)
                    printf("%d ",x[i]);
                printf("%d\n",x[1]);
            }
            else
                hamiltonian(k+1);
        }
    }
}
int main(){
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    x[1]=1;
    hamiltonian(2);
    return 0;
}
