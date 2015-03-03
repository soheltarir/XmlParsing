#include <iostream>
#include "sources.h"

using namespace std;

int main()
{
	 int A = 114;
	 enSource C = NSE;
	 cout << "Source=" << source_name[C] << endl;
	 cout << "Enum= " << GetSource("NSE") << endl;
	 return 0;
}

