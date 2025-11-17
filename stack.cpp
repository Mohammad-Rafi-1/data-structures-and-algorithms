#include<iostream>
using namespace std;

class stack{
    public:
     int top=-1;
     int* arr;
     int size;
     stack(int value){
        arr=new int[value];
        size=value;
     };


    void  push(int value){
        if(top+1==size){
            cout<<"stack is full \n";
        }
        else{
            top+=1;
            *(arr+top)=value;
            cout<<value <<" inserted into the stack \n";
        }
     }

     void pop(){
        if(top==-1){
            cout<<"stack is empty \n";
        }
        else{
            cout<<*(arr+top)<" element deleted from stacjk \n";
            *(arr+top)=-1;
            top-=1;
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
    stack s(5);
    for(int i=0;i<7;i++){
        s.push(i);
    }
    s.display();


    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
}
