#include <iostream>


using namespace std;

class Link
{
	private:
		typedef struct Node
		{
			Node* next;
			int data;
		} *listPtr;
	
	listPtr header;
	listPtr last;

	void InsertNode(listPtr &header, listPtr &last, int value);
	void PrintList(listPtr header);
	void InvertList(listPtr &header, listPtr &last);
	void deleteNode(listPtr &header, int key);

	public:
	
	Link()
	{
		header = NULL;
		last = NULL;
	}

	void Insert(int value);
	void Delete(int key);
	void Print();
	void Invert();
};
