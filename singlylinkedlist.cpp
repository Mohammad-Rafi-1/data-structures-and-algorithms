#include<iostream>
#include<string>

using namespace std;

class Node{
    public :
     int data;
     Node* next;

     Node(int value){
        data=value;
        next=nullptr;
     }
};

class singlyLinkedlist{

    public:
     
     Node* insert_at_begining(Node* root, int value){
        if(root==nullptr){
            return new Node(value);
        }
        else{
            Node* temp = new Node(value);
            temp->next=root;
            return temp;

        }
     }



     Node* insert_at_end(Node* root, int value){

        if(root==nullptr){
            return new Node(value);
        }
        else{
            Node* current = root;

            while(current->next!=nullptr){
                current=current->next;
            }
            current->next =new Node(value);
            return root;
        }

     }

     Node* insert_at_pos(Node* root,int value,int pos){
        if(root==nullptr){
            cout<<"empty linked list \n";
            return nullptr;
        }
        else{
            int count=1;
            Node* current=root;
            while(current->next!=nullptr && count<pos-1){
                current=current->next;
                count+=1;
            }
            cout<<"insert at position : "<<pos<<"\n";
            if(current->next!=nullptr){
                Node* temp=current->next;
                current->next=new Node(value);
                current->next->next=temp;
            }
            else{
                current->next=new Node(value);
            }
            return root;
        }
     }



     Node* delete_at_end(Node* root){
        if(root==nullptr){
            cout<<"your list is empty"<<"\n";
            return nullptr;
        }
        else if(root->next==nullptr){
            cout<<"deleted : "<<root->data<<"\n";
            delete root;

            return nullptr;
        }
        else{
            Node* current = root;

            while(current->next->next!=nullptr){
                current=current->next;
            }
            Node* temp =current->next;
            cout<<"deleted : "<<temp->data<<"\n";
            current->next=nullptr;
            delete temp;
            return root;
        }
    }


    Node* delete_at_start(Node* root){
        if(root==nullptr){
            cout<<"your list is empty"<<"\n";
            return nullptr;
        }
        else if(root->next==nullptr){
            cout<<"deleted : "<<root->data<<"\n";
            delete root;

            return nullptr;
        }
        else{

            Node* temp=root->next;
          
            root->next=nullptr;
            cout<<"deleted : "<<root->data<<"\n";

            delete root;

            return temp;

        }

    }

     Node* delete_at_pos(Node* root,int pos){
        if(root==nullptr){
            cout<<"empty linked list \n";
            return nullptr;
        }
        else{
            int count=1;
            Node* current=root;
            while(current->next!=nullptr && count<pos-1){
                current=current->next;
                count+=1;
            }
            if(current->next==nullptr){

                 cout<<"pos doesn't exist"<<"\n";
                
            }
            else{
               
                Node* temp=current->next;
                current->next=temp->next;
                cout<<"element deleted "<<temp->data<<" at pos "<<pos<<"\n";
                delete temp;
            }
            return root;
        }
     }

    void traverse(Node* root){
        if(root!=nullptr){
            Node* current = root;

            while(current->next!=nullptr){
                cout<<current->data<<"\n";
                current=current->next;
            }
            cout<<current->data<<"\n";
        }
    }
};



int main(){

    singlyLinkedlist l;
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



    for(int i=0;i<5;i++){
        root=l.delete_at_start(root);
    }
    cout<<"traverse"<<"\n";
    l.traverse(root);


    root=l.insert_at_pos(root,1000,9);
    cout<<"traverse"<<"\n";
    l.traverse(root);


    root=l.delete_at_pos(root,4);
    cout<<"traverse"<<"\n";
    l.traverse(root);

}


