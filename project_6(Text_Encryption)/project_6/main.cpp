#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int indexof(char index, int size, const char alpahbetArray[]) { // a function used to get the index of a character in any arrays
    for (int k = 0; k < size; ++k) {
        if (index == alpahbetArray[k]) {
            return k;
        }
    }
}

int main(int argc, char * argv[]) {
    const char alphabet[]= {'A' , 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X' , 'Y', 'Z'};
    const char alphabet2[]= {'a' , 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x' , 'y', 'z'};
    string inputText; // A string for the text in the input file
    string outputText;// A string for the text in the output file
    bool isencrypt = false;//A flag that will check if we are encrypting or decrypting
    bool isdecrypt = false;//A flag that will check if we are encrypting or decrypting
    string inputName;
    string outputName;
    int shift; // the amount we are shifting by
    //Used these two variables to get the right indexing
    int addition = 0;
    int difference = 0;
    ifstream filestream;
    ofstream oFile;


    for (int i = 0; i < argc; ++i) { // check for the user's input. 
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'e') { // check for encryption
                isencrypt = true;
                isdecrypt = false;
            } else if (argv[i][1] == 'd') {// check for decryption
                cout << "Decrypting..." << endl;
                isdecrypt = true;
                isencrypt = false;
            } else if (argv[i][1] == 'k' || argv[i][1] == 'K') {// check for the number of shifts
                shift = atoi(argv[i + 1]);
                cout << "Shifting the characters by: " << shift << endl;

            } else if (argv[i][1] == 'i' || argv[i][1] == 'I') { // check for input file name
                inputName = argv[i + 1];
                cout << inputName << endl;
            } else if (argv[i][1] == 'o' || argv[i][1] == 'O') {// check for output file name
                outputName = argv[i + 1];
                cout << outputName << endl;

            }
        }


    }
    filestream.open(inputName);
    oFile.open(outputName, ios_base::app);

    if (!filestream.is_open()) {
        cout << "File is not open" << endl;
    }

    if (filestream.bad()) {
        cout << "File is bad" << endl;
    }
    if (filestream.good()) {
        cout << "File is good" << endl;
    }
    while (!filestream.eof() && filestream.is_open()) {
        // filestream >> text;
        if (isencrypt == true && isdecrypt == false) { // if we are encrypting
            getline(filestream, inputText); // get input
            outputText = inputText;
            for (int x = 0; x < inputText.size(); ++x) { // check for each character in the input
                for (int z = 0; z < sizeof(alphabet); ++z) { 
                    if (inputText.at(x) == alphabet[z]) { // compare to the alphabet is in the array
                        // This is the process of shifting
                        addition = shift + indexof(inputText.at(x), sizeof(alphabet), alphabet);
                        difference = addition - sizeof(alphabet);
                        if (difference >= 0) {
                            outputText.at(x) = alphabet[difference];

                        } else {
                            outputText.at(x) = alphabet[z + shift];


                        }

                    } else if (inputText.at(x) == alphabet2[z]) { // same process but if the letteres are small
                        addition = shift + indexof(inputText.at(x), sizeof(alphabet2), alphabet2);
                        difference = addition - sizeof(alphabet2);
                        if (difference > 0) {
                            outputText.at(x) = alphabet2[difference];

                        } else {
                            outputText.at(x) = alphabet2[z + shift];
                        }

                    } else if (inputText.at(x) == ' ') { // check for spaces
                        outputText.at(x) = ' ';
                    } else {}

                }

            }


        } else if (isdecrypt == true && isencrypt == false) { // check if it is decrypting which is the same procedure as encrypting but we are reverse shifting
            getline(filestream, inputText); // 
            outputText = inputText;
            shift = shift * -1;
            for (int x = 0; x < inputText.size(); ++x) {
                for (int z = 0; z < sizeof(alphabet); ++z) {
                    if (inputText.at(x) == alphabet[z]) {
                        //inputText.at(x)
                        addition = shift + indexof(inputText.at(x), sizeof(alphabet), alphabet);
                        if (addition < 0) {
                            difference = sizeof(alphabet) + addition;
                            outputText.at(x) = alphabet[difference];


                        } else {
                            difference = shift + indexof(inputText.at(x), sizeof(alphabet), alphabet);
                            outputText.at(x) = alphabet[difference];
                        }



                    } else if (inputText.at(x) == alphabet2[z]) {
                        addition = shift + indexof(inputText.at(x), sizeof(alphabet2), alphabet2);
                        if (addition < 0) {
                            difference = sizeof(alphabet2) + addition;
                        } else {
                            difference = shift + indexof(inputText.at(x), sizeof(alphabet2), alphabet2);
                        }
                        outputText.at(x) = alphabet2[difference];

                    } else if (inputText.at(x) == ' ') { // check for spaces
                        outputText.at(x) = ' ';
                    } else {}

                }

            }

        }



        oFile << outputText << "\n"; // output the text in the output file
    }

    filestream.close();
    oFile.close();

    return 0;

}
