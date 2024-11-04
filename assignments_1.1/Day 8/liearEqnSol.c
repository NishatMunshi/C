/*
Write a menu-driven program for solving a system of linear equations given below
using
a. Gauss-Elimination method
b. Gauss Elimination with pivoting method
c. Jacobi’s method

Use the following system of equations-
i. 	x+y+z=6 	ii. x+y+z=3 	iii. 2x+4y+2z=15
	x+y−z=0 		2x+3y+z=6 		 2x+y+2z=−5
	x−y+z=2 		x−y−z=−3 		 4x+y−2z=0
*/

#include <stdio.h>
#include <stdlib.h>

void gauss1(){
    float a[3][4]={{1,1,1,6},{1,1,-1,0},{1,-1,1,2}}, x[3], ratio;
	 int i,j,k,n=3;
	 for(i=1;i<=n-1;i++){
		  if(a[i][i] == 0.0){
			   printf("\nDivergent");
			   return;
		  }
		  for(j=i+1;j<=n;j++){
			   ratio = a[j][i]/a[i][i];
			   for(k=1;k<=n+1;k++){
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--){
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++){
		  	x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
	 printf("\nSolution:\n");
	 for(i=1;i<=n;i++)
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	 return;
}
void gauss2(){
    float a[4][5]={{0,0,0,0,0},{0,1,1,1,3},{0,2,3,1,6},{0,1,-1,-1,-3}}, x[10], ratio;
	 int i,j,k,n=3;
	 for(i=1;i<=n-1;i++){
		  if(a[i][i] == 0.0){
			   printf("\nDivergent");
			   return;
		  }
		  for(j=i+1;j<=n;j++){
			   ratio = a[j][i]/a[i][i];
			   for(k=1;k<=n+1;k++){
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--){
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++){
		  	x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
	 printf("\nSolution:\n");
	 for(i=1;i<=n;i++)
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	 return;
}
void gauss3(){
    float a[4][5]={{0,0,0,0,0},{0,2,4,2,15},{0,2,1,2,-5},{0,4,1,-2,0}}, x[10], ratio;
	 int i,j,k,n=3;
	 for(i=1;i<=n-1;i++){
		  if(a[i][i] == 0.0){
			   printf("\nDivergent");
			   return;
		  }
		  for(j=i+1;j<=n;j++){
			   ratio = a[j][i]/a[i][i];
			   for(k=1;k<=n+1;k++){
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--){
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++){
		  	x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
	 printf("\nSolution:\n");
	 for(i=1;i<=n;i++)
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	 return;
}
void gausspivot1(){
    int n=3,i,j,k,temp;
    float a[3][4]={{1,1,1,6},{1,1,-1,0},{1,-1,1,2}},c,d[10]={0};
    for(i=n-1;i>0;i--){
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++){
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++){
            c=(a[i+1][k]/a[k][k]);
            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }
    for(i=n-1;i>=0;i--){
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            if (a[i][i]==0.0){
                    printf("\nDivergent condition");
                    return;
            }

        d[i]=(a[i][n]-c)/a[i][i];
    }
    printf("\nSolution:\n");
    for(i=0;i<n;i++)
    printf("%.3f\n",d[i]);
    return;
}
void gausspivot2(){
    int n=3,i,j,k,temp;
    float a[3][4]={{1,1,1,3},{2,3,1,6},{1,-1,-1,-3}},c,d[10]={0};
    for(i=n-1;i>0;i--){
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++){
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++){
            c=(a[i+1][k]/a[k][k]);
            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }
    for(i=n-1;i>=0;i--){
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            if (a[i][i]==0.0){
                    printf("\nDivergent condition");
                    return;
            }

        d[i]=(a[i][n]-c)/a[i][i];
    }
    printf("\nSolution:\n");
    for(i=0;i<n;i++)
    printf("%.3f\n",d[i]);
    return;
}
void gausspivot3(){
    int n=3,i,j,k,temp;
    float a[3][4]={{2,4,2,15},{2,1,2,-5},{4,1,-2,0}},c,d[10]={0};
    for(i=n-1;i>0;i--){
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++){
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++){
            c=(a[i+1][k]/a[k][k]);
            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }
    for(i=n-1;i>=0;i--){
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            if (a[i][i]==0.0){
                    printf("\nDivergent condition");
                    return;
            }

        d[i]=(a[i][n]-c)/a[i][i];
    }
    printf("\nSolution:\n");
    for(i=0;i<n;i++)
    printf("%.3f\n",d[i]);
    return;
}
void jacobi1(){
    int i,j,n;
    float a1,b1,c1;
    float a,b,c;
    float ar[3][4]={{1,1,1,6},{1,1,-1,0},{1,-1,1,2}},x[3];
    printf("Enter the no. of Iteration : ");
    scanf("%d",&n);
    printf("Enter The initial value : ");
    scanf("%f %f %f",&a,&b,&c);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a1=6-b-c;
            b1=c-a;
            c1=b+2-a;
            a=a1;
            b=b1;
            c=c1;
        }
    }
    printf("\nHence condition is divergent\n");
    return;
}
void jacobi2(){
    int i,j,n;
    float a1,b1,c1;
    float a,b,c;
    float ar[3][4]={{1,1,1,3},{2,3,1,6},{1,-1,-1,-3}},x[3];
    printf("Enter the no. of Iteration : ");
    scanf("%d",&n);
    printf("Enter The initial value : ");
    scanf("%f %f %f",&a,&b,&c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a1=3-b-c;
            b1=(6-a*2-c)/3;
            c1=3+a-b;
            a=a1;
            b=b1;
            c=c1;
        }
    }
    printf("\n%f\n%f\n%f",a1,b1,c1);
    return;
}
void jacobi3(){
    int i,j,n;
    float a1,b1,c1;
    float a,b,c;
    float ar[3][4]={{2,4,2,15},{2,1,2,-5},{4,1,-2,0}},x[3];
    printf("Enter the no. of Iteration : ");
    scanf("%d",&n);
    printf("Enter The initial value : ");
    scanf("%f %f %f",&a,&b,&c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a1=(c*2-b)/4;
            b1=(15-a*2-c*2)/4;
            c1=(-5-a*2-b)/2;
            a=a1;
            b=b1;
            c=c1;
        }
    }
    printf("\n%f\n%f\n%f",a1,b1,c1);
    return;
}
void main(){
	int ch1,ch2,i,j;
	do{
	system("cls");
	printf("\n1.\tx+y+z=6\t\tx+y-z=0\t\tx-y+z=2");
	printf("\n2.\tx+y+z=3\t\t2x+3y+z=6\tx-y-z=-3");
	printf("\n3.\t2x+4y+2z=15\t2x+y+2z=-5\t4x+y-2z=0");
	printf("\n4.\tExit");
	printf("\nEnter system to solve:\t");
	scanf("%d",&ch1);
	switch(ch1){
		case 1:
			printf("\n1. Guass elimination\n2. Guass elimination with pivoting\n3. Jacobi iteration\nEnter method for solving:\t");
			scanf("%d",&ch2);
			switch(ch2){
				case 1:
					gauss1();
					break;
				case 2:
					gausspivot1();
					break;
				case 3:
					jacobi1();
					break;
				default:
					printf("\n Wrong choice!");
					break;
			}
			break;
		case 2:
			printf("\n1. Guass elimination\n2. Guass elimination with pivoting\n3. Jacobi iteration\nEnter method for solving:\t");
			scanf("%d",&ch2);
			switch(ch2){
				case 1:
					gauss2();
					break;
				case 2:
					gausspivot2();
					break;
				case 3:
					jacobi2();
					break;
				default:
					printf("\n Wrong choice!");
					break;
			}
			break;
		case 3:
			printf("\n1. Guass elimination\n2. Guass elimination with pivoting\n3. Jacobi iteration\nEnter method for solving:\t");
			scanf("%d",&ch2);
			switch(ch2){
				case 1:
					gauss3();
					break;
				case 2:
					gausspivot3();
					break;
				case 3:
					jacobi3();
					break;
				default:
					printf("\n Wrong choice!");
					break;
			}
			break;
		case 4:
			exit(0);
		default:
			printf("\n Wrong choice!");
			break;
	}
	printf("\n\n1. Repeat\n0. Exit\nEnter choice:\t");
	scanf("%d",&ch1);
}while(ch1);
}