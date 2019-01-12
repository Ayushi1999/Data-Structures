#include<stdio.h>
void reverse(char str[])
{
    int i=0,j=0;
    int k=0;
    char temp;
    char str1[100][100];
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
             str1[k][j]='\0';
             k++;
             j=0;
        }
        else
        {
            str1[k][j]=str[i];
            j++;
        }
    }
    str1[k][j]='\0';
    char temp3[10];
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-i-1;j++)
        {
            if(strcmp(str1[j],str1[j+1])>0)
            {
                strcpy(temp3,str1[j]);
                strcpy(str1[j],str1[j+1]);
                strcpy(str1[j+1],temp3);
            }
        }
    }
/*    i=0;
  int  p=0;
   // k=0;

   j=k;
    char str2[1000];
    while(j>=0)
    {
        i=0;
        while(str1[j][i]!='\0')
        {
            str2[p++]=str1[j][i];
            i++;
        }
        j--;
    }*/
   /* for(i=0;i<=k;i++)
    {
      int  len=strlen(str1[i]);
       for(j=0,x=len-1;j<len/2;j++,x--)
       {
           temp=str1[i][j];
           str1[i][j]=str1[i][x];
           str1[i][x]=temp;
       }
      // str2[p]=str1[i];
    }*/

 /*   char temp1;
     k=0;
    for(i=0;i<strlen(str);i++)
    {
        for(j=0;j<strlen(str);j++)
        {
            str[k]=str1[i][j];
            k++;
        }
    }
    str[k]='\0';*/
   /* for(i=0,j=strlen(str)-1;i<strlen(str1)/2;i++,j--)
    {
        temp1=str[i];
        str[i]=str[j];
        str[j]=temp1;
    }*/
    for(i=0;i<k;i++)
    {
        printf("%c ",str1[i]);
    }
  /*  while(i<strlen(str)/2)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }  */
}
int main()
{
    char str[]="hello how are you";
    reverse(str);
}
