#include<stdio.h>
#include<stdbool.h>

#define max 100
typedef struct{ //structure for PROCESS!!
    int ct,at,bt,wt,tat,pno,rt;
}p;
typedef struct{ //Structure for QUEUE!!
    int front,rear; //indices!!
    p *array[max];
}q;
void display(p* queue,int n){
    printf("\nPNO AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){
        printf("%3d %2d %2d %2d %3d %2d\n",queue[i].pno,queue[i].at,queue[i].bt,queue[i].ct,queue[i].tat,queue[i].wt);
    }
}
q* createq(){
    q* p_queue=(q*)malloc(sizeof(q));
    p_queue->front=-1;
    p_queue->rear=-1;
    return p_queue;
}
bool isFull(q* p_queue){
    return (p_queue->rear==max-1);//rear is back!!
}
bool isEmpty(q* p_queue){
    return(p_queue->front==-1);
}
void enqueue(q* p_queue,p* process){
    if(isFull(p_queue)){
        printf("p_queue is full\n");
        return;
    }
    if(isEmpty(p_queue))
        p_queue->front=0;
    p_queue->rear++;
    p_queue->array[p_queue->rear]=process;
}
p* dequeue(q* p_queue){
    if(isEmpty(p_queue)){
        printf("q is empty\n");
        return NULL;
    }
    p* process=p_queue->array[p_queue->front];
    if(p_queue->rear==p_queue->front)
        p_queue->front=p_queue->rear=-1;
    else
        p_queue->front++;
    return process;
}
void rr(p * queue,int n,int tq){
    int current_time=0,completed=0;
    q* p_queue=createq();
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(queue[i].rt!=0 && queue[i].at<current_time){
                enqueue(p_queue,&queue[i]);
            }
        }
        while(!isEmpty(p_queue)){
            p* current_process=dequeue(p_queue);
            if(current_process->rt<=tq){
                current_process->ct=current_time+current_process->rt;
                current_time=current_process->ct;
                current_process->rt=0;
                completed++;
            }
            else{
                current_time+=tq;
                current_process->rt-=tq;
                enqueue(p_queue,current_process);
            }
        }
    }

}
int main(){
    int n,tq;
    p queue[10]={0};
    printf("Enter the no of process and time quantum:");
    scanf("%d %d",&n,&tq);
    for (int i=0;i<n;i++){
        printf("Enter the PNO AT BT:");
        scanf("%d %d %d %d",&queue[i].pno,&queue[i].at,&queue[i].bt);
    }
    //npps(queue,n);
    rr(queue,n,tq);
}