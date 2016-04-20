#include<stdio.h>


//判定勝利，true1,false0
int check_win(int t[][3]){
    /*
    勝利條件有四種
    1.橫排
    2.直排
    3.左上右下
    4.左下右上
    */
    int col=0,row=0,slant1=0,slant2=0;
    int i,g;

    for(i=0;i<3;i++){
        row=0;
        col=0;
        for(g=0;g<3;g++){
            if(t[i][g]==1){
                row++;
                //printf("%d,%d row:%d\n",i,g,row);
            }
            if(t[g][i]==1){
                col++;
                //printf("%d,%d col:%d\n",i,g,col);
            }
        }
        if(row==3 || col==3){
            return 1;
        }
    }
    for(i=0;i<3;i++){
        if(t[i][i]==1){
            slant1++;
        }
    }
    if(slant1==3){
        return 1;
    }
    if(t[2][0]==1 && t[1][1]==1 && t[0][2]==1){
        return 1;
    }



    return 0;


}
void inputBingo(int p[][3]){
    //ok
    int i,g;
    for(i=0;i<3;i++){
        for(g=0;g<3;g++){
            scanf("%d",&p[i][g]);
        }
    }

}
void check_point(int p[][3],int c[],int t[][3]){
    //ok
    int i,g,k;

    for(i=0;i<3;i++){
        for(g=0;g<3;g++){
            t[i][g]=0;
            for(k=0;k<3;k++){
               // printf("[%d,%d]=%d,c=%d,",i,g,p[i][g],c[k]);
                if(p[i][g]==c[k]){
                    t[i][g]=1;
                 //   printf("true\n");
                }else{
                   // printf("false\n");
                }
            }
        }
    }
}
void process(){
    int player1[3][3]={0};
    int player2[3][3]={0};
    int temp_p1[3][3]={0};
    int temp_p2[3][3]={0};
    int p1,p2;
    int c[3]={0};
    int go_on=0;
    int i,g;

    while(go_on==0){


        inputBingo(player1);
        inputBingo(player2);
        for(i=0;i<3;i++){
            scanf("%d",&c[i]);
        }


        check_point(player1,c,temp_p1);
        check_point(player2,c,temp_p2);

        /*
        printf("===t1====\n");
        for(i=0;i<3;i++){
            for(g=0;g<3;g++){
                printf("%d ",temp_p1[i][g]);
            }
            printf("\n");
        }
        printf("===t2====\n");
        for(i=0;i<3;i++){
            for(g=0;g<3;g++){
                printf("%d ",temp_p2[i][g]);
            }
            printf("\n");
        }
        printf("============\n");
        */


        //printf("===t1====\n");
        p1=check_win(temp_p1);


        //printf("===t2====\n");
        p2=check_win(temp_p2);

        //printf("p1=%d,p2=%d\n",p1,p2);
        if(p1>p2){
            printf("Player1 wins\n");
        }else if(p1==p2){
            printf("Draw\n");
        }else{
            printf("Player2 wins\n");
        }

        scanf("%d",&go_on);
    }





}

int main(){
    /*int player2[3][3];
    int c[3],i,g;
    int temp[3][3]={0};
    inputBingo(player2);
        for(i=0;i<3;i++){
            scanf("%d",&c[i]);
    }
    check_point(player2,c,temp);
    for(i=0;i<3;i++){
        for(g=0;g<3;g++){
            printf("%d ",player2[i][g]);
        }
        printf("\n");
    }
    for(g=0;g<3;g++){
        printf("%d ",c[g]);
    }
    printf("\n");
    for(i=0;i<3;i++){
        for(g=0;g<3;g++){
            printf("%d ",temp[i][g]);
        }
        printf("\n");
    }*/

    process();


}
