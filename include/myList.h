#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T item;
    Node<T> * next;
    Node<T> * before;
};
template <class type>
class myList
{
    public:
        class Iterator
        {
            private:
                friend myList;
                Node<type> *current;
            public:
                Iterator()
                {
                    current = NULL;
                };
                Iterator(Node<type> *ptr)
                {
                    current = ptr;
                };
                Iterator operator ++ ()
                {
                    current = current->next;
                    return *this;
                }
                Iterator operator -- ()
                {
                    current = current->before;
                    return *this;
                };
                type& operator * ()
                {
                    return (this->current->item);
                };
                bool operator == (const Iterator & ptr)
                {
                    return (current == ptr.current);
                };
                bool operator != (const Iterator & ptr)
                {
                    return (current != ptr.current);
                };
        };
        myList()
        {
            Node<type> *newNode;
            newNode = new Node<type>;
            newNode->item = NULL;
            newNode->before = NULL;
            newNode->next = NULL;
            first = newNode;
            last = newNode;
            length = 0;
        };
        ~myList()
        {
            Node<type> *temp;
            while (first != NULL)
            {
                temp = first;
                first = first->next;
                delete temp;
            }
            last = NULL;
            length = 0;
        };
        int Size()
        {
            return length;
        };
        void Insert(type value, Iterator &position)
        {
            if(position == first)
            {
                Node<type> *newNode;
                newNode = new Node<type>;
                newNode->item = value;
                newNode->before =   NULL;
                newNode->next = position.current;
                position.current->before = newNode;
                first = newNode;
                --position;
                length++;
                return;
            }
            Node<type> *temp = first;
            while(temp != NULL)
            {
                if(position == temp)
                {
                    Node<type> *newNode;
                    newNode = new Node<type>;
                    newNode->item = value;
                    newNode->before = position.current->before;
                    newNode->next = position.current;
                    position.current->before->next = newNode;
                    position.current->before = newNode;
                    length++;
                    --position;
                    return;
                }
                temp = temp->next;
            }
            cout<<"Wrong Position"<<endl;
            exit(0);
        };
        Iterator Erase(Iterator &position)
        {
            if(position == first)
            {
                position.current->next->before = NULL;
                first = first->next;
                delete position.current;
                position.current = first;
                length--;
                return position;
            }
            Node<type> *temp = first;
            while(temp != last)
            {
                if(position == temp)
                {
                    position.current->before->next = position.current->next;
                    position.current->next->before = position.current->before;
                    ++position;
                    delete temp;
                    length--;
                    return position;
                }
                temp = temp->next;
            }
            cout<<"Wrong Position"<<endl;
            exit(0);
        };
        myList<type>& operator = (myList<type>& another_list)
        {
            if (first->next != NULL)
            {
                Node<type> *temp;
                while (first->next != NULL)
                {
                    temp = first;
                    first = first->next;
                    delete temp;
                }
                    last = first;
                    length = 0;
            }
            if (another_list.Begin() == another_list.End())
            {
                return *this;
            }
            else
            {
                Iterator cur = another_list.End();
                Iterator position = Begin();
                while(cur != another_list.Begin())
                {
                    --cur;
                    Insert(cur.current->item,position);
                }
                return *this;
            }
        };
        Iterator Begin()
        {
            Iterator temp(first);
            return temp;
        };
        Iterator End()
        {
            Iterator temp(last);
            return temp;
        };
        void display()
        {
            Node<type> *current = first;
            while(current != last)
            {
                cout<<current->item<<endl;
                current = current->next;
            }

        };
    protected:
        Node<type> *last;
        Node<type> *first;
        int length;
    private:

};

#endif // MYLIST_H
