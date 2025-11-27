#include <stdio.h>

int main() {
    int a[100], i, n, pos;

    printf("Enter the length of the array\n");
    scanf("%d", &n);

    printf("Enter the array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos > n)
        printf("Invalid position");
    else {
        for (i = pos - 1; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }

    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}
