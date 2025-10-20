#include<stdio.h>
void merge(int arr[] , int l , int mid , int h){
    int i = l , j = mid+1 , k = l;
    int b[h];
    while(i<=mid && j<=h){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= h){
            b[k] = arr[j];
            j++,k++;
        }
    }
    else{
        while(i <= mid){
            b[k] = arr[i];
            i++,k++;
        }
    }
    for(k=l;k<=h;k++){
        arr[k] = b[k];
    }
}
void mergesort(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr , low , mid , high);
    }
}
int main(){
    int arr[7] , l = 0 , i;
    printf("enter 7 element : ");
    for(i = 0 ; i<7 ; i++){
        scanf("%d",&arr[i]);
    }
    int high = sizeof (arr)/sizeof (arr[0])-1;
    mergesort(arr , l , high);
    printf("\n sorted array : \n");
    for(i = 0 ;i<=high; i++){
        printf("%d" ,arr[i]);
        printf("\n");
        
    }
    return 0 ;
}
