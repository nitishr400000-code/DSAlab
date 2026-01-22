#include <stdio.h>
#define SIZE 10

int ht[SIZE];

int main() {
    int i, ch, key, index, start;

    for (i = 0; i < SIZE; i++)
        ht[i] = -1;

    while (1) {
        printf("\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter key: ");
            scanf("%d", &key);
            index = key % SIZE;

            while (ht[index] != -1)
                index = (index + 1) % SIZE;

            ht[index] = key;
            printf("Inserted\n");
        }

        else if (ch == 2) {
            printf("Enter key: ");
            scanf("%d", &key);
            index = key % SIZE;
            start = index;

            while (ht[index] != -1) {
                if (ht[index] == key) {
                    printf("Found\n");
                    break;
                }
                index = (index + 1) % SIZE;
                if (index == start)
                    break;
            }
            if (ht[index] != key)
                printf("Not Found\n");
        }

        else if (ch == 3) {
            printf("Enter key: ");
            scanf("%d", &key);
            index = key % SIZE;
            start = index;

            while (ht[index] != -1) {
                if (ht[index] == key) {
                    ht[index] = -1;
                    printf("Deleted\n");
                    break;
                }
                index = (index + 1) % SIZE;
                if (index == start)
                    break;
            }
            if (ht[index] != -1)
                printf("Not Found\n");
        }

        else if (ch == 4) {
            for (i = 0; i < SIZE; i++) {
                if (ht[i] == -1)
                    printf("[%d] : EMPTY\n", i);
                else
                    printf("[%d] : %d\n", i, ht[i]);
            }
        }

        else if (ch == 5)
            return 0;

        else
            printf("Invalid choice\n");
    }
}