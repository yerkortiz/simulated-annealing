for filenames in exp/exp1/*.txt; do
    cat $filenames | python3 plot.py > plot.txt
done