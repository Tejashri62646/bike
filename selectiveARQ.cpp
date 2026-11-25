
#include <iostream>
using namespace std;

int main()
{
    int n, windowSize;

    cout << "Enter number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> windowSize;

    int ack[100] = {0};
    int i = 0;

    while (i < n)
    {
        cout << "\nSending window:\n";

        int end = i + windowSize;

        if (end > n)
            end = n;

        // Send frames in current window
        for (int j = i; j < end; j++)
        {
            if (ack[j] == 0)
            {
                cout << "Frame " << j + 1 << " sent.\n";

                int choice;

                cout << "Was Frame " << j + 1
                     << " received? (1 = Yes, 0 = No): ";
                cin >> choice;

                if (choice == 1)
                {
                    ack[j] = 1;
                    cout << "ACK " << j + 1 << " received.\n";
                }
                else
                {
                    cout << "Frame " << j + 1 << " lost!\n";
                }
            }
        }

        // Retransmit only lost frames
        cout << "\nChecking for lost frames...\n";

        for (int j = i; j < end; j++)
        {
            if (ack[j] == 0)
            {
                cout << "Retransmitting Frame " << j + 1 << "...\n";

                int choice;

                cout << "Was Frame " << j + 1
                     << " received? (1 = Yes, 0 = No): ";
                cin >> choice;

                if (choice == 1)
                {
                    ack[j] = 1;
                    cout << "ACK " << j + 1 << " received.\n";
                }
                else
                {
                    cout << "Frame " << j + 1 << " lost again!\n";
                }
            }
        }

        // Check whether all frames are acknowledged
        bool allAck = true;

        for (int j = i; j < end; j++)
        {
            if (ack[j] == 0)
            {
                allAck = false;
                break;
            }
        }

        // Move window only when all frames are acknowledged
        if (allAck)
        {
            cout << "All frames in window acknowledged.\n";
            i = end;
        }
        else
        {
            cout << "Some frames are still lost. Retrying...\n";
        }
    }

    cout << "\nAll frames transmitted successfully!\n";

    return 0;
}
