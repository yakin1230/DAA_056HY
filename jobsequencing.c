#include<stdio.h>
//#include<conio.h>
#define MAX 10
struct job {
    int id;
    int deadline;
    int profit;
};
void sortjobs(struct job jobs[], int n){
    int i , j;
    struct job temp;
    for(i = 0 ; i < n-1 ; i++){
        for(j = 0 ; j < n-i-1 ; j++){
            if(jobs[j].profit < jobs[j+1].profit){
                temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}
void jobsequencing(struct job jobs[] , int n){
    int i , k;
    int maxDeadline = 0;
    int timeSlot[MAX] = {0};
    int totalProfit = 0;
    for(i = 0 ; i < n ; i++){
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline ;
    }
    if(maxDeadline >= MAX)
        maxDeadline = MAX-1;
    for(i = 1 ; i <= maxDeadline ; i++){
        timeSlot[i] = -1;
    }
    for(i = 0 ; i < n ; i++){
        k = (jobs[i].deadline <= maxDeadline);
        while(k >= 1){
            if(timeSlot[k] == -1){
                timeSlot[k] = i;
                totalProfit += jobs[i].profit;
                break;
            }
            k--;
        }
    }
    printf("\n job sequence (with deadline) :\n");
    for(i = 1 ; i<=maxDeadline;i++){
        if(timeSlot[i] == -1)
            printf("slot %d --> job %d [profit = %d] \n" , i , jobs[timeSlot[i]].id , jobs[timeSlot[i]].profit);
        else
            printf("slot %d --> empty \n" , i);
    }
    printf("\n Totalprofit = %d \n" , totalProfit);
}
int main(){
    struct job jobs[MAX];
    int n , i;
    printf("enter number of jobs : ");
    scanf("%d" , &n);
    for(i = 0 ; i<n ; i++){
        printf("\n enter details for job %d \n" , i+1);
        jobs[i].id = i+1;
        scanf("%d" ,&jobs[i].deadline);
        scanf("%d" ,&jobs[i].profit);
    }
    sortjobs(jobs, n);
    jobsequencing(jobs, n);
    
    return 0;
}
