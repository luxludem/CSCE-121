// store class.cpp

#include<iostream>
#include<fstream>
#include<ostream>
#include<istream>
#include<algorithm>
#include"store.h"
#include<string>
#include<vector>

using namespace std;


void Store::AddCustomerToList(customer test)
{
	customer AddCustomer;
	AddCustomer=test;

	customerlist.push_back(AddCustomer);


}

void Store::addProductToList(product producttest)
{
	product p;
	p = producttest;
	productlist.push_back(p);

	
}



void Store::PrintCustList() const
{
	customer c;
		for (int i = 0; i < customerlist.size(); i++)
		{
			c = customerlist.at(i);
				c.Print();

		}
}

void Store::PrintProductList() const
{
	product p;
	for (int i = 0; i < productlist.size(); i++)
	{
		p = productlist.at(i);
		p.Print();

	}
}

void Store::findProduct(int mondelnum) const
{
	
		
		product find;
		string holder1;
		int modelhold;
		double holder2;
		double holder3;
		int holder4;

		for (int i = 0; i < productlist.size(); i++)
		{
			find = productlist.at(i);
			find.getProductinfomation(holder1, modelhold, holder2, holder3, holder4);
			if (mondelnum == modelhold)
			{
				find.Print();
			}
			else {
				cout << "You did not enter a valid number" << endl;
			}

		}
	
	
	

}

void Store::findcustomer(int customerid) const
{
	
		customer holder;
		string firsthold;
		string secondhold;
		int idhold;
		

		for (int i = 0; i < customerlist.size(); i++)
		{
			holder = customerlist.at(i);
			holder.getcustomerinfo(firsthold, secondhold, idhold);
			if (customerid == idhold)
			{
				holder.Print();
				holder.getBalance();
				cout << "Purchase history:" << endl;
				holder.getpurchase();
			}
			else {
				cout << "You did not enter a valid id" << endl;
			}

		}
	
	
}

void Store::getshipment(int shipmodelnum, int quantity) 
{
	product find;
	string holder1;
	int modelhold;
	double holder2;
	double holder3;
	int holder4;
	

	for (int i = 0; i < productlist.size(); i++)
	{
		find = productlist.at(i);
		find.getProductinfomation(holder1, modelhold, holder2, holder3, holder4);
		if (shipmodelnum == modelhold)
		{
			find.addquantity(quantity);
			productlist.at(i) = find;
		//replace(productlist.begin(), productlist.end(), productlist.at(i), find);
			cout << "Stock has been updated" << endl;
		}
		else {
			cout << "We don't have this in stock, must be a shipment error" << endl;
		}
	}

}






void Store::makepurchase(int idnum, int modelnum, int quantity)
{
	customer temp;
	string  f;
	string l;
	int  id;
	int customerplaceholder;
	product purchase;
	
	string n;
	int m;
	double w;
	double r;
	int q;
	int productplaceholder;
	
	for (int i = 0; i < customerlist.size(); i++)
	{
		temp = customerlist.at(i);
		temp.getcustomerinfo(f, l, id);
		if (idnum == id)
		{
			customerplaceholder = i;
			temp=customerlist.at(i);

		}

	}
	for (int i = 0; i < productlist.size(); i++)
	{
		purchase = productlist.at(i);
		purchase.getProductinfomation(n, m, w, r, q);
		if (modelnum== m)
		{
			productplaceholder = i;
			purchase = productlist.at(i);

		}

	}
	
	double incre;
	incre = r*quantity;
	temp.addbalance(incre);
	while(quantity > q)
	{
		cout << "Not enough in stock enter new quanitiy" << endl;
		cin >> quantity;
	}
	purchase.subquantity(quantity);
	purchase.getamountpurchased(quantity);
	temp.addtopurchaselist(purchase);
	customerlist.at(customerplaceholder) = temp;
	productlist.at(productplaceholder) = purchase;
	temp.Print();
	purchase.Print();

	

	
}

void Store::customerpayment(int id,int amount)
{
	
	customer temp;
	string  f;
	string l;
	int  idnum;
	int customerplaceholder;
	

	for (int i = 0; i < customerlist.size(); i++)
	{
		temp = customerlist.at(i);
		temp.getcustomerinfo(f, l, idnum);
		if (id == idnum)
		{
			customerplaceholder = i;
			temp = customerlist.at(i);

		}

	}

	double balanceholder;
	temp.getBalanceum(balanceholder);
	while (amount > balanceholder)
	{
		cout << "We dont offer credit Please enter another payment amount under your owed" << endl;
		cin >> amount;
	}
	
	temp.addbalance(-amount);
	customerlist.at(customerplaceholder) = temp;


}

void Store::setsale(int id, int percentage)
{	

	cout << "This is the product before the sale" << endl;
	findProduct(id);
	cout << "This is the product after the sale" << endl;

	product saleproduct;
	string n;
	int m;
	double w;
	double r;
	int q;
	int productplaceholder;

	for (int i = 0; i < productlist.size(); i++)
	{
		saleproduct = productlist.at(i);
		saleproduct.getProductinfomation(n, m, w, r, q);
		if (id == m)
		{
			productplaceholder = i;
			saleproduct = productlist.at(i);
			

		}

	}
	saleproduct.setsale(percentage);
	saleproduct.Print();
	productlist.at(productplaceholder) = saleproduct;
	

}





int Store::getIdNum(int& position) const
{
	
	position = (customerlist.size() - 1);
		return position;
}






		





