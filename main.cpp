#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "ConfigHandler.h"
 
int main(int argc, char** argv)
{
	ConfigHandler* obj = new ConfigHandler("./SOR_Conf.xml");
	cout << "NSE Source: " << obj->Source("NSE") << endl;
	return 0;
}
