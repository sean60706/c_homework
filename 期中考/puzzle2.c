#include<stdio.h>

int create(int n,int puzzle[][40]){
    int i,g;
    //scanf("%d",&i);

    for(i=0;i<n;i++){
        for(g=0;g<n;g++){
            scanf("%d",&puzzle[g][i]);
        }
    }

}
int go(int n,int puzzle[][40],int x,int y){
    if((x==(n-2))&&(y==(n-2))){
        puzzle[x][y]=9;
        return 1;
    }else if(puzzle[x][y]==1){
        return -1;
    }else if(puzzle[x][y]==2){
        return -1;
    }else{
        puzzle[x][y]=2;
        if(go(n,puzzle,x+1,y)==1){//右
            puzzle[x][y]=9;
            return 1;
        }else if(go(n,puzzle,x,y+1)==1){//下
            puzzle[x][y]=9;
            return 1;
        }else if(go(n,puzzle,x-1,y)==1){//左
            puzzle[x][y]=9;
            return 1;
        }else if(go(n,puzzle,x,y-1)==1){//上
            puzzle[x][y]=9;
            return 1;
        }


    }

}

int main(){
    int i,g,n;
    int puzzle[40][40];
    scanf("%d",&n);
    create(n,puzzle);


    go(n,puzzle,1,1);
    for(i=0;i<n;i++){
        for(g=0;g<n;g++){
            printf("%d ",puzzle[g][i]);
        }
        printf("\n");
    }




}
