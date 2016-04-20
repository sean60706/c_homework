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
    float m;
    float x;
    int ans=0;
    int con=0;
    while(con==0){
        scanf("%d",&n);
        scanf("%d",&con);
        m=bin_to_dec(n);
        x=c(m);
        ans=dec_to_bin(x);
        if(ans<10){
            printf("000");
        }else if(ans<100){
            printf("00");
        }else if(ans<1000){
            printf("0");
        }

        printf("%d\n",ans);
        //printf("%f\n",m);
        //printf("%f\n",x);

    }



}
