#include <iostream>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

int main() {
    srand(time(0));
    
    string fileName;
    int order = 0;
    int maxGeneratedWords = 0;

    cout << "Enter the name of the source file: ";
    std::getline(std::cin, fileName);

    while (order > 3 || order < 1) {
        cout << "Enter the order for generation (Between 1 and 3): ";
        cin >> order;
    }
    
    while (maxGeneratedWords < order) {
        cout << "Enter the maximum amount of words *you want generated*. It has to be at least the order: ";
        cin >> maxGeneratedWords;
    }

    /*
    3. Use a named capacity, for example const int MAX_WORDS = 5000; declare words, prefixes, and suffixes with that capacity. Pass the actual capacity to the functions. This project may train on only the first 5000 words of a larger file.
    4. Read the file. Explain a -1 result as a file-open failure. If the count is <= order, explain that at least order + 1 training words are needed. Do not try to generate from those inputs.
    */

    const int MAX_WORDS = 5000; // this is the max number of words that can be read from a file
    std::string words[MAX_WORDS];

    int count = readWordsFromFile(fileName, words, MAX_WORDS);
    if (count == -1) {
        cout << "Error encountered opening file. Please try again and ensure that the file is correct.\n";
        return -1;
    }
    if (count <= order) {
        cout << "At least order + 1 training words are needed. You don't have enough in your file!\n";
        return -1;
    }

    /*
    5. Build the chain and confirm chainSize > 0 before random selection. If the input array filled to capacity, tell the user that at most MAX_WORDS input words were used and additional words, if any, were ignored.
    */

    std::string prefixes[MAX_WORDS], suffixes[MAX_WORDS];
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, MAX_WORDS);
    // cout << chainSize;
    if (chainSize <= 0) {
        cout << "Error: No prefix-suffix pairs could be made.\n";
        return -1;
    }

    if (chainSize < MAX_WORDS) {
        cout << "\nWARNING: Prefixes and suffixes filled to capacity. The rest of the text has been ignored.\n";
    }
   
    /*
    6. Generate up to the requested number of words, stopping if a prefix has no successor.
    7. Print the generated text and its actual word count. If it is shorter than requested, explain that generation stopped at a dead end. Count the words in the returned text; do not change the required function signature.
    */

    cout << endl;
    cout << "--------------------- Generated Text ---------------------" << endl;
    std::string output = generateText(prefixes, suffixes, chainSize, order, maxGeneratedWords);
    std::cout << output << std::endl;
    
    int generatedWords = 0;
    for (int i = 0; i < output.length(); i++) {
        if (output[i] == ' ') {
            generatedWords++;
        }
    }
    generatedWords++; // it's always 1 off for some reason...

    cout << "\n--------------------- Generation Summary ---------------------" << endl;
    cout << "File: " << fileName << endl;
    cout << "Order: " << order << endl;
    cout << "Words generated: " << generatedWords << "/" << maxGeneratedWords << endl;
    
    if (generatedWords < maxGeneratedWords) {
        cout << "The generation stopped at a dead end, causing " << generatedWords << "/" << maxGeneratedWords << " words to be generated." << endl;
    }
    
    return 0;
}