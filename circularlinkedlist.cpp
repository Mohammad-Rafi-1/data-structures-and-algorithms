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

      Node* insert_at_begining(Node* root, int value){
        if(root==nullptr){

            Node* temp=new Node(value);
            temp->next=temp;
            return temp;

        }
        else{

            Node* temp=new Node(value);
            Node* current=root;
            while(current->next!=root){
                current=current->next;
            }
            current->next=temp;
            temp->next=root;
            root=temp;

            return root;
        }
      };


      Node* insert_at_pos(Node* root, int value,int pos){
        if(root==nullptr){
            Node* temp=new Node(value);
            temp->next=temp;
            return temp;
        }
        else{
            Node* current=root;
            int count=1;
            while(current->next!=root && count <pos-1){
                current=current->next;
                count+=1;
            }
            if(count==pos-1){
                cout<<"insert at position : "<<pos<<"\n";
                Node* temp=current->next;
                current->next=new Node(value);
                current->next->next=temp;
                return root;

            }
            else{
                cout<<"position not found";
                return root;
            }
             

        }
      }

      Node* delete_from_begining(Node* root){
        if(root==nullptr){
            cout<<"empty list"<<"\n";
            return nullptr;
        }
        else{
            cout<<"delete element : "<<root->data<<"\n";
            Node* current=root;
            while(current->next!=root){
                current=current->next;
            }
            if(current->next->next!=current){
                Node* temp=current->next;
                root=temp->next;
                current->next=root;
                delete temp;
                return root;
            }
            else{
                
                 Node* temp=current->next;
                 delete temp;
                 return current;
            }

        }
      };


      Node* delete_from_end(Node* root){
         if(root==nullptr){
            cout<<"empty list"<<"\n";
            return nullptr;
        }
        else if(root->next!=root){
            Node* current=root;
            while(current->next->next!=root){
                current=current->next;
            }
            Node* temp=current->next;
            current->next=root;
            cout<<"delete element :"<<temp->data<<"\n";
            delete temp;
            return root;

        }
        else{
            cout<<"delete element :"<<root->data<<"\n";
            delete root;
            return nullptr;
        }

      };

      Node* delete_at_pos(Node* root,int pos){

         if(root==nullptr){
            cout<<"empty list"<<"\n";
            return nullptr;
        }
        else{
            Node* current=root;
            int count=1;
            while(current->next!=root && count<pos-1){
                current=current->next;
                count+=1;
            }
            if(current->next==root){
                cout<<"position does not exist\n";
                return root;
            }
            else{
                cout<<"element deleted at pos "<<pos;
                Node* temp=current->next;
                current->next=temp->next;
                delete temp;
                return root;
            }
        }

      };

    



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


      };

};






int main(){

    circularlinkedlist l;
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


    root=l.insert_at_pos(root,1000,92);
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


    root=l.delete_at_pos(root,50);
    cout<<"traverse"<<"\n";
    l.traverse(root);


}