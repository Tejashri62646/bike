#include<iostream>
#include<string>
using namespace std;

int main(){
	string data, div, rem;
	cout << " --Sender Side-- \n";
	cout << "Enter Data : " ;
	cin >> data;
	cout << "Enter Generator : ";
	cin >> div;
	
	int dlen = div.length();
	 rem = data;
	
	for(int i=0; i < dlen-1; i++){
		rem += '0';
	}	
	cout << "Appended Data: " << rem << endl;
	
	//Modulo Division (XOR)
	for(int i= 0; i < (rem.length() - dlen); i++){
		if(rem[i] == '1'){
			for(int j=0 ; j < dlen; j++){
				if( rem[i+j] == div[j]){
					rem[i+j] = '0';
				}else{
					rem[i+j] = '1';
				}
			}
		}
	}
	
	string crc = rem.substr(rem.length() - dlen + 1);
	
	cout << "Your Final CRC is: " << crc << endl;
	cout << "Data Sent: " << data+crc << endl;
	
	// Receiver Side
	string rec;
	cout << " --Receiver Side-- \n";
	cout << "Enter Received Data: " << endl;
	cin >> rec;
	for(int i= 0; i < (rec.length() - dlen); i++){
		if(rec[i] == '1'){
			for(int j=0 ; j < dlen; j++){
				if( rec[i+j] == div[j]){
					rec[i+j] = '0';
				}else{
					rec[i+j] = '1';
				}
			}
		}
	}
	cout << "Remainder after Division :" << rec << endl;
	
	int err = 0;
	for(int i =0; i < rec.length() ; i++){
		if(rec[i] == '1'){
			err = 1;
			break;
		}
	}
	
	if(err == 0){
		cout << "Data is valid ! (No Error)" << endl;
	}else{
		cout << "Data is Invalid ! (Error)" << endl;
	}
	return 0;
	
}
