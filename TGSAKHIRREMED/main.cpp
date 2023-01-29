#include <stdio.h>
#include <stdlib.h>

// inisialisasi struct

struct data{
    int number;
    struct data *left, *right, *height, *depth; // pointer untuk menampung percabangan kiri dan kanan dan tinggi dan kedalaman
} *root;

// fungsi push -> menambah data baru pada tree
void push(struct data **current, int number){
    // jika pointer current kosong, maka akan membuat blok data baru
    if((*current) == NULL){
        // alokasikan memori
        (*current) = (struct data *)malloc(sizeof (struct data));
        (*current)->number = number;
        (*current)->left = (*current)->right = NULL;
        // jika tidak kosong, maka akan dibandingkan apakah angka yang akan dimasukkan lebih kecil dari root.
        // jika iya, maka belok ke kiri dan lakukan rekursif terus menerus hingga kosong
    } else if(number < (*current)->number){
        push(&(*current)-> left, number);
    } else if(number >= (*current)->number){
        // jika lebih besar, maka belok ke kanan
        push(&(*current)->right, number);
    }
}

// preOrder Binary Tree Traversal --> parent/value, kiri, kanan
void preOrder(struct data **current){
    if((*current) != NULL){
        printf("%d -> ", (*current)->number);
        preOrder(&(*current)->left);
        preOrder(&(*current)->right);
    }
}

// inOrder Binary Tree Traversal --> kiri, parent/value, kanan
void inOrder(struct data **current){
    if((*current) != NULL){
        inOrder(&(*current)->left);
        printf("%d -> ", (*current)->number);
        inOrder(&(*current)->right);
    }
}

// postOrder Binary Tree Traversal --> kiri, kanan, parent/value
void postOrder(struct data **current){
    if((*current) != NULL){
        postOrder(&(*current)->left);
        postOrder(&(*current)->right);
        printf("%d -> ", (*current)->number);
    }
}

int main()
{
    push(&root, 21);
    push(&root, 13);
    push(&root, 36);
    push(&root, 8);
    push(&root, 15);
    push(&root, 6);
    push(&root, 11);
    push(&root, 18);
    push(&root, 26);
    push(&root, 17);
    push(&root, 4);

    printf("\nTampilan InOrder   : ");
    inOrder(&root);
    printf("Tampilan PreOrder  : ");
    preOrder(&root);
    printf("\nTampilan PostOrder : ");
    postOrder(&root);

    return 0;
}
