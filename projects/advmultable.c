#include <stdio.h>
int main()
{
   int i, j;
   while (1)
   {
      printf("Please enter the number whose multiplication table you would like to see\n");
      scanf("%d", &j);
      if (j!=0)
      {
         for (i = 1; i <= 10; i++)
      {
         printf("%dx%d=%d\n", j, i, i * j);
      }
      }
      else
      {
         break;
      }
   }

   return 0;
}