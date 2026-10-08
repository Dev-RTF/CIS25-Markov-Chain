#include <iostream>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

int main() {
    srand(time(0));

    // joinWords test:
    // std::string testWords[] = {"the", "cat", "sat", "down"};
    // std::cout << joinWords(testWords, 0, 2) << std::endl;  // Should print: the cat
    // std::cout << joinWords(testWords, 1, 3) << std::endl;  // Should print: cat sat down

    // readWordsFromFile test:
    cout << endl;
    cout << "readWordsFromFile test:" << endl;
    cout << endl;
    std::string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    std::cout << "Read " << count << " words" << std::endl;
    for (int i = 0; i < 10 && i < count; i++) {
        std::cout << words[i] << std::endl;
    }

    // buildMarkovChain test:
    int order = 3;
    
    cout << endl;
    cout << "buildMarkovChain test:" << endl;
    cout << endl;
    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, 1000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
        // cout << "main\n";
        std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    }
    
    // getRandomSuffix test:
    // string prefix;
    // cout << "Prefix: ";
    // cin >> prefix;
    cout << endl;
    cout << "getRandomSuffix test:" << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "The cat") << std::endl;
    }

    // getRandomPrefix test:
    cout << endl;
    cout << "getRandomPrefix test:" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        std::cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    }

    // generateText test:
    // it's weird because sometimes there aren't 200 words, and sometimes there are. quite strange
    cout << endl;
    cout << "generateText test:" << endl;
    cout << endl;
    
    int numWords = 200;
    cout << "\norder: " << order << endl;
    cout << "numWords: " << numWords << endl;
    std::string output = generateText(prefixes, suffixes, chainSize, order, numWords);
    std::cout << output << std::endl;

    return 0;
}