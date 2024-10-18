#include "Homework6_2.h"
#include "Global.h"

#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

void LinearTextSuffixSearch(const std::string& T, const std::string& S, std::vector<std::string*>& out);
unsigned long long StringHash(const std::string& x);
unsigned long long RkTextCount(const std::string& T, const std::string& S);
static const std::string StopSymbols = " .;,:!?\n";

Homework6_2::Homework6_2(const std::string& name) : TaskContainer(name)
{
    _tasks = { new Task1("1"), new Task2("2") };
}

void Homework6_2::Task1::Execute()
{
    std::vector<std::string*> words;

    std::cout << "Введите название файла: ";
    std::string fileName;
    std::getline(std::cin, fileName);
    constexpr unsigned int bufferSize = 1024 * 16;
    char buffer[bufferSize];
    std::ifstream file(fileName);
    file.read(buffer, bufferSize);
    std::string text = std::string(buffer, file.gcount());
    file.close();
    std::cout << "Введите суффикс для поиска: ";
    std::string suffix;
    std::cin >> suffix;
    auto start = std::chrono::steady_clock::now();
    LinearTextSuffixSearch(text, suffix, words);
    auto end = std::chrono::steady_clock::now();
    auto duration = end - start;

    if (words.empty())
    {
        std::cout << "Слова не найдены.\n";
    }
    else
    {
        std::cout << "Найденные слова:\n";
        for (auto word : words)
        {
            std::cout << *word + '\n';
            delete word;
        }
    }
    DisplayTimeDuration(duration);
}

void Homework6_2::Task2::Execute()
{
    std::cout << "Введите название файла: ";
    std::string fileName;
    std::getline(std::cin, fileName);
    constexpr unsigned int bufferSize = 1024 * 16;
    char buffer[bufferSize];
    std::ifstream file(fileName);
    file.read(buffer, bufferSize);
    std::string text = std::string(buffer, file.gcount());
    file.close();
    std::cout << "Введите слово для поиска: ";
    std::string word;
    std::cin >> word;
    auto start = std::chrono::steady_clock::now();
    unsigned long long count = RkTextCount(text, word);
    auto end = std::chrono::steady_clock::now();
    auto duration = end - start;

    if (count == 0)
    {
        std::cout << "Слова не найдены.\n";
    }
    else
    {
        std::cout << "Количество найденных слов: " << count << '\n';
    }
    DisplayTimeDuration(duration);
}

void LinearTextSuffixSearch(const std::string& T, const std::string& S, std::vector<std::string*>& out)
{
    
    for (unsigned int i = 0; i + S.length() < T.length(); ++i)
    {
        bool found = true;
        for (unsigned int j = 0; j < S.length(); ++j)
        {
            if (S[j] != T[i + j])
            {
                found = false;
                break;
            }
        }
        if (!found) continue;
        if (i + S.length() < T.length())
        {
            found = false;
            for (char c : StopSymbols)
            {
                if (c == T[i + S.length()])
                {
                    found = true;
                }
            }
        }
        if (!found) continue;

        std::string* currentString = new std::string(S);
        unsigned int k = i - 1;
        while (k > 0 && T[k] != ' ' && T[k] != '\n')
        {
            currentString->insert(0, 1, T[k]);
            --k;
        }
        out.push_back(currentString);
    }
}

unsigned long long StringHash(const std::string& x)
{
    unsigned long long out = 0;
    unsigned long long power = 1;
    for (unsigned int i = 0; i < x.length(); ++i)
    {
        out += power * static_cast<unsigned char>(x[i]);
        power *= 11;
    }
    return out;
}

unsigned long long RkTextCount(const std::string& T, const std::string& S)
{
    size_t count = 0;
    const unsigned long long sHash = StringHash(S);
    size_t sLen = S.length();
    unsigned long long currentHash = StringHash(T.substr(0, sLen));
    const unsigned long long maxPower = PowI(11, sLen - 1);
    for (size_t i = sLen; i + sLen < T.length(); ++i)
    {
        currentHash -= static_cast<unsigned char>(T[i - sLen]);
        currentHash /= 11;
        currentHash += static_cast<unsigned char>(T[i]) * maxPower;
        count += currentHash == sHash;
    }

    return count;
}
