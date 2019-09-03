#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
}sdir,mdir[10];
struct tree_element
{
char name[20];
int x,y,ftype,lx,rx,nc,level;
struct tree_element *link[5];
};
typedef struct tree_element
node;

void singleLevel()
{
	int i,ch;
	char f[30];
	sdir.fcnt = 0;
	printf("\nEnter name of directory -- ");
	scanf("%s", sdir.dname);
	while(1)
	{
		printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the name of the file -- ");
				scanf("%s",sdir.fname[sdir.fcnt]);
				sdir.fcnt++;
				break;
			case 2: printf("\n Enter the name of the file -- ");
				scanf("%s",f);
				for(i=0;i<sdir.fcnt;i++)
				{
					if(strcmp(f, sdir.fname[i])==0)
					{
						printf("File %s is deleted ",f);
						strcpy(sdir.fname[i],sdir.fname[sdir.fcnt-1]);
						break;
					}
				}
				if(i==sdir.fcnt)
					printf("File %s not found",f);
				else
					sdir.fcnt--;
					break;
			case 3: printf("\n Enter the name of the file -- ");
				scanf("%s",f);
				for(i=0;i<sdir.fcnt;i++)
				{
					if(strcmp(f, sdir.fname[i])==0)
					{
						printf("File %s is found ", f);
						break;
					}
				}
				if(i==sdir.fcnt)
					printf("File %s not found",f);
				break;
			case 4: if(sdir.fcnt==0)
					printf("\n Directory Empty");
				else
				{
					printf("\n The Files are -- ");
					for(i=0;i<sdir.fcnt;i++)
						printf("\t%s",sdir.fname[i]);
				}
				break;
			default: exit(0);
		}
	}
}

void multiLevel()
{
	int i,ch,dcnt,k;
	char f[30], d[30];
	dcnt=0;
	while(1)
	{
		printf("\n\n 1. Create Directory\t 2. Create File\t 3. Delete File");
		printf("\n 4. Search File \t \t 5. Display \t 6. Exit \t\n Enter your choice -- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter name of directory -- ");
				scanf("%s", mdir[dcnt].dname);
				mdir[dcnt].fcnt=0;
				dcnt++;
				printf("Directory created");
				break;
			case 2: printf("\n Enter name of the directory -- ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
					if(strcmp(d,mdir[i].dname)==0)
						{
							printf("Enter name of the file -- ");
							scanf("%s",mdir[i].fname[mdir[i].fcnt]);
							mdir[i].fcnt++;
							printf("File created");
							break;
						}
					if(i==dcnt)
						printf("Directory %s not found",d);
				break;
			case 3: printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{
					if(strcmp(d,mdir[i].dname)==0)
					{
						printf("Enter name of the file -- ");
						scanf("%s",f);
						for(k=0;k<mdir[i].fcnt;k++)
						{
							if(strcmp(f, mdir[i].fname[k])==0)
							{
								printf("File %s is deleted ",f);
								mdir[i].fcnt--;
								strcpy(mdir[i].fname[k],mdir[i].fname[mdir[i].fcnt]);
								goto jmp;
							}
						}
					printf("File %s not found",f);
					goto jmp;
					}
				}
				printf("Directory %s not found",d);
				jmp : break;
			case 4: printf("\nEnter name of the directory -- ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{

					if(strcmp(d,mdir[i].dname)==0)
					{
						printf("Enter the name of the file -- ");
						scanf("%s",f);
						for(k=0;k<mdir[i].fcnt;k++)
						{
							if(strcmp(f, mdir[i].fname[k])==0)
							{
								printf("File %s is found ",f);
								goto jmp1;
							}
						}
					printf("File %s not found",f);
					goto jmp1;
					}
				}
				printf("Directory %s not found",d);
				jmp1: break;
			case 5: if(dcnt==0)
					printf("\nNo Directory's ");
				else
				{
					printf("\nDirectory\tFiles");
					for(i=0;i<dcnt;i++)
					{
						printf("\n%s\t\t",mdir[i].dname);
						for(k=0;k<mdir[i].fcnt;k++)
							printf("\t%s",mdir[i].fname[k]);
					}
				}
				break;
			default:  exit(0);
			}
		}

}
void hierarchial()
{	
	int gd=DETECT,gm;
	node *root;
	root=NULL;
	
	create(&root,0,"root",0,639,320);

	initgraph(&gd,&gm,"c:\\tc\\BGI");
	display(root);
	getch();
	closegraph();
}
create(node **root,int lev,char *dname,int lx,int rx,int x)
{
	int i,gap;
	if(*root==NULL)
	{
		(*root)=(node *)malloc(sizeof(node));
		printf("Enter name of dir/file(under %s) :",dname);
		fflush(stdin);
		gets((*root)->name);
		printf("enter 1 for Dir/2 forfile :");
		scanf("%d",&(*root)->ftype);
		(*root)->level=lev;
		(*root)->y=50+lev*50;
		(*root)->x=x;
		(*root)->lx=lx;
		(*root)->rx=rx;
		for(i=0;i<5;i++)
			(*root)->link[i]=NULL;
		if((*root)->ftype==1)
		{
			printf("No of sub directories/files(for %s):",(*root)->name); scanf("%d",&(*root)->nc);
			if((*root)->nc==0)
				gap=rx-lx;
			else gap=(rx-lx)/(*root)->nc;
			for(i=0;i<(*root)->nc;i++)
				create(&((*root)->link[i]),lev+1,(*root)->name,lx+gap*i,lx+gap*i+gap,lx+gap*i+gap/2);
		}
		else (*root)->nc=0;
	}
}
display(node *root)
{
	int i;
	settextstyle(2,0,4);
	settextjustify(1,1);
	setfillstyle(1,BLUE);
	setcolor(14); if(root!=NULL)
	{
		for(i=0;i<root->nc;i++)
		{
			line(root->x,root->y,root->link[i]->x,root->link[i]->y);
		}
		if(root->ftype==1) bar3d(root->x-20,root->y-10,root->x+20,root->y+10,0,0); else
		fillellipse(root->x,root->y,20,20);
		outtextxy(root->x,root->y,root->name); 
		for(i=0;i<root->nc;i++)
		{
			display(root->link[i]);
		}
}
}
	
void main()
{
	int ch;

		while(ch!=4){
		printf("Stimulate:\n\t 1.Single Level\n\t 2.MultiLevel\n\t 3.Hierarchial\n\t4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: singleLevel();
				break;
			case 2: multiLevel();
				break;                    
			case 3:
				hierarchial();
				break;
			default: printf( "Exit");
					break;;
		}
	}
	getch();
}
