//products class.h
#include<iostream>
#include"product.h"



void product::getNewProduct(string name, int ModelNum, double WholeSalePrice, double retailPrice, int quantity)
{
	product_name = name;
	product_id = ModelNum;
	whole_cost = WholeSalePrice;
	retail_cost = retailPrice;
	amount = quantity;
	
	return;
}

void product::getProductinfomation(string & name, int & ModelNum, double & WholeSalePrice, double & retailPrice, int & quantity)
{
	name = product_name;
	ModelNum = product_id;
	WholeSalePrice = whole_cost;
	retailPrice = retail_cost;
	quantity=amount;


}

void product::addquantity(int quantity) 
{ 
	amount = amount+quantity;
	return;
	
}

void product::subquantity(int quanity)
{
	amount = amount - quanity;
	return;
}

void product::getamountpurchased(int amountsold)
{
	amountpurchased = 0;
	amountpurchased =amountpurchased+amountsold;
	return;
}



void product::setsale(double percent)
{
	percent = percent / 100.0;
	percent = 1 - percent;
	retail_cost = percent*retail_cost;
	return;

}

void product::Print() const
{
	cout << product_name << "    |   " << product_id << "      |    " << whole_cost << "   |   " << retail_cost <<"   |  "<<amount<<"  |   "<<amountpurchased<<endl;
}
