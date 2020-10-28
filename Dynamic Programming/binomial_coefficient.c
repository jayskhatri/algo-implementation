#include<stdio.h>
int main(){
    int n,k,i,j,arr[50][50];
        do{printf("\n\nEnter N : ");
        scanf("%d",&n);
        printf("Enter K : ");
        scanf("%d",&k);
        for(i=0;i<n;i++){
                for(j=0;j<=k;j++){
                    if(i+1==j || j==0){
                        arr[i][j]=1;
                    }
                    else if(i+1>=j){
                        arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                    }
                }
        }
        for(i=0;i<n;i++){
            for(j=0;j<=k;j++){
                printf("%d\t",arr[i][j]);
        }
            printf("\n");
        }
        printf("\nOutput of C(%d , %d) is : %d",n,k,arr[i-1][j-1]);
    }while(1);
    return 0;
}

