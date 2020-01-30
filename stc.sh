#!/bin/bash
for filename in output/out1/*; do 
    ./stc < $filename >> "exp"/"exp1"/"exp.txt"
done
for filename in output/out2/*; do 
    ./stc < $filename >> "exp"/"exp2"/"exp.txt"
done
for filename in output/out3/*; do 
    ./stc < $filename >> "exp"/"exp3"/"exp.txt"
done
for filename in output/out4/*; do 
    ./stc < $filename >> "exp"/"exp4"/"exp.txt"
done