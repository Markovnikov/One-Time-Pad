#include <iostream>
#include <string.h>
#include <string>
#include "OTP.hpp"


OTP::OTP() // default constructor
{
    userWord = "";
    binaryCode = "";
    keyWord = "";
    binaryKey = "";
    cipherWord = "";
    randomNumber = 0;
}

void OTP::setUserWord(std::string incomingWord) // set the word
{
    userWord = incomingWord;
}

std::string OTP::getUserWord() // get the user word
{
    return userWord;
}

int OTP::makeRandomNumber() // generate a random number
{
    //variables

    // generate the random number
    randomNumber = 32 + rand() % 126;

    return randomNumber;
}

void OTP::stringToBinary() // convert string of words to string of binary
{
    // variables
    int i = 0; // counter for the for loop
    long long int wordSize = 0; // size of userWord

    wordSize = userWord.size(); // assign the size of userWord to wordSize

    // convert the word to binary
    for(i = 0; i < wordSize; i++)
    {
        std::bitset<8> b(userWord.c_str()[i]);
        binaryCode += b.to_string();
    }

    printBinaryCode(); // print the binary code
    
}

void OTP::createKeyWord() // create the keyword
{
    // variables
    int i = 0; // counter for the for loop
    long long int wordSize = 0; // size of the word
    char rand = '0'; // random ascii character

    // set wordSize equal to the size of userWord
    wordSize = userWord.size();

    // create a random word as the keyword
    for(i = 0; i < wordSize; i++)
    {
        rand = makeRandomNumber();
        keyWord = keyWord + rand;
    }

    std::cout << "Your key word is: " << keyWord << std::endl;

}

void OTP::keyToBinary() // convert key word to binary
{
    // variables
    int i = 0; // counter for the for loop
    long long int wordSize = 0; // size of keyWord

    wordSize = keyWord.size(); // assign the size of keyWord to wordSize

    // convert the word to binary
    for(i = 0; i < wordSize; i++)
    {
        std::bitset<8> z(keyWord.c_str()[i]);
        binaryKey += z.to_string();
    }

    printBinaryKeyCode(); // print the binary code

}

void OTP::addTwoCodes() // adds two binary codes together
{
    // variables
    long long int wordSize = 0; // size of the binary strings to xor (only needs 1, they should both be the same size)
    int i = 0; // counter for the for loop

    wordSize = binaryCode.size();


    // begin XOR operations on both binary strings
    for(i = 0; i < wordSize; i++)
    {
        cipherWord[i] = ((binaryCode[i]-'0') ^ (binaryKey[i]-'0')) + '0';
        cipherWord = cipherWord + cipherWord[i];
    }
}

void OTP::printBinaryCode() // print the binary code
{
    std::cout << "Your Binary Code is: " << binaryCode << std::endl;
}

void OTP::printBinaryKeyCode() // print the binary key's code
{
    std::cout << "The key converted to Binary Code is: " << binaryKey << std::endl;
}

void OTP::printCipherWord() // print the cipher word
{
    std::cout << "The cipher word is: " << cipherWord << std::endl;
}