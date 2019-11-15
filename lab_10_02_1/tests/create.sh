#!/bin/bash

for i in {1..5}; do
    echo "in_$i.txt"
	echo "outfile_$i.txt" >> out_$i.txt
    ./a.out in_$i.txt >> out_$i.txt
done
