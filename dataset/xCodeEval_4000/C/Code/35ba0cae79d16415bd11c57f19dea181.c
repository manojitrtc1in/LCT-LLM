#include<stdio.h>
#include<math.h>
#include<stdlib.h>








    

    

   
    


     
int main()
{

















   


    
       

     

    



      

























               










   


int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);

}
int c=0;
int l=0;
int max=1;
for(int i=1;i<n;i++)
{

    if(a[i]==a[i-1])
        l++;

}
if(l==n-1)

    printf("1");
else{

for(int i=1;i<n;i++)
{

    if(a[i]>a[i-1])
    {

        c++;
        if(c+1>max)
        {

            max=c+1;
        }

    }
    else
        {
        c=0;
    }

}

printf("%d",max);
}
return 0;
}


