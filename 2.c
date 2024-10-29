#include<stdlib.h>
#define nul 1000
#define nodes 10
int no;
struct node
{
int a[nodes][4];
}router[nodes];
void init(int r)
{
int i;
for(i=1;i<=no;i++)
{
router[r].a[i][1]=i;
router[r].a[i][2]=999;
router[r].a[i][3]=nul;
}
router[r].a[r][2]=0;
router[r].a[r][3]=r;
}
void inp(int r)
{
int i;
printf("\n Enter Distance from the Node %d to Other Nodes",r);
printf("\n Please Enter 999 if there is No Direct Route\n",r);
for(i=1;i<=no;i++)
{
if(i!=r)
{
printf("\n Enter Distance to the Node %d:",i);
scanf("%d",&router[r].a[i][2]);
router[r].a[i][3]=i;
}
}
}
void display(int r)
{
int i,j;
printf("\n\nThe Routing Table for Node %d is as follows:",r);
for(i=1;i<=no;i++)
{
if(router[r].a[i][2]>=999)
printf("\n\t\t\t %d \t no link \t no hop",router[r].a[i][1]);
else
printf("\n\t\t\t %d \t %d \t\t %d",router[r].a[i][1],router[r].a[i][2],router[r].a[i][3]);
}
}
void dv_algo(int r)
{
int i,j,z;
for(i=1;i<=no;i++)
{
if(router[r].a[i][2]!=999 && router[r].a[i][2]!=0)
{
for(j=1;j<=no;j++)
{
z=router[r].a[i][2]+router[i].a[j][2];
if(router[r].a[j][2]>z)
{
router[r].a[j][2]=z;
router[r].a[j][3]=i;
}
}
}
}
}
int main()
{
int i,j,x,y;
char choice;
printf("Enter the No. of Nodes Required (Less Than 10 Nodes):");
scanf("%d",&no);
for(i=1;i<=no;i++)
{
init(i);
inp(i);
}
printf("\n The Configuration of the Nodes After Initialization is as follows:");
for(i=1;i<=no;i++)
display(i);
for(i=1;i<=no;i++)
dv_algo(i);
printf("\n The Configuration of the Nodes After Computation of Paths is as follows:");
for(i=1;i<=no;i++)
display(i);
while(1)
{
printf("\n\nWanna continue (y/n):");
scanf("%c",&choice);
if(choice=='n')
break;
printf("\n Enter the Nodes between which Shortest Path is to be found:\n");
scanf("%d %d",&x,&y);
printf("\n The Length of the Shortest Path is %d",router[x].a[y][2]);
}
}