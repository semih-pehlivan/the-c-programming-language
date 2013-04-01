#!/bin/bash

# To test the wordcount program (rewritten using a switch statement)
# We can pass the ipso_lorem.txt file to it:

make build/wordcount

<ipso_lorem.txt ./build/wordcount

# The inputs most likely to cause problems are files with variation 
# at the boundary conditions. For example, files that have multiple
# newlines in a row, or that mix multiple blank characters between 
# words.
# 
# Another class of problems could occur with special characters and 
# unicode. For example, the carriage return special character '\r' 
# would be counted as part of a word. Punctuation should not cause 
# problems, at least in english, as it almost always attached to a 
# word malformed or poorly formatted input could be problematic 
# though. For exam[le "However , I" would be counted incorrectly as 
# three words. Similarly, since the program has no knowledge of 
# syntax, it will be unable to distinguish words from presentation
# charactes, such as underlines or ascii header delimiters.


