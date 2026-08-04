// Subnetting code 

#include <iostream>
using namespace std;

int main()
{
    int firstOctet;

    cout << "Enter the first octet of the IP address: ";
    cin >> firstOctet;

    if (firstOctet >= 1 && firstOctet <= 126)
    {
        cout << "\nClass A" << endl;
        cout << "Address Range: 1.0.0.0 - 126.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.0.0.0" << endl;

        cout << "\nNumber of Networks: 2^7 - 2 = 126" << endl;
        cout << "Reason:" << endl;
        cout << "-> First bit is fixed to 0 to identify Class A." << endl;
        cout << "-> Remaining 7 bits are used for the Network ID." << endl;
        cout << "-> 2^7 = 128 possible networks." << endl;
        cout << "-> Subtract 1 because Network ID 0 is reserved." << endl;
        cout << "-> Subtract 1 because Network ID 127 is reserved for Loopback." << endl;

        cout << "\nNumber of Hosts per Network: 2^24 - 2 = 16,777,214" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 24 bits are used for the Host ID." << endl;
        cout << "-> 2^24 = 16,777,216 possible host addresses." << endl;
        cout << "-> Subtract 1 for the Network Address (all host bits = 0)." << endl;
        cout << "-> Subtract 1 for the Broadcast Address (all host bits = 1)." << endl;
    }
    else if (firstOctet == 127)
    {
        cout << "\nLoopback Address (127.x.x.x)" << endl;
        cout << "Address Range: 127.0.0.0 - 127.255.255.255" << endl;

        cout << "Definition: A loopback address is a reserved IP address used "
             << "by a computer to communicate with itself." << endl;

        cout << "Purpose: It is used to test the TCP/IP protocol stack and "
             << "network applications without using a physical network." << endl;

        cout << "Justification: Any packet sent to 127.x.x.x never leaves the "
             << "computer. The most commonly used loopback address is "
             << "127.0.0.1 (localhost)." << endl;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        cout << "\nClass B" << endl;
        cout << "Address Range: 128.0.0.0 - 191.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.255.0.0" << endl;

        cout << "\nNumber of Networks: 2^14 = 16,384" << endl;
        cout << "Reason:" << endl;
        cout << "-> First 2 bits are fixed to 10 for Class B." << endl;
        cout << "-> Remaining 14 bits are used for the Network ID." << endl;

        cout << "\nNumber of Hosts per Network: 2^16 - 2 = 65,534" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 16 bits are used for the Host ID." << endl;
        cout << "-> Subtract 1 for the Network Address." << endl;
        cout << "-> Subtract 1 for the Broadcast Address." << endl;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        cout << "\nClass C" << endl;
        cout << "Address Range: 192.0.0.0 - 223.255.255.255" << endl;
        cout << "Default Subnet Mask: 255.255.255.0" << endl;

        cout << "\nNumber of Networks: 2^21 = 2,097,152" << endl;
        cout << "Reason:" << endl;
        cout << "-> First 3 bits are fixed to 110 for Class C." << endl;
        cout << "-> Remaining 21 bits are used for the Network ID." << endl;

        cout << "\nNumber of Hosts per Network: 2^8 - 2 = 254" << endl;
        cout << "Reason:" << endl;
        cout << "-> Remaining 8 bits are used for the Host ID." << endl;
        cout << "-> Subtract 1 for the Network Address." << endl;
        cout << "-> Subtract 1 for the Broadcast Address." << endl;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "\nClass D (Multicast)" << endl;
        cout << "Address Range: 224.0.0.0 - 239.255.255.255" << endl;
        cout << "Purpose: Used for multicast communication." << endl;
        cout << "Reason: Class D addresses are reserved for sending data to "
             << "multiple hosts simultaneously." << endl;
    }
    else if (firstOctet >= 240 && firstOctet <= 255)
    {
        cout << "\nClass E (Experimental)" << endl;
        cout << "Address Range: 240.0.0.0 - 255.255.255.255" << endl;
        cout << "Purpose: Reserved for research and experimental use." << endl;
        cout << "Reason: These addresses are not assigned to normal hosts or networks."
             << endl;
    }
    else
    {
        cout << "Invalid IP Address." << endl;
    }

    return 0;
}