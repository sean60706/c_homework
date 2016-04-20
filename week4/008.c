#include<stdio.h>
#include<string.h>

/*
1.將文章切成一個一個的字輸入，用字去做替換與確認，但缺點在於無法判斷輸入的是文章還是英文字PQ
2.將文章全部存在一個字串，之後將文章字串切成個別的單字，逐個字元去比對PQ
3.將文章全部存在一個字串，直接比對操作
*/
/*
程式基本功都寫好了，但是切換到輸入時就會不動作
*/

void article_cut(char s[]){
    char *test = strtok(s, " ");

    while (test != NULL) {
        printf("%s\n", test);
        test = strtok(NULL, " ");
    }
}
void replace(char s[],char p[],char q[]){
    int i=0;
   // printf("%s,%s,%s\n",s,p,q);
    char *test = strtok(s," ");

    //因為p改用輸入的話，會自動加/0，需要把這個銷掉!
    /*while(p[i]!=0){
        i++;
    }
    p[i-1]=NULL;
    i=0;*/

    //printf("%d,%s,\n",i,p);

    while(test!=NULL){
      //  printf("%s,%s,%d\n",test,p,strcmp(test,p));
       // getchar();
        if(strcmp(test,p)==0){
            printf("%s ",q);
        }else{
            printf("%s ",test);
        }
        test = strtok(NULL, " ");
    }
}
void insert(char s[],char p[],char q[]){
    int i=0;
    char *test=strtok(s," ");

    //因為p改用輸入的話，會自動加/0，需要把這個銷掉!
   /*while(p[i]!=0){
        i++;
    }
    p[i-1]=NULL;
    i=0;
    while(q[i]!=0){
        i++;
    }
    q[i-1]=NULL;
    i=0;*/

    while(test!=NULL){
        if(strcmp(test,p)==0){
            printf("%s ",q);
            printf("%s ",test);
        }else{
            printf("%s ",test);
        }
        test=strtok(NULL," ");
    }
}
void del(char s[],char p[],char q[]){
    int i=0;
    char *test=strtok(s," ");

    //因為p改用輸入的話，會自動加/0，需要把這個銷掉!
    /*while(p[i]!=0){
        i++;
    }
    p[i-1]=NULL;
    i=0;
    while(q[i]!=0){
        i++;
    }
    q[i-1]=NULL;
    i=0;*/

    while(test!=NULL){
        if(strcmp(test,p)==0){

        }else{
            printf("%s ",test);
        }
        test=strtok(NULL," ");
    }
}
void anl(char s[]){
    int i=0,g=0;
    int end=0;//紀錄最後的位置
    int exist=0;//確認有沒有重複

    //w跟count的位置應為相同的，一個是單字，一個是次數
    int count[500][2]={0};//計數單字出現的次數
    char *w[500];//紀錄的單字
    int temp_count=0;
    char *temp_w;
    int site=0;
    char *min;


    char *test=strtok(s," ");
    while(test!=NULL){
        exist=0;
        //    printf("test=%s,",test);
        for(i=0;i<end;i++){//從頭跑到尾

            if(strcmp(w[i],test)==0){//假設紀錄中有符合的
              //  printf("w[%d]=%s is exist!!,",i,w[i]);
                exist=1;//存在確認
                count[i][0]++;//計數增加
            //    printf("count[%d]=%d\n",i,count[i]);

                //end++;//最後的位置增加



            }else{

            }
        }
        if(exist==0){//跑過上述的確認後還是沒有
         //   printf("no exist,");
            w[end]=test;//紀錄
            count[end][0]=1;
//            printf("w[%d]=%s,count[%d]=%d\n",end,w[end],end,count[end]);

            end++;
        }else{
           // printf("exist\n");
        }
        test=strtok(NULL," ");
    }
    ////////////將分析的結果排序(小到大)/////////////

    for(i=0;i<end;i++){
        min=w[i];
       // printf("\n%s,",min);
        for(g=i+1;g<end;g++){
            if(strcmp(w[g],min)==-1){//strcmp(w[g],min)   w[g]<min
              //  printf("%s is min",w[g]);
                min=w[g];
                site=g;
             //   printf("min!\n");
            }else{
             //   printf(".....");
            }
        }
        if(strcmp(w[g],min)!=0){
            temp_w=w[i];
            temp_count=count[i][0];

            w[i]=w[site];
            count[i][0]=count[site][0];

            w[site]=temp_w;
            count[site][0]=temp_count;

        }
    }
    /////////////////////////
   // printf("\nresult\n");
    int max,k;


    for(k=0;k<end;k++){
        max=0;
        for(i=0;i<end;i++){
            if(count[i][1]==0&&count[i][0]>max){
                max=count[i][0];
            }

        }
      //  printf("max=%d",max);
        for(g=0;g<end;g++){
            if(count[g][1]==0&&count[g][0]==max){
                    printf("%s %d\n",w[g],count[g][0]);
                    count[g][1]=1;
            }
        }

    }




    /*
    for(i=0;i<end;i++){
        printf("%s %d\n",w[i],count[i][0]);
    }*/





}
void anl2(char s[]){
    int i=0,g=0;
    int end=0;//紀錄最後的位置
    int exist=0;//確認有沒有重複

    //w跟count的位置應為相同的，一個是單字，一個是次數
    int count[500][2]={0};//計數單字出現的次數
    char *w[500];//紀錄的單字
    int temp_count=0;
    char *temp_w;
    int site=0;
    char *min;


    char *test=strtok(s," ");
    while(test!=NULL){
        exist=0;
        //    printf("test=%s,",test);
        for(i=0;i<end;i++){//從頭跑到尾

            if(strcmp(w[i],test)==0){//假設紀錄中有符合的
              //  printf("w[%d]=%s is exist!!,",i,w[i]);
                exist=1;//存在確認
                count[i][0]++;//計數增加
            //    printf("count[%d]=%d\n",i,count[i]);

                //end++;//最後的位置增加



            }else{

            }
        }
        if(exist==0){//跑過上述的確認後還是沒有
         //   printf("no exist,");
            w[end]=test;//紀錄
            count[end][0]=1;
//            printf("w[%d]=%s,count[%d]=%d\n",end,w[end],end,count[end]);

            end++;
        }else{
           // printf("exist\n");
        }
        test=strtok(NULL," ");
    }




    ////////////將分析的結果排序(小到大)////////////
    int change=0;
    for(i=0;i<end;i++){
        change=0;
        min=w[i];
       // printf("\n%s,",min);
        for(g=i+1;g<end;g++){

            if(strcmp(w[g],min)==-1){//strcmp(w[g],min)   w[g]<min
               // printf("%s is min\n",w[g]);
                min=w[g];
                site=g;
                change=1;
            }else{
            }
        }
        if(change==1){
            temp_w=w[i];
            temp_count=count[i][0];
            w[i]=w[site];
            count[i][0]=count[site][0];
            w[site]=temp_w;
            count[site][0]=temp_count;
        }
    }

    /////////////////////////////小到大////

    int max,k;
    for(k=0;k<end;k++){
        max=0;
        for(i=0;i<end;i++){
            if(count[i][1]==0&&count[i][0]>max){
                max=count[i][0];
            }

        }
        for(g=0;g<end;g++){
            if(count[g][1]==0&&count[g][0]==max){
                    printf("%s %d\n",w[g],count[g][0]);
                    count[g][1]=1;
            }
        }

    }








}


