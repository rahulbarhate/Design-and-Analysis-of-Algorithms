#include <stdio.h>
#include <stdlib.h>

int x[100],cnt=0 ;

int place(int k,int i)                                          
{
    int j;

    for(j=0;j<k;j++)
    {
        if((x[j] == i) || ((abs(x[j] - i) == abs(j-k))))
        {
            return 0;
        }
    }

    return 1;
}

void Nqueen(int k,int n)
{
    int i,a,b;

    for(i=0;i<n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;

            for(a=0;a<n;a++)
            {
                for(b=0;b<n;b++)
                {
                    if(x[a] == b)
                    {
                        printf(" Q%d ",a+1);
                    }
                        
                    else
                        printf(" 0 ");
                }
                    printf("\n");
            }

            printf("\n\n");

            if(k==(n-1))
            {
                cnt++;
                printf("\n------Solution %d ------\n",cnt);

                for(a=0;a<n;a++)
                {
                    for(b=0;b<n;b++)
                    {
                        if(x[a] == b)
                        {
                            printf(" Q%d ",a+1);
			   
                        }
                        
                        else
                            printf(" 0 ");
			
                    }
                    printf("\n");

                }
		printf("\n---------------------------\n");
                printf("\n\n");
		 
            }

            else
            {
                Nqueen(k+1,n);
            }
        }
    }
}

int main(void) 
{
    int n;
    printf("Enter no. of queens : ");
    scanf("%d",&n);

    Nqueen(0,n);
    return EXIT_SUCCESS;
}
