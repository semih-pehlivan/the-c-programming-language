#!/bin/bash


source helper.sh

suite entab 

test_string "abcdef"          entab "abcdef"        "Doesn't mangle simple input"
test_string "  cdef"          entab "  cdef"        "Keeps short spaces"
test_string "    abcde"       entab "\tabcde"       "Converts obvious tabs"
test_string "      abcde"     entab "\t  abcde"     "Converts tabs without munching extra spaces"
test_string "  \nabcde"       entab "  \nabcde"     "Doesn't mangle blank lines"
test_string "aaaabb    cc"    entab "aaaabb\t  cc"  "Deals with inner tabs"
test_string "  \n     abcde"  entab "  \n\t abcde"  "Deals with mixed cases"

endsuite
