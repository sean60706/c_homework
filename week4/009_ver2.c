#include<stdio.h>
#include<string.h>

/*
Today is my 45 birthday, There are 65 guest coming for the 1000 party, I got 789 gifts to open.
Object-oriented programming is a programming paradigm based on the concept of objects, a app, xxxxxxxxxxx.

第一行取出其中數字 45, 65, 1000, 789， 分別作反轉後相加。54+56+1+987+0=1098 ，第一組密碼即為 1098。
第二行分析字元頻率，(e, 7), (o,7), (r, 6), (a, 8)，第二組密碼即為 7768，其中(x, 11)超過10不予計算。
*/


/*
判斷是否為連續數字，
需要先判斷是否為數字，再判斷是否為連續
為連續數字回傳1，不是則回傳0

經過問老師，連續數字就是數字，例如:183就是連續數字!
*/
int is_continue_number(char n[]){//完成!!!
    int i=0;
    //確認是否為數字單字
    while(n[i]!=0){
        if(n[i]-'0'>=0&&n[i]-'0'<=9){


        }else{
            return 0;
        }
        i++;
    }
    return 1;
}
int str_inverse(char s[]){
    char s2[100000];
    int i=0;
    int end=strlen(s)-1;
    strcpy(s2,s);

    for(i=0;i<=end;i++){
        s[i]=s2[end-i];

    }



}


/*
處理密碼一，將文章中的連續數字取出並反轉，之後再將數字相加取<10000的四位數當密碼
首先需要先將文章拆解成個別單字，再將個別單字判斷是否為連續數字，
為連續數字的話再進行反轉，反轉後再相加，相加後再取四位數

只要是數字就是連續數字，但要考慮參雜的情況
ex:1a1b1c1d
這樣應該要取出4個1
1a12b975d
取出1、12、975
*/
int p1(char s[]){
    char *test=strtok(s," ");
    int num=0;
    int i=0;
    while(test!=NULL){
        /*
        if(is_continue_number(test)==1){
                str_inverse(test);
                num+=atoi(test);
              //  printf("%d,%d\n",num,atoi(test));
        }*/


        /*while(test[i]!=0){

            if(test[i]-'0'>=0&&test[i]-'0'<=9){


            }else{
                return 0;
            }

            i++;
        }*/
        //printf("%s\n",test);
        i=0;
        while(test[i]!=0){
            printf("%c",test[i]);
            i++;
        }
        printf("\n");

        printf("%s\n",test);

        test=strtok(NULL," ");
    }


    //return num%10000;

    return 0;





}
int p2(char s[]){
    char word[52];
    int count[52][2]={0};
    int i=0,g=0,end=0,exist=0;
    end=0;
    while(s[i]!=0){

        if(s[i]>='a'&&s[i]<='z' ||  s[i]>='A'&&s[i]<='Z'  ){

            exist=0;
            for(g=0;g<end;g++){
                if(s[i]==word[g]){
                    exist=1;
                    count[g][0]+=1;
                }
            }
            if(exist==0){
                word[end]=s[i];
                count[end][0]=1;
                end++;
            }
        }
        i++;
    }
    /*
    for(i=0;i<end;i++){
        printf("%c,%d\n",word[i],count[i]);
    }*/
    g=0;
    int k=9;
    while(g<=4&&k>0){
        for(i=0;i<end;i++){
            if(g==4){
                break;
            }
            if(count[i][0]==k){
                g++;
                count[i][1]=1;
            }
        }
        k--;
    }
    for(i=0;i<end;i++){
        if(count[i][1]==1){
            printf("%d",count[i][0]);
        }


    }



}




int main(){
    char s1[100000];
    char s2[100000];

    gets(s1);

    //gets(s2);
    printf("%d",p1(s1));
    //p2(s2);


//    printf("%d\n",s1[0]-s1[1]);



    //puts("1213213");

}
