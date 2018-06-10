#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rectangle
{
    int name[20], length, width;
} Rectangle;

main()
{
    Rectangle *p, t;
    int n, i, j, perimeter;

    scanf("%d", &n);
    p = (Rectangle *) calloc(n, sizeof(Rectangle));
    for (i = 0; i < n; ++i)
        scanf("%s %d %d", p[i].name, &p[i].length, &p[i].width);
    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if (strcmp(p[j].name, p[j + 1].name) > 0)
                t = p[j], p[j] = p[j + 1], p[j + 1] = t;
    for (i = 0; i < n; ++i, ++p) {
        perimeter = 2 * (p->length + p->width);
        printf("%s %d %d %d\n", p->name, perimeter, p->length, p->width);
    }
}