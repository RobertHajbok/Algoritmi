#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct lnode
{
	char* inf;
	struct lnode* next;
} *head = NULL;

struct lnode* cr_ad(struct lnode* p, char s[])
{
	struct lnode* q;
	if ((q = malloc(sizeof(struct lnode))) == NULL || (q->inf = malloc(strlen(s) + 1)) == NULL) {
		fprintf(stderr, "Memorie insuficienta!!!");
		exit(1);
	}
	else {
		strcpy(q->inf, s);
		q->next = p;
	}
	return q;
}

void tipar(struct lnode* p)
{
	struct lnode* q;
	for (q = p; q != NULL; q = q->next)
		printf("%s", q->inf);
}

struct lnode* sterg(struct lnode* p, char* s)
{
	struct lnode* q, * t;
	for (q = p; q != NULL; q = q->next) {
		if (!strcmp(q->inf, s)) {
			if (q == p) {
				p = q->next;
				free(q);
			}
			else {
				t->next = q->next;
				free(q);
			}
			break;
		}
		t = q;
	}
	return p;
}

struct lnode* sterg2(struct lnode* p, char* s)
{
	struct lnode** q, * t;
	for (q = &p; *q != NULL; q = &(*q)->next)
		if (!strcmp((*q)->inf, s))
		{
			t = *q;
			*q = (*q)->next;
			free(t);
			break;
		}
	return p;
}

int main()
{

	FILE* fp;
	char s[25];
	fp = fopen("cuvinte.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Nu pot deschide fisierul cu date!!!");
		exit(1);
	}
	while ((fgets(s, 30, fp)) != NULL)
		head = cr_ad(head, s);
	head = sterg(head, "sfarsit");
	tipar(head);
	getch();
	return 0;
}