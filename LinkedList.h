/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    Node* FindKthElementFromEnd(const int k)
    {
        Node *slow_ptr = NULL;
        if(head && k > 0)
        {
            Node *fast_ptr = head;
            for(int i=1; i < k ; ++i)
            {
                fast_ptr = fast_ptr->next;  //increment it by k steps
                if(fast_ptr == NULL)
                {
                    std::cout << "k is out of bound" << std::endl;
                    return NULL;
                }
            }
            std::cout << "kthEle from start : " << fast_ptr->data << std::endl;
            slow_ptr = head;
            while(fast_ptr && fast_ptr->next != NULL)
            {
                slow_ptr = slow_ptr->next;  
                fast_ptr = fast_ptr->next; 
            }
            //std::cout << "Middle Node of the list : " << slow_ptr->data << std::endl;
        }
        return slow_ptr;
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
    void Reverse()
    {
        if(head && head->next)
        {
            Node *prev = NULL;
            Node *curr = head;
            Node *next = head->next;
            head->next = NULL;
            while(next)
            {
                prev = curr;
                curr = next;
                next = next->next;
                curr->next = prev;
            }
            head = curr;
        }
    }
        
};

int main()
{
    LinkedList list;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.AddNode(40);
    list.AddNode(50);
    list.AddNode(60);
    list.AddNode(70);
    list.AddNode(80);
    list.AddNode(90);
    list.AddNode(100);
    list.Print();
    Node *mid = list.FindMiddle();
    std::cout<<"Middle ele - " << mid->data << std::endl;
    Node *kthEle = list.FindKthElementFromEnd(2);
    if(kthEle)
        std::cout<<"kthEle ele - " << kthEle->data << std::endl;

    list.Reverse();
    list.Print();
    return 0;
}
