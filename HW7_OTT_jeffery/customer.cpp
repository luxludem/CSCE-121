//customer.cpp
#include<iostream>
#include"customer.h"
using namespace std;




void customer::SetNewCustomer(string getfirstname, string getlastname, int id)
{
	firstname = getfirstname;
	lastname = getlastname;
	customerId = id;
	balance = 0;
	return;
}



void customer::Print() const
{
	
	cout <<"Customer Info: " <<firstname << " " << lastname << "      " << customerId << " " << endl;
	
	return;
}

void customer::getpurchase()
{
	product p;
	for (int i = 0; i < purchasehist.size(); i++)
	{
		p = purchasehist.at(i);
		p.Print();
	}

}

void customer::addtopurchaselist(product purchase)
{
	product hold = purchase;
	purchasehist.push_back(hold);
}

void customer::getcustomerinfo(string & getfirstname, string & getlastname, int & id)
{
	getfirstname = firstname;
	getlastname = lastname;
	id = customerId;
	return;

}

void customer::getBalance() const
{
	cout <<"Balance: "<<balance <<" $"<<endl;
}

void customer::getBalanceum(double& bal)
{
	
	bal = balance;
	return;
}

void customer::addbalance(double prices)
{
	balance = balance + prices;
	return;
}








