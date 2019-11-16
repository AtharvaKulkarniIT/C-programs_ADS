//Heuristic Algorithm-technique for solving problems quickly and efficiently
// Manhatten distance- Horizontal and vertical distance between 2 points on a grid 
# include<stdio.h>
# include<math.h>
int MROWNO = 3;
int MCOLNO=3;
double INF= 999;
struct node
{
double cost1;
double cost2;
int prow;
int pcol;
};
typedef struct node node;
struct store
{
int rowno;
int colno;
};
typedef struct store store;

store start;
store last;
int data[4][4]; 
store Q[100];
node info[4][4];
int status[4][4];
 


int checkrange(int row, int col)
{
if(row < 0 || col < 0 || row >MROWNO || col > MCOLNO)
return 0;
return 1;
}
int checkblocked(int row,int col)
{

if(data[row][col]==0)
return 0;
return 1;

}
int pathtrace()
{
int row=last.rowno;
int col=last.colno;
store arr[50];
int  astart=0;
char dir[4][10];
store temp;
int temprow;
int tempcol;
while(!(info[row][col].prow==row && info[row][col].pcol==col)) //     not parent =node
{
 temp.rowno=row;
 temp.colno=col;
 arr[astart]=temp; 
 temprow=info[row][col].prow;
 tempcol=info[row][col].pcol;
 row=temprow;
 col=tempcol;
 astart=astart+1;
}
store old; //Last node to add
old.rowno=temprow;
old.colno=tempcol;
arr[astart]=old;
int i;
printf("\nPath");
for(i=astart;i>=0;i--)
{
printf("\n%d %d,",arr[i].rowno,arr[i].colno);
if(arr[i-1].rowno==(arr[i].rowno-1) && arr[i-1].colno==arr[i].colno)
printf("\nNorth");
if(arr[i-1].rowno==(arr[i].rowno+1) && arr[i-1].colno==arr[i].colno)
printf("\nSouth");
if(arr[i-1].rowno==arr[i].rowno && arr[i-1].colno==(arr[i].colno+1))
printf("\nEast");
if(arr[i-1].rowno==arr[i].rowno && arr[i-1].colno==(arr[i].colno-1))
printf("\nWest");


}
}

double histr(int row1, int col1, int row2,int col2) 
{ 
    return ( abs(row1-row2) + abs(col1-col2)) ;
}


int testnodes(int data[][MCOLNO+1])
{
int i,j;
for(i=0;i<MROWNO;i++)
{
for(j=0;i<MCOLNO;i++)
{
if(!(data[i][j] ==1 || data[i][j]==0))
return 0;
}
}
return 1;
}
int testfinal(int row,int col ,int prow , int pcol ,store last)
{
int c1=last.colno;
int r1=last.rowno;

if(row == last.rowno && col ==last.colno)
{
info[r1][c1].prow=prow;
info[r1][c1].pcol=pcol;

return 1;

}
return 0;
}



int processnode(int row,int col,int prow,int pcol,int* plast)
{

if(checkrange (row,col)==0)
{
return 0;
}


if (checkblocked (row,col)==0)
{
return 0;
}
if(testfinal(row,col,prow,pcol,last)==1)
{

return 1;
}
if(status[row][col]==1)
{
return 0;
}
int gnew=info[prow][pcol].cost1+1;
double hnew= histr(row,  col,  last.rowno, last.colno); 
double fnew=gnew+hnew;

if(info[row][col].cost2==INF || fnew < info[row][col].cost2 +info[row][col].cost1) //diff
{

*plast=*plast+1;
Q[*plast].rowno=row;
Q[*plast].colno=col;
info[row][col].cost1=gnew;
info[row][col].cost2=hnew;
info[row][col].prow=prow;
info[row][col].pcol=pcol;

}
return -1;    //else garbage or 1 if not the end.         	
}


int searchnode(int data[][4],store start,store last)
{

int i,j;
for(i=0;i<=MROWNO;i++)
{
for(j=0;j<=MCOLNO;j++)
{
info[i][j].cost1=INF;
info[i][j].cost2=INF;
info[i][j].prow=-1;
info[i][j].pcol=-1;
}
}


for(i=0;i<=MROWNO;i++)
{
for(j=0;i<=MCOLNO;i++)
{
status[i][j]=0;
}
}
  int check;
  info[start.rowno][start.colno].cost1=0;
  info[start.rowno][start.colno].cost2=0;
  
  info[start.rowno][start.colno].prow=start.rowno;
  info[start.rowno][start.colno].pcol=start.colno;
  int qlast=-1;
  Q[0]=start;
  
  int qstart=0; 
  qlast=0;
  int  L=0; 
 

  

 while(qlast >=0)

 {
   store data;
   int st=0;
   while(st <= qlast)
   {
   
   printf("\ndata %d %d ",Q[st].rowno, Q[st].colno);
   st++;


   }

  store temp=Q[0];

  L=0;
  while(L < qlast)
  {
  Q[L]=Q[L+1];
  L=L+1;
  }
  qlast=qlast-1;
status[temp.rowno][temp.colno]=1;
store north;
north.rowno=temp.rowno-1;
north.colno=temp.colno;
store south;
south.rowno=temp.rowno+1;
south.colno=temp.colno;
store east;
east.rowno=temp.rowno;
east.colno=temp.colno+1;
store west;
west.rowno=temp.rowno;
west.colno=temp.colno-1;
int test;

test =processnode(east.rowno, east.colno, temp.rowno, temp.colno,&qlast);
if(test==1)
{

pathtrace();
return 1;
}


test =processnode(west.rowno, west.colno, temp.rowno, temp.colno,&qlast);
if(test==1)
{
pathtrace();
return 1;
}



test=processnode(north.rowno, north.colno, temp.rowno, temp.colno,&qlast);
if(test==1)
{
pathtrace();
return 1;
}


test =processnode(south.rowno, south.colno, temp.rowno, temp.colno,&qlast);
if(test==1)
{
pathtrace();
return 1;
}

 }


}




int main()
{

int i,j;

for(i=0;i<=MROWNO;i++)
{
for(j=0;j<=MCOLNO;j++)
{
printf("\nEnter data for row %d col %d ",i,j);
scanf("%d",&data[i][j]);

}

}
for(i=0;i<=MROWNO;i++)
{
for(j=0;j<=MCOLNO;j++)
{

//printf("%d ",data[i][j]);

}
printf("\n");
}
int test=testnodes(data);

if(test==0)
{
printf("\nNode value should be 0 or 1");
return 0;

}
// starting and last row struct

printf("\nEnter start row no ");
scanf("%d",&start.rowno);
printf("\nEnter start col  no ");
scanf("%d",&start.colno);
printf("enter last row no ");
scanf("%d",&last.rowno);
printf("\nEnter start col  no ");
scanf("%d",&last.colno);
searchnode( data,start, last);


}
