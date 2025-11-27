#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int parent[MAX];
int rank[MAX];

void makeSet(int x) {
    if (parent[x] != -1) {
        printf("\nElement %d is already in the set\n", x);
        return;
    }
    parent[x] = x;
    rank[x] = 0;
    printf("\nSet created for element %d\n", x);
}

int findSet(int x) {
    if (parent[x] == -1) {
        printf("\nElement %d is not in any set\n", x);
        return -1;
    }
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int repX = findSet(x);
    int repY = findSet(y);

    if (repX == -1 || repY == -1) return;

    if (repX != repY) {
        if (rank[repX] > rank[repY]) {
            parent[repY] = repX;
        } else if (rank[repX] < rank[repY]) {
            parent[repX] = repY;
        } else {
            parent[repY] = repX;
            rank[repX]++;
        }
        printf("\nSets containing %d and %d have been merged\n", x, y);
    } else {
        printf("\nElements %d and %d are already in the same set\n", x, y);
    }
}

void displaySets(int n) {
    printf("\n
