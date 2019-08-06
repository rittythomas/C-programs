#include<stdio.h>
#include<conio.h>

##DONE ONLY FCFS. SJS AND PRIORITY LEFT.

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
	printf("FCFS");
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
void main()
{

	int n,i, tat[20],wt[20],bt[20];
	clrscr();
	printf("Enter number of process:");
	scanf("%d",&n);
	printf("\n Enter process Burst time:\n");
	for(i=0 ; i<n; i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d", &bt[i]);
	}
	FCFSAlgorithm(n,bt,wt,tat);
	getch();
}
