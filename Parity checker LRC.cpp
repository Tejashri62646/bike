#include<iostream>
#include<string>
using namespace std;

int main(){
	string send_binary = "";
	cout << "Enter 16 bit data: ";
	cin >> send_binary;
	
	char arr[4][4];
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			arr[i][j] = send_binary[i * 4 + j];
		}
	}
	
	cout << "\n4*4 Matrix: \n";
	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	
	string parity = "";
	for(int i=0 ; i<4; i++){
		int count = 0;
		for(int j=0; j <4; j++){
			if(arr[j][i] == '1'){
				count++;
			}
		}
		if(count % 2 == 0){
			parity  = parity + "0";
		}else{
			parity = parity + "1";
	}
	}
	
	
	
	cout << "Final Parity is: " << parity << endl;
	
	send_binary = send_binary + parity;
	cout << "Your 20 bit data is: " << send_binary ;
	
}
