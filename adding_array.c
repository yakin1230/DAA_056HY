#include<stdio.h>
int main(){
    int arr1[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("entr element no. %d of row %d : ",j+1,i+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n2nd matrix\n");

     int arr2[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("entr element no. %d of row %d : ",j+1,i+1);
            scanf("%d",&arr2[i][j]);
        }
    }
    
    //adding without extra variable

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",arr1[i][j]+arr2[i][j]);
           
        }
        printf("\n");
    }

    // int brr[2][2];
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         brr[i][j]=arr1[i][j]+arr2[i][j];
    //     }
    // }    
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         printf("%d ",brr[i][j]);
           
    //     }
    //     printf("\n");
    // }

    return 0;
}