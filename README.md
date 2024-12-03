# Check If a Word Occurs As a Prefix of Any Word in a Sentence using Two Pointers Approach
- ### Intuition
    The problem asks us to determine the index of the first word in a sentence that has a given string `searchWord` as a prefix. If no word has `searchWord` as a prefix, we return `-1`.

    To solve this, we need to iterate through the sentence, process each word, and check if the word starts with the string `searchWord`. We also need to ensure we are only considering the prefix match and not a complete match. The first word that matches is the result.

- ### Approach
    1. **Initialization:**
    - We start by setting a variable `searchWordIndex` to the maximum possible integer value (`numeric_limits<int>::max()`) to represent the fact that we haven't found a match yet.
    
    2. **Word Parsing:**
    - We split the sentence into words by iterating through the sentence character by character.
    - When we encounter a space `' '`, we check the current word. If it starts with `searchWord`, we then compare the prefix of the current word with `searchWord`.

    3. **Prefix Check:**
    - For each word, we compare the first few characters (up to the length of `searchWord`) to check if it is a prefix.
    - If we find a match, we update `searchWordIndex` with the 1-based index of the word.

    4. **Handle the Last Word:**
    - After processing all spaces, we may have a word that doesn't end with a space (i.e., the last word in the sentence). We need to check this word too.

    5. **Return the Result:**
    - If we found a match during the iteration, `searchWordIndex` will hold the index of the first word that matches. If no match is found, we return `-1`.

- ### Code Implementation
    - **Python Solution**
        ```python3 []
        class Solution:
            def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
                # Initialize searchWordIndex as infinity to track the earliest word index
                searchWordIndex = float('inf')
                
                # Split the sentence into words
                words_In_Sentence = sentence.split()

                # Loop through each word in the sentence by index
                for index in range(len(words_In_Sentence)):
                    currentWord = words_In_Sentence[index]
                    
                    # Check if the first letter of the current word matches the first letter of searchWord
                    if searchWord[0] == currentWord[0]:
                        tempIndex = 0  # Temporary index to check characters of both searchWord and currentWord
                        
                        # Compare each character of searchWord with currentWord until we find a mismatch
                        while (tempIndex < len(currentWord) and 
                            tempIndex < len(searchWord) and 
                            searchWord[tempIndex] == currentWord[tempIndex]):
                            tempIndex += 1
                        
                        # If we successfully matched the entire searchWord as a prefix of currentWord
                        if tempIndex == len(searchWord):
                            # Update the result with the current word index (1-based index)
                            searchWordIndex = min(searchWordIndex, index + 1)
                            break

                # If we found a matching word, return the 1-based index of the word, otherwise return -1
                return searchWordIndex if searchWordIndex != float('inf') else -1
        ```
    
    - **C++ Solution**
        ```cpp []
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
                            if(tempIndex == searchWord.length())  {
                                searchWordIndex = min(searchWordIndex, index + 1);
                                break;  // Found the first match, no need to check further words
                            }
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
                if(searchWordIndex == numeric_limits<int>::max() && searchWord[0] == currentWord[0]) {
                    int tempIndex = 0; // Temporary index to compare characters of searchWord and currentWord
                    
                    // Compare characters of searchWord with currentWord to check if it's a prefix
                    while(tempIndex < currentWord.length() && 
                        tempIndex < searchWord.length() && 
                        searchWord[tempIndex] == currentWord[tempIndex]) {
                        ++tempIndex; // Move to the next character if they match
                    }

                    // If we've matched the whole searchWord, update searchWordIndex
                    if(tempIndex == searchWord.length()) {
                        searchWordIndex = min(searchWordIndex, index + 1);
                    }
                }

                // If we found a valid index, return it; otherwise return -1 indicating no match
                return (searchWordIndex != numeric_limits<int>::max()) ? searchWordIndex : -1;
            }
        };
        ```

- ### Time Complexity
    - **O(n)**:  
    The time complexity is linear with respect to the length of the sentence `n`. This is because we iterate through the sentence once, processing each character in it. Additionally, for each word, we check at most `m` characters (where `m` is the length of the longest word), but this happens a constant number of times, so the overall complexity remains O(n).

- ### Space Complexity
    - **O(m)**:  
    The space complexity is O(m), where `m` is the length of the longest word in the sentence. This is because we store the current word as we process it, and we only need space for one word at a time.

    In the worst case, the space complexity will be proportional to the length of the longest word in the sentence.