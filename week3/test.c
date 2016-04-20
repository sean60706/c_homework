#include<stdio.h>

//(1)求字串長度
int strlen(char str[]){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}
//(2)判斷是否為子字串
int strisparent(char parent[],char child[]){
    int g=0;
    int child_len;
    int i=0;
    child_len=strlen(child);

    while(parent[i]!=0){
        if(parent[i]==child[g]){
            g++;
        }else{
            g=0;
        }
        if(g==child_len){
            return 1;//true
        }
        i++;
    }
    return 0;//false
}
//3判斷兩字串的大小
int strcmp(char str1[],char str2[]){
    int l1,l2,i;
    int equal=0;
    l1=strlen(str1);
    l2=strlen(str2);
    if(l1>l2){
        return 1;
    }else if(l1<l2){
        return -1;
    }else{
        for(i=0;i<l1;i++){
            if(str1[i]>str2[i]){
                return 1;
            }else if(str1[i]>str2[i]){
                return -1;
            }
        }
    }
    return 0;
}


int main(){
    char str[]="testing";
    char str2[]="testing";
    int len;
    len=strcmp(str,str2);
    printf("%d\n",len);

}
