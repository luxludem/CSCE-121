// HMWK 7.cpp : Defines the entry point for the console application.
// at least 7 source code files or more both .h and .cpp two for each print menu part of main, switch statment 
// the only include statment could interact with a single store store need find product find customer


#include<iostream>
#include<math.h>
#include<cstring>
#include<algorithm>
#include"customer.h"
#include"store.h"
#include <stdexcept>


using namespace std;

void customerinfo(string& firstname, string& lastname)
{
	

	cout << "Enter Customer first name" << endl;
	cin >> firstname;
	cout << "Enter Customer last name" << endl;
	cin >> lastname;
	

		return;
}
void productinfo(string& name, int& modelnumber, double& whole, double& retail,int& startingstock)
{
	cout << "Enter Product Name " << endl;
	cin >> name;
	cout << "Enter Model Number" << endl;
	cin >> modelnumber;
	cout << "Enter Wholesale Cost" << endl;
	cin >> whole;
	cout << "Enter Retail cost " << endl;
	cin >> retail;
	cout << "Enter Amount currently in stock" << endl;
	cin >> startingstock;

}

int main()
{
	cout << "Welcome to THE online store how may we help you today?" << endl;
	cout << endl;
	Store store;
	char c = 'y';
	int selection;
	bool test;
	while (c == 'y')
	{
		try {
			cout << "1:  See a list of all the customers and Id numbers" << endl;
			cout << "2:  See a list of all the products" << endl;
			cout << "3:  Add a new product to stock" << endl;
			cout << "4:  Add a new customer to registar " << endl;
			cout << "5:  Find Product" << endl;
			cout << "6:  Find customer (Get specific information about customer)" << endl;
			cout << "7:  Receive Shipment" << endl;
			cout << "8:  Set Sale on product" << endl;
			cout << "9:  Customer Purchase" << endl;
			cout << "10: Customer Payment" << endl;

			cout << endl;





			for (selection = -1; !(1 <= selection && selection <= 10); ) {
				if (!(cin >> selection)) {
					cout << "invalid input" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}




			switch (selection)
			{
			case 1:
			{ cout << "Customer Name| Id number" << endl;
			store.PrintCustList();
			break;
			}
			case 2:
			{cout << "Name|Model Number|Whole sale cost|Retail cost| Stock| Amount sold" << endl;
			store.PrintProductList();

			break;
			}
			case 3:
			{
				product Product;
				string  ProductName;
				int modelnum;
				double wholecost;
				double retailcost;
				int amount;
				productinfo(ProductName, modelnum, wholecost, retailcost, amount);
				Product.getNewProduct(ProductName, modelnum, wholecost, retailcost, amount);
				Product.getamountpurchased(0);
				cout << "Product Info:" << endl;
				cout << "Name|Model Number|Whole sale cost|Retail cost| Stock| Amount sold" << endl;
				Product.Print();
				store.addProductToList(Product);
				break;
			}
			case 4:
			{
				customer Customer;

				string fn;
				string ln;
				int idnum = 0;
				customerinfo(fn, ln);
				idnum = store.getIdNum(idnum) + 1;
				Customer.SetNewCustomer(fn, ln, idnum);
				cout << "Customer Info:" << endl;
				cout << "Customer Name| Id number" << endl;
				Customer.Print();
				store.AddCustomerToList(Customer);



				break;
			}
			case 5:
			{ int modelnum;
			cout << "Which product are you looking for please enter the Model Number" << endl;
			cin >> modelnum;
			cout << "Name|Model Number|Whole sale cost|Retail cost| Stock| Amount sold" << endl;
			store.findProduct(modelnum);
			break;
			}
			case 6:
			{ int idnum;
			cout << "Can we help you find a customer? Please enter the Id number" << endl;
			cout << "Customer Name| Id number" << endl;
			cin >> idnum;
			if (idnum < 0)
			{
				throw runtime_error("you need to enter an id on the list");
			}
			store.findcustomer(idnum);
			break;


			}
			case 7:
			{ int modelnum;
			int quant;
			cout << "Please Enter the Model number followed by the amount be stocked" << endl;
			cin >> modelnum;
			cin >> quant;
			while (quant < 1)
			{
				cout << "Please retype the amount you are shipping" << endl;
				cin >> quant;
			}
			store.getshipment(modelnum, quant);
			break;
			}
			case 8:
			{ int idnum;
			double sale;
			cout << "Enter the Id of the Product you would like to create a sale on" << endl;
			cin >> idnum;
			cout << "Enter the amount out of 100 you would like to take of the product" << endl;
			cin >> sale;
			store.setsale(idnum, sale);


			break;
			}
			case 9:
			{ int cust, mod, amo;

			cout << "Enter customer Id" << endl;
			cin >> cust;
			cout << "Enter model number" << endl;
			cin >> mod;
			cout << "Enter amount purchased" << endl;
			cin >> amo;
			if (amo < 0)
			{
				throw runtime_error("you can't purchase a negative amount");
			}
			store.makepurchase(cust, mod, amo);
			break;
			}
			case 10:
			{  int id;
			double payment;

			cout << "Enter customer Id" << endl;
			cin >> id;
			if (id < 0)
			{
				throw runtime_error("you need to enter an id on the list");
			}

			cout << "Enter amount customer has payed" << endl;
			cin >> payment;

			store.customerpayment(id, payment);

			cout << "Customer Balance has been updated" << endl;

			break;
			}

			default:
				cout << "It seems you did not enter a proper selection" << endl;
				break;
			}















		}
		catch (runtime_error& error)
		{
			cout << error.what() << endl;
			cout << "Make sure the lists are populated and you are using the correct inputs" << endl;

		}

	
	




	cout << "can we help you with anything else y/n?"<<endl;
	cin >> c;

}

			system("pause");
			return 0;
		
}

