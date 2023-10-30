#include <iostream>
#include <windows.h>
using namespace std;

class Hotel
{
private :
	struct Node
	{
		int id, date;
		string name, roomtype;
		Node* next;
	};

public :
	Node* head = NULL;
	void insert();
	void menu();
	void update();
	void search();
	void del();
	void sort();
	void show();
	void list();
};

void Hotel::menu() 
{
p:
	int choise;
	cout << endl;
	cout << "\n";
	cout << " \t Welcome to hotel system" << endl;
	cout << "\n\t_______HOTEL SYSTEM_______";
	cout << "\n\n¹       Function                        Description" << endl;
	cout << "\n1.\tAllocate room\t\t\tAdd new room" << endl;
	cout << "\n2.\tSearch room\t\t\tSearch room by Id " << endl;
	cout << "\n3.\tUpdate room\t\t\tUpdate room record " << endl;
	cout << "\n4.\tDelete room\t\t\tDelete room record " << endl;
	cout << "\n5.\tShow room record\t\tShow full information about room record" << endl;
	cout << "\n6.\tExit" << endl;

	cout << "\nEnter your choise : ";
	cin >> choise;

	switch (choise)
	{
	case 1 :
		insert();
		menu();
		break;
	case 2 :
		search();
		menu();
		break;
	case 3 :
		update();
		menu();
		break;
	case 4 :
		del();
		menu();
		break;
	case 5:
		sort();
		show();
		menu();
		break;
	case 6:
		exit(0);
		default:
			cout << "Invalid number";
		break;
	}
}

void Hotel::insert()
{
	cout << "\n_____Hotel Managment System_____" ;
	Node* new_Node = new Node;
	cout << "\nEnter room id : " ;
	cin >> new_Node->id;
	cout << "\nEnter Customer name : " ;
	cin >> new_Node->name;
	cout << "\nEnter Allocated Date : " ;
	cin >> new_Node->date;
	cout << "\nEnter Room Type (single/Double/twin) : " ;
	cin >> new_Node->roomtype;

	if (head == NULL)
	{
		head = new_Node;
	}
	else 
	{
		Node* ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_Node;
	}
	cout << "\n\tNEW ROOM ADDED!!!!" << endl;

}



void Hotel::search()
{
	cout << "\n_____Hotel Managment System_____";
	int t_id;
	if (head == NULL)
	{
		cout << "\nLINKED LIST IS EMPTY!!!";
	}
	else 
	{
		cout << "\nRoom ID : ";
		cin >> t_id;
		Node* ptr = head;

		while (ptr != NULL)
		{
			if (t_id == ptr->id)
			{
				cout << "\n\tRoom Id : " << ptr->id;
				cout << "\n\tCustomer name : " << ptr->name;
				cout << "\n\tRoom Allocated date : " << ptr->date;
				cout << "\n\tRoom Type : " << ptr->roomtype;
			}
			ptr = ptr->next;
		}

	}
}


void Hotel::update()
{
	cout << "\n_____Hotel Managment System_____";
	int t_id;
	if (head == NULL)
	{
		cout << "\nLINKED LIST IS EMPTY!!!";
	}
	else
	{
		cout << "\nRoom Id :";
		cin >> t_id;
		Node* ptr = head;
		while (ptr != NULL)
		{
			if (t_id == ptr->id)
			{
				cout << "\nRoom Id :";
				cin >> ptr->id;
				cout << "\nCustomer name : ";
				cin >> ptr->name;
				cout << "\nRoom Allocated date : ";
				cin >> ptr->date;
				cout << "\nRoom Type : ";
				cin >> ptr->roomtype;

				cout << "\nRECORD IS SUCCESSFULY UPDATED";
			}
			ptr = ptr->next;
		}
	}
}


void Hotel::del()
{
	cout << "_____Hotel Managment System_____";
	int t_id;
	if (head == NULL)
	{
		cout << "\nLINKED LIST IS EMPTY!!!";
	}
	else
	{
		cout << "\nRoom Id :";
		cin >> t_id;
		if (t_id == head->id)
		{
			Node* ptr = head;
			head = head->next;
			delete ptr;
			cout << "\nROOM WAS DELETED SUCCESSFULY!!!";
		}
		else
		{
			Node* pre = head;
			Node* ptr = head;
			while (ptr != NULL)
			{
				if (t_id == ptr->id)
				{
					pre->next = ptr->next;
					delete ptr;
					cout << "\nROOM WAS DELETED SUCCESSFULY!!!";
					break;
				}
				pre = ptr;
				ptr = ptr->next;
			}
		}
	}
}

void Hotel::show()
{
	Node* ptr = head;
	while (ptr != NULL)
	{
		cout << "\n\n Room Id : " << ptr->id;
		cout << "\n\n Customer name : "<< ptr->name;
		cout << "\n\n Room Allocated date : " << ptr->date;
		cout << "\n\n Room Type : " << ptr->roomtype;
		ptr->next;
	}
}

void Hotel::sort()
{
	if (head == NULL)
	{
		cout << "\n\nLINKED LIST IS EMPTY!!!";
		menu();
	}

	int count = 0, t_date, t_id;
	string t_name , t_roomtype;

	Node* ptr = head;
	while (ptr!= NULL)
	{
		count++;
		ptr = ptr->next;
	}

	for (int i = 1 ; i <=count; i++)
	{
		Node* ptr = head;
		for (int j = 1 ; j < count; j++)
		{
			if (ptr->id > ptr->next->id)
			{
				t_id = ptr->id;
				t_name = ptr->name;
				t_date = ptr->date;
				t_roomtype = ptr->roomtype;

				//save date in current node 
				ptr->id = ptr->next->id;
				ptr->name = ptr->next->name;
				ptr->date = ptr->next->date;
				ptr->roomtype = ptr->next->roomtype;

				//save date in next node
				ptr->next->id = t_id;
				ptr->next->name = t_name;
				ptr->next->date = t_date;
				ptr->next->roomtype = t_roomtype;
			}
			ptr = ptr->next;
		}
	}
}

int main()
{
	system("COLOR 9");

	Hotel h;
	h.menu();
}
