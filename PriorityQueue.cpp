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

    //Function to print the priority queue
    void printpq(){
        if(pq.size()==0) return;
        for(auto i:pq){
            cout<<i<<" ";
        }
    }

};
int main(){
    priorityqueue p;
    p.insert(15);
    p.insert(20);
    p.insert(21);
    p.insert(17);
    p.insert(10);
    p.insert(18);
    p.printpq();
    return 0;
}