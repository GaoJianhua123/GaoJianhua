#include "Elysia.h"
#include<string.h>
void help(void)
{
	cout << "******************************" << endl;
	cout << "help:帮助信息" << endl;
	cout << "insert:插入链表节点" << endl;
	cout << "print:遍历链表  " << endl;
	cout << "search:查询链表某个节点 " << endl;
	cout << "delete:删除链表某个节点 " << endl;
	cout << "free:释放整个链表 " << endl;
	cout << "cls:清屏" << endl;
	cout << "quit:退出程序 " << endl;
	cout << "******************************" << endl;
}
#if 0
//链表插入之在头部之前插入
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//从堆区申请待插入的节点空间；
	*pi = tmp;
	pi->next = NULL;//给空间赋值；

	//判断链表是否为空
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
//链表插入之尾部插入
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//从堆区申请待插入的节点空间；
	*pi = tmp;
	pi->next = NULL;//给空间赋值；

	//判断链表是否为空
	if (NULL == head)
	{
		head = pi;
	}
	else
	{
		//寻找尾节点
		STU* pb = head;
		while (pb->next != NULL)
			pb = pb->next;
		//在尾节点插入pi
		pb->next = pi;
	}
	return head;
}
#endif
#if 1
//链表插入之有序插入
STU* insertLink(STU* head, STU tmp)
{
	STU* pi = new STU;//从堆区申请待插入的节点空间；
	*pi = tmp;
	pi->next = NULL;//给空间赋值；

	//判断链表是否为空
	if (NULL == head)
	{
		head = pi;
	}
	else
	{
		STU* pf = head, * pb = head;
		while((pb ->num<pi->num)&&(pb->next!=NULL))
		{
			//pf保存pb的位置
			pf = pb;
			//pb移动到下一个节点
			pb = pb->next;
		}
		//判断插入点的位置
		if (pb->num >= pi->num)
		{
			if (pb == head)//头部插入
			{
				pi->next = head;
				head = pi;
			}
			else//中部插入
			{
				pf->next = pi;
				pi->next = pb;
			}
		}
		else//尾部插入
		{
			pb->next = pi;
		}
	}
	return head;
}
#endif

//遍历
void printLink(STU* head)
{
	//判断链表是否存在
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

//查询
STU* searchLink(STU* head, char *name)
{
	//判断链表是否存在
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//逐个节点查询
	STU* pb = head;
	while ((strcmp(pb->name, name) != 0) && (pb->next != NULL))
		pb = pb->next;
	if (strcmp(pb->name, name) == 0)
	{
		return pb;
	}
	else
	{
		cout << "未找到相关节点"<<endl;
	}
	return NULL;
}

//删除节点
STU* deleteLink(STU* head, int num)
{
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//逐个节点比较，寻找删除点
	STU* pf = head, * pb = head;
	while ((pb->num != num) && (pb->next != NULL))
	{
		pf = pb;
		pb = pb->next;
	}
	if (pb->num == num)
	{
		if (pb == head)//头部删除
		{
			head = head->next;
			delete head;
		}
		else//中尾部删除
		{
			pf->next = pb->next;
		}
		delete pb;
	}
	else
	{
		cout << "未找到要删除的节点";
	}
	return head;
}
//释放
STU* freeLink(STU* head)
{
	if (NULL == head)
	{
		cout << "link is not exist" << endl;
		return NULL;
	}
	//逐个节点释放
	STU* pb = head;
	while (pb != NULL)
	{
		head = head->next;
		delete pb;
		pb = head;
	}
	return head;

}