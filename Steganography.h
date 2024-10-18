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
  void readImage(std::string fileName);
  void printImage(std::string fileName);
  void readCipherText(std::string fileName);
  void printCipherText(std::string fileName);
  void cleanImage();
  void encipher();
  std::string decipher();
};

#endif // STEGANOGRAPHY_H
