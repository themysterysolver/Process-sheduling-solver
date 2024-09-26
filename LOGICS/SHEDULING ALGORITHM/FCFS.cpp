//FIRST COME FIRST SERVE 
#include<stdio.h>
//structure to store all the datas of the table!!!
typedef struct{
	int ct,at,bt,tat,wt,pno;
}p;
//display function to display the table!!
void display(p *queue,int n){
	int i=0;
	printf("Pno AT BT CT TAT WT\n");
	for(i=0;i<n;i++){
		printf("%3d %2d %2d %2d %3d %2d\n",queue[i].pno,queue[i].at,queue[i].bt,queue[i].ct,queue[i].tat,queue[i].wt);
	}
}
//sorting based on AT!!!  ASCENDING!!!
void sort(p *queue,int n){
	int i=0,j=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(queue[j].at>queue[j+1].at){
				p temp=queue[j];
				queue[j]=queue[j+1];
				queue[j+1]=temp;
			}
		}
	}
	display(queue,n);	
}

void fcfs(p *queue,int n){
	sort(queue,n);
	int stat=0,swt=0,ct=0;
	float atat,awt;
	for(int j=0;j<n;j++){
		queue[j].ct=queue[j].bt+ct;
		ct+=queue[j].bt;
		queue[j].tat=queue[j].ct-queue[j].at;
		stat+=queue[j].tat;
		queue[j].wt=queue[j].tat-queue[j].bt;
		swt+=queue[j].wt;
	}
	display(queue,n);
	printf("\nAverage TAT:%.3f\nAverage WT:%.3f",float(stat)/n,float(swt)/n);

}

int main(){
	int n,i;
	float avgTAT,avgWT;
	p queue[10]={0};
	printf("Enter the no of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		 printf("Enter the process no.:");
		scanf("%d",&queue[i].pno);
		 printf("Enter the arrival time and burst time:");
		scanf("%d %d",&queue[i].at,&queue[i].bt);
	}
	display(queue,n);
	fcfs(queue,n);
}
