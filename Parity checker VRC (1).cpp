#include<iostream>
#include<string>
using namespace std;

int main(){
	string data, received_data ;
	int ct = 0;
	cout << "Sender:- "<< endl;
	cout << "Enter Data: ";
	cin >> data;
	for (int i=0; i < data.length(); i++){
		if(data[i] == '1'){
			ct++ ;
		}
	}
	if(ct % 2 == 0){
		data += "0";
	}else{
		data += "1";
	}

	cout << "Data sent by sender: " << data << endl;

	
	cout << "\nReceiver:- " <<endl;
	cout << "Data received by Receiver : ";
	cin >> received_data;
	int count = 0;
	for (int i = 0; i < received_data.length(); i++){
		if(received_data[i] == '1'){
			count++;
		}
		
		if(count % 2 == 0){
			cout << "Data Received is valid.\n";
		}else{
			cout << "Data Received is invalid.\n";
		}
		return 0;
	} 
}
