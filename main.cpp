/**
 * Egemen Bozkus
 * 3/10/2019
 * Phone number to letter converter
 */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// Takes in phone number in char* and string form
// Uses char* form to write letter combinations into .txt file
// Uses string form to create its unique file name with .txt extension
void makeWords(char* input, string phone) {
    // create new txt file to write
    string file_ext = ".txt";  // file extension
    phone += file_ext;
    ofstream ofs;
    ofs.open(phone.c_str());  // create txt file
    if (!ofs.is_open()) {
        cout << "Could not open " << phone << endl;
        return;
    }

    //map containing letters corresponding to each digit (char)
    map<char, string> num2letter;
    num2letter['0'] = "";
    num2letter['1'] = "";
    num2letter['2'] = "ABC";
    num2letter['3'] = "DEF";
    num2letter['4'] = "GHI";
    num2letter['5'] = "JKL";
    num2letter['6'] = "MNO";
    num2letter['7'] = "PQRS";
    num2letter['8'] = "TUV";
    num2letter['9'] = "WXYZ";
    num2letter['-'] = "";

    // generates every combination of letters and writes into .txt file
    // 7 for loops for 7 digits, skips the index of '-'
    string c;
    for (int i = 0; i < num2letter[input[0]].size(); ++i) {
        c = num2letter[input[0]][i];
        string start1 = c;
        for (int j = 0; j < num2letter[input[1]].size(); ++j) {
            c = num2letter[input[1]][j];
            string start2 = start1 + c;
            for (int k = 0; k < num2letter[input[2]].size(); ++k) {
                c = num2letter[input[2]][k];
                string start3 = start2 + c;
                    for (int m = 0; m < num2letter[input[4]].size(); ++m) {
                        c = num2letter[input[4]][m];
                        string start5 = start3 + c;
                        for (int n = 0; n < num2letter[input[5]].size(); ++n) {
                            c = num2letter[input[5]][n];
                            string start6 = start5 + c;
                            for (int o = 0; o < num2letter[input[6]].size(); ++o) {
                                c = num2letter[input[6]][o];
                                string start7 = start6 + c;
                                for (int p = 0; p < num2letter[input[7]].size(); ++p) {
                                    c = num2letter[input[7]][p];
                                    string start8 = start7 + c;  // 7 letter word
                                    ofs << start8 << endl;  // write word into .txt
                                }
                            }
                        }
                    }

            }
        }
    }
    ofs.close();  // closes .txt file
    cout << "text file created" << endl;
}

// main method
// takes in phone number stored in argv[1] and converts into char array
// also creates string of number to use as name
int main(int argc, char* argv[]) {
    string phone = argv[1];  // number in string form
    cout << "Given phone number: " << phone << endl;
    char num[9];  // extract number stored in argv[1] into char num[] array
    for (int i = 0; i < 8; i++) {
        num[i] = argv[1][i];
    }
    num[8] = '\0';  // nullptr
    makeWords(num, phone);
    return 0;
}


