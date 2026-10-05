#include <iostream>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

int main() {
    // srand(time(0));
    
    std::string testWords[] = {"the", "cat", "sat", "down"};
    std::cout << joinWords(testWords, 0, 2) << std::endl;  // Should print: the cat
    std::cout << joinWords(testWords, 1, 3) << std::endl;  // Should print: cat sat down

    return 0;
}