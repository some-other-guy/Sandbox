#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Please provide a maximum number of cards in the deck"
else
    echo "Running shuffle with card sizes 1 - $1"
    echo "Running shuffle with card sizes 1 - $1" > out.txt
    date >> out.txt
    for (( i = 1; i <= $1; i++ ))
    do
        ./shuffle $i >> out.txt
    done
    date >> out.txt
fi

