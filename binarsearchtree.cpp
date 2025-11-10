#include<iostream>
#include<string>
using namespace std;


class Node{
    public:
     int data;
     Node* left;
     Node* right;
     Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
     }
     
};


class binarysearchtree{

    public:
     
     Node* insert(Node* root,int value){
        if(root==nullptr){
            return new Node(value);
        }
        else if(root->data<value){

            root->right=insert(root->right,value);
    
        }
        else{
            root->left=insert(root->left,value);
        }
        return root;
     };


     int predecessor(Node* root){
        Node* current=root;
        while(current->right!=nullptr){
            current=current->right;
        }
        return current->data;
     };


     int successor(Node* root){
        Node* current=root;
        while(current->left!=nullptr){
            current=current->left;
        }
        return current->data;
     };



     Node* delete_ele(Node* root,int value){
        if (root==nullptr){
            return nullptr;
        }
        else if(root->data>value){
            root->left=delete_ele(root->left,value);
        }
        else if(root->data<value){
            root->right=delete_ele(root->right,value);
        }
        else{
            if(root->left!=nullptr){
                
                root->data=predecessor(root->left);
                cout<<root->data;
                root->left=delete_ele(root->left,root->data);

            }
            else if(root->right!=nullptr){
                root->data=successor(root->right);
                root->right=delete_ele(root->right,root->data);

            }
            else{
                delete root;
                root=nullptr;
            }
        }
        return root;
     };


     void search(Node* root,int value){
        if(root==nullptr){
            cout<<"element not found \n";
        }
        else{
            if(root->data>value){

                search(root->left,value);

            }
            else if(root->data<value){
                search(root->right,value);
            }
            else{
                cout<<"element found "<<root->data<<"\n";
            }
        }
     };
     

     void traverse(Node* root){
        if (root!=nullptr){
            traverse(root->left);
            cout<<root->data<<"\n";
            traverse(root->right);
        }
     };

};



int main(){

    binarysearchtree bst;
    Node* root=nullptr;

    int arr[]={20,-1,9,0,100,89};
    for(int i=0;i<6;i++){

        root=bst.insert(root,arr[i]);
    }
    bst.traverse(root);
    
    cout<<"delete element \n";
    root=bst.delete_ele(root,0);
    bst.traverse(root);
    bst.search(root,1000);

}