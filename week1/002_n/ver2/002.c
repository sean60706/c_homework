#include<stdio.h>




int input(float x[][101]){
    int n=0;
    int i,g=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(g=0;g<n+1;g++){
            scanf("%f",&x[i][g]);
        }
    }


    return n;
}
void printLamda(int n,float lamda[]){//印出結果
    int i,g=0;
    /*for(i=0;i<n;i++){
        for(g=0;g<n+1;g++){
            printf("%f\t",x[i][g]);
        }
        printf("\n");
    }*/

    for(i=0;i<n;i++){
        if(i==n-1){
            printf("X[%d] = %.3f",i+1,lamda[i]);
        }else{
            printf("X[%d] = %.3f\n",i+1,lamda[i]);
        }

    }

}

void guess_tri(int n,float x[][101]){//使用高斯消去法將原始陣列變成三角形的狀態
 /*
三角形:
x00 x01 x02 x03
0   x11 x12 x13
0   0   x22 x23
 */

    int i,g,each;
    float temp;//為了解決可能出現分母為0的情況，所以需要遇到上方第一列第一個數值為0時，要互換
    float a,b;//a是上方列的第一個數值，b是下方列的第一個數值
    for(i=0;i<n-1;i++){
        for(g=i+1;g<n;g++){
            a=x[i][i];
            b=x[g][i];
            if(a==0 && b!=0){//互換
                //printf("change   i=%d,g=%d\n",i,g);
                for(each=0;each<n+1;each++){
                    temp=x[i][each];
                    x[i][each]=x[g][each];
                    x[g][each]=temp;
                }
            }else if(b!=0){
                //printf("------   i=%d,g=%d\n",i,g);
                for(each=0;each<n+1;each++){
                    x[i][each]*=b;
                    x[g][each]*=a;
                    x[g][each]-=x[i][each];
                }
            }
            //printf("======\n");
            //printData(n,x);
            //printf("======\n");
        }
    }

}
void guess_lamda(int n,float x[][101],float lamda[]){
    int i,g;
    lamda[n-1]=x[n-1][n]/x[n-1][n-1];

    for(i=n-2;i>=0;i--){
        lamda[i]=x[i][n];
        for(g=n-1;g>i;g--){
            lamda[i]-=lamda[g]*x[i][g];
        }
        lamda[i]/=x[i][i];
    }

    for(i=0;i<n;i++){
        if(x[i][n]==0){
            lamda[i]=0;
        }
    }


}
void printData(int n,float x[][101]){
    int i,g;
    for(i=0;i<n;i++){
        for(g=0;g<n+1;g++){
            if(g!=n){

                if(x[i][g]<0){
                    if(g==0){
                        printf("%.3f X%d ",x[i][g],g+1);
                    }else{
                        printf("- %.3f X%d ",-x[i][g],g+1);
                    }


                }else{
                    if(g==0){
                        printf("%.3f X%d ",x[i][g],g+1);
                    }else{
                        printf("+ %.3f X%d ",x[i][g],g+1);
                    }


                }



            }else if(g==n){
                printf("= %.3f",x[i][g],g+1);
            }


        }
        printf("\n");
    }


    /*for(i=0;i<n;i++){
        for(g=0;g<n;g++){
            if(x[i][g]>0&&g==0){
                printf("%.3f X%d",x[i][g],g+1);
            }if(x[i][g]<0&&g==0){
                printf("-%.3f X%d",-x[i][g],g+1);
            }else if(x[i][g]>0){
                printf(" + %.3f X%d",x[i][g],g+1);
            }else{
                printf(" - %.3f X%d",-x[i][g],g+1);
            }

        }
        printf("= %.3f\n",x[i][n]);
    }*/
}

int main(){
    /*
    先輸入有幾個變數，而後輸入個個變數的係數與值，有幾個變數就需要幾條算式，例如
    3
    1  1  1  3    x+y+z=3
    1  1 -1  1    x+y-z=1
    1 -1 -1 -1    x-y-z=-1

    輸入為float
    */
    int i,g=0;
    int n=0;//有幾個變數
    float x[100][101];//多元一次方程式的係數與值
    float lamda[100]={0};//答案

    n=input(x);
    printData(n,x);
    guess_tri(n,x);
    //printf("====\n");
    //printData(n,x);
    guess_lamda(n,x,lamda);
    printLamda(n,lamda);


}
