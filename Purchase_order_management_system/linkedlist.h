#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

class userinfo
{
public:
	string staffid;
	string username;
	string password;
	string position;
	userinfo* next;
};

class iteminfo
{
public:
	string itemid, itemname, suppid;
	int stocknum;		
	iteminfo* inext;
};

class purchasereq
{
public:
	string itemid, itemname, suppid,prid;
	int stocknum;
	string idrequestby;
	string daterequired;
	string status;
	string approvebyid;
	purchasereq* pnext;
};

class purchaseorder
{
public:
	string itemid, itemname, suppid, poid;
	int stocknum;
	string idrequestby;
	string daterequired;
	string status;
	string approvebyid;
	purchaseorder* ponext;
};

class supplierinfo
{
public:
	string suppid, suppname;
	supplierinfo* snext;
};


class linkedlist
{
public:
	userinfo* uhead;
	

	int usersize;
	linkedlist()
	{
		this->usersize = 0;
		this->uhead = nullptr;		
		
	}

	void addUserfromfile(string id, string name, string password, string pos)
	{
		userinfo* newnode = new userinfo;
		string userid;
		newnode->username = name;
		newnode->password = password;
		newnode->position = pos;
		newnode->staffid = id;		
		newnode->next = uhead;
		uhead = newnode;
		usersize++;
	}
	void displayuser()
	{
		userinfo* current = uhead;
		if (current ==NULL)
		{
			cout << "User list empty" << endl;
		}
		else
		{
			while (current!=NULL)
			{
				cout << "User ID: " << current->staffid << endl;
				cout << "User Name: " << current->username << endl;				
				cout << "User Position: " << current->position << endl;
				current = current->next;
			}
		}
	}
	
	
	bool checkpassword(string uname,string psw)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;

		bool found = false;
		while (current!=NULL)
		 {
			if (current->username==uname)
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
			if (current->password == psw)
			{				
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	string getuserid(string uname)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;

		bool found = false;
		while (current != NULL)
		{
			if (current->username == uname)
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
			return current->staffid;
		}
	}
	int getusertype(string uname)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;

		bool found = false;
		while (current != NULL)
		{
			if (current->username == uname)
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
			if (current->position=="admin")
			{
				return 1;
			}
			else if (current->position == "SM")
			{
				return 2;
			}
			else if (current->position == "PM")
			{
				return 3;
			}
		
		}
	}

	void display()
	{
		cout << "\t\tFunctionalities" << endl;
		cout << "1.Item Entry (Add/Delete/Edit)" << endl;
		cout << "2.Supplier Entry (Add/Delete/Edit)" << endl;
		cout << "3.Daily Item-wise Sales Entry (Add/Delete/Edit)" << endl;
		cout << "4.Purchase Requisition (Add/Delete/Edit)" << endl;
		cout << "5.Display Requisition" << endl;
		cout << "6. List of Items " << endl;
		cout << "7. List of Suppliers" << endl;		
		cout << "8. Generate Purchase Order" << endl;
		cout << "9. List of Purchaseer Orders " << endl;
		cout << "10. Add new user" << endl;
		cout << "11.Logout" << endl;
		cout << "selection : ";
	}
	void adminfunc()
	{
		cout << "1. Add new user to the system" << endl;
		cout << "2. Remove user from the system" << endl;
		cout << "3. Back " << endl;
		cout << "Selection :";
	}
	bool searchusername(string search)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;

		bool found = false;
		while (current != NULL)
		{
			if (current->username == search)
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
			return true;
		}
		else
		{
			return false;;
		}
	}
	bool searchadmin(string search)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;

		bool found = false;
		while (current != NULL)
		{
			if (current->staffid == search)
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
			if (current->position == "admin")
			{
				return true;
			}

		}
		else
		{
			return false;;
		}
	}
	void addnewuser(string name, string password, string pos)
	{
		userinfo* newnode = new userinfo;
		string userid;
		newnode->username = name;
		newnode->password = password;
		newnode->position = pos;
		if (pos == "admin")
		{
			userid = "a";
			newnode->staffid = userid + to_string(usersize + 101);
		}
		else if (pos == "SM")
		{
			userid = "sm";
			newnode->staffid = userid + to_string(usersize + 101);
		}
		else if (pos == "PM")
		{
			userid = "pm";
			newnode->staffid = userid + to_string(usersize + 101);
		}
		newnode->next = uhead;
		uhead = newnode;
		usersize++;
	}
	void deleteuser(string id)
	{
		userinfo* current = uhead;
		userinfo* prev = uhead;
		bool found = false;
		while (current != NULL)
		{
			if (current->staffid == id)
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
			if (current == uhead)
			{
				uhead = uhead->next;
				delete current;
				cout << "Remove user success" << endl;
			}
			else
			{
				prev->next = current->next;
				delete current;
				cout << "Delete success" << endl;
			}
		}
	}
	void saveuser()
	{
		userinfo* current = uhead;
		ofstream writer("admininfo.txt");
		if (writer.is_open())
		{
			while (current != NULL)
			{
				writer << current->staffid << "\t" << current->username << "\t" << current->position << "\t" << current->password << endl;
				current = current->next;
			}
		}
		writer.close();
	}
	
};


