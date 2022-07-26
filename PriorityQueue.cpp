#include<iostream>
#include<vector>
using namespace std;

class priorityqueue{
    vector<int> pq;
    public:
    //create a constructor
    priorityqueue(){

    }

    bool isempty(){
        return pq.size()==0;
    }
    
    int getsize(){
        return pq.size();
    }

    int getmin(){
        if(isempty()) return 0;
        return pq[0];
    }

    //Function to insert data into the priority queue
    void insert(int data){
        pq.push_back(data);
        int childindex=pq.size()-1;
        int parentindex;
        while(childindex>0){
            parentindex=(childindex-1)/2;
            if(pq[parentindex]>=pq[childindex])    swap(pq[childindex],pq[parentindex]);
            else break;
            childindex=parentindex;
        }
    }

    //Remove minimum from the priority queue// Basically this is Heap Sort
    int removemin(){
        if(isempty()) return 0; //Priority queue is empty
        int ans=pq[0];
        //swap(pq[0],pq[pq.size()-1]);
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentindex=0;
        int lci=2*parentindex+1;
        int rci=2*parentindex+2;
        while(lci<pq.size()){
            int minindex=parentindex;
            if(pq[minindex]>pq[lci]) minindex=lci;
            if(rci<pq.size() && pq[minindex]>pq[rci])   minindex=rci;
            if(parentindex==minindex) break;
            swap(pq[parentindex],pq[minindex]);
            parentindex=minindex; 
            lci=2*parentindex+1;
            rci=2*parentindex+2;
        }
        return ans;
    }


    //Function to print the priority queue
    void printpq(){
        if(pq.size()==0) return;
        for(auto i:pq){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

};
int main(){
    priorityqueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    p.printpq();
    while(!p.isempty()){
        cout<<p.removemin()<<" ";
    }
    return 0;
}