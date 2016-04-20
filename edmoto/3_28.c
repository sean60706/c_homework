#include<stdio.h>
#include<string.h>

void f1(char *s,char *p[]){//輸出句子中的每一個英文字(指標陣列p)

    char *t=strtok(s," ");
    int i=0;
    while(t!=NULL){
        p[i]=t;
        t=strtok(NULL," ");
        i++;
    }
}
void f2(char *p[],char *q[]){//輸出排序好的英文字(指標陣列 q)
    //我有先將指標陣列p中全部初始化，一開始的值皆是"-1"，否則求單字總數時用p[]==NULL會出錯
    char *temp;
    int len=0,g=0,i=0,site=0;
    while(p[len]!="-1"){
        q[len]=p[len];
        len++;//求單字總數
    }

    for(i=0;i<len;i++){
        for(g=0;g<len-i-1;g++){
            if(strcmp(q[g],q[g+1])==1){
                temp=q[g];
                q[g]=q[g+1];
                q[g+1]=temp;
            }
        }
    }
}
void f3(char *s, char *p[], int count[]){//輸出句子中英文字出現的個數(指標陣列 p, 整數陣列 count)
    int i=0,g=0,end=0,exist;
    char *t=strtok(s," ");
    while(t!=NULL){
        exist=0;//先假設不存在
        for(i=0;i<end;i++){//從以記錄找尋是否存在
            if(p[i]==t){
                exist=1;
                count[i]++;
            }
        }
        if(exist==0){//如果未被紀錄就新增
            p[end]=t;
            count[end]=1;
            end++;
        }
        t=strtok(NULL," ");
    }
}


int main(){
    char s[]="Today is my 45 birthday, There are 65 guest coming for the 1000 party, I got 789 gifts to open.";
    char *p[1000];
    char *q[1000];
    int count[1000]={0};
    int i=0,g=0;
    int len;

    for(g=0;g<1000;g++){
        p[g]="-1";

    }

    f1(s,p);
    f2(p,q);
    f3(s,p,count);



    /*while(p[i]!="-1"){
        printf("%s                     p\n",p[i]);
        i++;
    }
    printf("%d\n",i);
    for(g=0;g<i;g++){
        printf("%s\n",q[g]);
    }*/



    /*for(g=0;g<20;g++){
        printf("%s\n",p[g]);
    }*/




}
