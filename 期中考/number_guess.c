#include<stdio.h>


void list_make(int list[][5]){
    int i,g;
    int thus,hru,ten,one;
    for(i=0;i<9999;i++){
        thus=i/1000;
        hru=(i/100)%10;
        ten=(i/10)%10;
        one=i%10;
        list[i][0]=thus;
        list[i][1]=hru;
        list[i][2]=ten;
        list[i][3]=one;
        list[i][4]=-1;
        if(thus!=hru && thus !=ten && thus!=one && hru!=ten && hru!=one && ten!=one){
            list[i][4]=1;
        }
    }
}
int check(int list[][5],int num[],int in_a,int in_b){
    int i,g,x,y,total=0;
    int a=0;
    int b=0;
    for(i=0;i<9999;i++){
        if(list[i][4]==1){
            for(x=0;x<4;x++){
                for(y=0;y<4;y++){
                    if(num[x]==list[i][y]){
                        if(x==y){
                            a++;
                        }else{
                            b++;
                        }
                    }
                }
            }
            if(a!=in_a && b!=in_b){
                list[i][4]=-1;
            }else{
                total+=1;
            }
        }

    }
    if(total==1){
        return ans(list);
    }
    return 0;
}
int ans(int list[][5]){
    int i;

    for(i=0;i<9999;i++){
        if(list[i][4]==1){
            printf("%d%d%d%d",list[i][0],list[i][1],list[i][2],list[i][3]);
        }
    }
    return 1;
}
void input_process(char input[],int num[],int *a,int *b){
    scanf("%s",input);
    num[0]=input[0]-'0';
    num[1]=input[1]-'0';
    num[2]=input[2]-'0';
    num[3]=input[3]-'0';
    *a=input[5]-'0';
    *b=input[7]-'0';

}

int main(){
    int i,g;
    int list[9999][5];
    char input[9];
    int number[4];
    int a;
    int b;
    int end=0;

    list_make(list);
    while(end==0){
        input_process(input,number,&a,&b);

        end=check(list,number,a,b);


    }
  //  printf("%d\n",end);






    /*for(i=0;i<4;i++){
        printf("%d",number[i]);
    }
    printf(",%d %d",a,b);*/

    /*for(i=0;i<150;i++){
        if(list[i][4]==1){
            for(g=0;g<4;g++){
                printf("%d",list[i][g]);
            }
            printf("\n");
        }

    }*/



}
