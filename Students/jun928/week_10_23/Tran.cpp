#include "ran.h"
#include <iostream>
#include <math.h>
using namespace std;
int main(){


	int long numb_trial = 100000;
	
Ran myran(30);
int CS = 1;
float al;
float a2[] = {0,.25,.5,.75,1,1.25,1.5,1.75,2,2.25,2.5,2.75,3,3.5,4,4.5,5};//alpha 

for(int j=0; j<17;j++){
al = a2[j];
int ID=0;
for( int o = 0; o<100; o++){
Ran MR(myran.int32());
for (int i= 1; i<numb_trial; i++){
	float sp = MR.doub();//stage probabilty
	if (CS != 0){
		float p = pow(((CS+1)/float(CS)),al)/(1+pow(((CS+1)/float(CS)),al));

		if (sp>=0&&sp<p){
			CS = CS +1;
			
				}
	
		else{
		CS =CS-1;
		}
		}
	else if (CS ==0){
	CS =1;
	
	}
	
}	
ID = ID+CS;
}
cout<< "CS is "<<ID/100<<" when coefficient alpha is "<<al<<endl;		
}

return 0;
}