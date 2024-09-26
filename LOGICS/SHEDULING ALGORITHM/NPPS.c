#include<stdio.h>
typedef struct{
 int pno,priority,ct,at,bt,tat,wt;
}p;
void display(p* queue,int n){
    printf("\nPNO PRIORITY AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){
        printf("%3d %8d %2d %2d %2d %3d %2d\n",queue[i].pno,queue[i].priority,queue[i].at,queue[i].bt,queue[i].ct,queue[i].tat,queue[i].wt);
    }
}
void npps(p* queue,int n){
    int completed=0,isComplete[n],current_time=0,min=-1;
    for(int i=0;i<n;i++)
        isComplete[i]=0;
    while(completed!=n){
        min=-1;
        for(int i=0;i<n;i++){
            if(!isComplete[i] && queue[i].at<=current_time){       //finds pno is laready used and also checks for at!
                if(min==-1||queue[i].priority<queue[min].priority){  //finds TOP PRIORITY!!
                    min=i;
                }
            }
        }
        printf("%D",min);
        if(min!=-1){
            queue[min].ct=queue[min].bt+current_time;
            current_time=queue[min].ct;
            queue[min].tat=queue[min].ct-queue[min].at;
            queue[min].wt=queue[min].tat-queue[min].bt;
            completed++;
            isComplete[min]=1;
        }
        else    
            current_time++;
    }
    display(queue,n);
}
int main(){
    int n;
    p queue[10]={0};
    printf("Enter the no of process:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter the PNO PRIORITY AT BT:");
        scanf("%d %d %d %d",&queue[i].pno,&queue[i].priority,&queue[i].at,&queue[i].bt);
    }
    npps(queue,n);
}