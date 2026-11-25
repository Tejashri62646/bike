
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

void goBackNARQ(int totalFrames, int windowSize)
{
    int frame = 1;

    cout << "\n--- GO-BACK-N ARQ ---\n";
    cout << "Total Frames : " << totalFrames << endl;
    cout << "Window Size : " << windowSize << endl;

    while (frame <= totalFrames)
    {
        cout << "\n[Sender] Sending frames: ";

        int end = frame + windowSize - 1;

        if (end > totalFrames)
            end = totalFrames;

        for (int i = frame; i <= end; i++)
        {
            cout << i << " ";
        }

        sleep(1);

        // Simulate frame loss or corruption
        int lostFrame = frame;

        if (rand() % 4 == 0 && end > frame)
        {
            lostFrame = frame + rand() % (end - frame + 1);

            cout << "\n[Error] Frame " << lostFrame
                 << " lost or corrupted!";

            cout << "\n[Receiver] Discarding Frame "
                 << lostFrame << " and all following frames.";

            cout << "\n[Sender] Timeout for Frame " << lostFrame;

            cout << "\n[Sender] Going back to Frame "
                 << lostFrame << " and retransmitting...";

            frame = lostFrame;
        }
        else
        {
            cout << "\n[Receiver] All frames received successfully.";

            cout << "\n[Receiver] Sending ACK " << end + 1;

            cout << "\n[Sender] ACK " << end + 1 << " received.";

            frame = end + 1;
        }
    }

    cout << "\n\nAll " << totalFrames
         << " frames transmitted successfully using Go-Back-N ARQ.\n";
}

int main()
{
    int totalFrames, windowSize;

    srand(time(NULL));

    cout << "===== GO-BACK-N ARQ SIMULATION =====\n";

    cout << "\nEnter total number of frames: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    if (totalFrames <= 0 || windowSize <= 0)
    {
        cout << "\nInvalid input!\n";
        return 0;
    }

    if (windowSize > totalFrames)
        windowSize = totalFrames;

    goBackNARQ(totalFrames, windowSize);

    return 0;
}
