#include<stdio.h>
int main(){
    int i=1,j=1,num=0;
    double sum=0;
    //printf("%.3f",1/(double)i);

    scanf("%d",&num);
    while(i<=num){
        sum=sum+j*1/(double)i;
        i++;
        j=j*(-1);
    }
    printf("%.3f",sum);
}