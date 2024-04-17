#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <windows.h>


struct node;
using node_ptr = node*;
constexpr int MAX_WORD_LENGTH = 50;

using namespace std;

struct node
{
    char word[MAX_WORD_LENGTH]{};
    node_ptr ptr_to_next_node = nullptr;
};

void assign_list(node_ptr& a_list);
void assign_new_node(node_ptr& a_list);
void print_list(node_ptr a_list);

void add_after(node_ptr& list, char a_word[], char word_after[]);
void delete_node(node_ptr& a_list, char a_word[]);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    node_ptr list = nullptr;

    char a_word[MAX_WORD_LENGTH]{};
    char word_after[MAX_WORD_LENGTH]{};

    assign_list(list);
    print_list(list);

    add_after(list, a_word, word_after);
    delete_node(list, a_word);
   

    return 0;
}

void assign_list(node_ptr& a_list)
{
    node_ptr current_node = nullptr, last_node = nullptr;

    assign_new_node(a_list);
    cout << "Введите первое слово";
    cout << "( или '.' для завершение списка ): ";
    cin >> a_list->word;
    if (!strcmp(".", a_list->word))
    {
        delete a_list;
        a_list = nullptr;
    }

    current_node = a_list;

    while (current_node != nullptr)
    {
        assign_new_node(last_node);
        cout << "Введите следующее слово";
        cout << "( или '.' для завершение списка ): ";
        cin >> last_node->word;
        if (!strcmp(".", last_node->word))
        {
            delete last_node;
            last_node = nullptr;
            current_node->ptr_to_next_node = nullptr;
            break;
        }
        current_node->ptr_to_next_node = last_node;
        current_node = last_node;
    }
}

void assign_new_node(node_ptr& a_list)
{
    a_list = new node;
    if (!a_list)
    {
        cout << "Извините, недостаточно оперативной памяти";
        exit(1);
    }
}

void print_list(node_ptr a_list)
{
    cout << "ТЕКУЩЕЕ СОДЕРЖИМОЕ СПИСКА: \n";
    while (a_list)
    {
        cout << a_list->word << " ";
        a_list = a_list->ptr_to_next_node;
    }
}

void add_after(node_ptr& list, char a_word[], char word_after[])
{
    
    char search_word[MAX_WORD_LENGTH];

    cout << "ПОСЛЕ КАКОГО СЛОВА ВЫ ХОТИТЕ ВСТАВИТЬ НОВОЕ СЛОВО? ";
    cin >> search_word;

    node_ptr current = list, new_node = nullptr;

    while (current != nullptr && strcmp(current->word, search_word) != 0)
    {
        current = current->ptr_to_next_node;
    }

    if (current != nullptr)
    {
       
        assign_new_node(new_node);
        cout << "Введите новое слово для вставки: ";
        cin >> new_node->word;

        if (current->ptr_to_next_node != nullptr)
        {
            new_node->ptr_to_next_node = current->ptr_to_next_node;
            current->ptr_to_next_node = new_node;
        }
        else
        {
            current->ptr_to_next_node = new_node;
            new_node->ptr_to_next_node = nullptr;
        }
    }
    else
    {
        cout << "Не удалось найти указанное слово в списке." << endl;
    }

    print_list(list);
}


void delete_node(node_ptr& a_list, char a_word[]) 
{
    node_ptr current = a_list, previous = nullptr;

    char search_word[MAX_WORD_LENGTH];

    cout << "КАКОЕ СЛОВО ВЫ ХОТИТЕ УДАЛИТЬ? ";
    cin >> search_word;

    while (current != nullptr && strcmp(current->word, search_word) != 0) 
    {
        previous = current;
        current = current->ptr_to_next_node;
    }

    if (current == nullptr) {
        cout << "Слово не найдено в списке." << endl;
        return;
    }


    if (previous == nullptr) {
        current = current->ptr_to_next_node; // Удаляем первый узел
    }
    else {
        previous->ptr_to_next_node = current->ptr_to_next_node; // Обновляем связи
    }

    delete current; // Удаляем найденный узел

    print_list(a_list);
}