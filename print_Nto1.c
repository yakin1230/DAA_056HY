#include<stdio.h>
void rev(int n){
    if(n==0) return;
    printf("%d",n);
    printf("\n");
    rev(n-1);
    return;
}
int main(){
int n;
printf("enter a number : ");
scanf("%d",&n);
rev(n);
    return 0;
}