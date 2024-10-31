#pragma once
#include <string>
#include <vector>
#include <chrono>


void InputNumbers(std::vector<unsigned char>& list, unsigned int amount, unsigned int maxNum);
void OutputNumbers(const std::vector<unsigned char>& list);
void Split(const std::string& text, const std::string& delimiter, std::vector<std::string>& tokens);
void GenerateRandomKeys(const unsigned int maxAmount, const unsigned int keysAmount, std::vector<unsigned int>& buffer);
void DisplayTimeDuration(std::chrono::steady_clock::duration duration);
bool IsPrime(unsigned int n);
unsigned int GetNextPrime(unsigned int n);
unsigned long long PowI(unsigned long long a, unsigned long long p);
std::string ToLowercase(const std::string& a);
int CompareStrings(const std::string& a, const std::string& b);