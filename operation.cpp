#include "list.h"
#include "operation.h"


void insert_sorted(List &L, infotype x) {
    /**
     * IS : List may be empty[cite: 9]
     * PR : insert an infotype x into an already sorted List L[cite: 9]
     *      so that the elements inside List L is still sorted in ascending order,[cite: 9]
     *      procedure must also check if such number is already exists (No Duplicate number),[cite: 9]
     *      allocate new element only if the conditions are met[cite: 9]
     * FS : elements in List L sorted in ascending order, x is inside List L[cite: 9]
     */

    address searchResult = findElm(L, x);
    if (searchResult != NULL) {
        return;
    }

    address P = allocate(x);
    if (P == NULL) {
        return;
    }

    if (first(L) == NULL || info(first(L)) > x) {
        insertFirst(L, P);
        return;
    }

    address Q = first(L);
    while (next(Q) != NULL && info(next(Q)) < x) {
        Q = next(Q);
    }

    insertAfter(L, Q, P);
}
