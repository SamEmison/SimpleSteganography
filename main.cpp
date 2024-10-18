/**
 * @file main.cpp
 * @author Sam Emison
 * @date 2024-10-17
 * @brief Main
 * 
 * Main.cpp for Steganography assignment
 */


#include <iostream>
#include "Steganography.h"

using namespace std;

int main() {
  Steganography stego;
  int choice; //Choice for the user to either encode or decode

  cout << "Choose an operation: " << endl;
  cout << "1. Encode a Message" << endl;
  cout << "2. Decode a Message" << endl;
  cout << "Enter a choice..." << endl;

  cin >> choice;

  if (choice == 1) {
    string inputPPM, inputText, outputPPM;

    cout << "Enter the PPM file name: " ;
    cin >> inputPPM;
    stego.readImage(inputPPM);
    
    cout << "Enter text file name: ";
    cin >> inputText;
    stego.readCipherText(inputText);

    cout << "Enter output PPM file name: ";
    cin >> outputPPM;
    stego.cleanImage();
    stego.encipher();
    stego.printImage(outputPPM);

    cout << "Encoding Complete! " << endl;
    cout << "Encoded image saved as: " << outputPPM << endl;
  }
  
  else if (choice == 2) {
    string inputPPM, outputText;

    cout << "Enter the PPM file name: ";
    cin >> inputPPM;
    stego.readImage(inputPPM);

    cout << "Enter output text file name: ";
    cin >> outputText;
    stego.decipher();
    stego.printCipherText(outputText);

    cout << "Decoding Complete!" << endl;
    cout << "Decoded text saved as: " << outputText << endl;
  }

  else {
    cout << "Invalid choice. Terminating program..." << endl;
  }

  return 0;
}
    
