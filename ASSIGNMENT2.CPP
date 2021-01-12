Question 1
Write a program to print the following pattern
1
2*2
3*3*3
4*4*4*4

Solution: #include<stdio.h>
using namespace std;
int main()
{
 int i,j,n;
 cin>>n;
 for(i=1;i<=n;i++){
   for(j=1;j<=i;j++){
     if(j<i)
       cout<<i<<"*";
     else
       cout<<i;
     return 0;
   }





Question 2
Write a program to print the following pattern
1
01
101
0101
10101
Solution:
#include<stdio.h>
#include<conio.h>
void main()
{
int i, j, n;
clrscn()’
printf(“\n Enter the value of n”);
scanf(“%d”&n);
for(i=0; i<n; i++);
{
for(j=0; j<1; j++)
{
if((i+j)%2==0)
{
printf(“\t0”);
}
else
{
printf(“\t1”);
}
 }
printf(“\n”);
}
getch();
}



