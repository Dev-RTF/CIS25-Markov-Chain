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
    cout << endl;
    cout << "buildMarkovChain test:" << endl;
    cout << endl;
    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 1000);
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
    // bug with chain size of 3. also don't know what is meant by "updating the prefix"
    cout << endl;
    cout << "generateText test:" << endl;
    cout << endl;
    std::string output = generateText(prefixes, suffixes, chainSize, 3, 200);
    std::cout << output << std::endl;
    // std::string output2 = generateText(prefixes, suffixes, chainSize, 2, 20, "[SPACE]");
    // std::cout << output2 << std::endl;
    // order 2: it looks as if there is an extra prefix appended to the front of the generated text
    // order 3: generates 
    return 0;
}