#pragma once
#include <iostream>

using namespace std;

class List
{
private:
    struct node
    {
        node() = default;
        node(int const rhs) : data(rhs) {};
        int data;
        node* next = nullptr, * prev = nullptr;
    };

    node* head = nullptr, * tail = nullptr;
public:
    List() = default;
    int size=0;

    void push_back(int rhs)
    {
        node* nn = new node(rhs);
        int i;
        if (!head)
        {
            head = nn;
            tail = head;
        }
        else
        {
            node* tmp = head;
            for (i = 0; i < size; ++i)
            {
                tmp = tmp->next;
            }
            if (!tmp)
            {
                tail->next = nn;
                tail->next->prev = tail;
                tail = tail->next;
            }
            else
            {
                if (tmp == head)
                {
                    head->prev = nn;
                    nn->next = head;
                    head = nn;
                }
                else
                {
                    nn->next = tmp;
                    nn->prev = tmp->prev;
                    tmp->prev = nn;
                    nn->prev->next = nn;
                }
            }
        }
        size++;
    }


    void pop_front()
    {
        if (!head)
            cout << "Empty" << endl;
        else
        {
            node* temp = head;
            head = head->next;
            delete temp;
            if (head)
                head->prev = nullptr;
        }
        size--;
        if (size == 0)
            head = NULL;
    }


    void push_front(int  rhs)
    {
        node* temp = new node(rhs);
        temp->next = nullptr;
        temp->prev = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }


    void pop_back()
    {
        if (!tail)
            cout << "Empty" << endl;
        else
        {
            node* temp = tail;
            tail = tail->prev;
            delete temp;
            if (tail)
                tail->next = nullptr;
        }
        size--;
        if (size == 0)
            head = NULL;
    }


    void insert(int rhs, size_t index)
    {
        if (!head || get_size() + 1 < index)
            return;

        if (index == 0)
        {
            push_front(rhs);
        }
        else if (index == get_size() + 1)
        {
            push_back(rhs);
        }
        else
        {
            node* previous = this->head;

            for (int i = 0; i < index- 1; i++)
            {
                previous = previous->next;
            }

            node* temp = new node(rhs);

            temp->next = previous->next;
            temp->prev = previous;
            previous->next = temp;
        }
    }


    int at(int index)
    {
        int i;
        node* tmp=head;
        for (i = 0; i < index; i++) 
        {
            tmp = tmp->next;
        }

        return (int)tmp->data;
    }


    void remove(int index)
    {
        int i;
        node* tmp = head;

        for (i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }

        if (tmp == head)
        {
            if (tail == tmp)
            {
                head = tail = nullptr;
            }
            else
            {
                head = tmp->next;
                head->prev = nullptr;
            }
        }
        else if (tmp == tail)
        {
            tail = tmp->prev;
            tail->next = nullptr;
        }
        else if (tmp)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }

        delete tmp;
        tmp = nullptr;
        size--;
    }


    void print()
    {
        node* tmp = head;
        while (tmp)
        {
            cout << tmp->data << "  ";
            tmp = tmp->next;
        }
        cout << endl;
    }


    size_t get_size()
    {
        return size;
    }


    void clear()
    {
        while (size != 0)
        {
            pop_front();
        }
    }


    bool IsEmpty()
    {
        return head == nullptr;
    }


    void set(int rhs, int index)
    {
        size_t size = get_size();
        if (size >= index + 1)
        {
            node* current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->data = index;
        }
    }

   
};
