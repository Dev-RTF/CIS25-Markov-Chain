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
    std::string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    std::cout << "Read " << count << " words" << std::endl;
    for (int i = 0; i < 10 && i < count; i++) {
        std::cout << words[i] << std::endl;
    }

    // buildMarkovChain test:
    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 1000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
        std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    }
    
    // getRandomSuffix test:
    // string prefix;
    // cout << "Prefix: ";
    // cin >> prefix;
    for (int i = 0; i < 10; i++) {
        std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "cat sat ") << std::endl;
    }

    // getRandomPrefix test:
    for (int i = 0; i < 5; i++) {
        std::cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    }

    cout << "-\n-\n-\n";
    // generateText test:
    // bug with chain size of 3. also don't know what is meant by "updating the prefix"
    std::string output = generateText(prefixes, suffixes, chainSize, 2, 20);
    std::cout << output << std::endl;

    return 0;
}