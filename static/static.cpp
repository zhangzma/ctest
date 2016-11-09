/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file static.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include <iostream>

class AP_Mission
{
public:

	static void is_nav_cmd(bool f)
	{
		std::cout << "static function" << std::endl;
		return f;
	}
	void is_nav_cmd(bool f) 
	{
		std::cout << "normal function" << std::endl;
		return (f || _flags);
	}

	void setter(bool flag)
	{
		_flags = flag;
	}


private:
	bool _flags;
};



int main(int argc, char *argv[])
{
	AP_Mission mission;

	mission.setter(true);

	mission.is_nav_cmd(false);
	AP_Mission::is_nav_cmd(false);
	
    return 0;
}


