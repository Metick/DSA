#pragma once
#include <iostream>
#include <cstring>

struct list_s
{
    void     *value;
    list_s   *next;
    list_s   *prev;
};


//If i wanted to we could've done the InsertAt / get ect, the ones that use a index to check from which side would be fastest to loop
//For example we could do size / 2 and check if it's under to loop from head, if it's above loop from tails
//I just didn't wanna spend my time doing that as i already understand how that works / can be implemented.
template <typename T>
class linked_list
{
private:
    list_s *head = nullptr;
    list_s *tail = nullptr;
    size_t size = 0;

    void pop()
    {
        if (!head)
            return;
        auto tmp = head;
        head = head->next;
        head->prev = tmp->prev;

        tmp->next = nullptr;
        tmp->prev = nullptr;
        free(tmp->value);
        free(tmp);
        tmp = nullptr;
    }

    list_s *create(T value)
    {
        list_s* new_node = (list_s*)malloc(sizeof(list_s));
        if (!new_node)
            std::runtime_error("Failed to allocate memory for list\n");
        new_node->value = (void*)(T)malloc(sizeof(T));
        if (!new_node->value)
            std::runtime_error("Failed to allocate memory for list\n");
        new_node->value = reinterpret_cast<void*>(value);
        new_node->next = nullptr;
        new_node->prev = nullptr;
        return new_node;
    }

public:

    linked_list(T value) 
    {
        head = create(value);
        tail = head;
        size++;
    }

    ~linked_list()
    {
        if (!head)
            return;
        while (head)
            pop();
    }

    size_t length()
    {
        return size;
    }

    void insertAt(T value, size_t index)
    {
        size_t current_index = 0;
        list_s *tmp = head;
        while(tmp != nullptr)
        {
            if(current_index == index)
            {
                list_s *new_tmp = tmp;
                list_s *new_node = create(value);
                new_node->next = tmp;
                new_node->prev = tmp->prev;
                tmp->prev->next = new_node;
                tmp->prev = new_node;
                tmp = new_node;
                size++;
                break;
            }
            current_index++;
            tmp = tmp->next;
        }
    }

    void remove(T value)
    {
        if (head == nullptr)
            return;
        list_s *tmp = head;
        while(tmp != nullptr)
        {
            if(reinterpret_cast<T>(tmp->value) == value)
            {
                //Previous node Next value becomes the ptr to the one that's next to the one we're removing.
                tmp->prev->next = tmp->next;
                //The Next nodes previous value becomes the one before this nodes ptr.
                tmp->next->prev = tmp->prev;
                size--;
                tmp->next = nullptr;
                tmp->prev = nullptr;
                free(tmp->value);
                free(tmp);
                break;
            }
            tmp = tmp->next;
        }
    }

    void removeAt(size_t index)
    {
        size_t current_index = 0;
        if (head == nullptr)
            return;
        list_s *tmp = head;
        while(tmp != nullptr)
        {
            if(current_index == index)
            {
                //Previous node Next value becomes the ptr to the one that's next to the one we're removing.
                tmp->prev->next = tmp->next;
                //The Next nodes previous value becomes the one before this nodes ptr.
                tmp->next->prev = tmp->prev;
                    size--;
                tmp->next = nullptr;
                tmp->prev = nullptr;
                free(tmp->value);
                free(tmp);
                break;
            }
            current_index++;
            tmp = tmp->next;
        }
    
    }

    void print()
    {
        list_s *tmp = head;
        while (tmp)
        {
            std::cout << "Node: " << tmp << std::endl;
            std::cout << "Next: " << tmp->next << std::endl;
            std::cout << "Prev: " << tmp->prev << std::endl;
            std::cout << "Value: " << (T)tmp->value << std::endl;
            tmp = tmp->next;
        }
    }

    void append(T value)
    {
        if (head == nullptr)
            return;
        list_s *new_node = create(value);
        auto tmp = tail;
        tail = new_node;
        tail->prev = tmp;
        tmp->next = tail;
        size++;
    }

    //Understand that while size = 1, we still go for the assumption that we start at 0, so index 0 = first.
    T get(size_t index)
    {
        size_t current_index = 0;
        list_s *tmp = head;
        T value;
        std::memset(&value, 0, sizeof(T));
        while(tmp != nullptr)
        {
            if(current_index == index)
                return reinterpret_cast<T>(tmp->value);
            tmp = tmp->next;
            current_index++;
        }
        return value;
    }
};