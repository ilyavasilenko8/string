#ifndef STRING_STRING__H
#define STRING_STRING__H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords{
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

void test_find_1();

void test_find_2();

void test_find_3();

void test_find_4();

void test_find_non_space_1();

void test_find_non_space_2();

void test_find_non_space_3();

void test_find_non_space_4();

void test_find_space_1();

void test_find_space_2();

void test_find_space_3();

void test_find_space_4();

void test_find_non_space_reverse_1();

void test_find_non_space_reverse_2();

void test_find_non_space_reverse_3();

void test_find_non_space_reverse_4();

void test_find_space_reverse_1();

void test_find_space_reverse_2();

void test_find_space_reverse_3();

void test_find_space_reverse_4();

int strcmp_(const char *lhs, const char *rhs);

void test_is_strings_equal_1();

void test_is_strings_equal_2();

void test_is_strings_equal_3();

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

void test_copy();

void test_copyIf();

void test_copyIfReverse();

void test_string_();

void removeNonLetters(char *s);

void assertSrting(const char *expected, char *got, char const *fileName, char const *funcName, int line);

void test_removeNonLetters();

char* copy_if_not_extra_spaces(char *beginSource, const char *endSource, char *beginDestination);

void removeExtraSpaces(char *s);

void test_removeExtraSpaces_1();

void test_removeExtraSpaces_2();

void test_removeExtraSpaces_3();

void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters();

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void digitToEnd(WordDescriptor word);

void digits_to_end(char *string);

void test_WordDescriptor();

void replace_digits_with_spaces(char *string);

void test_replace_digits_with_spaces();

bool are_two_words_equal(WordDescriptor a, WordDescriptor b);

bool are_words_in_string_ordered(char *string);

void test_are_words_in_string_ordered();

void replace(char *source, char *w1, char *w2);

bool are_two_words_ordered(WordDescriptor word1, WordDescriptor word2);

bool are_words_ordered(char *string);

void test_are_words_ordered();

void test_replace();

void getBagOfWords(BagOfWords *bag, char *s);

void print_words_in_reversed_order(char *string);

void test_print_words_in_reversed_order();

int is_palindrome(char *begin, char *end);

int count_palindromes(char *string);

void test_count_palindromes();

void join_strings(char *string1, char *string2, char *result);

void test_join_strings();

void reverse_words_order(char *string);

void test_reverse_words_order();

void printWordBeforeFirstWordWithA(char *s);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w);

void test_getWordBeforeFirstWordWithA();

void wordDescriptorToString(WordDescriptor word, char *destination);

char* getLastWordInFirstStringInSecondString(char *s1, char *s2);

//bool is_word_in_BagOfWords(BagOfWords bag, WordDescriptor word);

void test_getLastWordInFirstStringInSecondString();
#endif //STRING_STRING__H
