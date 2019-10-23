#include <stdio.h>

int main()
{
    int x, y, z, res, a, b, c, d, e, h, k;
    printf("x y z   (!x || !y)    (z == a)   (b == !z)   (x == y)    (d == c)   (x || y)   (e == h)   \n");
    for (x = 0; x <= 1; x++)
    {
        for (y = 0; y <= 1; y++)
        {
            for (z = 0; z <= 1; z++)
            {
                res = ((x || y) == (y && !z));
                a = (!x || !y);
                b = (z <= a);
                c = (b <= !z);
                d = (x == y);
                e = (d == c);
                h = (x || y);
                k = (e == h);
                printf("%d %d %d       %d           %d             %d           %d            %d           %d        %d\n", x, y, z, a, b, c, d, e, h, k);
            }
        }
    }
    return 0;
}