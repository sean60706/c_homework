#include<stdint.h>


int f(int total,int now){
    int dis=total-now;
    if(dis<0){
        return 0;
    }else if(dis==1){

        return 1;
    }else if(dis==2){

        return 1+f(total,now+1);
    }else if(dis==3){
        return 1+f(total,now+1)+f(total,now+2);
    }else{
        return f(total,now+1)+f(total,now+2)+f(total,now+3);
    }


}

int main(){
    int n;
    int list[900]={0};
    scanf("%d",&n);
    printf("%d\n",f(n,0));


}
