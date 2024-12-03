from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ("i love eating burger", "burg", 4),
                            2: ("this problem is an easy problem", "pro", 2), 
                            3: ("i am tired", "you", -1)}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_Case_1(self):
        sentence, searchWord, output = self.__testCases[1]
        result = self.__obj.isPrefixOfWord(sentence = sentence, searchWord = searchWord)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

    @timeout(0.5)
    def test_Case_2(self):
        sentence, searchWord, output = self.__testCases[2]
        result = self.__obj.isPrefixOfWord(sentence = sentence, searchWord = searchWord)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

    @timeout(0.5)
    def test_Case_3(self):
        sentence, searchWord, output = self.__testCases[3]
        result = self.__obj.isPrefixOfWord(sentence = sentence, searchWord = searchWord)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

if __name__ == '__main__': unittest.main()