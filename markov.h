#ifndef MARKOV_H
#define MARKOV_H

#include <string>

// What it does: This helper function takes several words from an array and glues them together into one string with spaces between them. You'll use this to create prefixes when order > 1.
// Parameters explained:
// words[] – The array of words to pull from.
// startIndex – Which position to start from.
// count – How many words to join together.
// Returns: A single string with the words joined by spaces. The caller must supply a nonnegative startIndex and count whose entire range is within the array. A count of 0 returns an empty string.
std::string joinWords(const std::string words[], int startIndex, int count);

// What it does: Opens a text file and reads whitespace-separated words into the array, stopping at maxWords. Punctuation and capitalization stay attached to the words. Additional words beyond the capacity are not used.
// Parameters explained:
// filename – The name of the file to read (like "alice.txt").
// words[] – An empty array that you will fill with words from the file.
// maxWords – The maximum number of words the array can hold. Stop reading if you hit this limit.
// Returns: The number of words actually read (0 for an empty or whitespace-only file). If the file cannot be opened, return -1. A nonpositive capacity permits no array writes.
int readWordsFromFile(std::string filename, std::string words[], int maxWords);

// What it does: This function scans through all the words and records "what comes after what." It's like making flashcards: on the front of each card you write a word (or words), and on the back you write the word that came after it.
// Parameters explained:
// words[] – The array filled by readWordsFromFile (Function 2).
// numWords – How many words are in that array.
// order – How many words to use as the prefix. Order 1 means one word, order 2 means two words joined together.
// prefixes[] – An empty array where you'll store the "front of the flashcard" (the word or words before).
// suffixes[] – An empty array where you'll store the "back of the flashcard" (the word that came after).
// maxChainSize – Maximum number of entries the arrays can hold.
// Returns: The number of prefix-suffix pairs you added.
int buildMarkovChain(const std::string words[], int numWords, int order, std::string prefixes[], std::string suffixes[], int maxChainSize);

// What it does: Given a prefix like "the cat", this function finds ALL the entries in the chain that have that prefix, then randomly picks one of the corresponding suffixes. It's like flipping through your flashcards, finding all the ones with "the cat" on the front, and randomly picking one to see what's on the back.
// Parameters explained:
// prefixes[] – The array of prefixes from buildMarkovChain.
// suffixes[] – The array of suffixes from buildMarkovChain.
// chainSize – How many entries are in the chain.
// currentPrefix – The prefix to look up (like "the" or "the cat").
// Returns: A randomly chosen recorded suffix. If chainSize <= 0 or the prefix has no matches, return an empty string "". Never compute rand() % 0.
std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[], int chainSize, std::string currentPrefix);

// What it does: This function just picks a random prefix from your chain to use as the starting point for text generation. It's like closing your eyes and pointing at a random flashcard to start with.
// Parameters explained:
// prefixes[] – The array of prefixes.
// chainSize – How many entries are in the chain.
// Returns: A randomly selected prefix string, or an empty string "" when chainSize <= 0.
std::string getRandomPrefix(const std::string prefixes[], int chainSize);

// What it does: This is the fun one! It "walks" the Markov chain to generate new text. It picks a random starting point, then keeps asking "what word comes next?" over and over, building up a sentence word by word.
// Parameters explained:
// prefixes[] – The array of prefixes.
// suffixes[] – The array of suffixes.
// chainSize – How many entries are in the chain.
// order – The chain order (1, 2, or 3). You need this to know how to update the prefix.
// numWords – The maximum number of output words, including the initial prefix. The user must request at least order words.
// Returns: Up to numWords words. Stop early at a dead end; do not invent a transition or restart elsewhere to fill the quota. For an empty chain, invalid order, or numWords < order, return "".
std::string generateText(const std::string prefixes[], const std::string suffixes[], int chainSize, int order, int numWords);

#endif