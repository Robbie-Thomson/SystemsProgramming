#include <stdio.h>
#include <string.h>

struct name {
    char first_name[10+1];
    char second_name[10+1];
};

void bubble_sort (struct name *a, int n) {
    int i, j = n, s = 1;
    struct name t;
    while (s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (strcmp(a[i].second_name, a[i - 1].second_name) < 0) {
                strncpy(t.first_name, a[i].first_name, 10);
                strncpy(t.second_name, a[i].second_name, 10);
                strncpy(a[i].first_name, a[i-1].first_name, 10);
                strncpy(a[i].second_name, a[i-1].second_name, 10);
                strncpy(a[i-1].first_name, t.first_name, 10);
                strncpy(a[i-1].second_name, t.second_name, 10);
                // directly copying the structs also works, because our strings store the
                // characters inside the struct (and not externally on thee heap).
                // t = a[i];
                // a[i] = a[i - 1];
                // a[i - 1] = t;

                s = 1;
            }
        }
        j--;
    }
}

int main() {
    struct name names [4];
    for (int i = 0; i < 4; i++) {
        printf("Enter first name: ");
        scanf("%10s", names[i].first_name);
        printf("Enter second name: ");
        scanf("%10s", names[i].second_name);
    }

    bubble_sort(names, 4);

    for (int i = 0; i < 4; i++) {
        printf("%s %s\n", names[i].first_name, names[i].second_name);
    }
}