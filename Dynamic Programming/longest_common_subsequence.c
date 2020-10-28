#include<stdio.h>

#include<string.h>

int main() {
    char X[15], Y[15], sub_s[15];
    int len_x, len_y, i, j, k = 0, count_sub = 0, temp, arr[15][15];
    do{
        printf("\n\nEnter String X : ");
        gets(X);
        printf("Enter String Y : ");
        gets(Y);
        len_x = strlen(X);
        len_y = strlen(Y);
        for (i = 0; i < 15; i++)
            for (j = 0; j < 15; j++)
                arr[i][j] = 0;
        for (i = 1; i <= len_x; i++) {
            for (j = 1; j <= len_y; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                } else if (arr[i - 1][j] >= arr[i][j - 1]) {
                    arr[i][j] = arr[i - 1][j];
                } else {
                    if (arr[i - 1][j] > arr[i][j - 1])
                        arr[i][j] = arr[i - 1][j];
                    else
                        arr[i][j] = arr[i][j - 1];
                }
            }
        }
        printf("\n ");
          printf("   ");
        for (i = 0; i < len_y; i++) {
            printf("%c ", Y[i]);
        }
        printf("\n----");
        for (i = 0; i < len_y; i++) {
            printf("--");
        }
        for (i = 1; i <= len_x; i++) {
            printf("\n%c | ", X[i - 1]);
            for (j = 1; j <= len_y; j++)
                printf("%d ", arr[i][j]);
        }
        temp = arr[--i][--j];
        i--;
        j--;
        while (count_sub != temp && i >= 0 && j >= 0) {
            if (X[i] == Y[j]) {
                sub_s[k] = Y[j];
                count_sub++;
                i--;
                j--;
                k++;
                continue;
            }
            if (arr[i + 1][j] > arr[i][j + 1]) {
                j--;
                continue;
            }
            if (arr[i + 1][j] <= arr[i][j + 1]) {
                i--;
            }
        }
        printf("\n\nHighest common Subsequence is : %s", strrev(sub_s));
    }while(1);
    return 0;
}


