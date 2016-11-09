/**
 * Project Fund
 * @author Yu
 * @version 1.00
 */


#ifndef _BID_H
#define _BID_H

#include "Fund.h"

class Bid {
public: 
	
	/**
	 * @param amount
	 */
	void setAmount(int amount);
	
	int getAmount();
	
	/**
	 * @param fund
	 */
	void setFund(Fund* fund);
	
	float calcFee();
	
	float calcUnit();
private: 
	int _amount;
};

#endif //_BID_H
