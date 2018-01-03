#include<stdio.h>
 
int main()
{
    int bt[10],p[10],wt[10],n,total=0,pos,temp,i,j;
    float avwt;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;          
    }
    for(i=0;i<n;i++)        // sorting using selection sort
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];                  // Here, the process is also swapped wrt the bus time
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            
    for(int i=1;i<n;i++)            // Here, BUS time is calculated
    {
        wt[i]=bt[i-1]+wt[i-1];      //  current wt=bt of previous process+wt of previous process
        
        total+=wt[i];
    }
 
    avwt=(float)total/n;  
 
    printf("\nProcess\t    Burst Time    \tWaiting Time");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t  %d\t\t    %d",p[i],bt[i],wt[i]);
    }
    printf("\n\nAverage Waiting Time=%f",avwt);
    return 0;
}