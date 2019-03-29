#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
int main(){
    //create the S box
    unsigned char S[256];
    int i = 0;
    for (i = 0; i < 256; i++)
        S[i] = i;
    int j = 0, option = 0;
    //choose option for decryption or encryption
    while (option != 1 && option != 2){
        std::cout << "encryption: 1, decryption: 2 \n";
        std::cin >> option;
    }
    //user input for key
    std::string key;
    std::cout << "Enter the key: ";
    std::cin >> key;
    while(key.length() < 5 || key.length() > 32){
        std::cout << "Key must be between 5 and 32 bytes\n";
        std::cout << "Enter proper key: ";
        std:: cin >> key;
    }
   //generate ksa
    for (i = 0; i < 256; i++){
        j = (j + S[i] + key.at(i % key.length())) % 256;
        std::swap(S[i], S[j]);
    }
    //prompt for file input
    std::string input, printFile;
    std::cout << "Input file to work with: ";
    std::cin >> input;
    //create file stream
    std::ifstream read(input, std::ios::binary);
    if (option == 1)
        printFile = "out.rc4";
    if (option == 2)
        printFile = "out.plain";
        //printFile = "out." + input.substr(0, input.length() - 4);
    std::ofstream print(printFile, std::ios::binary);
    int a = 0;
    char fill;
    for(a = 0; a < 3092; a++){
        fill = S[(S[i] + S[j]) % 256]; 
    }
    char x;
    j = 0;
    i = 0;
    while (read.read(&x, 1)){
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        std::swap(S[i], S[j]);
        char temp = S[(S[i] + S[j]) % 256] ^ x;
        print.write(&temp, 1);
    }
}

