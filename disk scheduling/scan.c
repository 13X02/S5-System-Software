#include<stdio.h>
int main(){
    int n,s,diff,tst=0;
    printf("Enter size of memory");
    scanf("%d",&s);
    printf("enter the no of request");
    scanf("%d",&n);
    int req[n+1],a[n],b[n];
    printf("Enter the current head position");
    scanf("%d",&req[0]);
    printf("Enter the requests");
    int k=0;
    int j=0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&req[i]);
        if(req[i]>req[0]){
            a[k]=req[i];
            k++;
        }else{
            b[j]=req[i];
            j++;
        }

    }

    for (int i = 0; i < k; i++)
    {
        for (int l = 0; l < k-i-1; l++)
        {
            if(a[l]>a[l+1]){
                int temp=a[l];
                a[l]=a[l+1];
                a[l+1]=temp;
            }
        }
        
    }

    for(int i=0;i<j;i++){
        for(int l=0;l<j-i-1;l++){
            if(b[l]<b[l+1]){
                int temp=b[l];
                b[l]=b[l+1];
                b[l+1]=temp;
            }
        }
    }

    printf("Path is %d->",req[0]);
    for(int i=0;i<k;i++){
        printf("%d->",a[i]);
    }
    printf("%d->",s-1);
    for(int i=0;i<j;i++){
        printf("%d",b[i]);
        if(i==j-1){
            break;
        }
        printf("->");
    }
    tst = ((s-1)-req[0])+((s-1)-b[j-1]);
    printf("Total seek time is %d",tst);
    return 0;
    
}