//
// Created by Grady on 2016/12/17.
//
#include <stdlib.h>
#include <cstdio>
#include <cassert>
#include "LinkListProblem.h"
#include <map>
#include <iostream>

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

Node *BuildList(int *arr, int size) {
	Node* newList = nullptr;
	for (int i = size - 1; i >= 0; --i) {
		Push(&newList, arr[i]);
	}

	return newList;
}


int Count(Node* head, int searchFor) {
	Node* cur = nullptr;
	int count = 0;

	for (cur = head; cur != nullptr; cur = cur->next) {
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

	/* 这里可以使用 i < index -1, 直接让cur停在要插入的位置的前一个位置即可，不用
	 * 再使用一个prev记录位置.
	 */
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

void InsertNth1(Node **head, int index, int newData) {
	if (index == 0) {
		Push(head, newData);
	}
	Node* curPtr = *head;
	int i = 0;
	for (i = 0; i < index - 1; ++i) {
		assert(curPtr != nullptr);
		curPtr = curPtr->next;
	}

	assert(curPtr != nullptr);
	Push(&(curPtr->next), newData);
}


void printList(Node *head) {
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
		prev = cur; /* 这里其实不应该维护一个prev指针，用cur->next就可以*/
	}

	/* 如果一开始将特殊情况先排除掉，那么就不会有这么多的情况*/
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

void SortedInsert1(Node **head, Node *newNode) {
	Node* cur = *head;

	if (cur == nullptr || cur->data >= newNode->data) {
		newNode->next = *head;
		*head = newNode;
	} else {
		for (; cur->next != nullptr && cur->next->data < newNode->data; cur = cur->next) {
		}
		newNode->next = cur->next;
		cur->next = newNode;
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

void Append1(Node** aHead, Node** bHead) {
	Node *aCur = *aHead;
	if (aCur == nullptr) {
		*aHead = *bHead;
	} else {
		while (aCur->next != nullptr) {
			aCur = aCur->next;
		}
		aCur->next = *bHead;
	}

	*bHead = nullptr;

}

void FrontBackSplit(Node *source, Node **frontHead, Node **backHead) {
	Node* slowPtr = source;
	Node* fastPtr = source;

	if (fastPtr == nullptr) {
		return;
	}

	/* 这里要注意的是，fastPtr前进的时候，必须确保它的下一步(fast->next->next)必须不为空，这样才能使得fast是slow的
	 * 两倍快，那么为了确保fastPtr->next->next不为nullptr，也就是说，
	 * fastPtr != nullptr && fast->next != nullptr, fast->next->next != nullptr*/
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

void FrontBackSplit1(Node *source, Node **frontHead, Node **backHead) {
	if (source == nullptr || source->next == nullptr) {
		*frontHead = source;
		*backHead = nullptr;
	}

	Node* slow = nullptr;
	Node* fast = nullptr;
	for (slow = source, fast = source;
	     fast != nullptr && fast->next != nullptr && fast->next->next != nullptr;
	     slow = slow->next, fast = fast->next->next) {
	}

	*frontHead = source;
	*backHead = slow->next;
	slow->next = nullptr;
}

void RemoveDuplicates(Node *head) {
	/* 用了三个指针去做这件事儿，说明啥呢，脑子还是没弄清楚，没弄到本质 */
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

void RemoveDuplicates1(Node *head) {
	Node* cur = head;

	if (cur == nullptr) {
		return;
	}

	for (; cur->next != nullptr; cur = cur->next) {
		if (cur->data == cur->next->data) {
			Node* nextNode = cur->next->next;
			cur->next->next = nullptr;
			cur->next->data = 0;
			free(cur->next);
			cur->next = nextNode;
		}
	}
}

void MoveNode(Node **destHead, Node **sourceHead) {
	if (*sourceHead == nullptr) {
		return;
	} else {
		Node* movedNode = *sourceHead;

		/* 下面这两句完全可以合成一句，不知道当时怎么想的 */
		Node *newSourceHead = movedNode->next;
		*sourceHead = newSourceHead;

		movedNode->next = *destHead;
		*destHead = movedNode;
	}
}

void AlternatingSplit2(Node *source, Node **aHead, Node **bHead) {
	Node* cur = source;
	bool front = true;
	Node* next = nullptr;

	/* 既然是连续的move，就不需要设置一个flag来判断了 */
	for (; cur != nullptr; cur = next) {
		next = cur->next;
		if (front) {
			MoveNode(aHead, &source);
			front = false;
		} else {
			MoveNode(bHead, &source);
			front = true;
		}
	}
}

void AlternatingSplit1(Node *source, Node **aHead, Node **bHead) {
	Node* a = nullptr;
	Node* b = nullptr;
	Node* cur = source;

	while (cur != nullptr) {
		MoveNode(&a, &cur);
		if (cur != nullptr) {
			MoveNode(&b, &cur);
		}
	}

	*aHead = a;
	*bHead = b;
}

/* 上面两种方式将链表分开时，其实是将链表节点的顺序刚好颠倒了，完全正序的将链表分开 */
void AlternatingSplit(Node* source, Node** aHead, Node** bHead) {
	Node** aTail = aHead;
	Node** bTail = bHead;
	Node* cur = source;

	while (cur != nullptr) {
		MoveNode(aTail, &cur);
		aTail = &((*aTail)->next);
		if (cur != nullptr) {
			MoveNode(bTail, &cur);
			bTail = &((*bTail)->next);
		}
	}
}


Node *ShuffleMerge(Node *a, Node *b) {
	if (a == nullptr) {
		return b;
	}
	if (b == nullptr) {
		return a;
	}
	Node* aCur = a;
	Node* bCur = b;
	Node* aNext = nullptr;
	Node* curHead = nullptr;

	for (; aCur->next != nullptr; aCur = aNext) {
		aNext = aCur->next;
		curHead = aNext;
		MoveNode(&curHead, &bCur);
		aCur->next = curHead;
	}

	if (bCur) {
		aCur->next = bCur;
	}

	return a;
}

/* don't use MoveNode() */
Node *ShuffleMerge1(Node *a, Node *b) {
	if (a == nullptr) {
		return b;
	}
	if (b == nullptr) {
		return a;
	}

	Node* resultHead = nullptr;
	Node** lastNodePtr = &resultHead;
	Node* aCur = a;
	Node* bCur = b;
	Node* aNext = nullptr;
	Node* bNext = nullptr;


	for (; aCur != nullptr && bCur != nullptr; aCur = aNext, bCur = bNext) {
		aNext = aCur->next;
		bNext = bCur->next;
		*lastNodePtr = aCur;
		(*lastNodePtr)->next = bCur;
		lastNodePtr = &((*lastNodePtr)->next->next);
	}

	if (aCur) {
		*lastNodePtr = aCur;
	}
	if (bCur) {
		*lastNodePtr = bCur;
	}

	return resultHead;
}

Node *SortedMerge1(Node *a, Node *b) {
	if (a == nullptr) {
		return b;
	}
	if (b == nullptr) {
		return a;
	}

	/* 这里使用的二级指针，是一个非常典型的套路 */
	Node* newHead = nullptr;
	Node** cur = &newHead;

	Node* aCur = a;
	Node* bCur = b;
	while (aCur != nullptr && bCur != nullptr) {
		if (aCur->data < bCur->data) {
			*cur = aCur;
			aCur = aCur->next;
		} else {
			*cur = bCur;
			bCur = bCur->next;
		}
		cur = &((*cur)->next);

	}

	if (aCur) {
		*cur = aCur;
	} else {
		*cur = bCur;
	}

	return newHead;

}

/* dummy node版本
 * 凡是可以使用二级指针解决的问题，都可以用dummy node来解决 */
Node* SortedMerge(Node* a, Node* b) {
	if (a == nullptr) {
		return b;
	}

	if (b == nullptr) {
		return a;
	}

	/* dummy node是一个temporary local node */
	Node dummy;
	Node* tail = &dummy;
	Node* aCur = a;
	Node* bCur = b;
	dummy.next = nullptr;

	while (aCur != nullptr && bCur != nullptr) {
		if (aCur->data < bCur->data) {
			tail->next = aCur;
			aCur = aCur->next;
		} else {
			tail->next = bCur;
			bCur = bCur->next;
		}

		tail = tail->next;
	}

	if (aCur) {
		tail->next = aCur;
	} else {
		tail->next = bCur;
	}

	return dummy.next;

}

/* recursive version */
Node *SortedMerge2(Node *a, Node *b) {
	if (a == nullptr) {
		return b;
	}
	if (b == nullptr) {
		return a;
	}

	Node* newHead = nullptr;
	if (a->data < b->data) {
		newHead = a;
		newHead->next = SortedMerge2(a->next, b);
	} else {
		newHead = b;
		newHead->next = SortedMerge2(a, b->next);
	}

	return newHead;
}


void MergeSort(Node **headRef) {
	Node* head = *headRef;
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* frontHead = nullptr;
	Node* backHead = nullptr;
	FrontBackSplit(head, &frontHead, &backHead);
	MergeSort(&frontHead);
	MergeSort(&backHead);
	*headRef = SortedMerge(frontHead, backHead);
}


Node *SortedIntersect(Node *a, Node *b) {
	Node* newHead = nullptr;
	Node** cur = &newHead;

	Node* aCur = a;
	Node* bCur = b;
	while (aCur != nullptr && bCur != nullptr) {
		if (aCur->data == bCur->data) {
			Push(cur, aCur->data);
			aCur = aCur->next;
			bCur = bCur->next;
			cur = &((*cur)->next);
		} else if (aCur->data < bCur->data) {
			aCur = aCur->next;
		} else {
			bCur = bCur->next;
		}
	}

	return newHead;
}


void Reverse(Node** head) {
	/* 重新起一个link head就可以 */
	Node* newHead = nullptr;

	Node* cur = *head;
	Node* next = nullptr;

	for (; cur != nullptr; cur = next) {
		next = cur->next;
		cur->next = newHead;
		newHead = cur;
	}

	*head = newHead;
}


/* 之所以没有写正确，是因为没有考虑两边的情况 */
void Reverse1(Node **head) {
	Node* prev = nullptr;
	Node* cur = nullptr;
	Node* next = nullptr;

	/* 为什么不写成
	 * for (cur = prev->next, next = cur->next; next != nullptr; prev = cur, cur = next, next = next->next) 呢？
	 * 因为next为nullptr，还要走一步cur->next = prev, 所以这个循环的主体其实是cur，cur不为nullptr，这个循环就应该继续进行 */
	/* cur是主体，所以这里应该将cur赋值为*head */
	for(cur = *head; cur != nullptr; prev = cur, cur = next) {
		next = cur->next;
		cur->next = prev;
	}

	*head = prev;
}


/* 自己写的错误版本 */
void Reverse1_false(Node **head) {
	if (*head == nullptr || (*head)->next == nullptr) {
		return;
	}

	Node* prev = *head;
	Node* cur = nullptr;
	Node* next = nullptr;

	for(cur = prev->next; cur != nullptr; prev = cur, cur = next) {
		next = cur->next;
		prev->next = nullptr;
		cur->next = prev;
	}

	*head = prev;
}

/* recursive version 这个版本对于recursion要有理解？ */
void Reverse2(Node** head) {
	if (*head == nullptr || (*head)->next == nullptr) {
		return;
	}

	Node* next = (*head)->next;
	Reverse2(&next);

	next->next = *head;
	(*head)->next = nullptr;

	*head = next;
}

int FindMergeNode(Node *headA, Node *headB)
{
	int lengthA = 0;
	int lengthB = 0;

	for(Node* curA = headA; curA != nullptr; curA = curA->next) {
		++lengthA;
	}
	for(Node* curB = headB; curB != nullptr; curB = curB->next) {
		++lengthB;
	}

	int n = 0;
	Node* curShort = nullptr;
	Node* curLong = nullptr;
	if (lengthA > lengthB) {
		n = lengthA - lengthB;
		curLong = headA;
		curShort = headB;
	} else {
		n = lengthB - lengthA;
		curLong = headB;
		curShort = headA;
	}

	for (int i = 0; i < n; ++i) {
		curLong = curLong->next;
	}

	int position = n + 1;
	while (curShort != nullptr) {
		if (curLong == curShort) {
			break;
		}
		curLong = curLong->next;
		curShort = curShort->next;
		++position;
	}

	return position;
	// Complete this function
	// Do not write the main method.
}

/*这种解法虽然代码看上去简洁但是不好理解，而且这个也不能得出position的位置 */
int FindMergeNode1(Node *headA, Node *headB)
{
	Node* curA = headA;
	Node* curB = headB;

	while (curA != curB) {
		if (curA->next != nullptr) {
			curA = curA->next;
		} else {
			curA = headB;
		}

		if (curB->next != nullptr) {
			curB = curB->next;
		} else {
			curB = headA;
		}
	}

	return curA->data;
}


/* 双向链表有序插入，这个也不难啊，为什么就半天写不对呢
 *
 * 看了上面的单链表soretedinsert，终于明白了：自己写单链表的时候就写的很麻烦，看完参考答案才觉得人家写得好
 * 然而并没有真正的想清楚*/
DoubleNode* SortedInsert(DoubleNode *head,int data)
{
	DoubleNode* newNode = new DoubleNode();
	newNode->data = data;
	if (head == nullptr) {
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		return head;
	}

	if (head->data > data) {
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;
		head = newNode;

		return head;
	}

	DoubleNode* prev = nullptr;
	DoubleNode* cur = head;
	while (cur != nullptr && cur->data < data) {
		prev = cur;
		cur = cur->next;
	}

	if (cur == nullptr) {
		newNode->next = nullptr;
		newNode->prev = prev;

		prev->next = newNode;
	} else {
		newNode->next = cur;
		newNode->prev = prev;

		cur->prev = newNode;
		prev->next = newNode;
	}

	return head;
	// Complete this function
	// Do not write the main method.

}

/* 看了上面单链表的实现，将上面的方法改的更简洁了一些 */
DoubleNode* SortedInsert1(DoubleNode *head,int data) {
	DoubleNode *newNode = new DoubleNode();
	newNode->data = data;

	if (head == nullptr) {
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		return head;
	}

	if (head->data > data) {
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;
		head = newNode;

		return head;
	}

	DoubleNode *cur = nullptr;
	for (cur = head; cur->next != nullptr && cur->next->data < data; cur = cur->next) {
	}

	newNode->next = cur->next;
	newNode->prev = cur;

	if (cur->next) {
		cur->next->prev = newNode;
	}
	cur->next = newNode;

	return head;
}


void PrintRandomList(RandomNode *head) {
	RandomNode* cur = nullptr;

	for (cur = head; cur != nullptr; cur = cur->next) {
		printf("data = %d, random data = %d\n", cur->data, cur->random->data);
	}
}

RandomNode *CopyRandomList1(RandomNode *head) {
	std::map<RandomNode*, RandomNode*> listMap;
	RandomNode* cur = head;
	RandomNode* newHead;
	RandomNode** newCur = &newHead;

	for (; cur != nullptr; cur = cur->next) {
		RandomNode* newNode = new RandomNode();
		newNode->data = cur->data;
		newNode->next = cur->next;
		newNode->random = nullptr;
		listMap[cur] = newNode;
		*newCur = newNode;
		newCur = &((*newCur)->next);
	}

	for(cur = head; cur != nullptr; cur = cur->next) {
		listMap[cur]->random = cur->random;
	}

	return newHead;
}

/* 这个题目的关键在于，如何保存旧节点和新节点的对应关系，以复制旧节点random的部分
 * 现在看来，要么是构建hash表去存储对应关系，要么是，将链表构建成交替链表，来保存新旧节点的对应关系*/
RandomNode* CopyRandomList(RandomNode* head) {
	RandomNode* newHead = nullptr;
	RandomNode* cur = head;

	if (head == nullptr) {
		return nullptr;
	}

	while (cur!= nullptr) {
		RandomNode *next = cur->next;
		RandomNode *newNode = new RandomNode();
		newNode->data = cur->data;
		newNode->next = next;
		cur->next = newNode;

		cur = next;
	}

	cur = head;
	while (cur != nullptr && cur->next != nullptr) {
		cur->next->random = cur->random->next;
		cur = cur->next->next;
	}

	cur = head;
	RandomNode **newCur = &newHead;
	while (cur != nullptr && cur->next != nullptr) {
		RandomNode* newNode = cur->next;
		cur->next = newNode->next;
		if (cur->next) {
			newNode->next = newNode->next->next;

		} else {
			newNode->next = nullptr;
		}
		*newCur = newNode;

		cur = cur->next;
		newCur = &((*newCur)->next);
	}

	return newHead;
}