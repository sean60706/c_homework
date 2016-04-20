#include<stdio.h>
#include<math.h>


int c(int m){
    printf("m=%d\n");
    if(m==0 || m==1){
        return 0;
    }else if(m%2==0){
        return 1+c(m/2);
    }else{
        return 1+c((m+1)/2);
    }

}
int r_cycle(int m){
    int i=0;
    int ans=0;

    for(i=0;i<=m;i++){
        ans+=c(m);
    }
    return ans;
}
float dec_to_bin(int n){
    float bin=0;
    int i=0;
    int temp;
    while(n>1){
        //printf("n=%d,",n);
        //printf("%d*%d,\n",n%2,pow(10,i));
        bin+=(n%2*pow(10,i));
        n/=2;
        i++;
    }

    bin+=(n*pow(10,i));



    return bin;

    /*
    10=1010
    */
}
float bin_to_dec(int n){
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

int main(){

    int n=0;
    int m=0;
    float x;
    int ans=0;
    int con=0;
    int r;
    while(con==0){
        /*scanf("%d",&n);
        m=bin_to_dec(n);*/
        scanf("%d",&m);
        ans=c(m);
        printf("ans=%d\n",ans);
    }



}
