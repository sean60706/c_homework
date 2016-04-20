#include<stdio.h>

/*
順子:三張花色相同且連續
刻子:三張花色、大小相同

對子:相同兩張牌
獲勝條件:五面子+對子

索:0~8
萬:9~17
筒:18~26
東南西北中發白:27~33

17張牌

*/


//輸入5 6 7 9 10 11 19 20 20 20 20 21 27 27 31 31 31
//印出結果，p為對子的數字，f為順子的個數，r1順子內容
//s為刻子的個數，r2為刻子內容
int printR(int p,int r1[5][3],int f, int r2[5], int s) {
    int i=0;
    int g=0;
    printf("%d-%d\n",p,p);
    for(i=0;i<f;i++){
        printf("%d-%d-%d\n",r1[i][0],r1[i][1],r1[i][2]);
    }
    for(g=0;g<s;g++){
         printf("%d-%d-%d\n",r2[g],r2[g],r2[g]);
    }



}
//輸入d: 5 6 7 9 10 11 19 20 20 20 20 21 27 27 31 31 31
//輸出：統計每一邊號牌型的張數，存入 c ，例如
//c: 0 0 0 0 0 1 1 1 0 1 1 1 0 0 0 0 0 0 0 1 4 1 0 0 0 0 0 2 0 0 0 3 0 0
//第0個為0表示編號0的排張數為0，
//第20個為4表示編號20張數為4
int process(int d[], int c[]) {
    //將data轉為card，已完成
    int i=0;
    for(i=0;i<17;i++){
        c[d[i]]++;
    }

}
//輸入：統計每一編號牌型的張數，c
//輸出：r 順子的內容
//回傳：順子組合的個數
int flush(int c[], int r[5][3]) {
    //為考慮到可能有重複的，例如 2、2、3、3、4、4
    //所以紀錄後應該將排刪除，以利之後的判斷
    //全部記錄完後再將card重置為一開始的狀態，或是一開始就用個副本來處理

    int i=0;
    int f=0;

    int c_copy[34];
    for(i=0;i<34;i++){//做出card的副本
        c_copy[i]=c[i];
    }
    for(i=0;i<=31;i++){//判斷該牌與之後以張牌是否連續，所以只需判斷到31即可，之後的33、32只與31有關係
        while(c_copy[i]>0 && c_copy[i+1] >0 && c_copy[i+2]>0){
            c_copy[i]--;
            c_copy[i+1]--;
            c_copy[i+2]--;
            //printf("%d-%d-%d     flush\n",i,i+1,i+2);//檢查部分，會拿掉
            r[f][0]=i;
            r[f][1]=i+1;
            r[f][2]=i+2;
            f++;
            i++;
        }

    }

    return f;
}
//輸入：統計每一編號牌型的張數，c
//輸出：r 刻子的內容
//回傳：刻子組合的個數
int same(int c[], int r[5]) {
    //刻子部分算是成功，後續會亂掉是test的問題
    //判斷完後的牌需要扣掉，才不會和之後的對子判斷重複

    int i=0;
    int s=0;
    int g=0;//r[]刻子填空
    for(i=0;i<34;i++){
        if(c[i]>=3){
            s++;
            c[i]-=3;
            ///////////////////////

            ///////////////////////
            r[g]=i;
           // printf("%d-%d-%d     %d\n",r[g],r[g],r[g],c[i]);//檢查部分，會拿掉
            g++;
        }
    }
    return s;
}
//印出陣列資料
int printData(int c[], int n) {
    //完成
    int i=0;
    if (n==17) printf("Input: ");
    else printf("Process: ");
    for (i=0; i<n; i++) {
       printf("%d ", c[i]);
    }
    printf("\n");
}
//先測試對子可能出現的牌編號 c[i]>1，使用兩種方法
//(1) 計算刻子後再計算順子 same, flush
//(2) 計算順子後再計算刻子 flush, same
int test(int data[], int card[]) {
    //流程感覺怪怪的，一開始檢查對子的地方不明確，重新檢查更是將每張牌直接-2，需要再更改或詢問

    int i=0, s=0, f=0, j=0,p=-1;
    int r1[5][3], r2[5];//r1順子，會存三張牌。r2是刻子，只存一張即可。順子+刻子超過5個為獲勝條件一
    //獲勝條件二為有對子
    //???刻子和順子可允許重複的排嗎?
    //???對子和順子、刻子又如何??

    //應該先判斷順子，之後刻子，最後在判斷對子
    //對子和刻子不能共用，

    //要先判斷順子，再判斷刻子，刻子的判斷減去的card要保留，確保刻子不會與對子重複計算，最後在對子

/*
    for (i=0; i<34; i++) {
        //嘗試對子出現的編號
        if (card[i]>1) {
            puts("//////////111111111111");

            /*
            card[i]-=2;//這裡可能會出問題，會直接減掉第一個滿足條件的對象，
            //不管後續是否有更適合的或是對象為刻子或順子，所以先註解掉
            */

/*
            f = flush(card, r1);
            s = same(card, r2);

            //第一種方法失敗，使用第二種方法
            if ((s+f)<5){
                    puts("//////////222222222222");
               //重新統計牌數
               //重新計算的話，之前紀錄的順子跟刻子應該要重製
               f=0;
               s=0;

               process(data, card);
               //card[i]-=2;
               f = flush(card, r1);
               s = same(card, r2);
            }
            //若胡排，則印出結果
            if ((s+f)>=5){
                puts("//////////33333333333333");
                printR(p, r1, f, r2, s);
                return 1;
            }
        puts("//////////4444444444444444");
            //重新統計牌數
            process(data, card);
        }
    }*/



    /*for(i=0;i<34;i++){
        printf("%d,",card[i]);
    }*/
    //printf("\n");
    f = flush(card, r1);


    /*for(i=0;i<34;i++){
        printf("%d,",card[i]);
    }*/
    //printf("\n");
    s = same(card, r2);


   /*for(i=0;i<34;i++){
        printf("%d,",card[i]);
    }*/
    //printf("\n");
    i=0;
    while(i<34&&p<0){
        if(card[i]>=2){
            p=i;
        }
        i++;
    }


    if ((s+f)>=5&&p>0){
                printR(p, r1, f, r2, s);
                return 1;
    }



    return 0;
}
int main() {
    //先輸入所有的排作為data，
    //將data做統計分類為card
    //利用card來判斷對子(未明確)、刻子same、順子flush。當前進度
    //判斷勝負



    int i=0, card[34]={0}, data[17]={0};
    for (i=0; i<17; i++) scanf("%d", &data[i]);
    //printData(data, 17);
    process(data, card);
    //printData(card, 34);
    printf("Result: %d", test(data, card));
    return 0;
}

/*
Input: 5 6 7 9 10 11 19 20 20 20 20 21 27 27 31 31 31
Process: 0 0 0 0 0 1 1 1 0 1 1 1 0 0 0 0 0 0 0 1 4 1 0 0 0 0 0 2 0 0 0 3 0 0
Output:
27-27 //對子
5-6-7 //順子
9-10-11 //順子
19-20-21 //順子
20-20-20 //刻子
31-31-31 //刻子
Result: 1
*/
