//
// Created by Grady on 2016/12/17.
//
#include <stdlib.h>
#include <cstdio>
#include "LinkListProblem.h"

void Push(Node** listHead, int newData) {
	Node *newNode = new Node();
	newNode->data = newData;
	newNode->next = *listHead;

	*listHead = newNode;
}

Node* BuildSimpleList() {
	Node *newList = nullptr;
	for (int i = 3; i >= 1; --i) {
		Push(&newList, i);
	}

	return newList;
}


int Count(Node* head, int searchFor) {
	Node* cur = head;
	int count = 0;

	for (; cur != nullptr; cur = cur->next) {
		if (cur->data == searchFor) {
			count++;
		}
	}

	return count;
}


int GetNth(Node *head, int index) {
	int i = -1;
	Node* cur = head;

	for (i = 0; cur != NULL && i < index; cur = cur->next, ++i) {
	}

	if (cur && i == index) {
		return cur->data;
	} else {
		return -1;
	}
}

void DeleteList(Node** head) {
	Node* next = nullptr;
	for (Node* cur = *head; cur != nullptr; cur = next) {
		next = cur->next;
		cur->data = 0;
		cur->next = nullptr;
		free(cur);
	}

	*head = nullptr;
}


int Pop(Node **head) {
	Node* popNode = nullptr;
	int data = -1;
	if (*head) {
		popNode = *head;
		*head = (*head)->next;
		data = popNode->data;

		popNode->data = 0;
		popNode->next = nullptr;
		free(popNode);

	}

	return data;

}

void InsertNth(Node **head, int index, int newData) {
	Node* curPtr = *head;
	Node* prev = nullptr;
	int i = 0;

	for (i = 0; curPtr != nullptr && i < index; curPtr = curPtr->next, ++i) {
		prev = curPtr;
	}
	if (i == index) {
		Node *newNode = new Node();
		newNode->data = newData;
		newNode->next = curPtr;

		if (prev) {
			prev->next = newNode;
		} else {
			*head = newNode;
		}
		printf("insert %d success\n", newData);
	} else {
		printf("insert failed!!!") ;
	}
}

void printList(Node* head) {
	for (Node* cur = head; cur != nullptr; cur = cur->next) {
		printf("%d\n", cur->data);
	}
}

void SortedInsert1(Node **head, int newData) {
	Node *cur = *head;
	Node **prev = head;

	Node *newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;

	for (; cur != nullptr; cur = cur->next) {
		if (newNode->data < cur->data) {
			break;
		}
		prev = &((*prev)->next);
	}

	*prev = newNode;
	newNode->next = cur;
}

void SortedInsert(Node **head, Node *newNode) {
	Node* cur = *head;
	Node *prev = nullptr;


	for (; cur != nullptr; cur = cur->next) {
		if (newNode->data < cur->data) {
			break;
		}
		prev = cur;
	}

	if (cur) {
		if(prev) {
			prev->next = newNode;
		} else {
			*head = newNode;
		}
		newNode->next = cur;
	} else {
		if (prev) {
			prev->next = newNode;
		} else {
			*head = newNode;
		}
	}
}

void InsertSort(Node **head) {
	Node* newHead = nullptr;
	Node* cur = *head;
	Node* next = nullptr;
	for (; cur != nullptr; cur = next) {
		next = cur->next;
		cur->next = nullptr;
		SortedInsert(&newHead, cur);
	}

	*head = newHead;
}

void Append(Node **aHead, Node **bHead) {
	Node* aCur = *aHead;
	for (; aCur != nullptr && aCur->next != nullptr; aCur = aCur->next) {
	}

	if (aCur) {
		aCur->next = *bHead;
	} else {
		*aHead = *bHead;
	}

	*bHead = nullptr;

}

void FrontBackSplit(Node *source, Node **frontHead, Node **backHead) {
	Node* slowPtr = source;
	Node* fastPtr = source;

	if (fastPtr == nullptr) {
		return;
	}

	for (; slowPtr != nullptr && fastPtr != nullptr && fastPtr->next != nullptr && fastPtr->next->next != nullptr;
	       slowPtr = slowPtr->next, fastPtr = fastPtr->next->next) {
	}

	if (slowPtr) {
		*backHead = slowPtr->next;
		slowPtr->next = nullptr;
	} else {
		*backHead = nullptr;
	}
	*frontHead = source;
}

void RemoveDuplicates(Node *head) {
	Node* prev = head;
	Node* cur = nullptr;
	Node* next = nullptr;

	if (prev == nullptr){
		return;
	}
	for (cur = prev->next; cur != nullptr; cur = next) {
		next = cur->next;
		if (cur->data == prev->data) {
			prev->next = next;
			cur->data = 0;
			cur->next = nullptr;
			free(cur);
		} else {
			prev = cur;
		}
	}
}

void MoveNode(Node **destHead, Node **sourceHead) {
	if (*sourceHead == nullptr) {
		return;
	} else {
		Node* movedNode = *sourceHead;
		Node *newSourceHead = movedNode->next;
		*sourceHead = newSourceHead;

		movedNode->next = *destHead;
		*destHead = movedNode;
	}
}

