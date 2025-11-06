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
        prev=nullptr;
     };
};


class doublylinkedlist{
    public:
     Node* insert_at_begining(Node* root, int value){
        if(root==nullptr){
            return new Node(value);
        }
        else {

        Node* temp=new Node(value);

        temp->next=root;
        root->prev=temp;

        return temp;

        }
     }

     Node* insert_at_end(Node* root,int value){
        if(root==nullptr){
            return new Node(value);
        }
        else{
            Node* current=root;
            while(current->next!=nullptr){
                current=current->next;
            }
            Node* temp=new Node(value);
            current->next=temp;
            temp->prev=current;

        }
        return root;

     }

     Node* insert_at_pos(Node* root,int value,int pos){
        if(root==nullptr){
            cout<<"empty linked list \n";
            return nullptr;
        }
        else{
            int count=1;
            Node* current=root;
            cout<<"insert at position : "<<pos<<"\n";
            while(current->next!=nullptr && count<pos-1){
                current=current->next;
                count+=1;
            }
            if(current->next!=nullptr){
                Node* temp=new Node(value);
                temp->next=current->next;
                current->next->prev=temp;
                current->next=temp;
                temp->prev=current;
            }
            else{
                Node* temp=new Node(value);
                current->next=temp;
                
                temp->prev=current;

            }
            return root;
        }
     }


     Node* delete_from_begining(Node* root){
        if(root==nullptr){
            cout<<"Empty list";
            return nullptr;
        }
        else{
            Node* temp=root;
            cout<<"deleted : "<<root->data<<"\n";
            root=root->next;
            root->prev=nullptr;
            delete temp;
            return root;
            }
     }

     Node* delete_from_end(Node* root){
         if(root==nullptr){
            cout<<"Empty list";
            return nullptr;
        }
        else if(root->next!=nullptr){

            Node* current=root;

            while(current->next->next!=nullptr){
                current=current->next;
            }

            Node* temp=current->next;
            cout<<"deleted : "<<temp->data<<"\n";
            current->next=nullptr;
            delete temp;
            return root;
        }
        else{

            delete root;
            return nullptr;
        }

     }

     Node* delete_at_pos(Node* root,int pos){
        if(root==nullptr){
            cout<<"empty list";
        }
        else{

            int count=1;
            Node* current=root;
            cout<<"insert at position : "<<pos<<"\n";
            while(current->next!=nullptr && count<pos-1){
                current=current->next;
                count+=1;
            }
            if(current->next==nullptr){
                cout<<"postion does not exist"<<"\n";
                return root;
            }
            else{
                cout<<"element deleted "<<current->next->data<<" at pos "<<pos<<"\n";
                if(current->next->next!=nullptr){
                    Node* temp = current->next;
                    current->next=temp->next;
                    temp->next->prev=current;
                    delete temp;
                }
                else{
                    Node* temp = current->next;
                    current->next=nullptr;
                    delete temp;
                }
            }
            return root;

        }
     }




     void traverse(Node* root){
        if(root!=nullptr){
            Node* current = root;
            cout<<"traverse-forword"<<"\n";
            while(current->next!=nullptr){
                cout<<current->data<<"\n";
                current=current->next;
            }
            cout<<current->data<<"\n";

            cout<<"traverse-backword"<<"\n";
            while(current->prev!=nullptr){
                cout<<current->data<<"\n";
                current=current->prev;
            }
            cout<<current->data<<"\n";



        }
    }
};



int main(){

    doublylinkedlist l;
    Node* root=nullptr;

    int arr1[]={10,9,8,7,6,5,4,3,2,1};
    for(int i =0;i<10;i++){
        cout<<"insert elemet "<<arr1[i]<< " at first"<<"\n";
        root=l.insert_at_begining(root,arr1[i]);
    }
    cout<<"traverse"<<"\n";
    l.traverse(root);


    int arr2[]={100,200,300,400,500};
    for(int i =0;i<5;i++){
        cout<<"insert elemet "<<arr2[i]<< " at last"<<"\n";
        root=l.insert_at_end(root,arr2[i]);
    }
    cout<<"traverse"<<"\n";
    l.traverse(root);


    root=l.insert_at_pos(root,1000,9);
    cout<<"traverse"<<"\n";
    l.traverse(root);


    for(int i=0;i<5;i++){
        root=l.delete_from_begining(root);
    }
    cout<<"traverse"<<"\n";
    l.traverse(root);


    for(int i=0;i<5;i++){
        root=l.delete_from_end(root);
    }
    cout<<"traverse"<<"\n";
    l.traverse(root);


    root=l.delete_at_pos(root,47);
    cout<<"traverse"<<"\n";
    l.traverse(root);


}