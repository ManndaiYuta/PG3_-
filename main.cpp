#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cell
{
	struct cell* prev;
	struct cell* next;
	int val;
	char c[100];
}CELL;

void create(CELL* currentCELL,const int val,const char *susi,const int strSize) 
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	strcpy_s(newCell->c, strSize, susi);
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
	printf("|rank|  前のアドレス  |寿司ネタ|値段|    アドレス    |  次のアドレス  |\n");
	printf("-----------------------------------------------------------------------\n");
	int no = 1;
	while (endCell->next!=nullptr)
	{
		endCell = endCell->next;
		printf("|%4d|", no);
		printf("%p|", endCell->prev);
		printf("%8s|", endCell->c);
		printf("%4d|", endCell->val);
		printf("%p|", endCell);
		printf("%p|\n", endCell->next);
		no++;
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
	int price;
	const int strSize = 100;
	char c[strSize];
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;


	while (1) 
	{
		printf("何番目に好きなお寿司ですか?\n");
		scanf_s("%d",&iterator);

		printf("好きなお寿司を入力してください？\n");
		scanf_s("%s",&c,strSize);

		printf("一貫の値段を入力してください\n");
		scanf_s("%d", &price);

		insertCell = getInsertListAddress(&head,iterator);
		create(insertCell, price,c,strSize);

		index(&head);
		
	}
	return 0;
}