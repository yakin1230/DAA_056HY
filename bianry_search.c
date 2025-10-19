#include<stdio.h>
int binarysearch(int arr[], int l , int h , int n){
    int mid = (l + h) / 2;
    if(l > h){
        return -1;
    }
    else{
        if(arr[mid] > n){
            h = mid-1;
        }
        else if(arr[mid] < n){
            l = mid + 1;
        }
        else {
            return 1;
        }
    }
    return binarysearch (arr , l , h , n);
}
int main(){
    int a[8] ,  l , h , key , res , i;
    printf("enter 8 sorted element : ");
    for(i = 0;i<8;i++){
        scanf("%d" , &a[i]);
    }
    printf("enter elmenet to search : ");
    scanf("%d" , &key);
    l = 0 , h = 7;
    res = binarysearch(a , l , h , key);
    if(res == 1)
        printf("element found");
    else    
        printf("element not found");
    
    return 0 ;
}
