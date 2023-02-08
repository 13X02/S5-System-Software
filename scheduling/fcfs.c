#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n],twt,ttat,at[n];
    printf("Enter the burst time and arrival time of processes");
    for (int i = 0; i < n; i++){
        scanf("%d",&bt[i]);
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                int temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
    wt[0]=0;
    for (int i = 1; i < n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
    twt=0;
    ttat=0;
    printf("-------------------------------------------------------------\n");
    printf("| Process | waiting time | arrival time |   ta time  |\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i]+bt[i];
        twt += wt[i];
        ttat += tat[i];
        printf("--------------------------------------------------------------\n");
        printf("|    %d    |     %d        |     %d        |    %d       |\n",i,wt[i],at[i],tat[i]);
    }
    printf("---------------------------------------\n");
    printf("Average waiting time is %.2f",(float)twt/n);
    printf("\nAverage turnaround time is %.2f",(float)ttat/n);
    return 0;    
}