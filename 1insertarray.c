#include <stdio.h>

int main() {
    int a[100], n, i, data, pos;

    printf("Enter the length\n");
    scanf("%d", &n);

    printf("Enter the array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter data for insertion: ");
    scanf("%d", &data);

    printf("Enter the position: ");
    scanf("%d", &pos);

    for (i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = data;
    n++;

    printf("Inserted data is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
