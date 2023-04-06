// Kristella Lieu
//
// Run the following commands to run the CLI:
//
// g++ cli.cpp -o cli.exe
// cli.exe
//

#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
using namespace std;

#define TEXT_CMD_ID1 0x24
#define TEXT_CMD_ID2 0x25
#define COLOR_CMD_ID 0x26
#define SCROLL_CMD_ID 0x27
#define ANIMATION_CMD_ID 0x28
#define CLEAR_CMD_ID 0x29

const string colorOpt[] = {"WHITE","RED","GREEN","BLUE","YELLOW","CYAN","PURPLE"};
const int colorHexVal[] = {0x57, 0x52, 0x47, 0x42, 0x59, 0x43, 0x50};
const string scrollOpt[] = {"SCROLL OFF","SCROLL ON"};
const int scrollHexVal[] = {0x01, 0x02};
const string animationOpt[] = {"OPTION 1","OPTION 2", "OPTION 3"};
const int animationHexVal[] = {0x01, 0x02, 0x03};

string enterText();
string enterColor();
string enterScroll();
string enterAnimation();
char* formatSerialBytes(string commandType, string data, int *num_bytes);
int sendSerialBytes(char *bytes_to_send, int num_bytes);

int main() {
    string menuOpt;

    while (1) {
        cout << endl;
        cout << "======== MAIN MENU ========" << endl;
        cout << "1 - Text" << endl;
        cout << "2 - Color" << endl;
        cout << "3 - Scroll" << endl;
        cout << "4 - Animation" << endl;
        cout << "5 - Clear Screen" << endl;
        cout << "q - Exit" << endl;
        cout << "Enter Option> ";
        cin >> menuOpt;
        cin.ignore();

        if (menuOpt == "1") { 
            cout << "\n======== TEXT OPTIONS ========" << endl;
            enterText();
        } 
        else if (menuOpt == "2") {
            cout << "\n======== COLOR OPTIONS ========" << endl;
            enterColor();
        }
        else if (menuOpt == "3") {
            cout << "\n======== SCROLL OPTIONS ========" << endl;
            enterScroll();
        }
        else if (menuOpt == "4") {
            cout << "\n======== ANIMATION OPTIONS ========" << endl;
            enterAnimation();
        }
        else if (menuOpt == "5") {
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("clear", "", &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
        }
        else if (menuOpt == "q") {
            break;
        }
        else {
            cout << "INVALID OPTION. TRY AGAIN." << endl;
        }
    }

    return 0;
}

string enterText() {
    string userText;
    string menuOpt;
    
    while (1) {
        cout << "1 - First Line" << endl;
        cout << "2 - Second Line" << endl;
        cout << "q - Exit" << endl;
        cout << "Enter Option> ";
        cin >> menuOpt;
        cin.ignore();

        if (menuOpt == "1") {
            cout << "First Line> ";
            getline(cin, userText);
            cin.clear();
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("text_line_1", userText, &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
            cout << endl;
        }
        else if (menuOpt == "2") {
            cout << "Second Line> ";
            getline(cin, userText);
            cin.clear();
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("text_line_2", userText, &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
            cout << endl;
        }
        else if (menuOpt == "q") {
            break;
        }
        else {
            cout << "INVALID OPTION. TRY AGAIN." << endl;
        }
    }

    return userText;
}

string enterColor() {
    string userColorIndex;
    unsigned i = 1;
    unsigned count = 0;

    // Print color options
    for (string s : colorOpt) { 
        cout << i << " - " << s << endl;
        ++i;
    }
    cout << "q - Exit" << endl;
    cout << "Enter Option> ";
    cin >> userColorIndex;

    if (userColorIndex == "q") {
        return "";
    }

    // Validate user input
    for (int i = 0; i < userColorIndex.length(); i++) {
        if (isdigit(userColorIndex[i]) == true)
            count++;
    }

    if(count == userColorIndex.length()) { 
        // Input is an INTEGER
        int sizeColorOpt = sizeof(colorOpt)/sizeof(colorOpt[0]);
        if(stoi(userColorIndex) > 0 && stoi(userColorIndex) <= sizeColorOpt) {
            // Input is a VALID option
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("color", userColorIndex, &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
        }
        else {
            // Input is not a VALID option
            userColorIndex = "";
            cout << "INVALID OPTION. TRY AGAIN." << endl;
        }
    }
    else {
        // Input is not an INTEGER
        userColorIndex = "";
        cout << "INVALID OPTION. TRY AGAIN." << endl;
    }

    return userColorIndex;
}

string enterScroll() {
    string userScroll;
    unsigned x = 1;
    unsigned count = 0;

    // Print scroll options
    for (string s : scrollOpt) {
        cout << x << " - " << s << endl;
        ++x;
    }
    cout << "q - Exit" << endl;
    cout << "Enter Option> ";
    cin >> userScroll;

    if (userScroll == "q") {
        return "";
    }

    // Validate user input
    for (int i = 0; i < userScroll.length(); i++) {
        if (isdigit(userScroll[i]) == true)
            count++;
    }

    if(count == userScroll.length()) { 
        // Input is an INTEGER
        int sizeScrollOpt = sizeof(scrollOpt)/sizeof(scrollOpt[0]);
        if(stoi(userScroll) > 0 && stoi(userScroll) <= sizeScrollOpt) {
            // Input is a VALID option
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("scroll", userScroll, &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
        }
        else {
            // Input is not a VALID option
            userScroll = "";
            cout << "INVALID OPTION. TRY AGAIN." << endl;
        }
    }
    else {
        // Input is not an INTEGER
        userScroll = "";
        cout << "INVALID OPTION. TRY AGAIN." << endl;
    }
    
    return userScroll;
}

string enterAnimation() {
    string userAnimIndex;
    unsigned x = 1;
    unsigned count = 0;

    // Print scroll options
    for (string s : animationOpt) {
        cout << x << " - " << s << endl;
        ++x;
    }
    cout << "q - Exit" << endl;
    cout << "Enter Option> ";
    cin >> userAnimIndex;

    if (userAnimIndex == "q") {
        return "";
    }

    // Validate user input
    for (int i = 0; i < userAnimIndex.length(); i++) {
        if (isdigit(userAnimIndex[i]) == true)
            count++;
    }

    if(count == userAnimIndex.length()) { 
        // Input is an INTEGER
        int sizeAnimOpt = sizeof(animationOpt)/sizeof(animationOpt[0]);
        if(stoi(userAnimIndex) > 0 && stoi(userAnimIndex) <= sizeAnimOpt) {
            // Input is a VALID option
            int num_bytes;
            char *bytes_to_send = formatSerialBytes("animation", userAnimIndex, &num_bytes);
            sendSerialBytes(bytes_to_send, num_bytes);
            delete[] bytes_to_send;
        }
        else {
            // Input is not a VALID option
            userAnimIndex = "";
            cout << "INVALID OPTION. TRY AGAIN." << endl;
        }
    }
    else {
        // Input is not an INTEGER
        userAnimIndex = "";
        cout << "INVALID OPTION. TRY AGAIN." << endl;
    }
    
    return userAnimIndex;
}

char* formatSerialBytes(string command, string data, int *num_bytes) {
    // serial commands are formatted as follows:
    // commandID  - 1 byte
    // lengthData - 1 byte
    // data       - {lengthData} bytes
    char *bytes_to_send = new char[2 + data.length()];
    *num_bytes = 2 + data.length();
    printf("bytes to send len: %d\n", 2 + data.length());

    // Remove newline character from data
    if (!data.empty() && data[data.length() - 1] == '\n') {
        data = data.substr(0, data.length() - 1);
    }
    printf("data len: %d\n", data.length());

    // format serial command to change display text line 2
    if (command == "text_line_1") {
        bytes_to_send[0] = static_cast<char>(TEXT_CMD_ID1);
        bytes_to_send[1] = static_cast<char>(data.length());
        for (int i = 0; i < data.length(); i++) {
            bytes_to_send[i + 2] = static_cast<char>(data[i]);
        }
    } 
    // format serial command to change display text line 2
    else if (command == "text_line_2") {
        bytes_to_send[0] = static_cast<char>(TEXT_CMD_ID2);
        bytes_to_send[1] = static_cast<char>(data.length());
        for (int i = 0; i < data.length(); i++) {
            bytes_to_send[i + 2] = static_cast<char>(data[i]);
        }
    }
    // format serial command to change color
    else if (command == "color") {
        bytes_to_send[0] = static_cast<char>(COLOR_CMD_ID);
        bytes_to_send[1] = static_cast<char>(data.length());
        bytes_to_send[2] = static_cast<char>(colorHexVal[stoi(data) - 1]);
    }
    // format serial command to change scroll speed
    else if (command == "scroll") {
        bytes_to_send[0] = static_cast<char>(SCROLL_CMD_ID);
        bytes_to_send[1] = static_cast<char>(data.length());
        bytes_to_send[2] = static_cast<char>(scrollHexVal[stoi(data) - 1]);
    }
    // format serial command to change animation
    else if (command == "animation") {
        bytes_to_send[0] = static_cast<char>(ANIMATION_CMD_ID);
        bytes_to_send[1] = static_cast<char>(data.length());
        bytes_to_send[2] = static_cast<char>(animationHexVal[stoi(data) - 1]);
    }
    // format serial command to clear screen
    else if (command == "clear") {
        bytes_to_send[0] = static_cast<char>(CLEAR_CMD_ID);
        bytes_to_send[1] = static_cast<char>(0x01);
        bytes_to_send[2] = static_cast<char>(0x29);
    }
    else {
        cout << "INVALID COMMAND ID. TRY AGAIN." << endl;
    }

    return bytes_to_send;
}

int sendSerialBytes(char *bytes_to_send, int num_bytes) {
    // Declare variables and structures
    int numBytes = num_bytes;//sizeof(bytes_to_send);
    printf("num bytes: %d\n", numBytes);
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
         
    // Open the serial port number
    fprintf(stderr, "Opening serial port...");
    hSerial = CreateFile(
        // "COM5", GENERIC_READ|GENERIC_WRITE, 0, NULL,
        _T("\\\\.\\COM5"), GENERIC_READ|GENERIC_WRITE, 0, NULL,
        OPEN_EXISTING, 0, NULL );
    if (hSerial == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error\n");
        return -1;
    } else fprintf(stderr, "OK\n");
     
    // Set device parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams) == 0) {
        fprintf(stderr, "Error getting device state\n");
        CloseHandle(hSerial);
        return -1;
    }
     
    dcbSerialParams.BaudRate = CBR_9600; // 9600 baud rate
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if(SetCommState(hSerial, &dcbSerialParams) == 0) {
        fprintf(stderr, "Error setting device parameters\n");
        CloseHandle(hSerial);
        return -1;
    }
 
    // Set COM port timeout settings
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if(SetCommTimeouts(hSerial, &timeouts) == 0) {
        fprintf(stderr, "Error setting timeouts\n");
        CloseHandle(hSerial);
        return -1;
    }
 
    // Send bytes
    DWORD bytes_written, total_bytes_written = 0;
    fprintf(stderr, "Sending bytes...");
    if(!WriteFile(hSerial, bytes_to_send, numBytes, &bytes_written, NULL)) {
        fprintf(stderr, "Error\n");
        CloseHandle(hSerial);
        return -1;
    }
    fprintf(stderr, "%d bytes written\n", bytes_written);
     
    // Close serial port
    fprintf(stderr, "Closing serial port...");
    if (CloseHandle(hSerial) == 0) {
        fprintf(stderr, "Error\n");
        return -1;
    }
    fprintf(stderr, "OK\n");

    return 0;
}