class salesmanager
{
public:	
	iteminfo* ihead;
	supplierinfo* shead;
	purchasereq* phead;
	
	int itemsize, suppsize,psize;
	salesmanager()
	{		
		this->itemsize = 0;
		this->ihead = nullptr;
		this->suppsize = 0;
		this->shead = nullptr;
		this->psize = 0;
		this->phead = nullptr;		
	}
	void salesfunctiondisplay()
	{
		cout << "\t\tFunctionalities" << endl;
		cout << "1.Item Entry (Add/Delete/Edit)" << endl;
		cout << "2.Supplier Entry (Add/Delete/Edit)" << endl;
		cout << "3.Daily Item-wise Sales Entry (Add/Delete/Edit)" << endl;
		cout << "4.Purchase Requisition (Add/Delete/Edit)" << endl;
		cout << "5.Display Requisition" << endl;
		cout << "6.List of Purchaser Orders" << endl;
		cout << "7.Logout" << endl;
		cout << "selection : ";
	}
	void sfunctiondisplay()
	{
		cout << "\t\tFunction" << endl;
		cout << "1.Add" << endl;
		cout << "2.Delete" << endl;
		cout << "3.Edit"<< endl;
		cout << "4.View record" << endl;
		cout << "5.Back" << endl;
		cout << "Selection : ";
	}
	void prdisplay()
	{
		cout <<  "\t\tFunction" << endl;
		cout << "1.Add" << endl;
		cout << "2.Delete" << endl;
		cout << "3.Edit" << endl;
		cout << "4.Back" << endl;
		cout << "Selection : ";

	}
	

