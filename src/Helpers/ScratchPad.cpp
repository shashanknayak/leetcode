#include "Includes.h"
#include "Utils.h"

class ScratchPad {
    public: 

    void VectorScratchPad() {
        // c++11 initializer list syntax:
        std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
        std::cout << "words1: " << words1 << '\n';
    
        // words2 == words1
        std::vector<std::string> words2(words1.begin(), words1.end());
        std::cout << "words2: " << words2 << '\n';
    
        // words3 == words1
        std::vector<std::string> words3(words1);
        std::cout << "words3: " << words3 << '\n';
    
        // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
        std::vector<std::string> words4(5, "Mo");
        std::cout << "words4: " << words4 << '\n';
    }
};