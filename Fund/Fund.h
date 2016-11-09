/**
 * Project Fund
 * @author Yu
 * @version 1.00
 */


#ifndef _FUND_H
#define _FUND_H

class Fund 
{
public: 
	Fund(float price);
	
	float getPrice();
	
	float getFee();
	
	/**
	 * @param price
	 */
	void setPrice(float price);
	
	/**
	 * @param fee
	 */
	void setFee(float fee);

private: 
	float _fee;
	float _price;
};

#endif //_FUND_H
