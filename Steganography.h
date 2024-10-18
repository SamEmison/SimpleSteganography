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

#include<vector>

class Steganography {
 private:
  string magicNumber;
  int width;
  int height;
  int maxColor;
  vector<int> colorData;
  string cipherText;
  int getNthBit(char cipherChar, int n);

 public:
  void readImage(string fileName);
  void printImage(string fileName);
  void readCipherText(string fileName);
  void printCipherText(string fileName);
  void cleanImage();
  void encipher();
  void decipher();
};

#endif // STEGANOGRAPHY_H
