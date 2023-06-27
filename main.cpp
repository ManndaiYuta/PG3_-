#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cell
{
	struct cell* prev;
	struct cell* next;
	int val;

}CELL;

void create(CELL* currentCELL, int val) 
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCELL;
	newCell->next = currentCELL->next;

	if (currentCELL->next) 
	{
		CELL* nextCell = currentCELL->next;
		nextCell->prev = newCell;
	}
	currentCELL->next = newCell;
}
void index(CELL* endCell) 
{
	int no = 1;
	while (endCell->next!=nullptr)
	{
		endCell = endCell->next;
		printf("|%d|", no);
		printf("%p|", endCell->prev);
		printf("%5d|", endCell->val);
		printf("%p|", endCell);
		printf("%p|\n", endCell->next);

	}

}
CELL* getInsertListAddress(CELL* endCELL, int iterator) 
{
	for (int i = 0;i < iterator;i++) 
	{
		if (endCELL->next) 
		{
			endCELL = endCELL->next;
		}else{
			break;
		}
    }
	return endCELL;
}

int main() 
{
	int iterator;
	int inputValue;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;


	while (1) 
	{
		printf("何番目のセルに挿入しますか？\n");
		scanf_s("%d",&iterator);

		printf("挿入する値を入力して下さい？\n");
		scanf_s("%d",&inputValue);

		insertCell = getInsertListAddress(&head,iterator);
		create(insertCell, inputValue);

		index(&head);
		
	}
	return 0;
}