#include <almoxarifado.core/LinkedList.h>
// --- PRIVATE FUNCTIONS --- //

static Node* Node_New(void* element)
{
    Node* node = malloc(sizeof(Node));

    node->Data = element;
    node->Next = NULL;
    node->Previous = NULL;
}

// --- INTERFACE IMPLEMENTATION --- //
List* List_New(FreeElementFunction free_element)
{
    List* list = malloc(sizeof(List));

    list->Free = free_element;
    list->Head = NULL;
    list->Tail = NULL;
    list->Length = 0;

    return list;
}
void List_Destroy(List* list);

void List_Append(List* list, void* element)
{
    Node* new_node = Node_New(element);    
    
    if(list->Length == 0)
    {
        list->Head = new_node;
    }

    if(list->Tail)
    {
        list->Tail->Next = new_node;
        new_node->Previous = list->Tail;
    }

    list->Tail = new_node;
    list->Length++;
}
void List_Prepend(List* list, void* element)
{
    Node* new_node = Node_New(element);
    
    if(list->Length == 0)
    {
        list->Tail = new_node;
    }
    if(list->Head)
    {
        list->Head->Previous = new_node;
        new_node->Next = list->Head;
    }

    list->Head = new_node;
    list->Length++;
}
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