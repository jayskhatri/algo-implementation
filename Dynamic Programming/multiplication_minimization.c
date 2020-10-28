#include<stdio.h>

void print(int val[10][10], int start, int finish) {
   if (start == finish)
      printf("A%d ", start);
   else {
      printf("( ");
      print(val, start, val[start][finish - 1] + 1);
      print(val, finish, val[start][finish] + 1);
      printf("\b) ");
   }
}
int main() {
   int arr[10][2], p[10], ans[10][10], k_val[10][10];
   int i, j, k, n, min;
   printf("Enter No. of matrices : ");
   scanf("%d", & n);
   for (i = 0; i < n; i++) {
      printf("Enter Row of matrix %d : ", (i + 1));
      scanf("%d", & arr[i][0]);
      printf("Enter Column of matrix %d : ", (i + 1));
      scanf("%d", & arr[i][1]);
   }
   for (i = 0, j = 0; i < n; i++, j++) {
      p[j] = arr[i][0];
      if (i == n - 1) {
         p[++j] = arr[i][1];
      }
   }
   for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++) {
         ans[i][j] = -1;
         k_val[i][j] = -1;
      }
   for (i = 1; i <= n; i++)
      for (j = 1; j <= i; j++)
         if (i == j) {
            ans[i][j] = 0;
            k_val[i][j] = 0;
         }
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i && j != i; j++) {
         k = j;
         min = 999;
         while (k < i) {
            ans[j][i] = ans[j][k] + ans[k + 1][i] + (p[i] * p[j - 1] * p[k]);
            if (ans[j][i] < min) {
               min = ans[j][i];
               k_val[j][i] = i - 1;
               //printf("\n(%d,%d) : \tAns : %d and K_val : %d",j,i,ans[j][i],k_val[j][i]);
            }
            k++;
         }
      }
   }
   printf("\n\nAnswer Table : ");
   for (i = 1; i <= n; i++) {
      printf("\n");
      for (j = 1; j <= i; j++) {
         printf("%d ", ans[j][i]);
      }
   }
   printf("\n\nK Table : ");
   for (i = 1; i <= n; i++) {
      printf("\n");
      for (j = 1; j <= i; j++) {
         printf("%d ", k_val[j][i]);
      }
   }
   printf("\n\nMultiplication Order is : ");
   print(k_val, 1, n);
   return 0;
}
