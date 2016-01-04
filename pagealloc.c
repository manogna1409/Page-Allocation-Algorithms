#include<stdio.h>

void fifo(char [],char [],int,int);
void lru(char [],char [],int,int);
void opt(char [],char [],int,int);
void lfu(char [],char [],int,int);
void display(int,char [],char [],int);

int main()
{
   int ch,YN=1,i,l,f;
   char F[10],s[25];
   int sz[20],sf[20];
   int pr[10];
   int nf;
   int np,S=0,choice;

   printf("\n Enter the total number of frames available");
   scanf("%d",&nf);
//printf("total number of frames are %d\n",nf);
   printf("\nEnter the number of processes");
   scanf("%d",&np);
   printf("\nenter the size of the processes\n");
   for(i=0;i<np;i++)
{
   scanf("%d",&sz[i]);
}

   printf("enter the priorities for the processes\n");
   for(i=0;i<np;i++)
{
   scanf("%d",&pr[i]);
}

   printf("\n\nEnter the length of the string:");
   scanf("%d",&l);
   printf("\n\nEnter the string: ");
   scanf("%s",s);
  
   for(i=0;i<np;i++)
{
   S=S+sz[i];
}
//printf("total size is %d",S);

    int fr,p;
   printf("\nenter the choice of your allocation : ");
   printf("\n\t1.EQUAL ALLOCATION\n\t2.PROPORTIONAL ALLOCATION\n\t3.PRIORITY ALLOCATION\n\t4.EXIT");
   scanf("%d",&choice);
while(1)
{
   if(choice==1)
{
   printf("\n IN EQUAL ALLOCATION\n");

   fr=nf/np;
   f=fr;
   printf("NUMBER OF FRAMES ALLOCATED TO EACH PROCESS ARE : %d\n",f);
   printf("\n\nOutput for fifo algorithm with the allocated frames is :\n");
   for(i=0;i<f;i++)
   {
   F[i]=-1;
   }
   fifo(s,F,l,f);
   printf("\n output for LRU algorithm with the allocated frames is:\n");
   for(i=0;i<f;i++)
   {
   F[i]=-1;
   }
   lru(s,F,l,f);
   printf("\n output for optimal algorithm with the allocated frames is : \n");
   for(i=0;i<f;i++)
   {
   F[i]=-1;
   }
   opt(s,F,l,f);
   printf("\n output for lfu algorithm with the allocated frames is : \n");
   for(i=0;i<f;i++)
   {
   F[i]=-1;
   }
   lfu(s,F,l,f);
}  

   if(choice==2)  // proportional
{ 
int j;
for(j=0;j<np;j++)
{
printf("IN PROPORTIONAL ALLOCATION :");
printf("FRAMES ALLOCATED FOR PROCESS %d ARE \t",j+1);
f=((sz[j]*nf)/S);  // size of process/total size * total no. of frames

printf("  %d\n ",f);
printf("\n\nFIFO page replacement algorithm\t");
for(i=0;i<f;i++)
   {
   F[i]=-1;
   }
fifo(s,F,l,f);
printf("\noptimal page replacement algorithm\t");
for(i=0;i<f;i++)
{
F[i]=-1;
}
opt(s,F,l,f);
printf("\nLRU page replacement algorithm\t");
for(i=0;i<f;i++)
{
F[i]=-1;
}
lru(s,F,l,f);
printf("\nLFU page replacement algotithm\t");
for(i=0;i<f;i++)
{
F[i]=-1;
}
lfu(s,F,l,f);
}
}

if(choice==3)
{

int j;
for(j=0;j<np;j++)
{
f=((pr[j]*nf)/S);
printf("\nIN PRIORITY ALLOCATION:\n");
printf("\nNUMBER OF FRAMES ALLOCATED TO EACH PROCESS %d ARE   %d \n",j+1,f);
printf("\nin FIFO page replacement algorithm\t");

for(i=0;i<f;i++)
{
F[i]=-1;
}
fifo(s,F,l,f);
printf("\noptimal page replacement algorithm\n");
for(i=0;i<f;i++)
{
F[i]=-1;
}
opt(s,F,l,f);
printf("\nLRU page replacement algorithm\n");
for(i=0;i<f;i++)
{
F[i]=-1;
}
lru(s,F,l,f);
printf("\nLFU page replacement algotithm\t");
for(i=0;i<f;i++)
{
F[i]=-1;
}
lfu(s,F,l,f);
}

}

if(choice==4)
exit(0);
printf("\nenter the choice of your allocation : ");
   printf("\n\t1.EQUAL ALLOCATION\n\t2.PROPORTIONAL ALLOCATION\n\t3.PRIORITY ALLOCATION\n\t4.EXIT");
   scanf("%d",&choice);
}   
 }  


