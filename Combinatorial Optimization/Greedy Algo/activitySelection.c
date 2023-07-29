#include<stdio.h>

void sort(int *start,int *finish,int n);
int activity_selector(int *act,int *start,int *finish,int n);

int main(int argc,char *argv[])
{

    int n;
    printf("Enter total activity:");
    scanf("%d",&n);

    int act[n],start[n],finish[n];

    FILE *fp;
    fp=fopen("actSelection.txt","r");

    //printf("Enter start and finish time:\n");
    for(int i=0;i<n;i++){
        //printf("Activity %d:",i+1);
        fscanf(fp,"%d %d",&start[i],&finish[i]);
    }
    fclose(fp);

    sort(start,finish,n);
    int activity=activity_selector(act,start,finish,n);

    printf("Optimal activity number:%d\n",activity);
    printf("Activity number:");
    for(int i=0;i<n;i++){
        if(act[i]!=0) printf("%d ",act[i]);
    }
    printf("\n");

    return 0;
}
void sort(int *start,int *finish,int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(finish[i]>finish[j]){
                temp=finish[i];
                finish[i]=finish[j];
                finish[j]=temp;

                temp=start[i];
                start[i]=start[j];
                start[j]=temp;
            }
        }
    }
}
int activity_selector(int *act,int *start,int *finish,int n){
    int count=1;
    int end=finish[0];
    act[0]=1;

    for(int i=1;i<n;i++){
        if(start[i]>=end){
            count++;
            end=finish[i];
            act[i]=i+1;
        }
    }

    return count;
}