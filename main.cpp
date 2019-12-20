#include <iostream>
#include <ctime>
#include "OTP.hpp"

int main() 
{
    // variables
    OTP userCall; // user's instance of the OTP class
    std::string usersWord; // user's word to encrypt

    // set up random seed
    unsigned int seed;
    seed = time(nullptr);
    srand(seed);

    
    std::cout << "Hello, welcome to the One Time Pad!" << std::endl;
    std::cout << "\nPlease enter a word to encrypt: ";
    std::getline(std::cin, usersWord);


    // send the users word to be set
    userCall.setUserWord(usersWord);
    userCall.stringToBinary();
    userCall.createKeyWord();
    userCall.keyToBinary();
    userCall.addTwoCodes();
    userCall.printCipherWord();




    return 0;
}