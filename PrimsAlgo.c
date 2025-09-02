#include<stdio.h>
#include<conio.h>
void prims(int , int [10][10]);
void main(){
    int i,j,n=3,cost[10][10] = {
        {0, 5, 10},
        {5, 0, 5},
        {10, 5, 0}
    };
    for(i=0;i<n;i++){
        printf("\n\n");
        for(j=0;j<n;j++){
            printf("%d  ",cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;//(INT_MAX from limis.h)
        }
    }
    printf("\n\n");
    prims(n,cost);
    getch();
}
void prims(int n , int cost[10][10]){
    int i, j, u, v, min ,mincost=0, visited[10]={0};
    visited[0]=1;
    min = 999; //INT_MAX from limits.h
    for(i=0;i<n;i++){
        min = 999; //INT_MAX from limits.h
        for(j=0;j<n;j++){
            if(cost[i][j]<min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
        if (visited[v]==0){
            mincost += min;
            visited[v]=1;
        }
        cost[u][v]=cost[v][u]=999; //INT_MAX from limits.h
    }
    printf("\nMinimum cost is %d",mincost); 
}