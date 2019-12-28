
#!/bin/bash
total_tests=5
for (( i = 1; i <= 5; i++ ))
do
console_in="./tests/in_$i.txt"
console_out="./tests/out_$i.txt"
temp_out="./tests/out_$i.txt"
./app.exe < $console_in > $temp_out
diff $console_out $temp_out > diff_$i
if [ -s diff_$i ]; then
    echo test\#$i: FAILED
    diff $console_out $temp_out
else
    echo test\#$i: OK
fi
rm diff_$i
rm $temp_out
done
for (( i = 10; i <= total_tests; i++ ))
do
console_in="./tests/in_$i.txt"
console_out="./tests/out_$i.txt"
temp_out="./tests/t_out_$i.txt"
./app.exe < $console_in > $temp_out
diff $console_out $temp_out > diff_$i
if [ -s diff_$i ]; then
    echo test\#$i: FAILED
    diff $console_out $temp_out
else
    echo test\#$i: OK
fi
rm diff_$i
rm $temp_out
done

