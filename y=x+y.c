#include<stdio.h>
#include<math.h>
void main(){
    printf("The differential equation is : y''=x+y\n");
    printf("Initial values are y(0)=y(1)=0 , h=0.25\n");
    int n=4,i;                   //  n=(1-0)/h
    float A[n],B[n],C[n],D[n],h=0.25;
    for(i=1;i<=n-1;i++){
        A[i]=1;
        B[i]=0;
        C[i]=-1;
        D[i]=h*i;
    }
    float a[n],b[n],c[n],d[n];
    for(i=1;i<=n-1;i++){
        a[i]=(A[i]/(h*h))-(B[i]/(2*h));
        b[i]=C[i]-((2*A[i])/(h*h));
        c[i]=(A[i]/(h*h))+(B[i]/(2*h));
    }
    float y[n+1];
    y[0]=0;y[n]=0;
    d[1]=D[1]-(y[0]*a[1]);
    d[n-1]=D[n-1]-(y[n]*c[n-1]);
    for(i=2;i<=n-2;i++)
        d[i]=D[i];
    float cdash[n],ddash[n];
    cdash[1]=c[1]/b[1];
    ddash[1]=d[1]/b[1];
    for(i=2;i<=n-1;i++){
        cdash[i]=c[i]/(b[i]-(a[i]*cdash[i-1]));
        ddash[i]=(d[i]-(a[i]*ddash[i-1]))/(b[i]-(a[i]*cdash[i-1]));
    }
    y[n-1]=ddash[n-1];
    for(i=n-2;i>=1;i--)
        y[i]=ddash[i]-(cdash[i]*y[i+1]);
    for(i=0;i<=n;i++)
        printf("y[%d]= %f\n",i,y[i]);
    return;