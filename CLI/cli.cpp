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

struct Options {
    string text, colorIndex, scrollIndex;
};

typedef struct Options Struct;

const string colorOpt[] = {"WHITE","BLACK","RED","GREEN","BLUE","YELLOW","CYAN","PURPLE"};
const string scrollOpt[] = {"OPTION 1","OPTION 2", "OPTION 3"};

Struct printMenu();

int main() {
    Struct userOptions = printMenu();
    // cout << userOptions.text << endl;
    // cout << userOptions.colorIndex << endl;
    // cout << userOptions.scrollIndex << endl;

    string s = userOptions.text;
    // s = s[0]; // for now, display only first letter of string

    // Convert string to uppercase
    for (int i = 0; i < s.length(); i++) {
  		s[i] = toupper(s[i]);
  	}

    int n = s.length();

    // Define bytes of data to send over serial port
    char bytes_to_send[n];

    // Copy user text to data array
    strcpy(bytes_to_send, s.c_str());
    
    // char bytes_to_send[] = "B";
    int numBytes = sizeof(bytes_to_send); // remove null terminator \0
 
    // Declare variables and structures
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
         
    // Open the highest available serial port number
    fprintf(stderr, "Opening serial port...");
    hSerial = CreateFile(
        "COM3", GENERIC_READ|GENERIC_WRITE, 0, NULL, //CHANGE PER PC 
        // _T("\\\\.\\COM5"), GENERIC_READ|GENERIC_WRITE, 0, NULL,
        // OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
        OPEN_EXISTING, 0, NULL );
    if (hSerial == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error\n");
        return 1;
    } else fprintf(stderr, "OK\n");
     
    // Set device parameters (38400 baud, 1 start bit,
    // 1 stop bit, no parity)
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams) == 0) {
        fprintf(stderr, "Error getting device state\n");
        CloseHandle(hSerial);
        return 1;
    }
     
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if(SetCommState(hSerial, &dcbSerialParams) == 0) {
        fprintf(stderr, "Error setting device parameters\n");
        CloseHandle(hSerial);
        return 1;
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
        return 1;
    }
 
    // Send specified text (remaining command line arguments)
    DWORD bytes_written, total_bytes_written = 0;
    fprintf(stderr, "Sending bytes...");
    if(!WriteFile(hSerial, bytes_to_send, numBytes, &bytes_written, NULL)) {
        fprintf(stderr, "Error\n");
        CloseHandle(hSerial);
        return 1;
    }
    fprintf(stderr, "%d bytes written\n", bytes_written);
     
    // Close serial port
    fprintf(stderr, "Closing serial port...");
    if (CloseHandle(hSerial) == 0) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fprintf(stderr, "OK\n");

    return 0;
}

string enterText() {
    string userText;

    cout << "DISPLAY TEXT -> ";
    cin >> userText; // Get user input

    return userText;
}

string enterColor() {
    string userColorIndex;
    unsigned i = 1;
    unsigned count = 0;

    for (string s : colorOpt) { // Print color options
        cout << i << " - " << s << endl;
        ++i;
    }

    cout << "TEXT COLOR -> ";
    cin >> userColorIndex; // Get user input

    for (int i=0; i<userColorIndex.length(); i++) {
        if (isdigit(userColorIndex[i]) == true)
            count++;
    }

    if(count == userColorIndex.length()) { 
        // Input is an INTEGER
        int sizeColorOpt = sizeof(colorOpt)/sizeof(colorOpt[0]);
        if(stoi(userColorIndex) > 0 && stoi(userColorIndex) <= sizeColorOpt) {
            // Input is a VALID option
            cout << colorOpt[stoi(userColorIndex)-1] << endl;
        }
        else {
            // Input is not a VALID option
            userColorIndex = "";
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
    for (string s : scrollOpt) {
        cout << x << " - " << s << endl;
        ++x;
    }
    cout << "SCROLL SPEED -> ";
    cin >> userScroll;
    return userScroll;
}

Struct printMenu() {
    Struct options;

    char menuOpt;
    do {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1 - Text" << endl;
        cout << "2 - Color" << endl;
        cout << "3 - Scroll" << endl;
        cout << "q - Quit" << endl << endl;
        // ADD ANIMATION (FLASH ?)
        cout << "Choose an option -> ";
        cin >> menuOpt;

        switch(menuOpt) {
            case '1': // Text Options
                cout << "======== TEXT OPTIONS ========" << endl;
                options.text = enterText();
                break;
            case '2': // Color Options
                cout << "======== COLOR OPTIONS ========" << endl;
                options.colorIndex = enterColor();
                break;
            case '3': // Scroll Options
                cout << "======== SCROLL OPTIONS ========" << endl;
                options.scrollIndex = enterScroll();
                break;
            case 'q':
                break;
            default:
                cout << "INVALID OPTION. TRY AGAIN." << endl;
                break;
        }
    } while (menuOpt != 'q');

    return options;
}