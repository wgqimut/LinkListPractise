//
// Created by Grady on 2016/12/17.
//

#ifndef JUSTP_LINKLISTPROBLEM_H
#define JUSTP_LINKLISTPROBLEM_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;

typedef struct RandomNode {
    int data;
    struct RandomNode* next;
    struct RandomNode* random;
} RandomNode;

#define LENGTH(arr) (sizeof(arr) / sizeof(int))

void Push(Node** listHead, int newData);
Node* BuildSimpleList();
Node *BuildList(int *arr, int size);
int Count(Node* head, int searchFor);
int GetNth(Node *head, int index);

void DeleteList(Node** head);
int Pop(Node **head);

void InsertNth(Node **head, int index, int newData);

void printList(Node *head);
void SortedInsert(Node **head, Node *newNode);
void InsertSort(Node **head);

void Append(Node **aHead, Node **bHead);
void FrontBackSplit(Node *source, Node **frontHead, Node **backHead);
void RemoveDuplicates(Node *head);
void MoveNode(Node **destHead, Node **sourceHead);
void AlternatingSplit(Node *source, Node **aHead, Node **bHead);
Node *SortedMerge(Node *a, Node *b);
void MergeSort(Node **headRef);
Node *ShuffleMerge(Node *a, Node *b);
Node *SortedIntersect(Node *a, Node *b);
void Reverse(Node** head);

int FindMergeNode(Node *headA, Node *headB);

DoubleNode* SortedInsert(DoubleNode *head,int data);
RandomNode* CopyRandomList(RandomNode* head);
void PrintRandomList(RandomNode* head);
Node* GetEntryOfLoopLinkList(Node* head);


#endif //JUSTP_LINKLISTPROBLEM_H
