#pragma once
#include<iostream>
using namespace std;
struct STU
{
	int num;
	char name[32];

	STU* next;
};
extern void help(void);
extern STU* insertLink(STU* head, STU tmp);
extern void printLink(STU*head);
extern STU* searchLink(STU* head, char* name);
extern STU* deleteLink(STU* head, int num);
extern STU* freeLink(STU* head);