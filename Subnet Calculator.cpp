#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Convert IP address into integer
unsigned int ipToInt(int a, int b, int c, int d)
{
    return ((unsigned int)a << 24) |
           ((unsigned int)b << 16) |
           ((unsigned int)c << 8) |
           (unsigned int)d;
}

// Convert integer into IP address
void intToIP(unsigned int ip)
{
    cout << ((ip >> 24) & 255) << "."
         << ((ip >> 16) & 255) << "."
         << ((ip >> 8) & 255) << "."
         << (ip & 255);
}

int main()
{
    int a, b, c, d, cidr;

    cout << "===== SUBNET CALCULATOR =====\n";

    cout << "Enter IP Address (4 octets): ";
    cin >> a >> b >> c >> d;

    cout << "Enter CIDR Prefix (0-32): ";
    cin >> cidr;

    // Validate input
    if (a < 0 || a > 255 || b < 0 || b > 255 ||
        c < 0 || c > 255 || d < 0 || d > 255 ||
        cidr < 0 || cidr > 32)
    {
        cout << "Invalid IP Address or CIDR Prefix!";
        return 0;
    }

    // Convert IP to integer
    unsigned int ip = ipToInt(a, b, c, d);

    // Calculate subnet mask
    unsigned int mask = (cidr == 0) ? 0 : (0xFFFFFFFFu << (32 - cidr));

    // Calculate network address
    unsigned int network = ip & mask;

    // Calculate broadcast address
    unsigned int broadcast = network | (~mask);

    // Calculate wildcard mask
    unsigned int wildcard = ~mask;

    // Calculate total addresses
    unsigned long long total = 1ULL << (32 - cidr);

    // Calculate usable hosts
    unsigned long long usable;

    if (cidr <= 30)
        usable = total - 2;
    else if (cidr == 31)
        usable = 2;
    else
        usable = 1;

    cout << "\n===== SUBNET DETAILS =====\n";

    cout << "IP Address       : ";
    intToIP(ip);

    cout << "\nSubnet Mask      : ";
    intToIP(mask);

    cout << "\nNetwork Address  : ";
    intToIP(network);

    cout << "\nBroadcast Address: ";
    intToIP(broadcast);

    cout << "\nWildcard Mask    : ";
    intToIP(wildcard);

    cout << "\nFirst Usable IP  : ";
    if (cidr <= 30)
        intToIP(network + 1);
    else if (cidr == 31)
        cout << "No conventional host range";
    else
        intToIP(network);

    cout << "\nLast Usable IP   : ";
    if (cidr <= 30)
        intToIP(broadcast - 1);
    else if (cidr == 31)
        cout << "No conventional host range";
    else
        intToIP(broadcast);

    cout << "\nTotal Addresses  : " << total;
    cout << "\nUsable Hosts     : " << usable;

    cout << "\n";

    return 0;
}
