#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,diff,tst=0;
    printf("enter the no of request");
    scanf("%d",&n);
    int req[n+1];
    printf("Enter the current head position");
    scanf("%d",&req[0]);
    printf("Enter the requests");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&req[i]);
        
        diff = abs(req[i]-req[i-1]);
        tst+=diff;
        
    }
    for (int i = 0; i < n+1; i++)
    {
        
        printf("%d",req[i]);
        if(i==n){
            break;
        }
        printf("->");
    }
    
    printf("Total seek time is %d",tst);
    return 0;
    
}