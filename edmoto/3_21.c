#include<stdint.h>


int f1(char s[]){
    int len=0;
    while(s[len]!=0){
        len++;
    }
    return len;
}

int f2(int n){
    if(n==1){
        return 1;
    }else{
        return f2(n-1)+n;
    }
}

int f3(int n){
    if(n==1){
        return 1;
    }else{
        return f3(n-1)*n;
    }
}
int f4(char *s1,char *s2){
    if(*s1>*s2){
        return 1;
    }else if(*s2>*s1){
        return -1;
    }else if(*s2==0 && *s1==*s2){
        return 0;
    }else{
        return f4(s1+1,s2+1);
    }
}


int main(){


}
