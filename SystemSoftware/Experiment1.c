#include<stdio.h>



void findWaitingTime(int n, int bt[], int wt[])
{
	int i;
	wt[0] = 0;
	for (i=1 ; i < n; i++)
		wt[i] = bt[i-1]+wt[i-1];
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[])
{
	int i;
	for(i = 0; i < n; i++)
		tat[i] = wt[i] + bt[i];
}
void FCFSAlgorithm(int n, int bt[],int wt[], int tat[])
{
	findWaitingTime(n,bt,wt);
	findTurnAroundTime(n,bt,wt,tat);
	printf("P BT WT TAT\n");
	for (int i=0; i<n ; i++)
	{
		printf("%d",i+1);
		printf(" %d",bt[i]);
		printf("  %d",wt[i]);
		printf("   %d",tat[i]);
		printf("\n");
	}
}
void SJF(int n,int bt[],int wt[],int tat[])
{
		int i,j,temp;
		for(i = 0;i < n; i++){
			int pos = i;
			for(j = i+1; j < n; j++){
				if(bt[j] < bt[pos]){
					pos = j;
				}
				temp = bt[i];
				bt[i] = bt[pos];
				bt[pos] = temp;
			}
		}
}
void Priority(int n,int bt[],int wt[], int tat[], int pr[],int p[]){
	int i,j,temp, pos,total;
	for(i=0;i<n;i++)
	 {
	     
			 pos=i;
			 for(j=i+1;j<n;j++)
			 {
					 if(pr[j]<pr[pos])
							 pos=j;
			 }

			 temp=pr[i];
			 pr[i]=pr[pos];
			 pr[pos]=temp;

			 temp=bt[i];
			 bt[i]=bt[pos];
			 bt[pos]=temp;

			 temp=p[i];
			 p[i]=p[pos];
			 p[pos]=temp;
	 }
	 wt[0]=0;	//waiting time for first process is zero

	 //calculate waiting time
	 for(i=1;i<n;i++)
	 {
			 wt[i]=0;
			 for(j=0;j<i;j++)
					 wt[i]+=bt[j];

		     total+=wt[i];
	 }

	 printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	 for(i=0;i<n;i++)
	 {
			 tat[i]=bt[i]+wt[i];     //calculate turnaround time
			 total+=tat[i];
			 printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	 }

}

void main()
{

	int ch,n,i, tat[20],wt[20],bt[20],p[20],pr[20];

	printf("Enter number of process:");
	scanf("%d",&n);
	printf("\n Enter process Burst time & Priority:\n");
	for(i=0 ; i<n; i++)
	{
		printf("P[%d]:",i+1);
		printf("Burst Time:");
			 scanf("%d",&bt[i]);
			 printf("Priority:");
			 scanf("%d",&pr[i]);
			 p[i]=i+1; //process number
	}
	printf("Stimulate:\n 1.FCFSAlgorithm\n 2.SFF\n 3.Priority\n 4.Round Robin\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
					FCFSAlgorithm(n,bt,wt,tat);
					break;
		case 2:
					SJF(n,bt,wt,tat);
					break;
		case 3:
					Priority(n,bt,wt,tat,pr,p);
					break;
		default:
					printf("Wrong input\n");
	}
	getch();
}

