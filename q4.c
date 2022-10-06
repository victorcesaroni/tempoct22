/**
 * Q4
 * Dada uma array de k , lista lincada “listas”, cada lista esta em ordem ascendente.
Mergear as listas lincadas em uma única lista em ordem ascendente.
Input: listas = [[1,3,8],[1,3,6],[8,9]]
output: [1,1,3,3,6,8,8,9]
listas = [ ]
output = [ ]
listas = [ [ ] ]
output = [ ]
struct ListaNode* mergeKListas(struct ListNode** listas, int listasSize){}
*/

    // TODO: finish me


#include <stdio.h>
#include <math.h>

typedef struct ListNode_t {
    int val;
    struct ListNode_t* next;
} ListNode;

typedef struct Lista_t {
    int size;
    struct ListNode_t* nodes;
} Lista;

ListNode** nextFreeNodePointerAddr(Lista* lista) {
    ListNode** pListNode = &lista->nodes;
    while ((*pListNode) != NULL) {
        pListNode = &(*pListNode)->next;
    }
    return pListNode;
}

ListNode** mergeLista(Lista* output, Lista* lista) {
    ListNode** pOutputNode = nextFreeNodePointerAddr(output);
    (*pOutputNode) = lista->nodes;
    output->size += lista->size;
    return nextFreeNodePointerAddr(output);
}

ListNode** mergeKListas(Lista* output, Lista* listas, int numListas) {
    for (int i = 0; i < numListas; i++) {
        mergeLista(output, &listas[i]);
    }
}

ListNode* addNode(Lista* lista, int val) {
    ListNode** pListNode = nextFreeNodePointerAddr(lista);
    (*pListNode) = malloc(sizeof(ListNode));
    (*pListNode)->next = NULL;
    (*pListNode)->val = val;
    lista->size++;
    return (*pListNode);
}

int main()
{
    int numListas = 3;
    Lista* listas = (Lista*)malloc(sizeof(Lista) * numListas);
    for (int i = 0; i < numListas; i++) {
        listas[i].size = 0;
        listas[i].nodes = NULL;
    }
    Lista* output = (Lista*)malloc(sizeof(Lista) * 1);
    output->size = 0;
    output->nodes = NULL;

    addNode(&listas[0], 1);
    addNode(&listas[0], 3);
    addNode(&listas[0], 8);
    
    addNode(&listas[1], 1);
    addNode(&listas[1], 3);
    addNode(&listas[1], 6);
    
    addNode(&listas[2], 8);
    addNode(&listas[2], 9);

    mergeKListas(output, listas, numListas);
    
    ListNode** pListNode = &output->nodes;
    while ((*pListNode) != NULL) {
        printf("%d, ", (*pListNode)->val);
        pListNode = &(*pListNode)->next;
    }

    return 0;
}


