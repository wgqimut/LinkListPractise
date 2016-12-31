#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
//#include "MyStack.h"
#include "LinkListProblem.h"

void Weclome(const char* func_name) {
	printf("\nWeclome %s world....\n", func_name);
}

void End(const char *func_name) {
	printf("%s end\n", func_name);
}

void CountTest() {
	Weclome(__func__);

	Node* newList = BuildSimpleList();
	Push(&newList, 2);
	int count = Count(newList, 2);
	printf("The count of %d is %d in newList\n", 2, count);
	End(__func__);
}

void GetNthTest() {
	Weclome(__func__);

	int index = 4;
	Node* myList = BuildSimpleList();
	int num = GetNth(myList, index);
	if (num == -1) {
		printf("Can't get the index %d number\n", index);
	} else {
		printf("the location %d is %d\n", index, num);
	}
	End(__func__);

}

void DeleteListTest() {
	Weclome(__func__);

	Node* myList = BuildSimpleList();
	DeleteList(&myList);
	if (myList) {
		printf("Delete Wrong...");
	}

	End(__func__);
}

void PopTest() {
	Weclome(__func__);
	int data = -1;
	Node *myList = BuildSimpleList();
	while (GetNth(myList, 0) != -1) {
		data = Pop(&myList);
		printf("Pop data = %d\n", data);
	}
	printf("build it, and destroy it success!!!\n");
	End(__FUNCTION__);
}

void InsertNthTest() {
	Weclome(__func__);
	Node* head = nullptr;

	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);

	printList(head);

	DeleteList(&head);
	End(__func__);
}

Node *GeneNode(int newData) {
	Node *newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;

	return newNode;
}

void SortedInsertTest() {
	Weclome(__func__);
	Node *myList = nullptr;

	SortedInsert(&myList, GeneNode(2));
	SortedInsert(&myList, GeneNode(1));
	SortedInsert(&myList, GeneNode(3));

	printList(myList);
	End(__FUNCTION__);
}

void DoAppend(Node** aList, Node** bList) {

	printf("before append: \n");
	printf("a list: \n");
	printList(*aList);
	printf("b list: \n");
	printList(*bList);

	Append(aList, bList);
	printf("After append: \n");
	printf("a list: \n");
	printList(*aList);
	printf("b list: \n");
	printList(*bList);
}

void AppendTest() {
	Weclome(__func__);

	Node* aList = nullptr;
	Node* bList = BuildSimpleList();
	DoAppend(&aList, &bList);

	Node* aaList = BuildSimpleList();
	Node* bbList = nullptr;
	DoAppend(&aaList, &bbList);

	Node* aaaList = BuildSimpleList();
	Node* bbbList = BuildSimpleList();
	DoAppend(&aaaList, &bbbList);

	Node* aaaaList = nullptr;
	Node* bbbbList = nullptr;
	DoAppend(&aaaaList, &bbbbList);

	End(__func__);
}

void FrontBackSplitTest() {
	Weclome(__FUNCTION__);
	Node* source = nullptr;
	int a[] = {2, 3, 5, 7, 11};

	int length = sizeof(a) / sizeof(int);
	for (int i = length - 1; i >= 0; --i) {
		Push(&source, a[i]);
	}
	printf("before split list:\n");
	printList(source);

	Node* frontHead = nullptr;
	Node* backHead = nullptr;
	FrontBackSplit(source, &frontHead, &backHead);
	printf("After split list:\n");
	printf("front list:\n");
	printList(frontHead);
	printf("back list:\n");
	printList(backHead);


	End(__func__);
}

void InsertSortTest() {
	Weclome(__func__);

	Node* head = nullptr;

	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	printf("before sort list:\n");
	printList(head);

	InsertSort(&head);
	printf("After sort list:\n");
	printList(head);

	End(__func__);
}

void RemoveDuplicatesTest() {
	Node* myList = nullptr;
	int a[] = {2, 2, 2, 3, 3, 7, 11, 11, 11, 45, 34, 34};

	int length = sizeof(a) / sizeof(int);
	for (int i = length - 1; i >= 0; --i) {
		Push(&myList, a[i]);
	}
	printf("before remove duplicates list: \n");
	printList(myList);

	RemoveDuplicates(myList);
	printf("After remove duplicates list: \n");
	printList(myList);
}

void MoveNodeTest() {
	Weclome(__func__);
	Node* destHead = BuildSimpleList();
	Node* sourceHead = BuildSimpleList();

	printf("Before Move node:\n");
	printf("Source list:\n");
	printList(sourceHead);
	printf("Dest list:\n");
	printList(destHead);
	MoveNode(&destHead, &sourceHead);
	printf("After Move node:\n");
	printf("Source list:\n");
	printList(sourceHead);
	printf("Dest list:\n");
	printList(destHead);

	End(__func__);
}

void AlternatingSplitTest() {
	Weclome(__func__);

	Node* myList = nullptr;
	int a[] = {2, 3, 4, 5, 6, 7, 8};

	int length = sizeof(a) / sizeof(int);
	for (int i = length - 1; i >= 0; --i) {
		Push(&myList, a[i]);
	}
	printf("Before Split list:\n");
	printList(myList);

	Node* aHead = nullptr;
	Node* bHead = nullptr;
	AlternatingSplit(myList, &aHead, &bHead);
	printf("After split list:\n");
	printf("myList is :\n");
	printList(myList);
	printf("a list:\n");
	printList(aHead);
	printf("b list:\n");
	printList(bHead);

	End(__func__);
}

