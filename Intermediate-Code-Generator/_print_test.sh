#!/bin/bash

# alias ccat='pygmentize -g'

for testcase in $(ls testcases); do
    echo "============================================================================================================="
    printf "Source code for: $testcase:\n"
    pygmentize -g testcases/$testcase
    printf "\n\n\n"
    ./run.sh testcases/$testcase
    echo "============================================================================================================="
    printf "\n\n\n"
done