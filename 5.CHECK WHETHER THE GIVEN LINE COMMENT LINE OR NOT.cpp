#include<stdio.h>
int main()
{
char a[30];
int i=2,b=0;

printf("\n Enter Text : ");

gets(a);
if(a[0]=='/')
{
if(a[1]=='/')

printf("\n It is a Comment.");

else if(a[1]=='*')
{
for(i=2;i<=30;i++)
{
if(a[i]=='*'&&a[i+1]=='/')
{
printf("\n It is a Comment.");
b=1;
break;
}
else continue;
}
if(b==0)

printf("\n It is Not a Comment.");
}
else

printf("\n It is Not a Comment.");

}
else

printf("\n It is Not a Comment.");

}
