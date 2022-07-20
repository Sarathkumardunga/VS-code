//K sorted array questions can be solved using priority queue concept 
//With time complexity (N+k)logk  approx~O(N)
#include<iostream>
#include<queue>
using namespace std;

void ksortedarray(int input[],int n,int k){
    if(n==0) return;
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){ 
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int input[]={12,15,6,1,7};
    ksortedarray(input,5,3);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}