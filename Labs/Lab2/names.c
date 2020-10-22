#include <stdio.h>
#include <string.h>

struct name {
	char first_name[16];
	char second_name[21];
};

void clean(){
	int c;

	do{
		c = getchar();
	}while (c != '\n' && c != EOF);
}




void bubble_sort () {
    
}

int main () {
	struct name names[4];
	
	for (int i = 0; i < 4; i ++){

		printf("Enter first name:");
		scanf("%15s", names[i].first_name);
		clean();
		printf("%s\n", names[i].first_name);


		printf("Enter second name:");
		scanf("%20s", names[i].second_name);
		clean();
		printf("%s\n", names[i].second_name);
	}

	//bubble_sort()
	struct name temp;
	for(int a=0;a<3;a++)
        for(int b=a+1;b<4;b++)
            if(strcmp(names[b].second_name, names[a].second_name) <0){

                strcpy(temp.first_name, names[a].first_name);
				strcpy(temp.second_name, names[a].second_name);

				strcpy(names[a].first_name, names[b].first_name);
				strcpy(names[a].second_name, names[b].second_name);

				strcpy(names[b].first_name, temp.first_name);
				strcpy(names[b].second_name, temp.second_name);
            } else if (strcmp(names[b].second_name, names[a].second_name) == 0){
				
				if(strcmp(names[b].first_name, names[a].first_name) <0){

                	strcpy(temp.first_name, names[a].first_name);
					strcpy(temp.second_name, names[a].second_name);

					strcpy(names[a].first_name, names[b].first_name);
					strcpy(names[a].second_name, names[b].second_name);

					strcpy(names[b].first_name, temp.first_name);
					strcpy(names[b].second_name, temp.second_name);
				}			
			}
	
	for(int x=0;x<4;x++) {
		printf("First name:%s\n", names[x].first_name);
		printf("Second name:%s\n\n", names[x].second_name);
    }
    return(0);
}



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