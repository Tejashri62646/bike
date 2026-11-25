#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void selectiveRepeat(){
	int n,window;
	cout<<"Enter no. of frames: ";
	cin>>n;
	cout<<"Enter window size: ";
	cin>>window;
	
	int start = 0;
	bool received[100] = {false};
	while(start<n){
		int end = start +window;
		if(end>n){
			end = n;
		}
		cout<<"\nSENDING WINDOW\n";
		for(int i=start;i<end;i++){
			if(received[i]) continue;
			cout<<"Sending frame "<<i<<endl;
			if(rand()%5==0){
				cout<<"Frame "<<i<<" lost\n";
			}
			else{
				cout<<"Frame "<<i<<" received\n";
				received[i] = true;
			}
		}
		
		for(int i=start;i<end;i++){
			if(!received[i]){
				cout<<"Retransmitting frame "<<i<<endl;
				if(rand()%5==0){
					cout<<"Frame "<<i<<" lost again\n";
				}
				else{
					cout<<"Frame "<<i<<" received\n";
					received[i] = true;
				}
			}
		}
		while(start<end && received[start]){
			start++;
		}
	}
	cout<<"All frames are received successfully!\n";
}

int main(){
	srand(time(0));
	cout<<"SELECTIVE REPEAT\n";
	selectiveRepeat();
	return 0;
}

