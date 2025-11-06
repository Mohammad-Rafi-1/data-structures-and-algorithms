#include<iostream>
#include<string>
using namespace std;


class Node{
    public:
     int data;
     Node* next;
     Node* prev;

     Node(int value){
        data=value;
        next=nullptr;
     }
};


class circularlinkedlist{


    public:

      Node* insert_at_end(Node* root, int value){

        if(root==nullptr){
            Node* temp=new Node(value);
            temp->next=temp;
            return temp;

        }
        else{
            Node* current=root;
            while(current->next!=root){
                current=current->next;
            }
            Node* temp=current->next;
            current->next=new Node(value);
            current->next->next=temp;
        }

        return root;


      }

      void traverse(Node* root){

        int count =0;
        Node* current=root;
        
        while(count!=3){
            if(current==root){
                count+=1;
                
            };
            cout<<current->data<<"\n";
            current=current->next;
            
        }


      }

};


int main(){

    circularlinkedlist l;
    Node* root=nullptr;

    int arr1[]={10,9,8,7,6,5,4,3,2,1};
    for(int i =0;i<10;i++){
        cout<<"insert elemet "<<arr1[i]<< " at last"<<"\n";
        root=l.insert_at_end(root,arr1[i]);
    }

    cout<<"traverse"<<"\n";
    l.traverse(root);
}