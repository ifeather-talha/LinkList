#include<iostream>
using namespace std;
struct Node
{
    int value;
    Node* next;
    Node* prev;
};

class LinkList
{
    private:
        Node obj;
        Node* Head;
        Node* Tail;
        int size;
    public:

        LinkList()
        {
            Head = NULL;
            Tail = NULL;
            size = 0;
        }

        void newElement(int value)
        {
            Node* obj = new Node;
            obj->value = value;
            if (Head == NULL)
            {
                Head = obj;
                Tail = obj;
                Head->next = NULL;
                Head->prev = NULL;
            }
            else
            {
                Tail->next = obj;
                obj->prev = Tail;
                Tail = obj;
                Tail->next = NULL;
            }
            size++;
        } 

        void displayStack()
        {
            Node* temp = Tail;
            cout << "Stack :- \n";
            while (temp != NULL)
            {
                cout << "\t" << temp->value << endl;
                temp = temp->prev;
            }
        } 

        void displayQueue()
        {
            Node* temp = Head;
            cout << "Queue: ";
            while (temp != NULL)
            {
                cout << "\t" << temp->value;
                temp = temp->next;
            }
            
        } 

        void deleteElement(int target)
        {
            int count = 0;
            if (target == Head->value)
            {
                Head = Head->next;
                Head->prev = NULL;
                cout << Head->value;
            }
            else
            {
                Node* temp = Head;
                while (temp != NULL)
                {
                    if (temp->value == target)
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        count++;
                        break;
                    }
                    temp = temp->next;
                }
                if (count == 0)
                {
                    cout << "\nNo Such Value in List\n";
                }   
            }  
            
        } 

        void addBetween(int value, int position)
        {
            Node* obj = new Node;
            obj->value = value;

            while (position < 0 || position > size + 1)
            {
                cout << "Size of List is: " << size << endl;
                cout << "Enter Valid Position: ";
                cin >> position;
            }

            if (position == 1)
            {
                
                Head->prev = obj;
                obj->next = Head;
                Head = obj;
                Head->prev = NULL;
            }
            else
            {
                Node* ptr = Head;
                for (int i = 1; i <= size; i++)
                {
                    if (i + 1 == position)
                    {
                        Node* temp = ptr->next;
                        ptr->next = obj;
                        obj->next = temp;
                        obj->prev = ptr;
                        temp->prev = obj;
                    }
                    ptr = ptr->next;
                }   
            } 
        }

        void swapNodes(int v1 , int v2)
        {
            int count = 0;
            int fpos = 1;
            int spos = 1;
            Node * check = Head;
            while(check != NULL)
            {
                if (check->value == v1 || check->value == v2)
                {   
                    count++;
                }
                check = check->next;
            }

            if (count != 2)
            {
                cout << "Required Values Dont Exist in LinkList\n";
            }
            else
            {
                Node* first = Head;
                Node* second = Head;
                
                while (first->value != v1)
                {
                    first = first->next;
                    fpos++;
                }
                while (second->value != v2)
                {
                    second = second->next;
                    spos++;
                }
                

                // cout << first->value << "\t" << second->value;
                deleteElement(first->value);
                deleteElement(second->value);

                // addBetween(second->value,spos);
                // addBetween(first->value,fpos);
            }  
        }
};

int main()
{
    LinkList list;
    list.newElement(10);
    list.newElement(20);
    list.newElement(30);
    list.addBetween(25,1);
   // list.swapNodes(25,30);
    list.deleteElement(25);
    list.deleteElement(30);
    list.displayQueue();
}