//SHORSTEST JOB FIRST!!
#include<stdio.h>
typedef struct{
    int ct,at,bt,wt,tat,pno;
}p;
void display(p* queue,int n){
    printf("\nPNO AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){
        printf("%3d %2d %2d %2d %3d %2d\n",queue[i].pno,queue[i].at,queue[i].bt,queue[i].ct,queue[i].tat,queue[i].wt);
    }
}
void sjf(p *queue,int n){
    int completed=0,current_time=0;
    int isComplete[n];
    for(int i=0;i<n;i++)
        isComplete[i]=0;
    while(completed!=n){
        int min=-1;
        for(int i=0;i<n;i++){
            if(!isComplete[i] && queue[i].at<=current_time){     //checking whether the process is already there are not! and alsoo looking for process with AT less thena the current time or the ct!!
                if(min==-1||queue[min].bt>queue[i].bt){
                    min=i;
                }
            }
        }
        if(min!=-1){
            queue[min].ct=current_time+queue[min].bt;
            current_time=queue[min].ct;
            queue[min].tat=queue[min].ct-queue[min].at;
            queue[min].wt=queue[min].tat-queue[min].bt;
            isComplete[min]=1;
            completed++;
        }
        else    
            current_time++;
    }
    display(queue,n);

}
int main(){
    int n;
    p queue[10]={0};
    printf("enter the no of process:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the PNO AT BT:");
        scanf("%d %d %d",&queue[i].pno,&queue[i].at,&queue[i].bt);
    }
    sjf(queue,n);
}