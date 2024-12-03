# [1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence?envType=daily-question&envId=2024-12-02)

__Type:__ Easy <br>
__Topics:__ Two Pointers, String, String Matching <br>
__Companies:__ Microsoft, Yelp, Google, tcs
<hr>

Given a `sentence` that consists of some words separated by a __single space__, and a `searchWord`, check if `searchWord` is a prefix of any word in `sentence`.

Return _the index of the word in_ `sentence` ___(1-indexed)___ where `searchWord` _is a prefix of this word_. If `searchWord` is a prefix of more than one word, return the index of the first word __(minimum index)__. If there is no such word return `-1`.

A __prefix__ of a string `s` is any leading contiguous substring of `s`.
<hr>

### Examples:
- __Example 1:__ <br>
__Input:__ sentence = "i love eating burger", searchWord = "burg" <br>
__Output:__ 4 <br>
__Explanation:__ "burg" is prefix of "burger" which is the 4th word in the sentence.

- __Example 2:__ <br>
__Input:__ sentence = "this problem is an easy problem", searchWord = "pro" <br>
__Output:__ 2 <br>
__Explanation:__ "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.

- __Example 3:__ <br>
__Input:__ sentence = "i am tired", searchWord = "you" <br>
__Output:__ -1 <br>
__Explanation:__ "you" is not a prefix of any word in the sentence.
<hr>

### Constraints
- `1 <= sentence.length <= 100`
- `1 <= searchWord.length <= 10`
- `sentence` consists of lowercase English letters and spaces.
- `searchWord` consists of lowercase English letters.
<hr>

### Hints
- First extract the words of the sentence.
- Check for each word if searchWord occurs at index 0, if so return the index of this word (1-indexed)
- If searchWord doesn't exist as a prefix of any word return the default value (-1).