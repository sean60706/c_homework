#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
有20項商品{1,2,....,20}
一人最多買五項，最少一項
一天最多1000筆資料
找兩筆資料最多人一同購買


輸入:
購買資料筆數
商品編號，不排序、以逗號隔開

輸出:兩個編號即出現次數，用逗號隔開，從小排到大
*/

/*
有二陣列
一為輸入的資料[1000][5]
一為分數[20][20]
輸入的資料進行配對，像是1,2,3,4就有1,2、1,3、1,4、2,3、2,4、3,4
1,2=2,1
挑出分數最高的
*/
/*
1.輸入商品:字串輸入，分辨字串為data[][]
2.data聘行配對，紀錄分數
3.將分數相同的相加ex:1,2=2,1
4.取出分數最高的輸出
*/
int Input(int data[][5]){
    int n;
    int i,g,c;
    scanf("%d",&n);
    char in[14];
    char *delim=",";
    char *pch;
    /*  逗號分隔輸入部分的原版
    char str[20]="1,2,5,10,20";
    char *delim=",";
    char *pch;
    pch=strtok(str,delim);
    while(pch!=NULL){
        printf("%s\n",pch);
        pch=strtok(NULL,delim);
    }

    */
    for(i=0;i<n;i++){
        //printf("i=%d:",i);
        scanf("%s",in);
        pch=strtok(in,delim);
        g=0;
        while(pch!=NULL){
            //printf("%s\n",pch);
            data[i][g]=atoi(pch);  ///////////////

            //printf("%d\n",data[i][g]);
            pch=strtok(NULL,delim);
            g++;
        }
    }
/*

    printf("\n\n\n");
    for(i=0;i<n;i++){
        printf("i=%d:",i);
        g=0;
        while(g<5){
            printf("%d,",data[i][g]);
            g++;

        }
        printf("\n");
    }*/

    return n;
}
void Data_to_Score(int n,int data[][5],int score[][21]){
    /*
    輸入的資料先不排序。全部分配紀錄分數，之後再將相同的情況判斷(2,1)=(1,2)
    */
    int i,g,k;
    for(i=0;i<n;i++){
        for(g=0;g<5-1;g++){
            for(k=g+1;k<5;k++){
                score[data[i][g]][data[i][k]]++;
                //printf("[%d,%d]=%d\t",data[i][g],data[i][k],score[data[i][g]][data[i][k]]);
            }

        }
        //printf("\n");
    }
/*
    printf("\n score1 \n");
    for(i=1;i<=10;i++){
        for(g=1;g<=20;g++){
            if(score[i][g]>0){
                printf("[%d,%d]=%d\t",i,g,score[i][g]);
            }

        }
        printf("\n");
    }
*/

}
void Score_DublePorcess(int score[][21]){
    //將原本的分數做進一步的處理，例如2,1=1,2，這時候就要將2,1的分數加到1,2中，然後用1,2去判斷熱門商品
    int i,g;

    for(i=20;i>=1;i--){
        for(g=1;g<i;g++){
            score[g][i]+=score[i][g];
        }

    }
   /* printf("\n===score2===\n");
    for(i=20;i>=1;i--){
        for(g=1;g<i;g++){
            if(score[g][i]>0){
                printf("[%d,%d]=%d\t",g,i,score[g][i]);
            }


        }
        printf("\n");
    }*/



}
void Result(int score[][21]){
    int i,g;
    int trade1,trade2,max;

    max=score[1][1];
    trade1=1;
    trade2=1;

    for(i=20;i>=1;i--){
        for(g=1;g<i;g++){
            if(score[g][i]>max){
                trade1=g;
                trade2=i;
                max=score[g][i];

            }

        }
    }

    printf("%d,%d,%d",trade1,trade2,max);
}

int main(){
    int data[1000][5]={0};
    int number=0;
    int score[21][21]={0};

    char in[14];
    int i,g;
    number=Input(data);
    Data_to_Score(number,data,score);
    Score_DublePorcess(score);
    Result(score);
/*
    char str[20]="1,2,5,10,20";
    char *delim=",";
    char *pch;
    pch=strtok(str,delim);
    while(pch!=NULL){
        printf("%s\n",pch);
        pch=strtok(NULL,delim);
    }

*/



}
