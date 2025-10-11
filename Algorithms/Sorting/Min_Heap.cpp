#include "Min_Heap.h"
#include <iostream>

using namespace std;

void pq_swap(min_heap* q, int i, int j)
{
    swap(q->q[i], q->q[j]);
}

int pq_parent(int n)
{
    if (n == 1) {
        return -1;
    }
    return ((int) n / 2);
}

int pq_young_child(int n)
{
    return 2 * n;
}

void pq_insert(min_heap* q, int x)
{
    if (q->n >= PQ_SIZE) {
        cout << "Warning! Priority queue overflow" << endl;
    }
    else {
        q->n = (q->n) + 1;
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}

void bubble_up(min_heap* q, int p)
{
    if (pq_parent(p) == -1) return;

    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}

void pq_init(min_heap* q)
{
    q->n = 0;
}

void make_heap(min_heap* q, int s[], int n)
{
    int i;
    pq_init(q);
    for (i = 0; i < n; ++i) {
        pq_insert(q, s[i]);
    }
}

int extract_min(min_heap* q)
{
    int min = -1;

    if (q->n <= 0) {
        cout << "Warning: empty priority queue. Called from extract_min()" << endl;
    }
    else {
        min = q->q[1];

        q->q[1] = q->q[q->n];
        q->n = q->n - 1;
        bubble_down(q, 1);
    }
    return min;
}

void bubble_down(min_heap* q, int p)
{
    int c;
    int i;
    int min_index;

    c = pq_young_child(p);
    min_index = p;

    for (i = 0; i <= 1; ++i) {
        if ((c + i) <= q->n) {
            if (q->q[min_index] > q->q[c + i]) {
                min_index = c + i;
            }
        }
    }

    if (min_index != p) {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);

    }
}

void heapsort(int s[], int n)
{
    int i;
    min_heap q;

    make_heap(&q, s, n);

    for (i = 0; i < n; ++i) {
        s[i] = extract_min(&q);
    }
}

void make_heap_fast(min_heap* q, int s[], int n)
{
    int i;

    q->n = n;

    for (i = 0; i < n; ++i) {
        q->q[i + 1] = s[i];
    }

    for (i = q->n / 2; i >= 1; --i) {
        bubble_down(q, i);
    }
}