//fifo
void fifo(char s[],char F[],int l,int f)
{
   int i,j=0,k,flag=0,cnt=0;
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
        flag=1;
    }

       if(flag==0)
    {
      printf("\n\t%c\t",s[i]);
      F[j]=s[i];
      j++;

      for(k=0;k<f;k++)
       {
        printf(" %c",F[k]);
       }
      printf("\tPage-fault%d",cnt);
      cnt++;
    }

       else
    {
      flag=0;
      printf("\n\t%c\t",s[i]);
      for(k=0;k<f;k++)
       {
        printf("%c",F[k]);
       }

      printf("\tNO page-fault");
    }
       if(j==f)
    j=0;
    }

}

//LRU
void lru(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,top=0;
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
       {
        flag=1;
         break;
       }
    }

       printf("\n\t%c\t",s[i]);
       if(j!=f && flag!=1)
    {
      F[top]=s[i];
      j++;

      if(j!=f)
       top++;
    }
       else
    {
       if(flag!=1)
        {
          for(k=0;k<top;k++)
           {
        F[k]=F[k+1];
           }

           F[top]=s[i];
        }
       if(flag==1)
        {
           for(m=k;m<top;m++)
           {
        F[m]=F[m+1];
           }

           F[top]=s[i];
        }
    }
       for(k=0;k<f;k++)
    {
     printf("   %c",F[k]);
    }

       if(flag==0)
    {
      printf("\tPage-fault%d",cnt);
      cnt++;
    }
       else
     printf("\tNo page fault");
       flag=0;
    }

}

//optimal
void opt(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,temp[10];

   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<10;i++)
     temp[i]=0;

   for(i=0;i<f;i++)
     F[i]=-1;

   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
        flag=1;
    }

       if(j!=f && flag==0)
    {
      F[j]=s[i];
      j++;
    }

       else if(flag==0)
    {
       for(m=0;m<f;m++)
        {
          for(k=i+1;k<l;k++)
           {
          if(F[m]!=s[k])
           {
             temp[m]=temp[m]+1;
           }
          else
           break;
           }
        }
       m=0;
       for(k=0;k<f;k++)
        {
           if(temp[k]>temp[m])
        {
          m=k;
        }
        }

       F[m]=s[i];
    }

       printf("\n\t%c\t",s[i]);
       for(k=0;k<f;k++)
    {
       printf("  %c",F[k]);
    }
       if(flag==0)
    {
      printf("\tPage-fault %d",cnt);
      cnt++;
    }
       else
     printf("\tNo Page-fault");
       flag=0;

       for(k=0;k<10;k++)
     temp[k]=0;
     }
}


//lfu
void lfu(char s[],char F[],int l,int f)
{

int i,j=0,k,ch,c,a1=0,a,line=6,nk;
          int st,ps,pos;
         for(i=0;i<f;i++)
          F[i]=-1;
          st=100;
          for(i=0;i<l;i++)
          {
                   a1=0;
                   st=100;
                   pos=100;
                   for(c=0;c<f;c++)
                   if(s[i]==F[c])
                   a1++;
                   if(a1==0)
                   {
                             if(j<f)
                             {
                                      F[j]=s[i];
                                      j++;
                             }
                             else
                             {
                                      for(k=0;k<f;k++)
                                      {
                                                a=0;
                                                for(ch=i;ch>=0;ch--)
                                                {
                                                          if(F[k]==s[ch])
                                                          {
                                                                   a++;
                                                                   nk=ch;
                                                          }
                                                }
                                                if(a>1)
                                                {
                                                          if(st>a)
                                                          {
                                                                   st=a;
                                                                   ps=k;
                                                          }
                                                          else
                                                          if(st==a)
                                                          {
                                                                   if(pos>ch)
                                                                   ps=k;
                                                          }
                                                }
                                                else
                                                if(a==1)
                                                {
                                                          if(pos>nk)
                                                          {
                                                                   pos=nk;
                                                                   ps=k;
                                                                   st=a;
                                  
                        }
                                                }
                                      }
                                      F[(ps)]=s[i];
                             }
                   }
                   display(f,s,F,i);
          }
          printf("\n");

}

void display(int f,char s[],char F[],int i)
{
          int k;
          if(i==1)
          {
                   printf("\t\t\t");
                   for(k=0;k<f;k++)
                   printf("_ _");
          }
          printf("\n%c",s[i]);
 
          for(k=0;k<f;k++)
          {
                   printf("|");
                   printf("_");
                   if(F[k]!=-1)
                   printf("%c",F[k]);
                   else
                   printf(" ");
                   printf("_");
          }
          printf("|");
}




