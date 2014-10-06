#include "ran.h"
#include <iostream>
using namespace std;
int main(){
	Ran myran(18);
	
	char state = 'A';
	int count_A =0,count_B = 0,count_C=0;
	for (int i = 0; i<25; i++){
		float prob = myran.doub();
		if (state == 'A'){
			if (prob <1./3 && prob>=0){
			state = 'B';
			count_B ++;
			}
			else if (prob>=1./3 && prob<=1){
			state = 'C';
			count_C++;
			}
		}
		else if (state == 'B'){
			if (prob <1./3 && prob>=0){
			state = 'C';
			count_C ++;
			}
			else if (prob>=1./3 && prob<=1){
			state = 'A';
			count_A++;
			}
		}
		else if (state == 'C'){
			if (prob <1./3 && prob>=0){
			state = 'A';
			count_A ++;
			}
			else if (prob>=1./3 && prob<=1){
			state = 'B';
			count_B++;
			}
		}
	
		
	cout<< prob<<endl;
	}
cout<< "A counted: "<<count_A<<"B counted: "<<count_B<<"C counted" << count_C<<endl;
	return 0;
	
}