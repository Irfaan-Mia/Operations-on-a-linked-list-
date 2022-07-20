#include <iostream>

using namespace std;

//Another method to declare a node 
/*struct Node 
{
    int data; 
    Node * next; 
};*/

class Node{
    public:
    int data; 
    Node * next; 
};

void print(Node * head)
{
    while(head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}


//Sends throught the memory address of the head node 
void insertfront(Node ** head, int newValue)
{
  Node * temp = new Node(); 
  temp->data = newValue;
  temp->next = *head;
  *head = temp; 
}

//Sends through the memory address of third Node
void insertback(Node ** third, int NewValue)
{
    Node * temp = new Node();
    temp->data = NewValue;
    temp->next = NULL;
    (*third)->next = temp; 
}

//Dont have to pass the head variables by address 
void insertatindex(Node ** head, int index, int newValue)
{
    Node * temp = new Node();
    temp->data = newValue;

    //Assumed first node would be referenced as zero 
    if(index == 0)
    {
        temp->next = *head;
        *head = temp; 
    }
    else
    {
        Node * previous; //Keep track of the previous node so its pointer can point to the new node 
        Node * iterator = *head; 
        for(int i = 0 ; i < index; i++)
        {
            previous = iterator; 
            iterator = iterator->next;
        }
        temp->next = iterator;  
        previous->next = temp; 
    }
}

void invertlinkedlist(Node ** head, int size)
{
    //Temp variables to store previous and next nodes data
    Node * iterator;
    Node * previous; 
   
    for(int i = 0 ; i < size; i++)
    {
        if(i == 0)
        {
           iterator = (*head)->next; //Next node 
           (*head)->next = NULL; //Make first node pointer null
           previous = *head; //Store first nodes memory address
           *head = iterator; //Make the first the next node 
        }
        else
        {
           if((*head)->next != 0) //For when it reaches the last node 
           {
            iterator = (*head)->next; //Next node 
           }
           
           (*head)->next = previous; //Link current node to previous node
           previous = *head;         //Store current node in previous
           *head = iterator;         //Point to new start of linked list
        }
    }
}

void insertlast(Node ** first, Node ** last, int num)
{
    Node * temp = new Node();
    temp->data = num; 
    temp->next = NULL;
    (*last)->next = temp; 
    *last = temp; 
}

//Assumed the linked list is sorted 
void removedupes(Node ** head)
{
    Node * previous = *head; 
    Node * current = (*head)->next; 

    //Loop until the currents memory address is null so the end of the linekd list 
    while(current != NULL)
    {
        //If the current nodes data and previous nodes data are equal we need to delete the node 
        if(previous->data != current->data)
        {
            previous = current; 
            current = current->next; 
        }
        else
        {
            previous->next = current->next; 
            delete(current); 
            current = previous->next; 
        }
    }
}

//Sets the first node to be referenced in the first position 
void deleteinggivingposition(Node ** first, Node ** last, int index)
{
    //Assume a index out of the number of nodes will not be given otherwise include a conditional statement
    //to check if the index is within the range of nodes 

    Node * previous;
    Node * iterator = *first; 
    //Loop until the index 
    for(int i = 1; i < index; i++)
    {
       previous = iterator; 
       iterator = iterator->next;
    }

    //Check if first node needs to be deleted or not 
    if(index == 1)
    {
        Node * temp = *first; 
        *first = (*first)->next;
        delete(temp); //Remove the Node from the heap 
    }
    else
    {
    previous->next = iterator->next; 
    delete(iterator); //Remove the Node from the heap   
    }

}



int main()
{

//If node is made using a structure the same method applies 
 
Node * head = new Node(); 
Node * second = new Node();
Node * third = new Node(); 

head->data = 5; 
head->next = second;
second->data = 10; 
second->next = third;
third->data = 15; 
third->next = NULL;

//Print the three element linked list
print(head);

//Adding a Node to front of linked list
insertfront(&head,69);
cout << endl;
print(head);
cout << endl;

//Adding a Node to back of linked list
insertback(&third,-69);
print(head);
cout << endl;

//Inserting a Node at any index point
insertatindex(&head,5,420); 
print(head); 
cout << endl;

//Invert the linked list
invertlinkedlist(&head,6);
print(head); 


//Making a dynamic linked list all other operations can be applied to this dynamic linked list using loops compared to the know number of nodes 
//Works the same when using a structure instead of a class 
Node * first = new Node();
Node * last = first; //Initially point to same node
int size = 1;

//Initilize the first node 
first->next = NULL; 
first->data = 1; 
//Filling list with some values and nodes 
for(int i = 1; i <= 5; i++)
{
    insertlast(&first,&last,i + 1); //The more this is used the longer the linked list can become 
    size++;
}
cout << endl;
cout << "Size of the linked list: " << size << endl;
print(first);
cout << endl;

//Deleting from linked list 
deleteinggivingposition(&first,&last,5);
print(first);

return 0;
}
