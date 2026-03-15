#include <stdio.h>

int main() {
    int n, cost[10][10], visited[10]={0};
    int i,j,min,a,b,u,v,ne=1,mincost=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    visited[1]=1;
    while(ne<n) {
        min=999;
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(cost[i][j] < min) {
                    if(visited[i]!=0) {
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0) {
            printf("\nEdge %d:(%d %d) cost:%d", ne++,a,b,min);
            mincost += min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost = %d",mincost);
}
