#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    // Function to check if searchWord is a prefix of any word in the sentence
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize searchWordIndex to max integer value to track the earliest index
        int searchWordIndex = numeric_limits<int>::max(); 
        
        // Index to track the word count (1-based index) in the sentence
        int index = 0;
        
        // Temporary variable to hold the current word being processed
        string currentWord = "";

        // Iterate through each character in the sentence
        for(const char& character: sentence) {
            // If we encounter a space, it indicates the end of a word
            if(character == ' ') {
                // Check if the current word starts with the same letter as searchWord
                if(searchWord[0] == currentWord[0]) {
                    int tempIndex = 0; // Temporary index to compare characters of searchWord and currentWord
                    
                    // Compare characters of searchWord with currentWord to check if it's a prefix
                    while(tempIndex < currentWord.length() && 
                          tempIndex < searchWord.length() && 
                          searchWord[tempIndex] == currentWord[tempIndex]) {
                        ++tempIndex; // Move to the next character if they match
                    }

                    // If we've matched the whole searchWord, update searchWordIndex
                    if(tempIndex == searchWord.length()) 
                        searchWordIndex = min(searchWordIndex, index + 1);
                }

                // Reset currentWord for the next word in the sentence
                currentWord = "";
                ++index; // Increment the index to keep track of word count
            } else {
                // If it's not a space, add the character to the current word
                currentWord += character;
            }
        }

        // After the loop, we may still have a word left to check (last word in the sentence)
        if(searchWord[0] == currentWord[0]) {
            int tempIndex = 0; // Temporary index to compare characters of searchWord and currentWord
            
            // Compare characters of searchWord with currentWord to check if it's a prefix
            while(tempIndex < currentWord.length() && 
                  tempIndex < searchWord.length() && 
                  searchWord[tempIndex] == currentWord[tempIndex]) {
                ++tempIndex; // Move to the next character if they match
            }

            // If we've matched the whole searchWord, update searchWordIndex
            if(tempIndex == searchWord.length())
                searchWordIndex = min(searchWordIndex, index + 1);
        }

        // If we found a valid index, return it; otherwise return -1 indicating no match
        return (searchWordIndex != numeric_limits<int>::max()) ? searchWordIndex : -1;
    }
};

int main() {
    string sentence = "i love eating burger", searchWord = "burg";
    Solution sol;
    cout << sol.isPrefixOfWord(sentence, searchWord) << endl;
}