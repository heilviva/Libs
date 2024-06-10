#include <iostream>
#include <string>

using namespace std;

extern "C" __declspec(dllexport) bool serchstr(const char* str, const char* chars) {
    while (*chars) {
        if (string(str).find(*chars++) == string::npos) {
            return false;
        }
    }
    return true;
}