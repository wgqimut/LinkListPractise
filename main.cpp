#include <iostream>
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

int main()
{
	/* stack exapmple
	MyStack new_stack = MyStack();
	if (new_stack.isEmpty()) {
		new_stack.push(1);
		new_stack.push(3);
		new_stack.push(5);
	} else {
		cout << "WTF" << endl;
	}

	int stack_size = new_stack.size();
	cout << "stack size is:" << stack_size << endl;
	cout << "the stack content is:" << endl;
	for (int i = 0; i < stack_size; ++i) {
		cout << new_stack.pop() << endl;
	}

	return 0;
	 */

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

	return 0;
}

