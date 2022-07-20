//Function to implement the HeapSort
#include<iostream>
using namespace std;
void heapsort(int input[],int n){
    if(n==0 || n==1) return;
    for(int i=1;i<n;i++){
        int ci=i;
        int pi=(ci-1)/2;
        while(ci>0){
            if(input[ci]>input[pi]) swap(input[ci],input[pi]);
            else break;
            ci=pi;
            pi=(ci-1)/2;
        }
    }
    int size=n;
    while(size>1){
        swap(input[0],input[size-1]);
        size--;
        int pi=0;
        int lci=2*pi+1;
        int rci=2*pi+2;
        while(lci<size){
            int minindex=pi;
            if(input[lci]>input[minindex]) minindex=lci;
            if(rci<size && input[rci]>input[minindex]) minindex=rci;
            if(minindex==pi) break;
            swap(input[minindex],input[pi]);
            pi=minindex;
            lci=2*pi+1;
            rci=2*pi+2;
        }
    }
}

int main(){
    int input[]={2,1,4,7,6};
    heapsort(input,5);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}