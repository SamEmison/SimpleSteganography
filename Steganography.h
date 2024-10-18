/**
 * @file Steganography.h
 * @author Sam Emison and Cole Belew
 * @date 2024-10-17
 * @brief Sets up structure
 * 
 * Sets up structure for the Steganography class by defining its members and operations
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <vector>
#include <string> 

class Steganography {
 private:
  std::string magicNumber;
  int width;
  int height;
  int maxColor;
  std::vector<int> colorData;
  std::string cipherText;
  int getNthBit(char cipherChar, int n);

 public:

/**
 * Reads in the PPM image with the provided fileName, storing it in the member variables
 *
 * @param std::string fileName The name of the image file
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void readImage(std::string fileName);


/**
 * Writes the PPM image stored in member data to the provided fileName
 *
 * @param std::string fileName The name of the image file
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void printImage(std::string fileName);


/**
 * Reads the plain text file (ciphertext) with the name fileName and stores it in the member data
 *
 * @param std::string fileName The name of the image file
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void readCipherText(std::string fileName);


/**
 * Writes the plain text (ciphertext) to the fileName
 *
 * @param std::string fileName The name of the image file
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void printCipherText(std::string fileName);


/**
 * Zeros out the least significant bit of each color value in colorData
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void cleanImage();


/**
 * Stores the text from cipherText in the image colorData
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void encipher();


/**
 * Reads the ciphertext back from colorData and stores it in ciphertext
 *
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string decipher();
};

#endif // STEGANOGRAPHY_H
