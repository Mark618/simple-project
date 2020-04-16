#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"linkedlist.h"

using namespace std;

void invalidinput()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Invalid input, try again" << endl << endl;
}

int main()
{
	/*ofstream writer("admininfo.txt");*/
	ifstream reader("admininfo.txt");
	userinfo* uinfo = new userinfo;
	linkedlist userlist;
	supplierinfo* sinfo = new supplierinfo;
	salesmanager func;
	purchasemanager function;	
	string sname,newname,iname,suppid, newiname;
	string pritemid,date,prid;
	int itemstock;
	string itemid;
	double itemprice;
	string login_name, login_pswd;
	string username, password, position,userid;
	int firstselect, secondselect;
	func.loaditemdata();
	func.loadsuppldata();
	func.loadprdata();

	function.loadpodata();
	function.loadprdata();
	bool logout = false;
	do
	{
		if (reader.is_open())
		{
			string line;
			while (getline(reader, line))
			{
				istringstream iss(line);
				string id;
				string name;
				string position, password;
				iss >> id;
				iss >> name;
				iss >> position;
				iss >> password;
				userlist.addUserfromfile(id, name, password, position);
			}
		}
		
		cout << "\t\t\tTSB System" << endl;
		cout << "User name :";
		cin >> login_name;
		cout << "Password :";
		cin >> login_pswd;
		if (userlist.checkpassword(login_name,login_pswd))
		{
			switch (userlist.getusertype(login_name))
			{
			case 1:
				cout << "Welcome admin" << endl;
				do
				{
					userlist.display();					
					if (cin >> firstselect)
					{
						switch (firstselect)
						{
						case 1://item 
							do
							{
								func.sfunctiondisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert item name :";
										cin >> iname;
										cout << "Insert the supplier id :";
										cin >> suppid;
										func.additem(iname, suppid, 0);
										break;
									case 2:
										cout << "Insert item id or item name :";
										cin >> iname;
										func.deleteitem(iname);
										break;
									case 3:
										cout << "Insert item id or item name :";
										cin >> iname;
										if (func.searchitemname(iname) == true)
										{
											cout << "Insert the new item name :";
											cin >> newiname;
											func.modifyitem(iname, newiname);
										}
										else
										{
											cout << "Item not found" << endl;
										}
										break;
									case 4:
										func.displayitem();
										break;
									case 5:
										func.writeitem();
										break;
									default:
										func.writeitem();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 5);
							break;
						case 2:
							do
							{
								func.sfunctiondisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert supplier name :";
										cin >> sname;
										func.addsupplier(sname);
										break;
									case 2:
										cout << "Insert supplier name :";
										cin >> sname;
										func.deletesupplier(sname);
										break;
									case 3:
										cout << "Insert supplier name that you wish to modify :";
										cin >> sname;
										cout << "Original details" << endl;
										func.searchresult(sname);
										cout << "This is what you can change" << endl;
										cout << "New supplier name :";
										cin >> newname;
										func.modifysuppl(sname, newname);
										break;
									case 4:
										func.viewallsup();
										break;
									case 5:
										func.writesupply();
										break;
									default:
										func.writesupply();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								

							} while (secondselect != 5);
							break;
						case 3:
							do
							{
								cout << "Daily Item-wise Sales Entry" << endl;
								cout << "1. Update stock item" << endl;
								cout << "2. Back " << endl;
								cout << "Selection : ";
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Enter the Item ID :";
										cin >> itemid;
										if (func.searchitemid(itemid) == true)
										{
											cout << "Enter the total sales of the item :";
											cin >> itemstock;
											func.modifyitem(itemid, itemstock);
										}
										else
										{
											cout << "No record found" << endl;
										}
										break;
									case 2:
										func.writeitem();
										break;
									default:
										func.writeitem();
										break;
									}
								}
								else
								{
									invalidinput();
								}

							} while (secondselect != 2);
							break;
						case 4:
							do
							{
								func.prdisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert the item id request :";
										cin >> pritemid;
										cout << "Insert the number of stock request :";
										cin >> itemstock;
										cout << "Insert the date item required :";
										cin >> date;
										func.addpr(pritemid, itemstock, userlist.getuserid(login_name), date);
										break;
									case 2:
										cout << "Insert the PR ID :";
										cin >> prid;
										func.deletepr(prid);
										break;
									case 3:
										cout << "Insert the PR ID :";
										cin >> prid;
										if (func.searchprid(prid) == true)
										{
											cout << "Insert the new Item ID :";
											cin >> pritemid;
											cout << "Insert the new quantity :";
											cin >> itemstock;
											cout << "Insert the new date required :";
											cin >> date;
											func.editpr(prid, pritemid, itemstock, date);
										}
										else
										{
											cout << "No record found " << endl;
										}
										break;
									case 4:
										func.writepr();
										break;
									default:
										func.writepr();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 4);
							break;
						case 5:
							system("CLS");
							cout << "\t\tPurchase request list" << endl;
							func.displaypr();
							break;
						case 6:
							system("CLS");
							cout << "\t\tItem list" << endl;
							func.displayitem();
							break;
						case 7:
							system("CLS");
							cout << "\t\tSupplier list" << endl;
							func.viewallsup();
							break;
						
						case 8:
							system("CLS");
							do
							{
								function.prdisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "\t\tPurchase Requisition Available" << endl;
										function.displaypr();
										cout << "Insert the PR ID that you approve :";
										cin >> prid;
										function.createpo(prid, userlist.getuserid(login_name));
										break;
									case 2:
										cout << "Insert the PR ID that you want to delete :";
										cin >> prid;
										function.deletepr(prid);
										break;
									case 3:
										cout << "Insert the PR ID that you want to edit :";
										cin >> prid;
										if (function.searchpoid(prid) == true)
										{
											cout << "This is what you can edit :" << endl;
											cout << "Item quantity :" << endl;
											cin >> itemstock;
											cout << "Item require date :" << endl;
											cin >> date;
											function.editpo(prid, itemstock, date);
										}
										else
										{
											cout << "No record found" << endl;
										}
										break;
									case 4:
										function.writepo();
										break;
									default:
										break;
									}
								}
								else
								{
									invalidinput();
								}
							
								
							} while (secondselect != 4);
							break;
						case 9:
							system("CLS");
							function.displaypo();
							break;
						case 10:
							system("CLS");
							do
							{
								userlist.adminfunc();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert the new user name :";
										cin >> username;
										if (userlist.searchusername(username) == true)
										{
											cout << "There is exsits user name" << endl;
										}
										else
										{
											cout << "Insert the password :";
											cin >> password;
											cout << "Insert the position :";
											cin >> position;
											userlist.addnewuser(username, password, position);
											cout << "Success" << endl;
										}
										break;
									case 2:
										cout << "Insert the user ID that you want to remove :";
										cout << "Current user in the system :" << endl;
										userlist.displayuser();
										cin >> userid;
										if (userlist.searchadmin(userid) == true)
										{
											cout << "Could not remove admin staff" << endl;
										}
										else
										{
											userlist.deleteuser(userid);
										}
										break;
									case 3:
										userlist.saveuser();
										
										break;
									default:
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 3);
						case 11:
							system("CLS");
							break;
						default:
							cout << "Invalid option try again " << endl;
							break;
						}
					}
					else
					{
						invalidinput();
					}
					
				} while (firstselect!=11);
				break;

			case 2:
				cout << "Welcome Sales Manager" << endl;
				do
				{
					func.salesfunctiondisplay();
					
					if (cin >> firstselect)
					{
						switch (firstselect)
						{
						case 1:
							do
							{								
								func.sfunctiondisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert item name :";
										cin >> iname;
										cout << "Insert the supplier id :";
										cin >> suppid;
										func.additem(iname, suppid, 0);
										break;
									case 2:
										cout << "Insert item id or item name :";
										cin >> iname;
										if (func.searchitemid(iname)==true)
										{
											func.deleteitem(iname);
										}
										else
										{
											cout << "No record found" << endl;
										}									
																				
										break;
									case 3:
										cout << "Insert item id or item name :";
										cin >> iname;
										if (func.searchitemname(iname) == true)
										{
											cout << "Insert the new item name :";
											cin >> newiname;
											func.modifyitem(iname, newiname);
										}
										else
										{
											cout << "Item not found" << endl;
										}
										break;
									case 4:
										func.displayitem();
										break;
									case 5:
										func.writeitem();
										break;
									default:
										func.writeitem();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 5);
							break;
						case 2:
							do
							{
								func.sfunctiondisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert supplier name :";
										cin >> sname;
										func.addsupplier(sname);
										break;
									case 2:
										cout << "Insert supplier name :";
										cin >> sname;
										func.deletesupplier(sname);
										break;
									case 3:
										cout << "Insert supplier name that you wish to modify :";
										cin >> sname;
										cout << "Original details" << endl;
										func.searchresult(sname);
										cout << "This is what you can change" << endl;
										cout << "New supplier name :";
										cin >> newname;
										func.modifysuppl(sname, newname);
										break;
									case 4:
										func.viewallsup();
										break;
									case 5:
										func.writesupply();
										break;
									default:
										func.writesupply();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								

							} while (secondselect != 5);
							break;
						case 3:
							do
							{
								cout << "Daily Item-wise Sales Entry" << endl;
								cout << "1. Update stock item" << endl;
								cout << "2. Back " << endl;
								cout << "Selection : ";
								if (cin>>secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Enter the Item ID :";
										cin >> itemid;
										if (func.searchitemid(itemid) == true)
										{
											cout << "Enter the total sales of the item :";
											cin >> itemstock;
											func.modifyitem(itemid, itemstock);
										}
										else
										{
											cout << "No record found" << endl;
										}
										break;
									case 2:
										func.writeitem();
										break;
									default:
										func.writeitem();
										break;
									}
									
								}
								else
								{
									invalidinput();
								}

							} while (secondselect!=2);
							break;
						case 4:
							do
							{
								func.prdisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "Insert the item id request :";
										cin >> pritemid;
										cout << "Insert the number of stock request :";
										cin >> itemstock;
										cout << "Insert the date item required :";
										cin >> date;
										func.addpr(pritemid, itemstock, userlist.getuserid(login_name), date);
										break;
									case 2:
										cout << "Insert the PR ID :";
										cin >> prid;
										func.deletepr(prid);
										break;
									case 3:
										cout << "Insert the PR ID :";
										cin >> prid;
										if (func.searchprid(prid) == true)
										{
											cout << "Insert the new Item ID :";
											cin >> pritemid;
											cout << "Insert the new quantity :";
											cin >> itemstock;
											cout << "Insert the new date required :";
											cin >> date;
											func.editpr(prid, pritemid, itemstock, date);
										}
										else
										{
											cout << "No record found " << endl;
										}
										break;
									case 4:
										func.writepr();
										break;
									default:
										func.writepr();
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 4);
							break;
						case 5:
							system("CLS");
							func.displaypr();
							break;
						case 6:
							system("CLS");
							function.displaypo();
							break;
						case 7:
							system("CLS");
							break;
						default:
							break;
						}
					}
					else
					{
						invalidinput();
					}
					
				} while (firstselect!=7);			
				break;
			case 3:
				cout << "Welcome Purchase Manager" << endl;
				do
				{
					function.displayfunction();
					if (cin>>firstselect)
					{
						switch (firstselect)
						{
						case 1:
							system("CLS");
							func.displayitem();
							break;
						case 2:
							system("CLS");
							func.viewallsup();
							break;
						case 3:
							system("CLS");
							func.displaypr();
							break;
						case 4:
							system("CLS");
							do
							{
								function.prdisplay();
								if (cin >> secondselect)
								{
									switch (secondselect)
									{
									case 1:
										cout << "\t\tPurchase Requisition Available" << endl;
										function.displaypr();
										cout << "Insert the PR ID that you approve :";
										cin >> prid;
										function.createpo(prid, userlist.getuserid(login_name));
										break;
									case 2:
										cout << "Insert the PR ID that you want to delete :";
										cin >> prid;
										function.deletepr(prid);
										break;
									case 3:
										cout << "Insert the PR ID that you want to edit :";
										cin >> prid;
										if (function.searchpoid(prid) == true)
										{
											cout << "This is what you can edit :" << endl;
											cout << "Item quantity :" << endl;
											cin >> itemstock;
											cout << "Item require date :" << endl;
											cin >> date;
											function.editpo(prid, itemstock, date);
										}
										else
										{
											cout << "No record found" << endl;
										}
										break;
									case 4:
										function.writepo();
										break;
									default:
										break;
									}
								}
								else
								{
									invalidinput();
								}
								
							} while (secondselect != 4);
							break;
						case 5:
							system("CLS");
							function.displaypo();
							break;
						case 6:
							system("CLS");
							break;
						default:
							cout << "Wrong input please try again " << endl;
							break;
						}
					}
					else
					{
						invalidinput();
					}
								
				} while (firstselect!=6);
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "Wrong username or password;" << endl;
		}

	} while (true);	
	
	reader.close();

}
