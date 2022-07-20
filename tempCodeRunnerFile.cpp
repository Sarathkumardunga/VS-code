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

    //Remove minimum from the priority queue
    int removemin(){
        if(isempty()) return 0;
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parentindex=0;
        
        while(parentindex<pq.size()-2){
            int lci=2*parentindex+1;
            int rci=2*parentindex+2;
            int minindex;
            if(lci<=pq.size()-1 && rci<=pq.size()-1){
                if(pq[parentindex]>pq[lci]) minindex=lci;
                else minindex=parentindex;
                if(pq[rci]<pq[minindex]) minindex=rci;
            }
            else if(lci<=pq.size()-1){
                if(pq[parentindex]>pq[lci])    minindex=lci;
                else minindex=parentindex;
            }
            swap(pq[parentindex],pq[minindex]);
            parentindex=minindex; 
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
    p.insert(10);
    p.insert(20);
    p.insert(100);
    p.insert(30);
    p.insert(40);

    //p.insert(50);
    p.printpq();
    cout<<p.removemin()<<endl;
    p.printpq();
    return 0;
}