void SortedMergeTest() {
	Weclome(__func__);
	Node* aList = nullptr;
	Node* bList = nullptr;
//	int a[] = {1, 1, 2, 3, 4};
//	int b[] = {3, 4, 4, 5};
	int a[] = {1};
	int b[] = {3};
	aList = BuildList(a, LENGTH(a));
	bList = BuildList(b, LENGTH(b));
	printf("Before merge list:\n");
	printf("a list : \n");
	printList(aList);
	printf("b list: \n");
	printList(bList);

	Node* newList = SortedMerge(aList, bList);
	printf("After merge list:\n");
	printf("new list : \n");
	printList(newList);
	printf("b list: \n");
	printList(bList);
	End(__func__);
}

void MergeSortTest() {
	Weclome(__func__);
	Node* myList = nullptr;
	int a[] = {6, 2, 9, 4, 3, 6, 1, 7, 2};
	myList = BuildList(a, LENGTH(a));
	printf("Before merge sort list:\n");
	printList(myList);

	MergeSort(&myList);
	printf("After merge sort list:\n");
	printList(myList);
	End(__func__);
}

void ShuffleMergeTest() {
	Weclome(__func__);
	Node* aList = nullptr;
	Node* bList = nullptr;
	Node* resultList = nullptr;
	int a[] = {1, 2, 3};
	int b[] = {7, 13, 1};
	aList = BuildList(a, LENGTH(a));
	bList = BuildList(b, LENGTH(b));

	printf("Before merge list:\n");
	printf("a list:\n");
	printList(aList);
	printf("b list:\n");
	printList(bList);

	resultList = ShuffleMerge(aList, bList);
	printf("After merge list:");
	printf("result list:\n");
	printList(resultList);
	printf("b list:\n");
	printList(bList);


	End(__func__);
}

void SortedIntersectTest() {
	Weclome(__func__);

	Node *aList = nullptr;
	Node *bList = nullptr;
	Node* resultList = nullptr;
	int a[] = {1, 2, 3, 6, 8};
	int b[] = {3, 3, 8, 10};
	aList = BuildList(a, LENGTH(a));
	bList = BuildList(b, LENGTH(a));

	printf("Before sort intersect list:\n");
	printf("a list:\n");
	printList(aList);
	printf("b list:\n");
	printList(bList);

	resultList = SortedIntersect(aList, bList);
	printf("After sort intersect list:\n");
	printf("result list:\n");
	printList(resultList);
	printf("a list:\n");
	printList(aList);
	printf("b list:\n");
	printList(bList);

	End(__func__);
}

void ReverseTest() {
	Weclome(__func__);
	Node* head;

	int a[] = {1, 2, 3};
	head = BuildList(a, LENGTH(a));
	printf("Before reverse list:\n");
	printList(head);
	Reverse(&head);
	printf("After reverse list:\n");
	printList(head);
	DeleteList(&head);

	End(__func__);
}

void FindMergeNodeTest() {
	Weclome(__func__);
	Node* headA;
	Node* headB;

	int a[] = {1, 4, 5, 6, 7};
	int b[] = {9, 5};
	headA = BuildList(a, LENGTH(a));
	Node* temp = headA;
	for (int i = 0; i < 3; ++i) {
		temp = temp->next;
	}

	headB = BuildList(b, LENGTH(b));
	Node* tempB = headB;
	while (tempB->next != nullptr) {
		tempB = tempB->next;
	}
	tempB->next = temp;
	int pos = FindMergeNode(headA, headB);
	printf("the position is %d\n", pos);

	End(__func__);
}

void CopyRandomListTest() {
	Weclome(__func__);
	RandomNode* newHead;
	RandomNode** curRef = &newHead;
	std::map<int, RandomNode*> numNodeMap;

	for (int i = 0; i < 10; ++i) {
		RandomNode *newNode = new RandomNode();
		numNodeMap[i] = newNode;
		newNode->data = i;
		newNode->next = nullptr;
		*curRef = newNode;
		curRef = &((*curRef)->next);
	}

	RandomNode* cur = nullptr;
	std::srand(std::time(0));
	for (cur = newHead; cur != nullptr; cur = cur->next) {
		cur->random = numNodeMap[std::rand() % 10];
	}
	printf("Before copy, old list is:\n");
	PrintRandomList(newHead);

	RandomNode* newNewHead;
	newNewHead = CopyRandomList(newHead);
	printf("After copy, old list is:\n");
	PrintRandomList(newHead);
	printf("new list is:\n");
	PrintRandomList(newNewHead);
	End(__func__);
}

int main()
{
	Node* newList = nullptr;
	newList = BuildSimpleList();

	Node* cur = newList;
	for (int i = 0; cur != nullptr; cur = cur->next, ++i) {
		printf("Node %d data = %d\n", i, cur->data);
	}

	CountTest();
	GetNthTest();
	DeleteListTest();
	PopTest();
	InsertNthTest();
	SortedInsertTest();
	InsertSortTest();
	AppendTest();
	FrontBackSplitTest();
	RemoveDuplicatesTest();
	MoveNodeTest();
	AlternatingSplitTest();
	SortedMergeTest();
	MergeSortTest();
	ShuffleMergeTest();
	SortedIntersectTest();
	ReverseTest();
	FindMergeNodeTest();
	CopyRandomListTest();

	return 0;
}

