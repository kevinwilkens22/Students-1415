#include "ran.h"
#include <iostream>
using namespace std;
int main(){
	Ran myran(24);
	for(int i = 0; i < 5; i++){
		cout << myran.int32() << endl;
		cout << myran.int64() << endl;
		cout << myran.doub() << endl;	
	}
	cout << "Success r?eally" << endl;
	return 0;
	
}