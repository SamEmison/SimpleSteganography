/**
 * @file Steganography.cpp
 * @author Sam Emison and Cole Belew
 * @date 2024-10-17
 * @brief Functionality for Steganography class
 * 
 * Adds the functionalities needed for the Steganography class that has been made
 */

#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Reads the PMM image file and store the data
void Steganography::readImage(string fileName) {
  ifstream inputFile(fileName);
  if (!inputFile.is_open()) { //If it doesnt open, return error
    cout << "Error opening: " << fileName << endl;
    return;
  }

  //Reads the magic number
  inputFile >> magicNumber;

  //Reads the width and height 
  inputFile >> width >> height;

  //Reads the maximum color value
  inputFile >> maxColor;

  //Reads the color data
  int colorValue;
  while (inputFile >> colorValue) {
    colorData.push_back(colorValue);
  }

  inputFile.close(); //Closes file
}

//Write the PMM image data to the specified file
void Steganography::printImage(string fileName) {
  ofstream outputFile(fileName); 
  if (!outputFile.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

  //Writes the magic number, width, height, and max color value
  outputFile << magicNumber << endl;
  outputFile << width << " " << height << endl;
  outputFile << maxColor << endl;

  //Write the color data
  for (size_t i = 0; i < colorData.size(); i++) {
    outputFile << colorData[i] << " ";
    if ((i + 1) % 3 == 0) {
      outputFile << endl;
    }
  }

  outputFile.close(); //Closes file
}

// Reads the ciphertext from a text file
void Steganography::readCipherText(string fileName) {
  ifstream inputFile(fileName);
  if (!inputFile.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

  //Clears the previous cipherText
  cipherText.clear();
  string line;
  while (getline(inputFile, line)) {
    cipherText += line + "\n";
  }

  inputFile.close();
}

//Writes the ciphertext into a text file
void Steganography::printCipherText(string fileName) {
  ofstream outputFile(fileName);
  if (!outputFile.is_open()) {
    cout << "Error opening: " << fileName << endl;
    return;
  }

  outputFile << cipherText; //Writes the cipherText
  outputFile.close(); //Closes the file
}

//Sets the least significant bit of each color value to zero
void Steganography::cleanImage() {
  for (size_t i = 0; i < colorData.size(); i++) {
    colorData[i] &= ~1; //Clears the least significant bit
  }
}

//Encodes the ciphertext into the image's color data
void Steganography::encipher() {
  size_t textIndex = 0;
  for (size_t i = 0; i < colorData.size() && textIndex < cipherText.length(); i++) {
    if (i % 3 == 0) {
      colorData[i] = (colorData[i] & ~1) | getNthBit(cipherText[textIndex], 0);
      textIndex++;
    }
  }
}

//Decodes the ciphertext from the image's color data
string Steganography::decipher() {
    cipherText.clear();
    for (size_t i = 0; i < colorData.size(); i += 8) {
        char ch = 0;
        for (int j = 0; j < 8; ++j) {
            ch |= (getNthBit(colorData[i + j], 0) << (7 - j));
        }
        if (ch == '\0') break;
        cipherText += ch;
    }
    return cipherText;
}

//Helper method to get the nth bit of a character
int Steganography::getNthBit(char cipherChar, int n) {
  return (cipherChar >> n) & 1; //Returns the nth bit 
}
