#include<stdio.h>
int main() {
   int item, capacity, temp, i, j, count;
   int weight_value[10][2], arr[10][10], quantity[10];
   do{
       printf("\n\nEnter Total No. of items : ");
       scanf("%d", & item);
       printf("Enter Total Capacity : ");
       scanf("%d", & capacity);
       for (i = 0; i < item; i++) {
          printf("Enter Value and Weight for item %d : ", (i + 1));
           scanf("%d", & weight_value[i][1]);
          scanf("%d", & weight_value[i][0]);


          quantity[i] = 0;
       }
       for (i = 0; i < item; i++) {
          for (j = 0; j < item - i - 1; j++) {
             if (weight_value[j][0] > weight_value[j + 1][0]) {
                temp = weight_value[j][0];
                weight_value[j][0] = weight_value[j + 1][0];
                weight_value[j + 1][0] = temp;
                temp = weight_value[j][1];
                weight_value[j][1] = weight_value[j + 1][1];
                weight_value[j + 1][1] = temp;
             }
          }
       }
       for (i = 0; i < item; i++) {
          count = weight_value[i][0];
          for (j = 0; j <= capacity; j++) {
             if (j == 0) {
                arr[i][j] = 0;
             }
             if (i == 0 && j != 0) {
                arr[i][j] = weight_value[i][1];
             }
             if (j < weight_value[i][0]) {
                arr[i][j] = arr[i - 1][j];
             }
             if (j == weight_value[i][0] && i != 0) {
                if (weight_value[i][1] > arr[i - 1][j]) {
                   arr[i][j] = weight_value[i][1];
                } else {
                   arr[i][j] = arr[i - 1][j];
                }
             }
             if (j > weight_value[i][0] && i != 0) {
                if (arr[i - 1][j] < (arr[i][j - weight_value[i][0]] + weight_value[i][1]) && count != 0) {
                   arr[i][j] = arr[i][j - weight_value[i][0]] + weight_value[i][1];
                   count--;
                } else if (arr[i - 1][j] > (arr[i][j - weight_value[i][0]] + weight_value[i][1]) && count != 0) {
                   arr[i][j] = arr[i - 1][j];
                   count--;
                }
                if (count == 0) {
                   arr[i][j] = arr[i][j - 1];
                }
             }
          }
       }
       i = item - 1;
       for (j = capacity; j > -1 && arr[i][j] != 0; j -= weight_value[i][0]) {
          if (i == 0) {
             quantity[i] = 1;
          } else {
             if (arr[i][j] == arr[i - 1][j]) {
                while (arr[i][j] == arr[i - 1][j] && i >= 1) {
                   i--;
                }
             }
             quantity[i] = 1;
          }
       }
       printf("\n\nValue Weight |");
       for (i = 0; i <= capacity; i++) {
          printf(" %5d", i);
       }
       printf("\n");
       for (i = 0; i <= 7 * capacity + 16; i++)
          printf("-");
       for (i = 0; i < item; i++) {
          printf("\n%4d %8d | ", weight_value[i][1], weight_value[i][0]);
          for (j = 0; j <= capacity; j++) {
             printf("%5d ", arr[i][j]);
          }
       }
       printf("\n\nItem Vector : ( ");
       for (i = 0; i < item; i++) {
          printf("%d , ", quantity[i]);
       }
       printf("\b\b )");
   }while(1);
   return 0; 
}
