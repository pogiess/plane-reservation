#include <iostream>
using namespace std;

void smoking(int[] , int);
void nonSmoking(int[] , int);
void whatIsThis(int);

int main(){
	const int plane_size = 10;
	int plane [plane_size] = { 0 };
	int key;
	
	cout << "if you want to reserve a seat in smoking section type 1 \n"
		 << "if you want to reserve a seat in nonsmoking section type 2\n\n";
	
	for(int i = 0; i < plane_size; i++){
		cout << "enter number(1,2) to reserve a seat : ";
		cin >> key;
		if(key == 1){
			smoking(plane , plane_size);
		}
		else if(key == 2){
			nonSmoking(plane , plane_size);
		}
		else{
			cout << "\a**invalid**\n";
			i--;
		}
	}
	
	cout << "\n(the plane is full)\n";
	
	return 0;
	
}

void smoking(int fly[] , int fly_size){
	int mis = 0;
	fly[fly_size] = {0};
	bool check;
	string prefer;
	for(int i = 0; i <= fly_size - 6; i++){
		if(fly[i] == 0){
			cout << "TICKET : " << "seat : " << i+1 << "  type : smoking\n";
			check = true;
			fly[i] = 1;
			break;
		}
		else{
			check = false;
		}
	}
	if(check == false){
		reapit:
		if(mis == 3){
			cout << "you maked too mistakes!!";
			exit(1);
		}
		cout << "the smoking section is over do you want to reserve a seat in nonsmoking section or no\n"
			 << "please answer with yes or no : ";
		cin >> prefer;
		if(prefer == "yes"){
			nonSmoking(fly , fly_size);
		}
		else if(prefer == "no"){
			cout << "next flight leaves in 3 hours\n";
		}
		else{
			cout << "\ainvalid\n\n";
			++mis;
			goto reapit;
		}
	}
}

void nonSmoking(int fly2[] , int fly_size2){
	int mis = 0;
	fly2[fly_size2] = {0};
	bool check2;
	string prefer2;
	for(int i = 5; i < fly_size2; i++){
		if(fly2[i] == 0){
			cout << "TICKET : " << "seat : " << i+1 << "  type : nonsmoking\n";
			fly2[i] = 1;
			check2 = true;
			break;
		}
		else{
			check2 = false;
		}
	}
	if(check2 == false){
		loop:
		if(mis == 3){
			cout << "you maked too mistakes!!";
			exit(1);
		}
		cout << "the smoking section is over do you want to reserve a seat in smoking section or no\n"
			 << "please answer with yes or no : ";
		cin >> prefer2;
		
		if(prefer2 == "yes"){
			smoking(fly2 , fly_size2);
		}
		else if(prefer2 == "no"){
			cout << "next flight leaves in 3 hours\n";
		}
		else{
			cout << "\ainvalid\n\n";
			++mis;
			goto loop;
		}
		
	}
	
}