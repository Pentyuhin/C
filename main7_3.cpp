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

void add_after(node_ptr& list);
void delete_node(node_ptr& a_list);

void insertion_sort(node_ptr& a_list);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    node_ptr list = nullptr;

    assign_list(list);
    print_list(list);

    add_after(list);
    delete_node(list);
    insertion_sort(list);


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

void add_after(node_ptr& list)
{

    char search_word[MAX_WORD_LENGTH];

    cout << "\nПОСЛЕ КАКОГО СЛОВА ВЫ ХОТИТЕ ВСТАВИТЬ НОВОЕ СЛОВО? ";
    cin >> search_word;

    node_ptr current = list, new_node = nullptr;

    assign_new_node(new_node);
    cout << "Введите новое слово для вставки: ";
    cin >> new_node->word;

    while (current != nullptr)
    {

        if (!strcmp(current->word, search_word))
        {
            new_node->ptr_to_next_node = current->ptr_to_next_node;
            current->ptr_to_next_node = new_node;
            print_list(list);
            return;
        }

        current = current->ptr_to_next_node;
    }

}



void delete_node(node_ptr& a_list)
{
    char search_word[MAX_WORD_LENGTH];

    cout << "\nКАКОЕ СЛОВО ВЫ ХОТИТЕ УДАЛИТЬ? ";
    cin >> search_word;

    if (!strcmp(a_list->word, search_word))
    {
        node_ptr old_head = a_list;
        a_list = a_list->ptr_to_next_node;
        delete old_head;
        cout << "Слово успешно удалено." << endl;
        print_list(a_list);
        return;
    }
    else
    {
        node_ptr prev_word = a_list;
        node_ptr cur_cord = a_list->ptr_to_next_node;

        while (cur_cord != nullptr)
        {
            if (!strcmp(cur_cord->word, search_word))
            {
                prev_word->ptr_to_next_node = cur_cord->ptr_to_next_node;
                delete cur_cord;
                cout << "Слово успешно удалено." << endl;
                print_list(a_list);
                return;
            }

            prev_word = cur_cord;
            cur_cord = cur_cord->ptr_to_next_node;
        }
    }

    cout << "Слово не найдено в списке." << endl;

    print_list(a_list);
}



void insertion_sort(node_ptr& a_list)
{
    if (a_list == nullptr || a_list->ptr_to_next_node == nullptr)
    {
        return; // Список пуст или содержит только один элемент, уже отсортирован
    }

    node_ptr sorted_list = nullptr;
    node_ptr current = a_list;

    while (current != nullptr)
    {
        node_ptr next = current->ptr_to_next_node;
        insert_node_sorted(sorted_list, current);
        current = next;
    }

    a_list = sorted_list;
}

void insert_node_sorted(node_ptr& sorted_list, node_ptr node_to_insert)
{
    if (sorted_list == nullptr || strcmp(node_to_insert->word, sorted_list->word) <= 0)
    {
        node_to_insert->ptr_to_next_node = sorted_list;
        sorted_list = node_to_insert;
    }
    else
    {
        node_ptr current = sorted_list;
        while (current->ptr_to_next_node != nullptr && strcmp(node_to_insert->word, current->ptr_to_next_node->word) > 0)
        {
            current = current->ptr_to_next_node;
        }
        node_to_insert->ptr_to_next_node = current->ptr_to_next_node;
        current->ptr_to_next_node = node_to_insert;
    }
}
