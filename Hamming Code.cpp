#include <iostream>
using namespace std;

int main() {
    int h[8] = {0};

    cout << "Enter 4 data bits: ";
    cin >> h[3] >> h[5] >> h[6] >> h[7];

    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    cout << "Hamming Code: ";
    for(int i = 1; i <= 7; i++)
        cout << h[i];

    cout << "\nEnter received 7 bits: ";
    for(int i = 1; i <= 7; i++)
        cin >> h[i];

    int p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    int p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    int p4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    int error = p1 + 2 * p2 + 4 * p4;

    if(error == 0) {
        cout << "No error detected." << endl;
    }
    else {
        cout << "Error at position: " << error << endl;

        h[error] = h[error] ^ 1;

        cout << "Corrected Hamming Code: ";
        for(int i = 1; i <= 7; i++)
            cout << h[i];

        cout << endl;
    }

    cout << "Original Data: ";
    cout << h[3] << h[5] << h[6] << h[7] << endl;

    return 0;
}
