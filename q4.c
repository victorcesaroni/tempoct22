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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ListNode_t {
    int val;
    struct ListNode_t* next;
} ListNode;

typedef struct Lista_t {
    struct ListNode_t* nodes;
} Lista;

ListNode** addNode(Lista* lista, int val);
ListNode** insertNodeAfterNode(ListNode** ppListNode, int val);
ListNode** nextFreeNodePointerAddr(Lista* lista);
void mergeKListas(Lista* output, Lista* listas, int numListas);
void mergeSortedLista(Lista* output, Lista* lista);

ListNode** nextFreeNodePointerAddr(Lista* lista)
{
    ListNode** ppListNode = &(lista->nodes);

    while ((*ppListNode) != NULL) {
        ppListNode = &((*ppListNode)->next);
    }

    return ppListNode;
}

void mergeSortedLista(Lista* output, Lista* lista)
{
    ListNode* inputNode = lista->nodes;

    while (inputNode != NULL)
    {
        int val = inputNode->val;

        ListNode** ppOutputNode = &(output->nodes);
        ListNode** ppLast = ppOutputNode;
        while ((*ppOutputNode) != NULL)
        {
            if ((*ppOutputNode)->val > val) {
                break;
            }
            ppLast = ppOutputNode;
            ppOutputNode = &((*ppOutputNode)->next);
        }

        if ((*ppLast) == NULL) {
            addNode(output, val);
        } else {
            insertNodeAfterNode(ppLast, val);
        }
        
        inputNode = inputNode->next;
    }
}

void mergeKListas(Lista* output, Lista* listas, int numListas)
{
    for (int i = 0; i < numListas; i++)
    {
        mergeSortedLista(output, &listas[i]);
    }
}

ListNode** addNode(Lista* lista, int val)
{
    ListNode** ppListNode = nextFreeNodePointerAddr(lista);

    (*ppListNode) = malloc(sizeof(ListNode));
    (*ppListNode)->next = NULL;
    (*ppListNode)->val = val;

    return ppListNode;
}

ListNode** insertNodeAfterNode(ListNode** ppListNode, int val)
{
    ListNode* oldNext = (*ppListNode)->next;

    (*ppListNode)->next = malloc(sizeof(ListNode));
    (*ppListNode)->next->next = oldNext;
    (*ppListNode)->next->val = val;
    
    return ppListNode;
}

int main()
{
    int numListas = 3;

    Lista* listas = (Lista*)malloc(sizeof(Lista) * numListas);

    for (int i = 0; i < numListas; i++) {
        listas[i].nodes = NULL;
    }

    Lista* output = (Lista*)malloc(sizeof(Lista) * 1);
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
    
    printf("[ ");
    ListNode** ppListNode = &(output->nodes);    
    while ((*ppListNode) != NULL) 
    {
        printf("%d", (*ppListNode)->val);
        
        if ((*ppListNode)->next) {
            printf(", ");
        }

        ppListNode = &((*ppListNode)->next);
    }
    printf(" ]\n");

    return 0;
}


