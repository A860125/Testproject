#include<iostream>
using namespace std;
class List//односвязный список
{
	class Node
	{
	public:
		int data;//значение
		Node* pNext;
		Node(int data = 0, Node* pNext = nullptr)
		{
			cout << "Node Constructor: " << this << endl;
			this->data = data;
			this->pNext = pNext;
		}
		~Node()
		{
			cout << "Node Destructor: " << this << endl;
		}
	};
	Node* head;
	int size;
public:
	List()
	{
		cout << "List Constructor: " << this << endl;
		head = nullptr;
		size = 0;
	}
	~List()
	{
		cout << "List Destructor: " << this << endl;
	}
	int getSize()
	{
		return size;
	}
	void push_front(int data)
	{
		//Node* current = head;
		//head = new Node(data);
		//head->pNext = current;// можно так
		head = new Node(data, head);//а можно и так
		size++;
	}
	void push_back(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
		}
		else
		{
			Node* current = head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(data);
		}
		size++;
	}
	int operator[](const int index)
	{
		int counter = 0;
		Node* current = head;
		while (current!= nullptr)
		{
			if (index == counter)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	void pop_front()//удаление первого элемента
	{
		Node* temp = head->pNext;
		delete head;
		head = temp;
		size--;
	}
	void removeAt(int index)//удаление определенного элемента
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* previous = head;
			for (int i = 0;i < index - 1;i++)
			{
				previous = previous->pNext;
			}
			Node* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			size--;
		}
	}
	void pop_back()
	{
		removeAt(size - 1);
	}
	void insert(int data, int index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* previous = head;
			for (int i = 0;i < index - 1;i++)
			{
				previous = previous->pNext;
			}
			Node* newNode = new Node(data, previous->pNext);
			previous->pNext = newNode;
			size++;
		}
	}
	void clear()//удаление всех элементов
	{
		for (int i = size;i > 0;i--)
		{
			pop_front();
		}
	}
	void output()//вывод всех элементов списка
	{
		cout << "All elements of the list: \n";
		for (int i = 0;i < size;i++)
		{
			cout << (*this)[i] << "\t";
		}
		cout << endl;
	}
	void input(int size)
	{
		srand(time(NULL));
		for (int i = 0;i < size;i++)
		{
			push_back(rand() % 100);
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	List list;
	list.input(10);
	list.output();

	list.pop_front();
	list.output();

	list.push_front(5);
	list.output();

	list.insert(10, 2);
	list.output();

	list.removeAt(2);
	list.output();

	list.pop_back();
	list.output();

	list.clear();
	return 0;
}
