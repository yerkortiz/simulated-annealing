#!/bin/bash
for filename in output/out1/*; do 
    ./stc < $filename >> "exp"/"exp1"/"exp.txt"
done