int main(){
    char words[1500][50];
    char article[100000]="This is a book That is a cook";
    char a1[100000];
    char a2[100000];
    char a3[100000];
    char a4[100000];
    char p[50]="is";
    char q[50]="was";

    int i=0;
/////////輸入部分/////////////
    gets(article);
    gets(p);
    gets(q);



    //因為p改用輸入的話，會自動加/0，需要把這個銷掉!
    /*while(p[i]!=0){
        i++;
    }
    p[i-1]=NULL;*/
    i=0;
   /* while(article[i]!=0){
        i++;
    }
    article[i-1]=NULL;
    i=0;*/
/////////輸入部分(完)//////////


    strcpy(a1,article);
    //printf("%s\n",a1);
    //printf("%s\n",p);
    //printf("%s\n",q);

    //printf("=====\n");
    strcpy(a1,article);
    strcpy(a2,article);
    strcpy(a3,article);
    strcpy(a4,article);

    //article_cut(a1);
    //printf("replace\n");


    //這段是結果!!!!
    replace(a1,p,q);
    printf("\n");


    //printf("insert\n");
    insert(a2,p,q);
    printf("\n");
    //printf("del\n");
    del(a3,p,q);





    printf("\n");
    anl2(a4);




   // char *ap="12312";

/*
    char *s[2];
    char *temp;
    char a[]="b";
    char b[]="a";

    s[0]=a;
    s[1]=b;

    temp=s[0];
    s[0]=s[1];
    s[1]=temp;

    printf("%s\n",s[0]);
    printf("%s\n",s[1]);
;
    int x=strcmp(a,b);//相同0，a>b=1，a<b=-1
    printf("%d\n",x);
*/


    /*if("a"<"is"){
        puts("yes");
    }else{
        puts("no");
    }*/

/*
    char aa[100000]="This is a book That is a cook";
    int i=0;

    while(aa[i]!=0){
        printf(",%c,\n",aa[i]);
        i++;
    }
*/
/*
    char mm[]="sean";
    char jj[10];
    gets(jj);
    int x=strcmp(mm,jj);
    printf("%d\n",x);
*/




}
