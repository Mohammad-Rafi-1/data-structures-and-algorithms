#include<iostream>
using namespace std;

class queue{
    public:
    int* arr;
    int first, last, size,capacity;
    queue(int m){

        arr=new int[m];
        first=-1;
        last=-1;
        size=m;
        capacity=m;

    };

    void enqueue(int value){
        if(last==-1 && first==-1){
            first+=1;
            last+=1;
            *(arr+first)=value;
            cout<<"element inserted "<<value<<" into the queue \n";
            capacity-=1;
        }
        else if(last<size-1){
            last+=1;
            *(arr+last)=value;
            cout<<"element inserted "<<value<<" into the queue \n";
            capacity-=1;

        }
        else{
            cout<<"queue is full can't insert \n";
        }

    };

   void  dequeue(){
        if(first==size-1){
            cout<<"element deleted "<<arr[first]<<" from the queue \n";
            *(arr+first)=-1;
            first=-1;
            last=-1;
            capacity=size;
        }
        else if(first<last){
            cout<<"element deleted "<<arr[first]<<" from the queue \n";
            *(arr+first)=-1;
            first+=1;
            capacity+=1;
        }
        else if(first==-1 && last==-1){
            cout<<"queue is empty\n";
        }
    }

    void display() {
        cout << "Elements in array: ";
        for (int i = 0; i < size; i++) {
            cout << *(arr + i) << " ";  
        }
        cout << endl;
    }

};



int main(){
    queue q(5);
    for(int i=0;i<7;i++){
        q.enqueue(i);
    }

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();

}