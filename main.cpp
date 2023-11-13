#include <iostream>
#include <string>

using namespace std;


string toBinNumber(long long number) {
    if (number == 0) {
        return 0;
    }
    string binary = "";
    while (number != 0) {
        int digit = number % 2;
        binary = to_string(digit) + binary;
        number /= 2;
    }
    return binary;
}

int toDecNumber(string num) {
    int dec = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') {
            dec += base;
        }
        base = base * 2;
    }
    return dec;
}

string addOneToBinary(string num) {
    int dec = toDecNumber(num);
    dec++;
    return toBinNumber(dec);
}

void calculator(int number, int bytes, int type) {
    bool ifMinus;
    if (number < 0) {
        ifMinus = true;
        number = number * -1;
    } else {
        ifMinus = false;
    }
    string bin;
    bin = toBinNumber(number);
    string dops;

    if (bin.length() > bytes) {
        for (int i = 0; i < (bytes - bin.length()); i++) {
            bin.erase(0, 1);
        }
    } else {
        for (int i = 0; i < (bytes - bin.length()); i++) {
            dops += "0";
        }
        bin = dops + bin;
    }

    if (!ifMinus) {
        cout << "Answer: " << bin;
    } else {
        bin[0] = 49;
        if (type == 1) {
            cout << "Answer: " << bin;
        } else {
            for (int j = 1; j < bin.length(); j++) {
                if (bin[j] == 49) {
                    bin[j] = 48;
                } else {
                    bin[j] = 49;
                }
            }
            if (type == 2) {
                cout << "Answer: " << bin;
            } else if (type == 3) {
                bin = addOneToBinary(bin);
                cout << "Answer: " << bin;
            }
        }
    }
}

int main() {
    int number, bytes, type;
    cin >> number;
    cin >> bytes;
    cin >> type;
    calculator(number, bytes, type);
    return 0;
}