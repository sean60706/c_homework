#include<stdint.h>


void big_add_three(int list[][100],int n){
    //list[n]=list[n-1]+list[n-2]+list[n-3]
    //list[n]=list[a]+list[b]+list[c]
    int i=0;
    int temp=0;
    for(i=0;i<100;i++){
        list[n][i]+=list[n-1][i]+list[n-2][i]+list[n-3][i];
        /*if(list[n][i]!=0){
            printf("%d+=%d+%d+%d\n",list[n][i],list[n-1][i],list[n-2][i],list[n-3][i]);
        }*/
        if(list[n][i]>9){
            list[n][i+1]+=list[n][i]/10;
            list[n][i]%=10;
        }


    }



}


void f(int n,int list[][100]){
    int i;
    for(i=1;i<=n;i++){
        if(i==0){

        }else if(i==1){
            list[i][0]=1;
        }else if(i==2){
            list[i][0]=2;
        }else if(i==3){
            list[i][0]=4;
        }else{
            //puts("n >3");
            big_add_three(list,i);
        }
    }
}

int main(){
    int n;
    int list[901][100]={0};
    int i=99;
    int g;
    int ans[100]={0};//為輸出的數太大了，會超過變數宣告的極限，所以需要用陣列來存大數
    //while(1){
        for(i=0;i<901;i++){
            for(g=0;g<100;g++){
                list[i][g]=0;
            }
        }



        scanf("%d",&n);
        f(n,list);
        i=99;
        while(list[n][i]==0){
            i--;
        }
        for(g=i;g>=0;g--){
            printf("%d",list[n][g]);
        }

        /*for(i=0;i<20;i++){
            printf("%d",list[n][i]);
        }*/
       // printf("\n");
    //}


}
