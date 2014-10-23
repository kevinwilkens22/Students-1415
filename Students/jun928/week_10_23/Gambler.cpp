#include "ran.h"
#include <iostream>
using namespace std;
int main(){
	Ran myran(39);
	int numb_trial = 1000000;
	
	char state = 'B';
	
	int count_A =0,count_F=0;
	for (int i = 0; i<numb_trial; i++){
		float prob = myran.doub();
		if (state == 'B'){
			if (prob <1./2 && prob>=0){
			state = 'A';
			count_A ++;
			state = 'B';
			}
			else if (prob>=1./2 && prob<1){
			state = 'C';
			}
		}
		else if (state == 'C'){
			if (prob <1./2 && prob>=0){
			state = 'A';
			count_A ++;
			state = 'B';
			}
			else if (prob>=1./2 && prob<1){
			state = 'E';
			}
		}
		else if (state == 'D'){
			if (prob <1./2 && prob>=0){
			state = 'B';
			}
			else if (prob>=1./2 && prob<1){
			state = 'F';
			count_F++;
			state = 'B';
			} 
			}
		else if (state == 'E'){
			if (prob <1./2 && prob>=0){
			state = 'D';
			}
			else if (prob>=1./2 && prob<1){
			state = 'F';
			count_F++;
			state = 'B';
			}
		}
	
		}
	
	
cout<< "Lose... "<<float(count_A)/float(count_A+count_F)<<"\n"<<"Aim achieved with " << float(count_F)/float(count_A+count_F)<<endl;
	return 0;
	
}   