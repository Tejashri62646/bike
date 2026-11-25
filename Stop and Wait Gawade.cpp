#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void StopAndWait(){
	int n;
	cout<<"Enter the number of frames: ";
	cin>>n;
	if(n<=0){
		cout<<"Invalid no. of frames"<<endl;
		return;
	}
	
	for(int i=1;i<=n;i++){
		while(true){
			cout<<"\nSending frame: "<<i<<endl;
			if(rand()%5 ==0){
				cout<<"frame "<<i<<" lost"<<endl;
				cout<<"Timeout-> resending frame: "<<i<<endl;
				continue;
			}
			cout<<"frame "<<i<<" received"<<endl;
			
			if(rand()%5==0){
				cout<<"Ack of "<<i<<" lost"<<endl;
				cout<<"Timeout-> resending frame: "<<i<<endl;
				continue;
			}
			cout<<"Ack received of frame "<<i<<endl;
			break;
		}
	}
	cout<<"All frames are received  successfully!"<<endl;
}

int main(){
	srand(time(0));
	cout<<"******STOP AND WAIT******"<<endl;
	StopAndWait();
	return 0;
}

