
#include<iostream>
#include<string>
using namespace std;

int main(){

    int choice;

    cout << "1. Single Bit Parity Check" << endl;
    cout << "2. Two Dimensional Parity Check" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1){

        string data, received_data;
        int count = 0;

        cout << "\nSender Side" << endl;
        cout << "Enter Data: ";
        cin >> data;

        for(int i = 0; i < data.length(); i++){
            if(data[i] == '1'){
                count++;
            }
        }

        if(count % 2 == 0){
            data += "0";
        }
        else{
            data += "1";
        }

        cout << "Data sent by sender: " << data << endl;

        cout << "\nReceiver Side" << endl;
        cout << "Enter Received Data: ";
        cin >> received_data;

        count = 0;

        for(int i = 0; i < received_data.length(); i++){
            if(received_data[i] == '1'){
                count++;
            }
        }

        if(count % 2 == 0){
            cout << "Data Received is valid." << endl;
        }
        else{
            cout << "Data Received is invalid." << endl;
        }
    }

    else if(choice == 2){

        string send_binary = "";

        cout << "\nEnter 16 bit data: ";
        cin >> send_binary;

        char arr[4][4];

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                arr[i][j] = send_binary[i * 4 + j];
            }
        }

        cout << "\n4*4 Matrix:\n";

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }

        string parity = "";

        for(int i = 0; i < 4; i++){

            int count = 0;

            for(int j = 0; j < 4; j++){
                if(arr[j][i] == '1'){
                    count++;
                }
            }

            if(count % 2 == 0){
                parity += "0";
            }
            else{
                parity += "1";
            }
        }

        cout << "Final Parity is: " << parity << endl;

        send_binary += parity;

        cout << "Your 20 bit data is: " << send_binary << endl;
    }

    else{
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
