#include<stdio.h>
#include<string.h>
int min(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
int main()
{
    char arr[1000]="abbababba";
    int l[10];
    int start=0,end=0,i=0,j;
    for(i=0;i<9;i++)
    {
        l[i]=1;
    }
    while(i<strlen(arr))
    {
        //to find the start and end of a palindromic string.
    while(start>0&&end<(strlen(arr)-1)&&arr[start-1] == arr[end+1])
    {
        start--;  //2
        end++;    //4
    }
    int newcenter=i+1;  //1 //2  //3  //4  //5

    l[i]=end-start+1;  //l[0]=1  //l[1]=1  //l[2]=1  //l[3]=3  //l[4]=9

    for(j=i+1;j<=end;j++)
    {
       // if((j+l[i-(j-i)]/2)<end)
//{
       //    l[j]=l[j-i];
       // }
        //else

        if((j+l[i-(j-i)]/2)==end)
        {
            newcenter=j;
        }
        else
        {
            l[j]=min(l[i-(j-i)],(1+(end-j)*2));//l[5]=3;
        }
    }
    i=newcenter;    //i=1  //i=2  //i=3;  //i=4;
    start=i-l[i]/2;  //start=1;  //start=2  //start=3  //start=4
    end=j-l[j]/2;    //end=1;    //end=2;   //end=3;   //end=4
    }
     for(i=0; i<=strlen(arr)); i++)
        printf("%c", l[i]);
}

