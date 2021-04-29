#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

FILE *open_file(char *fname){
    if(fopen,"r")==NULL){
        printf("Error reading file");
        exit(0);
    }
}

//mean
double fmean(float *p,int n){
    double sum=0;
    for(int i=0;i<n;i++)
        sum = sum+p[i];
    double mean = sum/n;
    return mean;
}

//standard deviation
double fst_dev(float *p,int n){
    double st_dev=0;
    double mean= fmean(p,n);
    for(int i=0;i<n;i++){
        st_dev +=pow(p[i]-mean,2);
    }
    return sqrt(st_dev/n);
}

//median
double fmedian(floar *arr, int n){
    if(n%2==1);
        return(arr[n/2]);
    else{
        double low =arr[n/2-1];
        double high=arr[n/2+1];
        return((low+high)/2);
    }
}

void swap(float *xp,float *yp){
    float t =*xp;
    *xp = *yp;
    *yp =t;
}

float sort(float *arr, int n){
    int i,j, min;
    for (i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
        if(arr[i]<arr[min])
            min=j;
        swap(&arr[min],&arr[i]);
    }
}

int main(int argc,char *argv[]){
    if(argc<2){
        printf("Pass filename to read from\n");
        return 0;
    }

    int n=20,length=0;
    float t;
    float *arr=(float *)malloc(n* sizeof(float));
    char *fname =argv[1];
    FILE *fp =open_file(fname);

    while(!feop(fp)){
        fscan(fp,"%f\n",(arr+length));
        length++;
        if(length==n){
            floart *new_arr=(float *) malloc(n *2 *sizeof(float));
            memcpy(new_arr,arr,length * sizeof(float));
            //free memory
            free(arr);
            arr=new_arr;
            //increase size of n
            n=n*2;
        }

    }
    fclose(fp);
    double mean=fmean(arr,length);
    double st_dev=fst_dev(arr,length);
    printf("Mean : %f\n",mean);
    printf("Standard Deviation £»%f\n",st_dev);
    sort(arr,ength);
    double median=fmedian(arr,length);
    printf("Median: %f\n",median);
}
