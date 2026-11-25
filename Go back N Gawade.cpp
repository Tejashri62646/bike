#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void GoBackN() {
    int n, window;
    cout << "Enter no. of frames: ";
    cin >> n;
    cout << "Enter window size: ";
    cin >> window;

    if (n <= 0 || window <= 0 || window > n) {
        cout << "Invalid Input \n";
        return;
    }

    int i = 0; 
    while (i < n) {
        cout << "\nSENDING WINDOW" << endl;
        int end = i + window;
        if (end > n) {
            end = n;
        }

        bool error = false;
        for (int j = i; j < end; j++) {
            cout << "Sending frame " << j + 1 << endl;
            if (rand() % 5 == 0) {
                cout << "Frame " << j + 1 << " lost" << endl;
                error = true;
                i = j; 
                break;
            }
            cout << "Frame " << j + 1 << " received" << endl;
        }

        if (error) {
            cout << "Error occured. Go back and resend from frame: " << i + 1 << endl;
            continue;
        }

        
        cout << "\nACK received for frames " << i + 1 << " to " << end << endl;
        i = end;
    }

    cout << "All frames are received successfully!" << endl;
}

int main() {
    srand(time(0));
    cout << "*********GO BACK N************" << endl;
    GoBackN();
    return 0;
}
