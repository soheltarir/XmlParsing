#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "XmlDomDocument.h"

int main()
{
	 string value;
	 XmlDomDocument* doc = new XmlDomDocument("./SOR_Conf.xml");
	 if (doc)
	 {
		  cout << "The Common Configuration is:" << endl;
		  for (int i = 0; i < doc->getChildCount("FLEXTRADE", 0, "COMMON"); i++)
		  {
				value = doc->getAttributeValue("COMMON", i, "DEBUG_LEVEL");
				cout << "DEBUG_LEVEL = " << value << endl;
		  }
		  cout << "SOR Configuration: " << endl;
		  for (int i = 0; i < doc->getChildCount("FLEXTRADE", 0, "SOR"); i++)
		  {
				cout << "Destination " << i+1 << " details:" << endl;
				value = doc->getAttributeValue("SOR", i, "DESTINATION");
				cout << "Exchange: " << value << endl;
				value = doc->getAttributeValue("SOR", i, "SOURCE");
				cout << "Source: " << value << endl;
				value = doc->getAttributeValue("SOR", i, "IS_PRIM");
				if (value != "")
					 cout << "This is the Primary Destination" << endl;
				else
					 cout << "This is not the Primary destination" << endl;
				value = doc->getChildValue("SOR", i, "OPEN_TIME");
				cout << "Open Time = " << value << endl;
				value = doc->getChildValue("SOR", i, "CLOSE_TIME");
				cout << "Close Time = " << value << endl;
				value = doc->getChildValue("SOR", i, "SWEEP_RATIO");
				cout << "Sweep ratio = " << value << endl;
		  }
	 }
	 delete doc;
	 return 0;
}

