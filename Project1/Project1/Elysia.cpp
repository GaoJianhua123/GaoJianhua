#include "Elysia.h"
#include<string.h>
void help(void)
{
	cout << "******************************" << endl;
	cout << "help:������Ϣ" << endl;
	cout << "insert:��������ڵ�" << endl;
	cout << "print:��������  " << endl;
	cout << "search:��ѯ����ĳ���ڵ� " << endl;
	cout << "delete:ɾ������ĳ���ڵ� " << endl;
	cout << "free:�ͷ��������� " << endl;
	cout << "cls:����" << endl;
	cout << "quit:�˳����� " << endl;
	cout << "******************************" << endl;
}
#if 0
//�������֮��ͷ��֮ǰ����
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//�Ӷ������������Ľڵ�ռ䣻
	*pi = tmp;
	pi->next = NULL;//���ռ丳ֵ��

	//�ж������Ƿ�Ϊ��
	if (NULL == head) 
	{
		head = pi;
	}
	else
	{
		pi->next = head;
		head = pi;
	}
	return head;
}
#endif

#if 0
//�������֮β������
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//�Ӷ������������Ľڵ�ռ䣻
	*pi = tmp;
	pi->next = NULL;//���ռ丳ֵ��

	//�ж������Ƿ�Ϊ��
	if (NULL == head)
	{
		head = pi;
	}
	else
	{
		//Ѱ��β�ڵ�
		STU* pb = head;
		while (pb->next != NULL)
			pb = pb->next;
		//��β�ڵ����pi
		pb->next = pi;
	}
	return head;
}
#endif
#if 1
//�������֮�������
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//�Ӷ������������Ľڵ�ռ䣻
	*pi = tmp;
	pi->next = NULL;//���ռ丳ֵ��

	//�ж������Ƿ�Ϊ��
	if (NULL == head)
	{
		head = pi;
	}
	else
	{
		STU* pf = head, * pb = head;
		while((pb ->num<pi->num)&&(pb->next!=NULL))
		{
			//pf����pb��λ��
			pf = pb;
			//pb�ƶ�����һ���ڵ�
			pb = pb->next;
		}
		//�жϲ�����λ��
		if (pb->num >= pi->num)
		{
			if (pb == head)//ͷ������
			{
				pi->next = head;
				head = pi;
			}
			else//�в�����
			{
				pf->next = pi;
				pi->next = pb;
			}
		}
		else//β������
		{
			pb->next = pi;
		}
	}
	return head;
}
#endif

//����
void printLink(STU* head)
{
	//�ж������Ƿ����
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return;
	}
	STU* pb = head;
	while (pb != NULL)
	{
		cout << pb->num << " " << pb->name << endl;
		pb = pb->next;
	}
	return;
}

//��ѯ
STU* searchLink(STU* head, char *name)
{
	//�ж������Ƿ����
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//����ڵ��ѯ
	STU* pb = head;
	while ((strcmp(pb->name, name) != 0) && (pb->next != NULL))
		pb = pb->next;
	if (strcmp(pb->name, name) == 0)
	{
		return pb;
	}
	else
	{
		cout << "δ�ҵ���ؽڵ�"<<endl;
	}
	return NULL;
}

//ɾ���ڵ�
STU* deleteLink(STU* head, int num)
{
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//����ڵ�Ƚϣ�Ѱ��ɾ����
	STU* pf = head, * pb = head;
	while ((pb->num != num) && (pb->next != NULL))
	{
		pf = pb;
		pb = pb->next;
	}
	if (pb->num == num)
	{
		if (pb == head)//ͷ��ɾ��
		{
			head = head->next;
			delete head;
		}
		else//��β��ɾ��
		{
			pf->next = pb->next;
		}
		delete pb;
	}
	else
	{
		cout << "δ�ҵ�Ҫɾ���Ľڵ�";
	}
	return head;
}
//�ͷ�
STU* freeLink(STU* head)
{
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//����ڵ��ͷ�
	STU* pb = head;
	while (pb != NULL)
	{
		head = head->next;
		delete pb;
		pb = head;
	}
	return head;

}