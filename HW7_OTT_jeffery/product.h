//products class.cpp
#ifndef  Included_product_H
#define Included_product_H
#include<iostream>
#include<string>
#include<vector>
#include <stdexcept>

using namespace std;

class product
{
public:
	void getNewProduct(string name, int ModelNum, double WholeSalePrice, double retailPrice, int quantity);
	void getProductinfomation(string& name, int& ModelNum, double& WholeSalePrice, double& retailPrice, int& quantity);
	void addquantity(int quantity);
	void subquantity(int quanity);
	void getamountpurchased(int amountsold);
	void setsale(double percent);
	void Print() const;
	
	


private:
 string product_name;
 int product_id;
 double  whole_cost;
 double retail_cost;
 int amount;
 int amountpurchased;




};
#endif