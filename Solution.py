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