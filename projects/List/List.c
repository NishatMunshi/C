#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *begin, *end; // As in C++ end is one after the end
    unsigned size;
} List;

List create_list()
{
    List list;

    list.begin = (Node *)malloc(sizeof(Node));
    list.end = list.begin;

    list.end->data = 0;
    list.end->next = NULL;

    list.size = 0;

    return list;
}
void push(List *const _list, const int _data)
{
    _list->end->data = _data;

    _list->end->next = (Node *)malloc(sizeof(Node));
    _list->end = _list->end->next;

    _list->end->data = 0;
    _list->end->next = NULL;

    _list->size++;
}
Node *at(const List *const _list, const unsigned _index)
{
    assert(_index < _list->size);

    Node *thisNode = _list->begin;
    for (unsigned i = 0; i < _index; ++i)
    {
        thisNode = thisNode->next;
    }
    return thisNode;
}

void pop(List *const _list)
{
    Node *newEnd = _list->begin;
    for (unsigned i = 0; i < _list->size - 1; ++i)
    {
        newEnd = newEnd->next;
    }

    free(newEnd->next);
    _list->end = newEnd;

    _list->end->data = 0;
    _list->end->next = NULL;

    _list->size--;
}

void add_after(List *const _list, const unsigned _index, const int _data)
{
    Node *const nodeToAddAfter = at(_list, _index);

    Node *const newNode = (Node *)malloc(sizeof(Node));

    newNode->data = _data;
    newNode->next = nodeToAddAfter->next;

    nodeToAddAfter->next = newNode;

    _list->size++;
}
int main()
{
    List list = create_list();
    push(&list, 5);
    push(&list, 1);
    push(&list, 3);

    add_after(&list, 2, 2);
    return 0;
}