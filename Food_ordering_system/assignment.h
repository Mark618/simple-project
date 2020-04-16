#pragma once
#include <iostream>
#include <string>

using namespace std;
struct orderinfo
{
	int orderNumber, itemCode,itembelongto;
	string itype;
	int quantity;
	float costPerItem;
	float totCost=0.00;
	char fulfillOrder;
	string recipient_name;
	string address;
	int telNum;	
	orderinfo* next;
	char selection;
};

struct linkedList
{
	orderinfo* head;
	orderinfo* itemhead;
	orderinfo* fullhead;
	int fullsize;
	int itemsize;
	int size;
	linkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->itemsize = 0;
		this->itemhead = nullptr;
		this->fullsize = 0;
		this->fullhead = nullptr;
	}

	void newOrder(string name, string addr, int telno)
	{
		orderinfo* norder = new orderinfo;
		norder->orderNumber = size + 1;
		norder->fulfillOrder = 'N';
		norder->recipient_name = name;
		norder->address = addr;
		norder->telNum = telno;
		norder->next =head;
		head = norder;
		size++;
	}
	void newItem(int icode, string itype, int quan, float price,int ib)
	{
		orderinfo* newItem = new orderinfo;
		newItem->itembelongto = ib;
		newItem->itemCode = icode;
		newItem->itype = itype;
		newItem->quantity = quan;
		newItem->costPerItem = price;
		newItem->next =itemhead;		
		itemhead = newItem;
		itemsize++;
	}

	
	void displayrecipient(string a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;

		bool found = false;
		while (current != NULL)
		 {
			if (current->recipient_name==a)
			{
				found = true;
				break;				
			}	
			else
			{
				prev = current;
				current = current->next;
			}
		 }
		if (found)
		{
			cout << "Order Number :" << current->orderNumber << endl;
			cout << "Order Status :" << current->fulfillOrder << endl;
			cout << "Customer status " << endl;
			cout << "Customer Name :" << current->recipient_name << endl;
			cout << "Customer address :" << current->address << endl;
			cout << "Customer Telephone number: " << current->telNum << endl;
			current = current->next;
		}
	}
	void displayrecipient(int a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;

		bool found = false;
		while (current != NULL)
		{
			if (current->orderNumber == a)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (found)
		{
			cout << "Order Number :" << current->orderNumber << endl;
			cout << "Order Status :" << current->fulfillOrder << endl;
			cout << "Customer status " << endl;
			cout << "Customer Name :" << current->recipient_name << endl;
			cout << "Customer address :" << current->address << endl;
			cout << "Customer Telephone number: " << current->telNum << endl;
			current = current->next;
		}
	}
	void modifyrecipientint(string name,string address,int tel,int a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->orderNumber == a)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (found)
		{
			current->recipient_name = name;
			current->address = address;
			current->telNum = tel;
			cout << "Customer Name :" << current->recipient_name << endl;
			cout << "Customer address :" << current->address << endl;
			cout << "Customer Telephone number: " << current->telNum << endl;
			current = current->next;
		}
	}

	void modifyrecipient(string name, string address, int tel, string a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;
		bool found = false;
		while (current != NULL)
		 {
			if (current->recipient_name == a)
			{
				found = true;
				break;			
			}
			else
			{
				prev = current;
				current = current->next;
			}			
		 }
		if (found)
		{
			current->recipient_name = name;
			current->address = address;
			current->telNum = tel;
			cout << "Customer Name :" << current->recipient_name << endl;
			cout << "Customer address :" << current->address << endl;
			cout << "Customer Telephone number: " << current->telNum << endl;
			current = current->next;
		}

	}
	void deleteitembelongto(int a)
	{
		orderinfo* itemcurrent = itemhead;
		orderinfo* prev = itemhead;
		bool found = false;
		while (itemcurrent != NULL)
		{
			if (itemcurrent->itembelongto==a)
			{
				found = true;
				break;
			}
			else
			{
				prev = itemcurrent;
				itemcurrent = itemcurrent->next;
			}
		}
		if (found)
		{
			if (itemcurrent == itemhead)
			{
				itemhead = itemhead->next;
				delete itemcurrent;
			}
			else
			{
				
				prev->next= itemcurrent->next;
				delete itemcurrent;
			}
		}
		else
		{
			cout << "" << endl;
		}

	}
	
	void deleteorderat(string a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;
		
		bool found = false;
		while (current != NULL)
		{
			if (current->recipient_name == a)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (found)
		{
			if (current == head)
			{
				head = head->next;
				deleteitembelongto(current->orderNumber);
				delete current;
			}
			else
			{
				prev->next = current->next;
				deleteitembelongto(current->orderNumber);
				delete current;
			}
		}
		else
		{
			cout << " Please check the spelling" << endl;
		}
	}
	void deleteorderat(int a)
	{
		orderinfo* current = head;
		orderinfo* prev = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->orderNumber == a)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (found)
		{
			if (current == head)
			{
				head = head->next;
				deleteitembelongto(current->orderNumber);
				delete current;
				cout << "Delete Success" << endl;
			}
			else
			{
				prev->next = current->next;
				deleteitembelongto(current->orderNumber);
				delete current;
				cout << "Delete Success" << endl;
			}
		}
		else
		{
			cout << "Record not exsist " << endl;
		}
	}
	

	void displayorder_item()
	{
		orderinfo* current = head;
		orderinfo* itemcurrent = itemhead;
		if (current == NULL)
		{
			cout << "No record in the list" << endl;
		}
		else
		{
			while (current != NULL)
			 {
				cout << "Order Number :" << current->orderNumber << endl;
				cout << "Order Status :" << current->fulfillOrder << endl;
				cout << "Customer status " << endl;
				cout << "Customer Name :" << current->recipient_name << endl;
				cout << "Customer address :" << current->address << endl;
				cout << "Customer Telephone number: " << current->telNum << endl;
				
				float total = 0.0;
				float deliveryc=0.0;
				float totalpay=0.0;
				
				cout << "Item order" << endl;
				cout << "Item code" << "\t" << "Item Name" << "\t" << "Purchase quantity" << "\t" << "Sum " << endl;
				while (itemcurrent!=NULL)
				{											
					if (current->orderNumber==itemcurrent->itembelongto)
					{				
						cout<<itemcurrent->itemCode<<"\t\t" << itemcurrent->itype<<"\t\t" << itemcurrent->quantity <<"\t\t\t"<< itemcurrent->costPerItem << endl;
						total=total+ itemcurrent->costPerItem;
						deliveryc = total * 0.05;
						totalpay = total * 1.05;
						itemcurrent = itemcurrent->next;
					}
					else
					{
						break;
					}
																				
				 }
				cout << "Total amount :" << total << endl;
				cout << "Delivery Charge : " << deliveryc << endl;
				cout << "Total Pay : " << totalpay << endl << endl;
				current = current->next;
				
			 }			
		}
	}

	void fufilordermove()
	{
		orderinfo* current = head;
		orderinfo* fullcurrent =fullhead;
		orderinfo* newfull = new orderinfo;
		newfull->orderNumber = current->orderNumber;
		newfull->fulfillOrder = 'F';
		newfull->recipient_name = current->recipient_name;
		newfull->address = current->address;
		newfull->telNum = current->telNum;
		deleteorderat(current->orderNumber);
		newfull->next = fullhead;
		fullhead = newfull;
		fullsize++;
	}

	void displayfullfillorder()
	{
		orderinfo* fullcurrent = fullhead;
		if (fullcurrent==NULL)
		{
			cout << "No order fullfilled" << endl;
		}
		else
		{
			while (fullcurrent!=NULL)
			{
				cout << "Order Number :" << fullcurrent->orderNumber << endl;
				cout << "Order Status :" << fullcurrent->fulfillOrder << endl;
				cout << "Customer status " << endl;
				cout << "Customer Name :" << fullcurrent->recipient_name << endl;
				cout << "Customer address :" << fullcurrent->address << endl;
				cout << "Customer Telephone number: " << fullcurrent->telNum << endl<<endl;
				fullcurrent = fullcurrent->next;
			}
		}
	}
	
	bool search()
	{
		orderinfo* current = head;
	
			if (current == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
	}
};
	
