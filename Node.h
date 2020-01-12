class Node
{
    int data;
    Node *next;
    public:
    Node(const int& value)
    {
        this->data = value;
        this->next = NULL;
    }
    Node(const Node& node)
    {
        this->data = node.data;
        this->next = node.next;
    }
};
