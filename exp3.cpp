#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    int ip[4];
    int subnet;

    // ---------------------------------------
    // Input IP Address
    // ---------------------------------------
    cout << "Enter IP Address (example: 192.168.1.10): ";

    char dot;
    cin >> ip[0] >> dot >> ip[1] >> dot >> ip[2] >> dot >> ip[3];

    // Validate IP address
    for (int i = 0; i < 4; i++)
    {
        if (ip[i] < 0 || ip[i] > 255)
        {
            cout << "Invalid IP Address." << endl;
            return 0;
        }
    }

    int firstOctet = ip[0];

    // ---------------------------------------
    // Display IP Address
    // ---------------------------------------
    cout << "\n========================================" << endl;
    cout << "          IP ADDRESS INFORMATION" << endl;
    cout << "========================================" << endl;

    cout << "IP Address: "
         << ip[0] << "." << ip[1] << "."
         << ip[2] << "." << ip[3] << endl;

    // ---------------------------------------
    // Class A
    // ---------------------------------------
    if (firstOctet >= 1 && firstOctet <= 126)
    {
        cout << "\nClass A" << endl;
        cout << "Address Range: 1.0.0.0 - 126.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.0.0.0" << endl;
        cout << "Default Prefix: /8" << endl;

        cout << "\nNumber of Networks: 2^7 - 2 = 126" << endl;
        cout << "Reason:" << endl;
        cout << "-> First bit is fixed to 0 to identify Class A." << endl;
        cout << "-> Remaining 7 bits are used for the Network ID." << endl;
        cout << "-> 2^7 = 128 possible networks." << endl;
        cout << "-> Network ID 0 is reserved." << endl;
        cout << "-> Network ID 127 is reserved for Loopback." << endl;

        cout << "\nNumber of Hosts per Network: 2^24 - 2 = 16,777,214" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 24 bits are used for the Host ID." << endl;
        cout << "-> Subtract 1 for the Network Address." << endl;
        cout << "-> Subtract 1 for the Broadcast Address." << endl;

        // Subnetting
        cout << "\nEnter Subnet Prefix (example: 24): ";
        cin >> subnet;

        if (subnet >= 8 && subnet <= 30)
        {
            int hostBits = 32 - subnet;
            int subnetBits = subnet - 8;

            long long hosts = (1LL << hostBits) - 2;
            long long subnets = 1LL << subnetBits;

            // Calculate subnet mask
            int mask[4] = {0, 0, 0, 0};

            for (int i = 0; i < subnet; i++)
            {
                mask[i / 8] += (1 << (7 - (i % 8)));
            }

            cout << "\nSubnet Prefix: /" << subnet << endl;

            cout << "Subnet Mask: "
                 << mask[0] << "." << mask[1] << "."
                 << mask[2] << "." << mask[3] << endl;

            cout << "Number of Subnets: " << subnets << endl;
            cout << "Number of Hosts per Subnet: " << hosts << endl;
        }
        else
        {
            cout << "Invalid prefix. Class A supports /8 to /30." << endl;
        }
    }

    // ---------------------------------------
    // Loopback
    // ---------------------------------------
    else if (firstOctet == 127)
    {
        cout << "\nLoopback Address (127.x.x.x)" << endl;
        cout << "Address Range: 127.0.0.0 - 127.255.255.255" << endl;

        cout << "\nDefinition:" << endl;
        cout << "A loopback address is a reserved IP address used "
             << "by a computer to communicate with itself." << endl;

        cout << "\nPurpose:" << endl;
        cout << "It is used to test the TCP/IP protocol stack and "
             << "network applications without using a physical network." << endl;

        cout << "\nJustification:" << endl;
        cout << "Any packet sent to 127.x.x.x never leaves the computer." << endl;
        cout << "The most commonly used loopback address is 127.0.0.1." << endl;
    }

    // ---------------------------------------
    // Class B
    // ---------------------------------------
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        cout << "\nClass B" << endl;
        cout << "Address Range: 128.0.0.0 - 191.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.255.0.0" << endl;
        cout << "Default Prefix: /16" << endl;

        cout << "\nNumber of Networks: 2^14 = 16,384" << endl;
        cout << "Reason:" << endl;
        cout << "-> First 2 bits are fixed to 10 for Class B." << endl;
        cout << "-> Remaining 14 bits are used for the Network ID." << endl;

        cout << "\nNumber of Hosts per Network: 2^16 - 2 = 65,534" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 16 bits are used for the Host ID." << endl;
        cout << "-> Subtract 1 for the Network Address." << endl;
        cout << "-> Subtract 1 for the Broadcast Address." << endl;

        // Subnetting
        cout << "\nEnter Subnet Prefix (example: 24): ";
        cin >> subnet;

        if (subnet >= 16 && subnet <= 30)
        {
            int hostBits = 32 - subnet;
            int subnetBits = subnet - 16;

            long long hosts = (1LL << hostBits) - 2;
            long long subnets = 1LL << subnetBits;

            int mask[4] = {0, 0, 0, 0};

            for (int i = 0; i < subnet; i++)
            {
                mask[i / 8] += (1 << (7 - (i % 8)));
            }

            cout << "\nSubnet Prefix: /" << subnet << endl;

            cout << "Subnet Mask: "
                 << mask[0] << "." << mask[1] << "."
                 << mask[2] << "." << mask[3] << endl;

            cout << "Number of Subnets: " << subnets << endl;
            cout << "Number of Hosts per Subnet: " << hosts << endl;
        }
        else
        {
            cout << "Invalid prefix. Class B supports /16 to /30." << endl;
        }
    }

    // ---------------------------------------
    // Class C
    // ---------------------------------------
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        cout << "\nClass C" << endl;
        cout << "Address Range: 192.0.0.0 - 223.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.255.255.0" << endl;
        cout << "Default Prefix: /24" << endl;

        cout << "\nNumber of Networks: 2^21 = 2,097,152" << endl;
        cout << "Reason:" << endl;
        cout << "-> First 3 bits are fixed to 110 for Class C." << endl;
        cout << "-> Remaining 21 bits are used for the Network ID." << endl;

        cout << "\nNumber of Hosts per Network: 2^8 - 2 = 254" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 8 bits are used for the Host ID." << endl;
        cout << "-> Subtract 1 for the Network Address." << endl;
        cout << "-> Subtract 1 for the Broadcast Address." << endl;

        // Subnetting
        cout << "\nEnter Subnet Prefix (example: 26): ";
        cin >> subnet;

        if (subnet >= 24 && subnet <= 30)
        {
            int hostBits = 32 - subnet;
            int subnetBits = subnet - 24;

            long long hosts = (1LL << hostBits) - 2;
            long long subnets = 1LL << subnetBits;

            int mask[4] = {0, 0, 0, 0};

            for (int i = 0; i < subnet; i++)
            {
                mask[i / 8] += (1 << (7 - (i % 8)));
            }

            cout << "\nSubnet Prefix: /" << subnet << endl;

            cout << "Subnet Mask: "
                 << mask[0] << "." << mask[1] << "."
                 << mask[2] << "." << mask[3] << endl;

            cout << "Number of Subnets: " << subnets << endl;
            cout << "Number of Hosts per Subnet: " << hosts << endl;
        }
        else
        {
            cout << "Invalid prefix. Class C supports /24 to /30." << endl;
        }
    }

    // ---------------------------------------
    // Class D
    // ---------------------------------------
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "\nClass D (Multicast)" << endl;
        cout << "Address Range: 224.0.0.0 - 239.255.255.255" << endl;

        cout << "Purpose: Used for multicast communication." << endl;
        cout << "Reason: Class D addresses are reserved for sending "
             << "data to multiple hosts simultaneously." << endl;
    }

    // ---------------------------------------
    // Class E
    // ---------------------------------------
    else if (firstOctet >= 240 && firstOctet <= 255)
    {
        cout << "\nClass E (Experimental)" << endl;
        cout << "Address Range: 240.0.0.0 - 255.255.255.255" << endl;

        cout << "Purpose: Reserved for research and experimental use." << endl;
        cout << "Reason: These addresses are not assigned to normal "
             << "hosts or networks." << endl;
    }

    // ---------------------------------------
    // Invalid
    // ---------------------------------------
    else
    {
        cout << "\nInvalid IP Address." << endl;
    }

    cout << "\n========================================" << endl;

    return 0;
}
