#include <iostream>
#include "assignment.h"
#include <string>
#include <sstream>
using namespace std;

void invalidinput()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Invalid input, try again" << endl << endl;
}
void displaysystem()
{
	cout << "\tFOOD ORDER AND DELIVERY SYSTEM" << endl;
	cout << "Pick one of the service below: " << endl;
	cout << "1.\tCreate a new order" << endl;
	cout << "2.\tSearch for an order" << endl;
	cout << "3.\tView orders information" << endl;
	cout << "4.\tView delivery list" << endl;
	cout << "5.\tQuit" << endl;
	cout << endl << "Your selection:";
}
void displaymenu()
{
	cout << "\t[Item Menu]" <<  endl;
	cout << "1.\tBurger\t\t\t$6.50 per one" << endl;
	cout << "2.\tSpagethetti\t\t$7.50 per one" << endl;
	cout << "3.\tCoke\t\t\t$1.50 per one" << endl;
	cout << "4.\tIce-cream\t\t$1.00 per one" << endl;
	cout << "5.\tApple Pie\t\t$2.80 per one" << endl;
	cout << "6.\tDrinking water\t\t$2.00 per one" << endl;
	cout << "7.\tAmericano Espresso\t$6.50 per one" << endl;
	cout << "8.\tCash Total" << endl;
	
}

void searchfuncdisplay()
{
	cout << "\tFOOD ORDER AND DELIVERY SYSTEM" << endl;
	cout << "Pick one of the service below: " << endl;
	cout << "1.\tDelete an order" << endl;
	cout << "2.\tModify for an order" << endl;
	cout << "3.\tBack <<" << endl;
	cout << endl << "Your selection:";
}

int main()
{
	linkedList orderlist;
	orderinfo* oinfo = new orderinfo;
	string name; 
	string addr; 
	int telno; 
	int icode;
	string itype;
	string searchname;
	int quan; 
	float price;
	int selectfunc,secondselect;
	int selectitem;
	int itembelong;
	int searchinfo, searchnum;
	do
	{
		displaysystem();
		
		if(cin >> selectfunc)
		{
			cout << endl;
			switch (selectfunc)
			{
			case 1:
				system("CLS");
				cout << "Insert Customer Name: ";
				cin >> name;
				cout << "Insert Customer Address: ";
				cin >> addr;
				cout << "Insert Customer telephone number: ";
				if (cin >> telno)
				{
					system("CLS");
					displaymenu();
					orderlist.newOrder(name, addr, telno);
					itembelong = orderlist.size;
					do
					{
						cout << "Insert item code: ";
						if (cin >> selectitem)
						{
							switch (selectitem)
							{
							case 1:
								icode = 1;
								itype = "Burger";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 6.50 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 2:
								icode = 2;
								itype = "Spagethetti";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 7.50 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 3:
								icode = 3;
								itype = "Coke";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 1.50 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 4:
								icode = 4;
								itype = "Ice-cream";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 1.00 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 5:
								icode = 5;
								itype = "Apple Pie";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 2.80 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);

								break;
							case 6:
								icode = 6;
								itype = "Drinking water";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 2.00 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 7:
								icode = 7;
								itype = "Americano Espresso";
								cout << "Insert item quantity: ";
								cin >> quan;
								price = 6.50 * quan;
								orderlist.newItem(icode, itype, quan, price, itembelong);
								break;
							case 8:
								system("CLS");
								break;
							default:
								break;
							}

						}
						else
						{
							invalidinput();
							system("CLS");
						}

					} while (selectitem != 8);
					itembelong++;
				}
				else
				{
					invalidinput();
				}
				
				break;
			case 2:
				char yn;
				cout << "Search order number or recipient name in order to proceed to next step: " << endl;
				cout << "1.Name\t2.Order Number" << endl;
				cout << "Selection: ";
				cin >> searchinfo;
				switch (searchinfo)
				{
				
				case 1:
					cout << "Search:";
					cin >> searchname;
					searchfuncdisplay();
					cout << endl;
					if (cin>>secondselect)
					{
						switch (secondselect)
						{
						case 1:
							orderlist.deleteorderat(searchname);
							cout << "Delete Success" << endl;
							break;
						case 2:
							system("CLS");
							cout << "This is what you can modify: " << endl;
							cout << "Original :" << endl;
							orderlist.displayrecipient(searchname);
							cout << endl;
							cout << "New information" << endl;
							cout << "Name : ";
							cin >> name;
							cout << "Customer new address :";
							cin >> addr;
							cout << "Customer new telephone number :";
							cin >> telno;
							cout << "Type 'Y' for confirmation and 'N' for cancel service" << endl;
							cin >> yn;
							if (yn == 'y' || yn == 'Y')
							{
								orderlist.modifyrecipient(name, addr, telno, searchname);
								cout << "Modify success" << endl;
								break;
							}
							else if (yn == 'n' || yn == 'N')
							{
								break;
							}
							else
							{
								invalidinput();
							}

						default:
							break;
						}
						break;
					}

					else
					{
						invalidinput();
					}
				case 2:
					cout << "Search:";
					cin >> searchnum;
					searchfuncdisplay();
					cout << endl;
					if (cin >> secondselect)
					{
						switch (secondselect)
						{
						case 1:
							orderlist.deleteorderat(searchnum);
							cout << "Delete Success" << endl;
							break;
						case 2:
							system("CLS");
							cout << "This is what you can modify: " << endl;
							cout << "Original :" << endl;
							orderlist.displayrecipient(searchnum);
							cout << endl;
							cout << "Name : ";
							cin >> name;
							cout << "Customer new address :";
							cin >> addr;
							cout << "Customer new telephone number :";
							cin >> telno;
							cout << "Type 'Y' for confirmation and 'N' for cancel service" << endl;
							cin >> yn;
							if (yn == 'y' || yn == 'Y')
							{
								orderlist.modifyrecipientint(name, addr, telno, searchnum);
								cout << "Modify success" << endl;
							}
							else if (yn == 'n' || yn == 'N')
							{
								break;
							}
							else
							{
								invalidinput();
							}

						default:
							break;
						}
						break;
					}
					else
					{
						invalidinput();
					}
				case 3:
					break;
				default:
					break;
				}			
				break;

			case 3:
				system("CLS");
				orderlist.displayorder_item();
				char fullfill;
				
				if (orderlist.search())
				{
					break;
				}
				else
				{
					cout << "Insert 'F' to fullfill the order and 'B' to back to the system" << endl;
					cout << "Note: Fulfilled order is the most recent order" << endl;
					cout << "Your selection: ";

					if (cin >> fullfill)
					{
						if (fullfill == 'F' || fullfill == 'f')
						{
							orderlist.fufilordermove();
							cout << "Fullfill order success" << endl << endl;
							system("CLS");
						}
						else
						{
							system("CLS");
							break;
							
						}
					}
					else
					{
						invalidinput();
					}
				}
				break;
			case 4:
				system("CLS");
				cout << "\tOrder Complete"<<endl;
				orderlist.displayfullfillorder();
				break;
			case 5:
				system("CLS");
				cout << "Thank you for using" << endl;
				exit(0);
			default:
				break;
			}
		}
		else
		{
			invalidinput();
			system("CLS");
		}
	
	} while (selectfunc!=5);			
}