//customer.h
#ifndef Included_customer_H
#define Included_customer_H
#include<string>
#include"product.h"
#

using namespace std;


class customer
{
public:
		void SetNewCustomer(string getfirstname,string getlastname,int id);
		void Print() const;
		void getpurchase();
		void addtopurchaselist(product purchase);
		void getcustomerinfo(string& getfirstname, string& getlastname, int& id);
		void getBalance() const;
		void getBalanceum(double& bal) ;
		void addbalance(double prices);
		
		
		


private:
	string firstname;
	string lastname;
	 int customerId;
	 double balance;
	 vector<product> purchasehist;

};
#endif