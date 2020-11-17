//store class .h
#ifndef Included_store_H
#define Included_store_H
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
#include<vector>
#include"product.h"
#include"customer.h"

using namespace std;


class Store: public customer, public product {

	vector<customer> customerlist;
	vector<product> productlist;
	

	
public:
	
	void AddCustomerToList(customer);
	void addProductToList(product);
	void PrintCustList() const;
	void PrintProductList() const;
	void findProduct(int modelnum)const;
	void findcustomer(int customerid) const;
	void getshipment(int shipmodelnum, int quantity);
	void makepurchase(int idnum, int modelnum, int quantity);
	void customerpayment(int id, int amount);
	void setsale(int id, int percentage);
	int getIdNum(int& position) const;
	


	 

};
#endif