#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    double weight; // Weight
    int parent, lc, rc; // Parent node, left child, right child index
} HuffmanNode;

HuffmanNode huffmanTree[MAX_SIZE];
int size = 0;

// Create Huffman Tree
void CreateHuffmanTree(double weights[], int n) {
    int m = 2 * n - 1;
    for (int i = 1; i <= m; ++i) {
        huffmanTree[i].weight = (i <= n) ? weights[i - 1] : 0;
        huffmanTree[i].parent = huffmanTree[i].lc = huffmanTree[i].rc = -1;
    }
    for (int i = n + 1; i <= m; ++i) {
        int s1 = -1, s2 = -1;
        // Choose the two nodes with the smallest weights
        for (int j = 1; j < i; ++j) {
            if (huffmanTree[j].parent == -1) {
                if (s1 == -1) {
                    s1 = j;
                } else if (huffmanTree[j].weight < huffmanTree[s1].weight) {
                    s2 = s1;
                    s1 = j;
                } else if (s2 == -1 || huffmanTree[j].weight < huffmanTree[s2].weight) {
                    s2 = j;
                }
            }
        }
        huffmanTree[i].lc = s1;
        huffmanTree[i].rc = s2;
        huffmanTree[i].weight = huffmanTree[s1].weight + huffmanTree[s2].weight;
        huffmanTree[s1].parent = huffmanTree[s2].parent = i;
    }
    size = m;
}

// Pre-order traversal
void PreorderTraversal(int index) {
    if (index == -1) return;
    printf("%.2lf ", huffmanTree[index].weight);
    PreorderTraversal(huffmanTree[index].lc);
    PreorderTraversal(huffmanTree[index].rc);
}

// In-order traversal
void InorderTraversal(int index) {
    if (index == -1) return;
    InorderTraversal(huffmanTree[index].lc);
    printf("%.2lf ", huffmanTree[index].weight);
    InorderTraversal(huffmanTree[index].rc);
}

// Post-order traversal
void PostorderTraversal(int index) {
    if (index == -1) return;
    PostorderTraversal(huffmanTree[index].lc);
    PostorderTraversal(huffmanTree[index].rc);
    printf("%.2lf ", huffmanTree[index].weight);
}


int main() {
    double weights[] = {0.05, 0.15, 0.40, 0.30, 0.10}; // Weights of the score segments
    int n = sizeof(weights) / sizeof(weights[0]);
    CreateHuffmanTree(weights, n);
    
    printf("Huffman Tree Preorder Traversal:\n");
    PreorderTraversal(size);
    printf("\n");
    
    printf("Huffman Tree Inorder Traversal:\n");
    InorderTraversal(size);
    printf("\n");
    
    printf("Huffman Tree Postorder Traversal:\n");
    PostorderTraversal(size);
    printf("\n");
    
    return 0;
}

