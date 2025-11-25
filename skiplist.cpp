#include<iostream>
#include<vector>
using namespace std;

int maxlevel=5;


class Node{
    public:
     int data;
     vector<Node*> next;
     Node(int value,int level){
        data=value;
        next=vector<Node*>(level+1,nullptr);
     }
};



class skiplist{
    private:
     Node* head;
     int level;
    
    public:
     skiplist(){
        head=new Node(0,maxlevel);
        level=0;
     };


     void insert(int value){
        
        int newLevel=0;

        while(newLevel<maxlevel && rand()%2==1){
            newLevel+=1;            
        }

        if(level<newLevel){
            head->next.resize(newLevel+1,nullptr);
            level=newLevel;
        }

        Node* current=head;

        vector<Node*>update_vec(level+1,nullptr);
        for(int i = level;i>=0;i--){
            while(current->next[i] and current->next[i]->data<value){
                current=current->next[i];
            }
            update_vec[i]=current;

        }

        current=current->next[0];

        if(current==nullptr or current->data!=value){
            Node* new_node=new Node(value,newLevel);

            for (int i =0;i<=newLevel;i++){
                new_node->next[i]=update_vec[i]->next[i];
                update_vec[i]->next[i]=new_node;
            }
            cout << "Element " << value << " inserted successfully.\n";
        }

        else
        {
            cout << "Element " << value << " already exists.\n";  
        }
     };

    
    void remove(int data){
        
        Node* current=head;

        vector<Node*>update_vec(level+1,nullptr);
        for(int i=level;i>=0;i--){

            while(current->next[i] and current->next[i]->data<data){
                current=current->next[i];
            }
            update_vec[i]=current;
        }

        current=current->next[0];

        if(current!=nullptr and current->data==data){

            for (int i = 0; i <= level; i++)
            {
                if (update_vec[i]->next[i] == current)
                {
                    update_vec[i]->next[i] = current->next[i];
                }
            }
            delete current;


            while(level>0 and head->next[level]==nullptr){
                level--;
            }

            cout << "Element " << data << " deleted successfully."<<endl;


        }
        else{
            cout << "Element " << data << " does not exist."<<endl;


        }

    }

    void search(int data){
        
        Node* current=head;

        for(int i=level;i>=0;i--){

            while(current->next[i] and current->next[i]->data<data){
                current=current->next[i];
            }
        }

        current = current->next[0]; 

        if (current != nullptr && current->data == data) 
        {
            cout << "Element " << data << " found.\n";
        }
        else  
        {
            cout << "Element " << data << " not found.\n";
        }


    }


    void display() 
    {

        cout << "skip List:"<< endl;

        for (int i = level; i >= 0; i--) 
        {
            Node* current = head->next[i]; 

            cout << "Level " << i << ": "; 

            while (current != nullptr)       
            {
                cout << current->data << " ";
                current = current->next[i]; 
            }
            cout << endl;
        }
    }


};




int main() 
{

    skiplist SkipList; // Creating the skip List

    // Inserting the Data in skip list

    SkipList.insert(10);
    SkipList.insert(20);
    SkipList.insert(30);
    SkipList.insert(40);
    SkipList.insert(50);

    // Display skip list after inserting the data
    SkipList.display();
    SkipList.search(20);
    SkipList.search(400);
    SkipList.remove(20);
    SkipList.remove(40);



    // Display the skip list after removing the data



    SkipList.display();
}