	void addsupplier(string sname)
	{		
		string supid = "s";
		supplierinfo* newnode = new supplierinfo;
		if (searchsuppname(sname) == true)
		{
			cout << "There are exsits name in the record" << endl;
		}
		else
		{
			newnode->suppid = supid + to_string(suppsize + 401);
			newnode->suppname = sname;
			newnode->snext = shead;
			shead = newnode;
			suppsize++;
		}
		
	}
	bool searchsuppid(string sid)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;
		bool found = false;
		while (current != NULL)
		{
			if (current->suppid == sid)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found==true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool searchsuppname(string sname)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;
		bool found = false;
		while (current != NULL)
		{
			if (current->suppname == sname)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool searchitemname(string iname)
	{
		iteminfo* icurrent = ihead;
		iteminfo* prev = ihead;
		bool found = false;
		while (icurrent != NULL)
		{
			if (icurrent->itemname == iname)
			{
				found = true;
				break;
			}
			else if (icurrent->itemid==iname)
			{
				found = true;
				break;
			}
			else
			{
				prev = icurrent;
				icurrent = icurrent->inext;
			}
		}
		if (found == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool searchitemid(string id)
	{
		iteminfo* icurrent = ihead;
		iteminfo* prev = ihead;
		bool found = false;
		while (icurrent != NULL)
		{
			if (icurrent->itemid == id)
			{
				found = true;
				break;
			}
			else if (icurrent->itemname==id)
			{
				found = true;
				break;
			}
			else
			{
				prev = icurrent;
				icurrent = icurrent->inext;
			}
		}
		if (found == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	   
	void additem(string item_name, string supp_id,int stock_num)
	{
	
		iteminfo* newitem = new iteminfo;
		string itemcode = "I";
		if (searchsuppid(supp_id)==true)
		{
			if (searchitemname(item_name) == false)
			{
				newitem->itemid = itemcode + to_string(itemsize + 301);
				newitem->itemname = item_name;
				newitem->suppid = supp_id;
				newitem->stocknum = stock_num;
				newitem->inext = ihead;
				ihead = newitem;
				itemsize++;							
			}
			else
			{
				cout << "There are exist product name " << endl;
			}
		}
		else
		{
			cout << "There are no exist Supplier" << endl;
		}	

	}

	void deleteitem(string search)
	{
		iteminfo* current = ihead;
		iteminfo* prev = ihead;
		bool found = false;
		while (current != NULL)
		{
			if (current->itemname ==search)
			{
				found = true;
				break;
			}
			else if(current->itemid==search)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->inext;
			}
		}
		if (found)
		{
			if (current == ihead)
			{
				ihead = ihead->inext;
				delete current;
				cout << "Delete success" << endl;
			}
			else
			{
				prev->inext = current->inext;
				delete current;
				cout << "Delete success" << endl;
			}
		}
	}

	void displayitem()
	{
		iteminfo* current = ihead;
		if (current == NULL)
		{
			cout << "No record in the list" << endl;
		}
		else
		{
			while (current != NULL)
			{
				cout << "Item ID :" << current->itemid << endl;
				cout << "Item Name :" << current->itemname << endl;
				cout << "Item supplied by :" << current->suppid << endl;
				cout << "Item stock number :" << current->stocknum << endl<<endl;
				current = current->inext;
			}
		}
	}

	void deletesupplier(string name)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;

		bool found = false;
		while (current != NULL)
		{
			if (current->suppname==name)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found)
		{
			if (current==shead)
			{
				shead = shead->snext;
				delete current;
				cout << "Delete success" << endl;
			}
			else
			{
				prev->snext = current->snext;
				delete current;
				cout << "Delete success" << endl;
			}
		}
	}

	bool searchsupp(string a)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;

		bool found = false;
		while (current != NULL)
		{
			if (current->suppname == a)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found)
		{
			cout << "Record found" << endl;
			return true;
		}
		else
		{
			cout << "Record does not exist" << endl;
			return false;
		}
	}
	void searchresult(string name)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;

		bool found = false;
		while (current != NULL)
		{
			if (current->suppname == name)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found)
		{
			cout << "Supplier ID :"<<current->suppid << endl;
			cout << "Supplier Name :" << current->suppname << endl;
		}
		else
		{
			cout << "Record does not exists";
		}
	}

	void viewallsup()
	{
		supplierinfo* current =shead;
		iteminfo* icurrent = ihead;
		if (current==NULL)
		{
			cout << "No record in the list" << endl;
		}
		else
		{
			while (current!=NULL)
			{
				cout << "Supplier ID :" << current->suppid << endl;
				cout << "Supplier Name :" << current->suppname << endl;
				
					cout << "Provide item :" << endl<<endl;
					while (icurrent!=NULL)
					{
						if (current->suppid== icurrent->suppid)
						{
							cout << "Item ID :" << icurrent->itemid << "\t" << "Item Name :" << icurrent->itemname << endl;
							icurrent = icurrent->inext;
						}
						else
						{
							break;
						}												
					}
				
				current = current->snext;
			}
		}
	}

	void modifysuppl(string name,string newname)
	{
		supplierinfo* current = shead;
		supplierinfo* prev = shead;

		bool found = false;
		while (current != NULL)
		{
			if (current->suppname == name)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->snext;
			}
		}
		if (found)
		{
			current->suppname = newname;
			current = current->snext;
			cout << "Modify success" << endl;
		}
		else
		{
			cout << "Record does not exists";
		}
	}

	void modifyitem(string search, string newname)
	{
		iteminfo* current = ihead;
		iteminfo* prev = ihead;

		bool found = false;
		while (current != NULL)
		{
			if (current->itemid == search)
			{
				found = true;
				break;
			}
			else if(current->itemname==search)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->inext;
			}
		}
		if (found)
		{		
				if (searchitemname(newname)==false)
				{
					current->itemname = newname;
					current = current->inext;
					cout << "Modify success" << endl;
				}
				else
				{
					cout << "Modify failed" << endl;
				}				
		}
		else
		{
			cout << "Record does not exists";
		}
	}
	void modifyitem(string search, int stocknum)
	{
		iteminfo* current = ihead;
		iteminfo* prev = ihead;

		bool found = false;
		while (current != NULL)
		{
			if (current->itemid == search)
			{
				found = true;
				break;
			}
			else if (current->itemname == search)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->inext;
			}
		}
		if (found)
		{
			
				current->stocknum =current->stocknum- stocknum;
				current = current->inext;
				cout << "Update success" << endl;			
		}
		else
		{
			cout << "Record does not exists";
		}
	}
	void addpr(string id, int stocknum, string idrequest, string date)
	{
		purchasereq* newnode = new purchasereq;
		iteminfo* icurrent = ihead;

		string requestid = "PR";
		iteminfo* prev = ihead;
		bool found = false;
		while (icurrent != NULL)
		{
			if (icurrent->itemid ==id)
			{
				found = true;
				break;
			}
			else
			{
				prev = icurrent;
				icurrent = icurrent->inext;
			}
		}
		if (found == true)
		{
			newnode->prid = requestid + to_string(psize + 601);
			newnode->itemid = id;
			newnode->suppid = icurrent->suppid;
			newnode->idrequestby = idrequest;
			newnode->stocknum = stocknum;
			newnode->daterequired = date;
			newnode->pnext = phead;
			phead = newnode;
			psize++;
		}
	}
	void displaypr()
	{
		purchasereq* current = phead;
		if (current==NULL)
		{
			cout << "No purchase required" << endl;

		}
		else
		{
			while (current!= NULL)
			{
				cout << "Purchase Rquest ID :" << current->prid<<endl;
				cout << "Requeste by :" << current->idrequestby << endl;
				cout << "Item ID Requested :" << current->itemid << endl;
				cout << "Date Required :" << current->daterequired << endl;
				cout << "Item Quantity :" << current->stocknum << endl;
				current = current->pnext;
			}
		}

	}
	void deletepr(string deletepr)
	{
		purchasereq* current = phead;
		purchasereq* prev = phead;

		bool found = false;
		while (current != NULL)
		{
			if (current->prid == deletepr)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->pnext;
			}
		}
		if (found)
		{
			if (current == phead)
			{
				phead = phead->pnext;
				delete current;
				cout << "Delete success" << endl;
			}
			else
			{
				prev->pnext = current->pnext;
				delete current;
				cout << "Delete success" << endl;
			}
		}
		else
		{
			cout << "No record found" << endl;
		}
	}
	void editpr(string prid1,string newitemcode,int newquan,string newdate)
	{
		purchasereq* pcurrent = phead;
		iteminfo* icurrent = ihead;
		purchasereq* pprev = phead;
		string requestid = "PR";
		iteminfo* prev = ihead;
		bool found = false;
		bool pfound = false;
		while (pcurrent!=NULL)
		{
			if (pcurrent->prid==prid1)
			{
				pfound = true;
				break;
			}
			else
			{
				pprev = pcurrent;
				pcurrent = pcurrent->pnext;
			}
		}
		if (pfound==true)
		{
			while (icurrent != NULL)
			{
				if (icurrent->itemid == newitemcode)
				{
					found = true;
					break;
				}
				else
				{
					prev = icurrent;
					icurrent = icurrent->inext;
				}
			}
			if (found == true)
			{
				pcurrent->itemid = newitemcode;
				pcurrent->stocknum = newquan;
				pcurrent->daterequired = newdate;
				icurrent = icurrent->inext;
			}
			pcurrent = pcurrent->pnext;
		}
		else
		{
			cout << "Could not modify " << endl;
		}
		
	}
	bool searchprid(string a)
	{
		purchasereq* pcurrent = phead;
		purchasereq* pprev = phead;
		bool found = false;
		while (pcurrent != NULL)
		{
			if (pcurrent->prid == a)
			{
				found = true;
				break;
			}
			else
			{
				pprev = pcurrent;
				pcurrent = pcurrent->pnext;
			}
		}
		if (found == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


	void writesupply()
	{
		supplierinfo* current = shead;		
		ofstream wsupply("supplierinfo.txt");
		if (wsupply.is_open())
		{
			while (current != NULL)
			{
				wsupply << current->suppid << "\t" << current->suppname << endl;		
				current = current->snext;
			}
		}
		wsupply.close();
	}
	void loadsuppldata()
	{
		supplierinfo* newnode = new supplierinfo;
		ifstream reader("supplierinfo.txt");
		string id, name;
		if (reader.is_open())
		{
			string line;
			while (getline(reader,line))
			 {
				istringstream iss(line);
				iss >> id;
				iss >> name;
				addsupplfromfile(id, name);
			 }
		}

		reader.close();
	}
	void addsupplfromfile(string id,string name)
	{
		supplierinfo* newnode = new supplierinfo;
		newnode->suppid = id;
		newnode->suppname = name;
		newnode->snext = shead;
		shead = newnode;
		suppsize++;
	}
	
	void loaditemdata()
	{
		iteminfo* newnode = new iteminfo;
		ifstream reader("iteminfo.txt");
		string id, name, suppid;
		int stocknum;
		if (reader.is_open())
		{
			string line;
			while (getline(reader, line))
			{
				istringstream iss(line);
				iss >> id;
				iss >> name;
				iss >> stocknum;
				iss >> suppid;
				additemfromfile(id, name, suppid, stocknum);
			}
		}
		reader.close();
	}
	void additemfromfile(string id,string name,string suppid,int snum)
	{
		iteminfo* newitem = new iteminfo;
		newitem->itemid = id;
		newitem->itemname = name;
		newitem->suppid = suppid;
		newitem->stocknum = snum;
		newitem->inext = ihead;
		ihead = newitem;
		itemsize++;
	}
	void writeitem()
	{
		iteminfo* current = ihead;
		ofstream wsupply("iteminfo.txt");
		if (wsupply.is_open())
		{
			while (current != NULL)
			{
				wsupply << current->itemid<< "\t" << current->itemname <<"\t"<< current->stocknum << "\t" << current->suppid << "\t" << endl;
				current = current->inext;
			}
		}
		wsupply.close();
	}

	void writepr()
	{
		purchasereq* current = phead;
		ofstream wpr("purchaserequest.txt");
		if (wpr.is_open())
		{
			while (current!=NULL)
			{
				wpr << current->prid << "\t" << current->itemid << "\t" << current->stocknum << "\t" << current->idrequestby << "\t" << current->daterequired << "\t" << current->suppid << "\t" << "Not approve\t" << "NULL" << endl;
				current = current->pnext;
			}
		}
		wpr.close();
	}
	void loadprdata()
	{
		ifstream reader("purchaserequest.txt");
		string prid, itemid, idrequest, date, suppid, status, approveby;
		int stocknum;
		if (reader.is_open())
		{
			string line;
			while (getline(reader,line))
			{
				istringstream iss(line);
				iss >> prid;
				iss >> itemid;
				iss >> stocknum;
				iss >>idrequest;
				iss >> date;
				iss >> suppid;
				iss >> status;
				iss >> approveby;
				addprfromfile(prid, itemid, stocknum, idrequest, date, suppid, status, approveby);
			}
		}
	}
	void addprfromfile(string prid1,string itemid,int stocknum,string idrequestby,string date,string suppid,string status,string approveby)
	{
		purchasereq* newnode = new purchasereq;
		newnode->prid = prid1;
		newnode->itemid = itemid;
		newnode->stocknum = stocknum;
		newnode->idrequestby = idrequestby;
		newnode->daterequired = date;
		newnode->suppid = suppid;
		newnode->status = status;
		newnode->approvebyid = approveby;
		newnode->pnext = phead;
		phead = newnode;
		psize++;
	}
};


class purchasemanager:public salesmanager
{
public:
	purchaseorder* pohead;
	int posize;
	purchasemanager()
	{
		this->pohead = nullptr;
		this->posize = 0;
	}

	void displayfunction()
	{
		cout << "\t\tFunction" << endl;
		cout << "1. List of Items " << endl;
		cout << "2. List of Suppliers" << endl;
		cout << "3. Display Requisition" << endl;
		cout << "4. Generate Purchase Order" << endl;
		cout << "5. List of Purchaseer Orders " << endl;
		cout << "6. Logout " << endl;
		cout << "Selection :";
	}

	void createpo(string a,string idapprove)
	{
		purchasereq* pcurrent=phead;
		purchasereq* pprev = phead;
		string poids = "PO";
		
		purchaseorder* newnode = new purchaseorder;
		bool found = false;
		while (pcurrent!=NULL)
		{
			if (pcurrent->prid==a)
			{
				found = true;
				break;

			}
			else
			{
				pprev = pcurrent;
				pcurrent = pcurrent->pnext;
			}
		}
		if (found==true)
		{
			newnode->poid = poids + to_string(posize + 701);			
			newnode->itemid =pcurrent->itemid;
			newnode->suppid = pcurrent->suppid;
			newnode->idrequestby = pcurrent->idrequestby;
			newnode->stocknum = pcurrent->stocknum;
			newnode->daterequired = pcurrent->daterequired;
			newnode->approvebyid = idapprove;
			newnode->status = "Approve";
			newnode->ponext = pohead;
			pohead = newnode;
			posize++;
			deletepr(a);
		}
	}
	bool searchpoid(string id)
	{
		purchaseorder* current = pohead;
		purchaseorder* prev = pohead;;
		bool found = false;
		while (current != NULL)
		{
			if (current->poid ==id)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->ponext;
			}
		}
		if (found)
		{
			cout << "Record found" << endl;
			return true;
		}
		else
		{
			cout << "Record does not exist" << endl;
			return false;
		}
	}
	void deletepo(string poid1)
	{
		purchaseorder* current = pohead;
		purchaseorder* prev = pohead;
		bool found = false;
		while (current!=NULL)
		{
			if (current->poid==poid1)
			{
				found = true;
				break;
			}
			else
			{
				prev = current;
				current = current->ponext;
			}
		}
		if (found)
		{
			if (current == pohead)
			{
				pohead = pohead->ponext;
				cout << "Delete success" << endl;
			}
			else
			{
				prev->ponext = current->ponext;
				delete current;
				cout << "Delete success" << endl;
			}
		}
		else
		{
			cout << "Record does not exist " << endl;
		}
	}
	void editpo(string poid1, int newstocknum, string newdate)
	{
		purchaseorder* current = pohead;
		purchaseorder* poprev = pohead;
		bool found = false;
		while (current!=NULL)
		{
			if (current->poid==poid1)
			{
				found = true;
				break;
			}
			else
			{
				poprev = current;
				current = current->ponext;
			}
		}
		if (found==true)
		{
			current->stocknum = newstocknum;
			current->daterequired = newdate;
			current = current->ponext;
			cout << "Modify success" << endl;
		}

	}
	void displaypo()
	{
		purchaseorder* current = pohead;
		if (current==NULL)
		{
			cout << "No purchase order being created" << endl;

		}
		else
		{
			while (current!=NULL)
			{
				cout << "Purchase Order ID :" << current->poid << endl;
				cout << "Requeste by :" << current->idrequestby << endl;
				cout << "Approved by :" << current->approvebyid << endl;
				cout << "Item ID Requested :" << current->itemid << endl;
				cout << "Item supplied by :" << current->suppid << endl;
				cout << "Date Required :" << current->daterequired << endl;
				cout << "Item Quantity :" << current->stocknum <<endl<<endl;
				current = current->ponext;
			}			
		}
	}

	void writepo()
	{
		purchaseorder* current = pohead;
		ofstream wpr("purchaseorder.txt");
		if (wpr.is_open())
		{
			while (current != NULL)
			{
				wpr << current->poid << "\t" << current->itemid << "\t" << current->stocknum << "\t" << current->idrequestby << "\t" << current->daterequired << "\t" << current->suppid << "\t" << "Approve\t" << current->approvebyid<< endl;
				current = current->ponext;
			}
		}
		wpr.close();
	}
	void loadpodata()
	{
		ifstream reader("purchaseorder.txt");
		string prid, itemid, idrequest, date, suppid, status, approveby,poid;
		int stocknum;
		if (reader.is_open())
		{
			string line;
			while (getline(reader, line))
			{
				istringstream iss(line);
				iss >> poid;				
				iss >> itemid;
				iss >> stocknum;
				iss >> idrequest;
				iss >> date;
				iss >> suppid;
				iss >> status;
				iss >> approveby;
				addpofromfile(poid, itemid, stocknum, idrequest, date, suppid, status, approveby);
			}
		}
	}
	void addpofromfile(string poid, string itemid, int stocknum, string idrequestby, string date, string suppid, string status, string approveby)
	{
		purchaseorder* newnode = new purchaseorder;
		newnode->poid = poid;
		newnode->itemid = itemid;
		newnode->stocknum = stocknum;
		newnode->idrequestby = idrequestby;
		newnode->daterequired = date;
		newnode->suppid = suppid;
		newnode->status = status;
		newnode->approvebyid = approveby;
		newnode->ponext = pohead;
		pohead = newnode;
		posize++;
	}

};


