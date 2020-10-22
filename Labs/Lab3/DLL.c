#include <stdio.h>
#include <stdlib.h>

//create node
struct node {
    struct node* next;
    struct node* prev;
    char value;
};


//print all node values and their pointers
void print_all(struct node* n) {
    if (n)
      printf("%c (%p) | next: %p | prev: %p\n", n->value, n, n->next, n->prev);
}

//print all node values
void print(struct node* n) {
    while (n) {
        printf("%c -> ", n->value);
        n = n->next;
    }
    printf("NULL\n");
}

//
void print_recursive(struct node* n) {
    if (n) {
        printf("%c -> ", n->value);
        print(n->next);
    } else {
        printf("NULL\n");
    }
}

//reverse the order of the nodes
struct node * reverse(struct node* n) {
    while (n) {
        struct node* ptr = n->next;
        n->next = n->prev;
        n->prev = ptr;
        if (ptr) {
            n = ptr;
        } else {
            return n;
        }
    }
    return NULL;
}

//reverse order of nodes recursvely
struct node * reverse_recursive(struct node* n) {
    if (n) {
        struct node* ptr = n->next;
        n->next = n->prev;
        n->prev = ptr;
        if (ptr) {
            return reverse(ptr);
        } else {
            return n;
        }
    }
    return NULL;
}

//creat a new node with no pointers
struct node * create_node(char value) {
    struct node* n = malloc(sizeof(struct node));
    if (n) {
        n->next = NULL;
        n->prev = NULL;
        n->value = value;
    }
    return n;
}

//delete a node
void destroy_node(struct node* n) {
    free(n);
}

//add new node to the end of the list 
struct node* append(struct node* list, struct node* n) {
    if (list) {
        if (list->next) {
            return append(list->next, n);
        } else {
            list->next = n;
            n->prev = list;
            return list;
        }
    }
    return NULL;
}

//add new node to the start of the list 
struct node* prepend(struct node* list, struct node* n) {
    return append(n, list);
}


void addAfter(struct node* list, int k, struct node* n) {
    if (list) {
        if (k - 1 > 0) {
            addAfter(list->next, k - 1, n);
        } else {
            n->next = list->next;
            n->prev = list;
            n->prev->next = n;
            n->next->prev = n;
        }
    }
}

void for_each(struct node* list, void (*f)(struct node*)) {
    if (list) {
        struct node* next = list->next;
        if (next) {
            f(list);
            for_each(next, f);
        }
    }
}

//delete the whole list
void destroy_list(struct node* list) {
    for_each(list, destroy_node);
}

void find_cycle(struct node* list) {
    struct node* slow_ptr = list;
    struct node* fast_ptr = list;
    while (fast_ptr != NULL) {
        fast_ptr = fast_ptr->next;
        if (fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }

        if (fast_ptr == slow_ptr) {
            printf("Cycle detected\n");
            return;
        }
    }
    printf("No cycle detected\n");
}

int main() {
    {
        struct node a = {NULL, NULL, 'A'};
        struct node b = {NULL, NULL, 'B'};
        struct node c = {NULL, NULL, 'C'};
        a.next = &b;
        b.prev = &a;
        b.next = &c;
        c.prev = &b;
        struct node* head = &a;
        print(head);
        head = reverse(head);
        print(head);
    }

    printf("\n");

    {
        struct node* aptr = create_node('a');
        struct node* bptr = create_node('b');
        struct node* cptr = create_node('c');
        struct node* head = aptr;
        append(bptr, cptr); // b -> c
        prepend(bptr, aptr); // a -> (b -> c)

        print(head);
        head = reverse(head);
        print(head);
        head = reverse(head);

        addAfter(head, 2, create_node('d'));
        print(head);

        destroy_list(head);
    }

    printf("\n");

    {
        struct node* list = append(create_node('x'),
                                   append(create_node('y'),
                                          create_node('z')));
        print(list);

        find_cycle(list);
        append(list, list);
        find_cycle(list);
        // print(list); // don't! will not finish

        destroy_list(list);
    }
}
