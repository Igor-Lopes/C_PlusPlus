#include <iostream>

#include "LinkedList.h"



void Link::Insert(int value)
{
	InsertNode(header, last, value);
}

void Link::InsertNode(listPtr &header, listPtr &last, int value)
{
	listPtr new_element = new Node;
	new_element -> next = NULL;
	new_element -> data = value;
	if(header == NULL)
	{
		header = new_element;
		last = header;
	}
	else
	{
		listPtr curr = header;	
		last -> next = new_element;
		last = new_element;
	}
}

void Link::Delete(int key)
{
	deleteNode(header, key);
}

void Link::deleteNode(listPtr &header, int key)
{
	listPtr curr = header;
	listPtr prev = header;
	while(curr != NULL)
	{
		if(curr -> data == key)
		{
			if(curr -> next != NULL)
			{
				if(curr == header)
				{
					header = curr -> next;
					curr -> next = NULL;
					curr = header;
					//return ;
				}
				else 
				{
					prev -> next = curr -> next;
					curr -> next = NULL;
					curr = prev -> next;
					//return;
				}
			}

			if(curr -> next == NULL)
			{
				curr = NULL;
				prev -> next = NULL;
				last = prev;
				//return;
			}
		}

		else

		if(curr -> next == NULL)
		{
			curr = NULL;
		}
		else
		{
			prev = curr;
			curr = curr -> next;
		}
	}
}

void Link::Invert()
{
	InvertList(header,last);
}

void Link:: InvertList(listPtr &header, listPtr &last)
{
	listPtr prev = header;
	listPtr curr = header;
	while(curr != NULL)
	{
		prev = curr;
		curr = curr -> next;

		if(curr -> next != NULL)
		{
			prev -> next = curr -> next;
			curr -> next = header;
			header = curr;
			curr = prev;
		}	
		
		if(curr -> next ==  NULL)
		{
			curr -> next = header;
			prev -> next = NULL;
			header = curr;
			curr = NULL;
			last = prev;
		}
	}	
}

void Link::Print()
{
	PrintList(header);
}

void Link::PrintList(listPtr header)
{
	listPtr curr = header;
	while(curr != NULL)
	{
		cout << curr -> data << endl;
		curr = curr -> next;
	}
}







