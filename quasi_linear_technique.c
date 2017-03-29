CODE:-

#include <stdio.h>
#include <math.h>
#define SIZE 20
int main()
{
    int i,k,l;
    float B[SIZE], X[SIZE], Y[SIZE];
    float A[SIZE][SIZE], D[SIZE];
    int delta_x;
    int count = 1;
    printf("                                      Solving Boundary Value Problem using Quasi Linearization Technique: \n");
    printf("                                      x belongs to the internval (1,2) \n");
    printf("                                      y(1) = 2 \n");
    printf("                                      y(2) = 4 \n");
    printf("                                      Question is y'' + 2yy' = 4 + 4x^3 \n");
    printf("=========================================================================================================\n");
    printf("Assuming that the numerator of h is 1\t Enter the denominator of h: ");
    scanf("%d",&delta_x);
    l = (delta_x)*(delta_x);
    for(i=0;i<=delta_x;i++)
            B[i] = 2 + (2*i)/(float)(delta_x);
    for(i=1;i<delta_x;i++)
                                X[i] = (1 + i/(float)delta_x)*(1 + i/(float)delta_x)*(1 + i/(float)delta_x);
do{
        count = 0;
        A[0][0] = (-2)*l + (B[2] - B[0])*(delta_x);
        A[0][1] = l + B[1]*delta_x;
        D[0] = 4 + 4*X[1] + B[1]*(B[2]-B[0])*delta_x - (B[0]*(l - B[1]*delta_x));                    for(i=2;i<delta_x-1;i++)
{    
            A[i-1][i-2] = l - B[i]*(delta_x);
            A[i-1][i-1] = (-2)*l + (B[i+1] - B[i-1])*(delta_x);
            A[i-1][i] = l + B[i]*(delta_x);
            D[i-1] = 4 + 4*X[i] + B[i]*(B[i+1]-B[i-1])*delta_x;
        }
        
        A[delta_x-2][delta_x-3] = l - B[delta_x-1]*(delta_x);
        A[delta_x-2][delta_x-2] = (-2)*l + (B[delta_x] - B[delta_x-2])*(delta_x);
                     D[delta_x-2] = 4 + 4*X[delta_x-1] + B[delta_x-1]*(B[delta_x]-B[delta_x-       2])*delta_x - (B[delta_x]*(l + B[delta_x-1]*delta_x));
// thomas algorithm starts    


        A[0][1] = A[0][1]/A[0][0];
        D[0]    = D[0]/A[0][0];
        for(k=1;k<delta_x-2;k++)
        {
            A[k][k+1] = A[k][k+1] / (A[k][k] - A[k][k-1]*A[k-1][k]);
            D[k]      = (D[k] - A[k][k-1]*D[k-1]) / (A[k][k] - A[k][k-1]*A[k-1][k]);            }            
                int h = delta_x-1;
D[h-1] = (D[h-1] - A[h-1][h-2]*D[h-2])/ (A[h-1][h-1] - A[h-2][h-1]*A[h-1][h-2]) ;         Y[h] = D[h-1];
for(k=h-2;k>=0;k--)
Y[k+1] = D[k] - A[k][k+1]*Y[k+2] ;
        for(i=1;i<=h;i++)
            {
if((B[i] - Y[i]) > 0.00001 || (Y[i]-B[i]) > 0.00001)
                    {
                        count = 1;                                break;
}
}
for(i=1;i<=h;i++)
            B[i] = Y[i];
        }while(count != 0);

    Y[0] = 2;
    Y[delta_x] = 4;
    for(i=0;i<=delta_x;i++)
           printf("Y[%0.2f] = %0.3f\n",(1 + i/(float)delta_x),Y[i]);
    printf("\n");
           return 1;
}