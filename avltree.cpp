#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};




class avltree{

    public:

     int getheight(Node* root){
        if(root!=nullptr){
            return root->height;
        }
        return 0;
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

     Node* leftrotate(Node* root){
        if(root!=nullptr){

            Node* i =root->left;
            Node* j =i->right;
            i->right=root;
            root->left=j;
            root->height=1+max(getheight(root->left),getheight(root->right));
            i->height=1+max(getheight(i->left),getheight(i->right));
            return i;


        }
        else{
            return nullptr;
        }
     };

     Node* rightrotate(Node* root){
        if(root!=nullptr){

            Node* i =root->right;
            Node* j =i->left;
            i->left=root;
            root->right=j;

            root->height=1+max(getheight(root->left),getheight(root->right));
            i->height=1+max(getheight(i->left),getheight(i->right));
            return i;


        }
        else{
            return nullptr;
        }
     }


     
     Node* insert(Node* root, int value){
        if(root==nullptr){
            return new Node(value);
        }
        else if(root->data>value){

            root->left=insert(root->left,value);
        }
        else{
            root->right=insert(root->right,value);
        }

        root->height=1+max(getheight(root->left),getheight(root->right));
        int balance=getheight(root->left)-getheight(root->right);
        
        if(balance<-1 && getheight(root->left)<0){

            return leftrotate(root);

        }
        else if(balance<-1 && getheight(root->left)>0){

            root->left=rightrotate(root->left);
            return leftrotate(root);
            

        }
        else if(balance>1 && getheight(root->left)<0){

            root->right=leftrotate(root->right);
            return rightrotate(root);

        }
        else if(balance>1 && getheight(root->right)>0){

            return rightrotate(root);

        }
        return root;
     };



     Node* delete_ele(Node* root,int value){
        if (root==nullptr){
            cout<<"element  not found : "<<value<<"\n";
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

        if(root==nullptr){
            return root;
        }

        int balance=getheight(root->left)-getheight(root->right);

        
        if(balance<-1 && getheight(root->left)<0){

            return leftrotate(root);

        }
        else if(balance<-1 && getheight(root->left)>0){

            root->left=rightrotate(root->left);
            return leftrotate(root);
            

        }
        else if(balance>1 && getheight(root->left)<0){

            root->right=leftrotate(root->right);
            return rightrotate(root);

        }
        else if(balance>1 && getheight(root->right)>0){

            return rightrotate(root);

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

    avltree bst;
    Node* root=nullptr;

    int arr[]={20,-1,9,0,100,89};
    for(int i=0;i<6;i++){

        root=bst.insert(root,arr[i]);
    }
    bst.traverse(root);


    cout<<"delete element \n";
    root=bst.delete_ele(root,200);
    bst.traverse(root);

    bst.traverse(root);
    bst.search(root,100);

<<<<<<< HEAD
=======
    
>>>>>>> 50fd63a (Added avl tree)


}