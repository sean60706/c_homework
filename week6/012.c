#include<stdio.h>
#include<math.h>
void Gray(int n,int k){
    int temp;
   // printf("\nn=%d,k=%d\n",n,k);
    if(n==1){
        printf("%d",k);
    }else if(k<pow(2,n-1)){
        printf("0");
        return Gray(n-1,k);
    }else{
        temp=(int)pow(2,n)-1-k;
        printf("1");
       // printf("        2^%d-1-%d=%d   ",n-1,k,temp);
        return Gray(n-1,temp);
    }
}

int main(){
    int n,k;
    int con=0;

    while(con==0){
        scanf("%d %d",&n,&k);

        Gray(n,k);
        printf("\n");


        scanf("%d",&con);
    }





}
