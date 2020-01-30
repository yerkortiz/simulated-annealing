import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from scipy import stats
import sys
data = sys.stdin.read()
a = ''
x = []
for i in data:
    if(i == ' ' or i == '\n'):
        x.append(int(a))
        a = ''
        continue
    a += i
sums = [0]*5
l = len(x)//5
for i in range(l):
    sums[i % 5] += x[i]
proms = []
y = []
for i in range(len(sums)):
    y.append('x' + str(i + 1))
for i in sums:
    proms.append(i/l)
print(proms)

