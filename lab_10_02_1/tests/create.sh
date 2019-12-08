#!/bin/bash

for i in {1..5}; do
    echo "in_$i.txt"
    touch ref.txt
    ../app.exe < in_$i.txt > ref.txt
    if [[ $(diff out_$i.txt stockpile.txt) ]]; then
        echo "Test $i failed"
    else
        echo "SUCCESS"
    fi
    rm ref.txt
done
