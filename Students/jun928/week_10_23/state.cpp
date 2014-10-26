#include "ran.h"

#include <iostream>
using namespace std;
class state{
	int tot, up;
	int tot_n, up_n;
	int tot_2b, up_2b;
	
	
	
	public:
	void SV(int,int); //This should s
	void DeF();//constructor .. initial value (2,1)

	float p_b();//backward probability 
	
	int total();//access to total value 
	void Next();
	int ShowN(){
	return tot_n;}
	void back2();
	void modify_n();
	void modify_2b();
	int upf();//access to up value
	
};

float state::p_b(){
	return float(up)/tot/2.0;}
void state::DeF(){
	tot = 1;
	up =1;}
	
void state::SV(int x, int y){
	tot = x;
	up = y;
}
int state::total(){
	return tot;}
void state::Next(){
	tot_n = 2*tot - up;
	up_n = tot-up;
	}
void state::back2(){
	up_2b = 3*up - tot;
	tot_2b = up;
	}
void state::modify_n(){
	up = up_n;
	tot = tot_n;
	}
void state::modify_2b(){
	up = up_2b;
	tot = tot_2b;
	}
	
int state::upf(){
	return up;}
	
int main(){
state s; 
Ran prob(19);
s.SV(2,1);
state goal;
goal.DeF();
int N =10000;
int count = 0;
int reverse = 0;


for (int i = 0; i<N ; i++){
	float CP = prob.doub();
	//cout<<CP<<endl;
	//cout<<s.p_b()<<"state total= "<<s.total()<<"state up= "<<s.upf()<<endl;
	//cout<<"      "<<endl;
	if (s.total() == 89&& s.upf() ==34){
		s.SV(1,0);

		reverse ++;
		}

if (CP< s.p_b()&&CP>=0){//probability less than forward probability 
	s.back2();
	s.modify_2b();
	if (s.total() == goal.total() && s.upf()==goal.upf()){
		count++;
		s.SV(1,0);
		}
	}
else if(CP>=s.p_b() &&CP<1){
	s.Next();
	s.modify_n();
	}
	
	
	}
	
cout<< "Hitting probability of state (1,1) from (1,2) is "<<float(count)/(count+reverse)<<endl;

return 0;
}

