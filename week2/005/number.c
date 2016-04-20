
//猜數字
#include<stdio.h>

void MakeList(int list[][5]){
    //列表完成
    int i,thus,hun,ten,one,n=0;
    int cc=0;
    for(i=123;i<9999;i++){

        one=i%10;
        ten=((i%100)-one)/10;
        hun=((i%1000)-ten-one)/100;
        thus=i/1000;
        if(thus!=hun && thus!=ten && thus!=one && hun!=ten && hun!=one && ten!=one){
            list[n][0]=thus;
            list[n][1]=hun;
            list[n][2]=ten;
            list[n][3]=one;
            list[n][4]=1;
            //printf("%d:%d   %d,%d,%d,%d\n",n,i,list[n][0],list[n][1],list[n][2],list[n][3]);
            n++;
        }


    }

}
void ProcessInput(int number[],int *a,int *b){
    //輸入處理，完成
    char input[9];
    scanf("%s",input);
    //printf("%s\n",input);
    number[0]=input[0]-'0';
    number[1]=input[1]-'0';
    number[2]=input[2]-'0';
    number[3]=input[3]-'0';
    *a=input[5]-'0';
    *b=input[7]-'0';

}
int judge(int list[][5],int number[],int *a_in,int *b_in){
    int a,b=0;
    int i,g,k;
    int candidate;
    for(i=0;i<5040;i++){
        a=0;
        b=0;
        for(g=0;g<4;g++){
            for(k=0;k<4;k++){
                if(list[i][g]==number[k]){
                    if(g==k){
                        a+=1;
                    }else{
                        b+=1;
                    }
                }
            }
        }

        if(*a_in==a && *b_in==b){

        }else{
            list[i][4]=0;
        }
    }
    g=0;
    for(i=0;i<5040;i++){
        if(list[i][4]==1){
            g++;
            candidate=i;
        }
    }
    //printf("g=%d,i=%d\n",g,i);
    if(g==1){
        printf("%d%d%d%d\n",list[candidate][0],list[candidate][1],list[candidate][2],list[candidate][3]);
        return 1;
    }
    return 0;

}
void run(){
    int list[9999][5];

    int number[4],*a,*b;
    int end=0;
    int i=0;
    MakeList(list);
    /*for(i=0;i<5040;i++){
        printf("%d: %d,%d,%d,%d\n",i,list[i][0],list[i][1],list[i][2],list[i][3]);
    }*/
    while(end==0){
        ProcessInput(number,&a,&b);
        end=judge(list,number,&a,&b);
    }



}
int main(){
/*
暴力破解法:
(1)先將所有可能的數字建立列表，列表為[][5]，第五個數字為劃去標記
(2)讀取輸入字串，將字串分解成四數字以及ab
(3)將列表中的每一組四個數字與輸入字串的四個數字做ab判斷，與輸入ab不符則劃去(第五位數劃掉)
(4)重複3直到剩唯一答案
*/

    run();


}
