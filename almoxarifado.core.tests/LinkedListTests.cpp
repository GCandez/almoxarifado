#include <gtest/gtest.h>

extern "C"
{
    #include <almoxarifado.core/LinkedList.h>
}

TEST(LinkedListTests, ListNew_ShouldReturnProperlyInitializedList)
{
    List* list = List_New(NULL);

    EXPECT_TRUE(list); //list shouldnt be null
    EXPECT_FALSE(list->Head); //list->head should be null
    EXPECT_FALSE(list->Tail);
    EXPECT_EQ(list->Length, 0);
}

// --- List_Append Tests --- //
TEST(LinkedListTests, ListAppend_ShouldAddItemsToTheEndOfTheList)
{
    List* list = List_New(NULL);

    int first = 5;
    int second = 15;
    int third = 20;

    List_Append(list, &first);
    List_Append(list, &second);
    List_Append(list, &third);

    int last_node_value = *(int*)list->Tail->Data;

    ASSERT_EQ(last_node_value, third);
}

TEST(LinkedListTests, ListAppend_ShouldIncreaseListLengthProperty)
{
    List* list = List_New(NULL);

    List_Append(list, NULL);
    ASSERT_EQ(list->Length, 1);

    List_Append(list, NULL);
    ASSERT_EQ(list->Length, 2);

    List_Append(list, NULL);
    ASSERT_EQ(list->Length, 3);
}

TEST(LinkedListTests, ListAppend_ShouldProperlyChangeNodesLinks)
{
    List* list = List_New(NULL);

    Node* nodes[3];
    for(int i = 0; i < 3; i++)
    {
        List_Append(list, NULL);
        nodes[i] = list->Tail;
    }

    Node* first_node = nodes[0];
    Node* second_node = nodes[1];
    Node* third_node = nodes[2];

    EXPECT_EQ(first_node->Next, second_node);
    EXPECT_EQ(second_node->Previous, first_node);

    EXPECT_EQ(second_node->Next, third_node);
    EXPECT_EQ(third_node->Previous, second_node);
}

// --- List_Prepend Tests --- //
TEST(LinkedListTests, ListPrepend_ShouldAddItemsToTheBegginingOfTheList)
{
    List* list = List_New(NULL);

    int first = 5;
    int second = 10;
    int third = 15;

    List_Prepend(list, &first);
    List_Prepend(list, &second);
    List_Prepend(list, &third);

    int first_node_value = *(int*)list->Head->Data;


    ASSERT_EQ(first_node_value, third);
}

TEST(LinkedListTests, ListPrepend_ShouldIncreaseListLengthProperty)
{
    List* list = List_New(NULL);

    List_Prepend(list, NULL);
    EXPECT_EQ(list->Length, 1);

    List_Prepend(list, NULL);
    EXPECT_EQ(list->Length, 2);

    List_Prepend(list, NULL);
    EXPECT_EQ(list->Length, 3);
}

TEST(LinkedListTests, ListPrepend_ShouldProperlyChangeNodesLinks)
{
    ASSERT_TRUE(false);
    List* list = List_New(NULL);

    Node* nodes[3];
    for(int i  = 0; i < 3; i++)
    {
        List_Prepend(list, NULL);
        nodes[i] = list->Head;
    }

    Node* first_node = nodes[2];
    Node* second_node = nodes[1];
    Node* third_node = nodes[0];

    EXPECT_EQ(first_node->Next, second_node);
    EXPECT_EQ(second_node->Previous, first_node);

    EXPECT_EQ(second_node->Next, third_node);
    EXPECT_EQ(third_node->Previous, second_node);
}