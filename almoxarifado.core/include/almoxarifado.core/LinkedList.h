#ifndef __LINKEDLIST_HEADERFILE
#define __LINKEDLIST_HEADERFILE

#include<stdbool.h>
#include<stdlib.h>

typedef void (*FreeElementFunction)(void* element);
typedef bool (*IteratorFunction)(void* element);
typedef int (*ElementCompareFunction)(void* first, void* second);

typedef enum _SortingOrder { ASCENDING, DESCENDING} SortingOrder;

typedef struct _Node
{
    void* Data;
    struct _Node* Next;
    struct _Node* Previous;
} Node;

typedef struct _List
{
    size_t Length;

    Node* Head;
    Node* Tail;

    FreeElementFunction Free;
} List;

List* List_New(FreeElementFunction free_element);
void List_Destroy(List* list);

void List_Append(List* list, void* element);
void List_Prepend(List* list, void* element);
void List_AppendMany(List* list, List* elements);
void List_PrependMany(List* list, List* elements);

void* List_FindFirst(List* list, ElementCompareFunction compare, void* element);
void* List_FindLast(List* list, ElementCompareFunction compare, void* element);
List* List_FindMany(List* list, ElementCompareFunction compare, void* element);

bool List_RemoveFirst(List* list, ElementCompareFunction compare, void* element);
bool List_RemoveLast(List* list, ElementCompareFunction compare, void* element);
size_t List_RemoveMany(List* list, ElementCompareFunction compare, void* element);

void List_ForEach(List* list, IteratorFunction iterator);

void List_Sort(List* list, ElementCompareFunction compare, SortingOrder order);

#endif