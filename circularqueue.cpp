#include<iostream>
using namespace std;


class circularQueue{
    public:
     int* arr;
     int first, last, size, capacity;
     
     circularQueue(int value){
        arr=new int[value];
        first=-1;
        last=-1;
        size=value;
        capacity=value;
     }


     void enqueue(int value){
        
        if(first==-1 && last==-1 ){

            first+=1;
            last+=1;
            *(arr+first)=value;
            cout << "inserted element "<<value<<" into the queue \n";
        }

        else if((last+1)%size!=first){
            last=(last+1)%size;
            *(arr+last)=value;
            cout << "inserted element "<<value<<" into the queue \n";
        }
        else{

            if (*(arr+first)==-1){
                *(arr+first)=value;
                cout << "inserted element "<<value<<" into the queue \n";

            }
            else{
                cout<<"queue is full \n";
            }

            
        }


     }

     void dequeue(){


        if(first==-1 || (first ==last && *(arr+first)==-1)){

            cout<<"queue is empty \n";

        }
        else if (first%size!=last){

            cout << "deleted element "<<*(arr+first)<<" from the queue \n";


            *(arr+first)=-1;
            first=(first+1)%size;
            
        }
        else{

            cout << "deleted element "<<*(arr+first)<<" from the queue \n";
            *(arr+first)=-1;
            
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


    circularQueue q(5);
    for(int i=0;i<7;i++){
        q.enqueue(i);
    }

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    

    for(int i=0;i<7;i++){
        q.enqueue(i*10);
    }
    q.display();


    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); 
    q.display();


    for(int i=0;i<7;i++){
        q.enqueue(i*10);
    }
    q.display();
    
}