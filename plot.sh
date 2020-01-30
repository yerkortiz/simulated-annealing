for filenames in ff11111/exp/exp1/*.txt; do
    cat $filenames | python3 plot.py > media1.txt
done
for filenames in ff11111/exp/exp2/*.txt; do
    cat $filenames | python3 plot.py > media2.txt
done
for filenames in ff11111/exp/exp3/*.txt; do
    cat $filenames | python3 plot.py > media3.txt
done
for filenames in ff11111/exp/exp4/*.txt; do
    cat $filenames | python3 plot.py > media4.txt
done