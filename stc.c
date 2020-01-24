#include <stdlib.h>
#include <stdio.h>
#define and &&
int main(void)
{
    int index = 1;
    int a, b, c, d;
    int aI = 0, bI = 0, cI = 0, dI = 0;
    while(scanf("%d%d%d%d", &a, &b, &c, &d)) {
        if(aI == 0 and a == 1) aI = index;
        if(bI == 0 and b == 1) bI = index;
        if(cI == 0 and c == 1) cI = index;
        if(dI == 0 and d == 1) dI = index;
        ++index;
    }
    printf("%d %d %d %d", aI, bI, cI, dI);
    return 0;
}