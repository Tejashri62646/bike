
#include <iostream>
#include <unistd.h>
using namespace std;

void stopAndWaitARQ(int totalFrames)
{
    cout << "\n--- Stop-and-Wait ARQ Simulation ---\n";

    for (int frame = 1; frame <= totalFrames; frame++)
    {
        bool success = false;

        while (!success)
        {
            cout << "\nSender: Sending Frame " << frame << "...";
            sleep(1);

            // Make the first transmission fail
            if (frame == 1)
            {
                static bool firstTry = true;

                if (firstTry)
                {
                    cout << "\nError: Frame " << frame << " lost!";
                    cout << "\nSender: Timeout. Retransmitting...\n";

                    firstTry = false;
                    continue;
                }
            }

            cout << "\nReceiver: Frame " << frame << " received.";

            cout << "\nReceiver: Sending ACK " << frame << "...";
            sleep(1);

            cout << "\nSender: ACK " << frame << " received.";

            cout << "\nFrame " << frame
                 << " transmitted successfully.\n";

            success = true;
        }
    }

    cout << "\nAll " << totalFrames
         << " frames transmitted successfully!\n";
}

int main()
{
    int totalFrames;

    cout << "Enter number of frames: ";
    cin >> totalFrames;

    stopAndWaitARQ(totalFrames);

    return 0;
}
