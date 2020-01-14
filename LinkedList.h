#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node():next(NULL)
    {
    }
    Node(const int value):next(NULL)
    {
        this->data = value;
    }
    Node(const Node& node)
    {
        this->data = node.data;
        this->next = node.next;
    }
};

class LinkedList
{
    Node *head;
    public:
    LinkedList():head(NULL)
    {
    }
    void AddNode(const int data)
    {
        if(head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }
    void Print()
    void DeleteNode(const int data)
    {
       
       if(head != NULL)
        {
            if(head->data == data)
            {
                Node *temp = head;
                head = head->next;
                delete(temp);
                temp = NULL;
            }
            else
            {
                Node *curr = head; 
                Node *prev = NULL; 
                while(curr != NULL)
                {
                    if(curr->data == data)
                    {
                        prev->next = curr->next;
                        delete(curr);
                    }
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    } 
    void Print()
    {
        if(head == NULL)
            std::cout << "List is Empty "<< std::endl;
        else
        {
            std::cout << "Elements of the list: "<< std::endl;
            Node *temp = head;
            while(temp != NULL)
            {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }
    }  
     Node* FindMiddle()
    {
        Node *slow_ptr = NULL;
        if(head)
        {
            slow_ptr = head;
            Node *fast_ptr = head->next;
            while(fast_ptr && fast_ptr->next != NULL)
            {
                slow_ptr = slow_ptr->next;  //increment it by 1 step 
                fast_ptr = fast_ptr->next->next;  //increment it by 2 steps
            }
            //std::cout << "Middle Node of the list : " << slow_ptr->data << std::endl;
        }
        return slow_ptr;
    }
    
    int SizeofList()
    {
        int length = 0;
        if(head)
        {
            length++;
           // Node *slow_ptr = head; //increment it by 1 step 
            Node *fast_ptr = head->next; //increment it by 2 steps
            while(1)
            {
                if(fast_ptr != NULL)
                {
                   length++ ;
                }
                else
                    break;
                if(fast_ptr->next != NULL)
                {
                   length++; 
                   fast_ptr = fast_ptr->next->next;
                }
                else
                    break;
            }
        }
        return length;
    }
};
