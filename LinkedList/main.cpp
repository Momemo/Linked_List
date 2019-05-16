#include<iostream>
#include<cstdlib>

using namespace std;

//*****************************************************************************
// Class has a structure that is used to create a link list
// ****************************************************************************

class Linked_List{
    
public:
    struct ListNode{
        int data;
        ListNode* next;
    };
    ListNode *head;
    Linked_List();
    void createList (int addData);
    void removeDuplicates( ListNode *list);
    void printList();
    ListNode* mergeList( ListNode* list1,  ListNode* list2);
    void AddNodeEnd(int addData);
    void addNodeFront(int addData);
    void deleteNode(int data);
    void reverse_print(ListNode* list);
    void  getCount(ListNode* head);
    void  printList_list3();
};

Linked_List::Linked_List(){
    head = NULL;
}
//*****************************************************************************
// This Function creates the list
// ****************************************************************************

void Linked_List:: createList(int addData){
    
    ListNode *newNode;
    newNode = new ListNode;
    newNode->data = addData;
    newNode->next = NULL;
    if (!head)
        head = newNode;
    else {
        ListNode *nodePtr;
        nodePtr = head;
        while (nodePtr->next){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}
//*****************************************************************************
// This Function prints the list in order
// ****************************************************************************
void Linked_List:: printList(){
    ListNode *nodePtr;
    for (nodePtr = head; nodePtr; nodePtr = nodePtr->next)
        cout << nodePtr->data << " ";
}
//*****************************************************************************
// This Function merges to the two Linked Lists together
// ****************************************************************************
Linked_List::ListNode* Linked_List:: mergeList(ListNode* list1, ListNode* list2){
    
    ListNode *temp=list1;
    while(temp->next)
        temp=temp->next;
    temp->next=list2; // adding list_2 at the end of list_1
    return list1;
}
//*****************************************************************************
// This Function is used to remove duplicates
// ****************************************************************************
void Linked_List:: removeDuplicates( ListNode *list1)
{
    struct ListNode *ptr1, *ptr2, *dup;
    ptr1 =list1;
    
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        
        /* Compare the picked element with rest
         of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
//*****************************************************************************
// This Function deletes a node given a value
// ****************************************************************************
void Linked_List::deleteNode(int value){
    
    if (!head)
        return;
    ListNode *nodePtr; // to traverse the list
    if (head->data == value) { // if first node is num
        nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;
    }
    else {
        ListNode *previousNode = nullptr; // trailing node pointer
        nodePtr = head;
        while (nodePtr && nodePtr->data != value) {
            previousNode = nodePtr; // save it!
            nodePtr = nodePtr->next; // advance it
        }
        if (nodePtr) { // num is found, set links + delete
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
//*****************************************************************************
// This Function adds a node at the end of the list
// ****************************************************************************
void Linked_List:: AddNodeEnd(int addData){
    
    ListNode *newNode;
    newNode = new ListNode;
    newNode->data = addData;
    newNode->next = NULL;
    if (!head)
        head = newNode;
    else {
        ListNode *nodePtr;
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}
//*****************************************************************************
// This Function adds nodes in the front of the list
// ****************************************************************************
void Linked_List:: addNodeFront(int addData){
    
    ListNode *newNode;
    newNode = new ListNode;
    newNode ->next =NULL;
    newNode ->data = addData;
    newNode ->next = head;// make next of new node as head
    head = newNode; // point head to new node
    
}
//*****************************************************************************
// This Function prints the list in reverser order
// ****************************************************************************
void Linked_List:: reverse_print(ListNode* list)
{
    if (list!= NULL)
    {
        reverse_print(list->next);
        cout << list->data << ' ';
    }
}
//*****************************************************************************
// This Function counts the elements in the list
// ****************************************************************************
void Linked_List:: getCount(ListNode* list)
{
    int count = 0;  // Initialize count
    ListNode* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    cout << count;
}

int main () {
    
    Linked_List list1;
    Linked_List list2;
    Linked_List list3;
    Linked_List list4;
    
    cout << "Welcome to my Singly LL Program" << endl << endl;
    
    for (int i=0; i< 15; i++){
        list1.createList(rand()%26);
    }
    for (int i=0; i< 15; i++){
        list2.createList(rand()%26);
    }
    cout << "List 1" << endl;
    list1.printList();
    cout << endl << "List 2" << endl;
    list2.printList();
    cout << endl;
    
    list3 = list1;
    list3.mergeList(list1.head, list2.head);
    cout << "List 3 " << endl;
    list3.printList();
    cout<<endl;
    list4 = list3;
    
    list4.removeDuplicates(list4.head);
    list4.AddNodeEnd(88);
    list4.AddNodeEnd(99);
    list4.addNodeFront(200);
    list4.addNodeFront(100);
    cout << "List 4" << endl;
    list4.printList();
    cout << endl << "List 4 element count is: ";
    list4.getCount(list4.head);
    list4.deleteNode(100);
    list4.deleteNode(99);
    cout << endl << "List 4 updated" << endl;
    list4.printList();
    cout <<endl << "List 4 reversed" << endl;
    list4.reverse_print(list4.head);
    cout << endl << endl << "This Simple LL program is implemented by:\n"
    "Mohammad March 27th, 2019" << endl << endl;
    
    return 0;
    
}
