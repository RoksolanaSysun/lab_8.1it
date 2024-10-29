
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str) {
    if (strlen(str) < 3)
        return 0;
    int count = 0;
    for (int i = 0; str[i + 2] != '\0'; i++) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
            count++;
    }
    return count;
}

char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 3)
        return str;
    char* tmp = new char[len * 4 / 3 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i + 2] != '\0') {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            strcat(t, "***");
            t += 3;
            i += 3;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    while (i < len) {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of '!!!'" << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}