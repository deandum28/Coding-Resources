// Sorting Algo

int N, A[N], B[N];
void merge_sort(int l, int r)
{
    int m = (l + r) >> 1, i, j, k;
    if (l == r) return;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for (i=l, j=m+1, k=l; i<=m || j<=r; )
        if (j > r || (i <= m && A[i] < A[j]))
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    for (k = l; k <= r; k++) A[k] = B[k];
}

void bubble_sort(int list[], int size)
{
    int temp;
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
        {
            if(list[j]<list[j-1])
            {
                temp=list[j-1];
                list[j-1]=list[j];
                list[j]=temp;
            }
        }
    }
}

void insertion_sort(int list[], int size)
{
    for(int j=1;j<size;j++)
    {
        int key=list[j];
        int i = j-1;
        while(i>-1 and list[i]>key)
        {
            list[i+1]=list[i];
            i=i-1;
        }
        list[i+1]=key;

    }
}

// Heap
class heap
{
    public:
        int *nodes;
        int length;
        int heap_size;
};

void max_heapify(heap list, int index)
{

        int left,right,largest,exchange_temp;

        left = LEFT(index);
        right = RIGHT(index);

        if(left <list.heap_size && list.nodes[left] > list.nodes[index])
        {
            largest = left;
        } else
        {
            largest = index;
        }

        if(right <list.heap_size && list.nodes[right] > list.nodes[largest])
        {
            largest = right;
        }


        if(largest != index)
        {
            exchange_temp = list.nodes[index];
            list.nodes[index] = list.nodes[largest];
            list.nodes[largest] = exchange_temp;
            max_heapify(list, largest);
        }

}

void build_max_heap(heap list)
{
    list.heap_size = list.length;
    for(int i = floor(list.length/2); i>=0; i--)
    {
        max_heapify(list, i);
    }
}

void heap_sort(int list[], int size)
{
    int exchange_temp;
    heap tempheap;
    tempheap.length = size;
    tempheap.nodes = list;
    tempheap.heap_size = size;
    build_max_heap(tempheap);


    for(int i= tempheap.length - 1; i>=1; i--)
    {
        exchange_temp = tempheap.nodes[0];
        tempheap.nodes[0] = tempheap.nodes[i];
        tempheap.nodes[i] = exchange_temp;
        tempheap.heap_size = tempheap.heap_size - 1;

        max_heapify(tempheap,0);
    }

}
//////

void quicksort_aux(int list[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = partition(list, p, r);
        quicksort_aux(list, p, q-1);
        quicksort_aux(list, q+1, r);
    }
}

void quick_sort(int list[], int size)
{
    quicksort_aux(list,0, size-1);
}

// Radix sort

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
////////////