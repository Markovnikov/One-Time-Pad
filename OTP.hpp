#include <iostream>
#include <bitset>

#ifndef ONE_TIME_PAD_OTP_HPP
#define ONE_TIME_PAD_OTP_HPP

class OTP
{
protected:
    std::string userWord; // user's word to encrypt
    std::string binaryCode; // binary version of the users string
    std::string keyWord; // the key to convert the word
    std::string binaryKey; // binary code for the key word
    std::string cipherWord; // resulting generated encoded word
    int randomNumber; // random number generated

public:
    OTP();
    void setUserWord(std::string); // set the string
    std::string getUserWord(); // get the string
    int makeRandomNumber(); // generate a random number
    void stringToBinary(); // convert string to binary
    void createKeyWord(); // create the key word
    void keyToBinary(); // convert key string to binary
    void addTwoCodes(); // add the userWord binary code and the keyWord binary code together
    void printBinaryCode(); // print the binary code
    void printBinaryKeyCode();// print the key's binary code
    void printCipherWord(); // print the cipher word (binary)


};

#endif //ONE_TIME_PAD_OTP_HPP
