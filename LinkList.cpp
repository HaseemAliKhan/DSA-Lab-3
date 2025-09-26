#include<iostream>
using namespace std; 

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL; //For avoiding the next ptr to point randomly anywhere in the memory 
    }

    //This node class can only create the nodes for a linked list we need a mechanism by which we can join these nodes. For that purpose we create another class named linked list.
};

class linkedList
{
    node* head ; 
    node* tail; 
    public:
    linkedList()
    {
        head = tail = NULL; //At the start we have pointed both at null in order to avoid random data entry.
    }

    void insertAtHead(int data) //This functions adds a new node to the start of the linked list 
    {
        node* newNode = new node(data);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head; 
            head = newNode;
        }
        
    }
    
    void insertAtLocation(int data , int position) //This function is used to insert a value anywhere in the linked list
    {
        //Finding the position where the new node is to be added 
        if(position < 0) 
        return;
        
        if(position == 0)
         insertAtHead(data);

    
        node* newNode = new node(data);
        node* temp = head;
        for(int i = 0 ; i < position-1 ; i++)
        {
           if(temp == NULL) //If the desired position exceeds the size of the list 
            {
                cout<<"Invalid position!"<<endl;
                return;
            }
                temp = temp->next;
        }
        newNode->next = temp->next; 
        temp->next = newNode;
    }

void deleteAtLocation(int position)
{
    if (head == NULL) // List empty
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (position < 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 0)
    {
        node* delNode = head;
        head = head->next;
        delete delNode;
        return;
    }

    node* temp = head;

    // Traverse until the node *before* the one we want to delete
    for (int i = 0; i < position - 1; i++)
    {
        if (temp == NULL || temp->next == NULL) // Position out of range
        {
            cout << "Invalid position!" << endl;
            return;
        }
        temp = temp->next;
    }

    node* delNode = temp->next;
    if (delNode == NULL) // Position out of range
    {
        cout << "Invalid position!" << endl;
        return;
    }

    temp->next = delNode->next;
    delete delNode;
}


    void countList()
{
    int count = 0;
    node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total nodes in the list: " << count << endl;
}

    void displayList()
    {
        node* temp = head;
        while(temp != NULL) 
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;     
    }

};

int main()
{
    linkedList l;
    l.insertAtHead(1);
    l.insertAtHead(2);
    l.insertAtHead(3);

    l.displayList();

    l.insertAtLocation(4,2); // as indexing starts from 0 , so 3rd location is at 3-1 = 2

    l.displayList();

    l.deleteAtLocation(1); // to delete the 2nd location we pass the index 2-1 = 1
    
    l.displayList();

    l.countList();

    return 0;
}
