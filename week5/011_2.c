#include<stdio.h>
#include<math.h>


int c(int m){
    if(m==0 || m==1){
        return 0;
    }else if(m%2==0){
        return 1+c(m/2);
    }else{
        return 1+c((m+1)/2);
    }

}
void dec_to_bin(int n){
    int i=0,end=0,g=0;
    int ans[11]={0};

    while(n>1){
        ans[i]=n%2;
        n/=2;
        i++;
    }
    ans[i]=n;
    for(g=10;g>=0;g--){
        printf("%d",ans[g]);
    }
    printf("\n");

}
int bin_to_dec(int n){
    float dec=0;
    int i=0;
    while(n>1){
        dec+=(n%10)*pow(2,i);
        n/=10;
        i++;
    }
    dec+=(n%10)*pow(2,i);
    return dec;

}
int r(int m){

    int i=0,ans=0;
    for(i=0;i<=m;i++){
        ans+=c(i);

    }
    return ans;
}
int main(){

    int n=0;
    float m;
    float x;
    int ans=0;
    int con=0;
    int rrr=0;
    while(con==0){

        scanf("%d",&n);

        m=bin_to_dec(n);
        ans=r(m);
        dec_to_bin(ans);
        scanf("%d",&con);
    }



}
