#pragma once
#define PQ_SIZE 100

typedef struct {
	int q[PQ_SIZE + 1];
	int n;
} min_heap;

// heaps and constructing heaps
void pq_swap(min_heap* q, int i, int j);
int pq_parent(int n);
int pq_young_child(int n);
void pq_insert(min_heap* q, int x);
void bubble_up(min_heap* q, int p);
void pq_init(min_heap* q);
void make_heap(min_heap* q, int s[], int n);

//extracting min
int extract_min(min_heap* q);
void bubble_down(min_heap* q, int p);
void heapsort(int s[], int n);
void make_heap_fast(min_heap* q, int s[], int n);

