#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class list
{
public:
	int data;
	int n;
	list* next;
	list(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
	}
};

list* head = 0;
list* prosmotr = 0;


void add(int a, list* b)
{
	if ((a == 0) && (head==0))
	{
		head = b;
		return;
	}

	if ((a != 0) && (head == 0))
	{
		head = new list(0, 0);
	}

	if ((a == 0) && (head != 0))
	{
		prosmotr = head;
		head = b;
		head->next = prosmotr;
		prosmotr->n++;
		while (prosmotr->next != 0)
		{
			prosmotr = prosmotr->next;
			prosmotr->n++;
		}
		return;
	}

	prosmotr = head;
	while (prosmotr->n != (a-1))
	{
		if (prosmotr->next == 0) prosmotr->next = new list(0,prosmotr->n+1);
		else prosmotr = prosmotr->next;
	}
	b->next = prosmotr->next;
	prosmotr->next = b;
	//b->n = prosmotr->n+1 ;
	prosmotr = prosmotr->next;
	while (prosmotr->next != 0)
	{
		prosmotr = prosmotr->next;
		prosmotr->n++;
	}
	
}

void get(int a)
{
	prosmotr = head;
	while (prosmotr->n != a)
	{
		prosmotr = prosmotr->next;
	}
	cout << prosmotr->data << endl;
}

void del(int a)
{
	prosmotr = head;
	if (a == 0)
	{
		head = prosmotr->next;
		prosmotr = head;
		prosmotr->n--;
	}
	else 
	{
		while (prosmotr->n != a - 1)
		{
			prosmotr = prosmotr->next;
		}
		list* q;
		q = prosmotr->next;
		prosmotr->next = q->next;
	}
	while (prosmotr->next != 0)
	{
		prosmotr = prosmotr->next;
		prosmotr->n--;
	}
}

int main()
{
	int number;
	cin >> number;
	string action;
	int l, h;
	for (int i = 0; i < number; i++)
	{
		cin >> action;
		if (action == "add")
		{
			cin >> l;
			cin >> h;
			list* sad;
			sad = new list(h, l);
			add(l, sad);
		}
		if (action == "get")
		{
			cin >> l;
			get(l);
		}
		if (action == "del")
		{
			cin >> l;
			del(l);
		}
	}
    return 0;
}
