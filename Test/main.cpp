#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

typedef bool (*CharCheckFunction)(const char*, const char*);

int main() {
    cout << "Enter a string to search characters in: ";
    string inputStr;
    getline(std::cin, inputStr);

    cout << "Enter the characters to search for: ";
    string searchChars;
    getline(std::cin, searchChars);

    HMODULE hDLL = LoadLibrary(L"DinamicLib.dll");
    if (hDLL == NULL) {
        cerr << "Failed to load DLL." << endl;
        return 1;
    }

    CharCheckFunction checkCharsInString = (CharCheckFunction)GetProcAddress(hDLL, "serchstr");
    if (checkCharsInString == NULL) {
        cerr << "Failed to get function address." << endl;
        FreeLibrary(hDLL);
        return 1;
    }

    bool result = checkCharsInString(inputStr.c_str(), searchChars.c_str());

    if (result) {
        cout << "All characters found!:)" << endl;
    }
    else {
        cout << "Not all characters found!:(" << endl;
    }

    FreeLibrary(hDLL);

    return 0;
}