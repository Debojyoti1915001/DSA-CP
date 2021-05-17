#include <bits/stdc++.h>
using namespace std;
//Debojyoti Das
#define ll int
void bubbleSort(ll ar[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n - i - 1; j++)
        {
            if (ar[j + 1] < ar[j])
                swap(ar[j], ar[j + 1]);
        }
    }
}
void insertionSort(ll ar[], ll n)
{
    for (ll i = 1; i < n; i++)
    {
        ll j = i - 1;
        ll key = ar[i];
        while (ar[j] > key && j > -1)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}
void selectionSort(ll ar[], ll n)
{
    for (ll i = 0; i < n - 1; i++)
    {
        ll k = i;
        ll j = i + 1;
        for (ll j = i + 1; j < n; j++)
        {
            if (ar[k] > ar[j])
                k = j;
        }
        swap(ar[k], ar[i]);
    }
}
void merge(ll arr[], ll L, ll mid, ll H)
{
    ll i = L, j = mid + 1;
    ll B[H + 1];
    ll k = L;
    while (i <= mid && j <= H)
    {
        if (arr[i] <= arr[j])
        {
            B[k++] = (arr[i]);
            i++;
        }
        else if (arr[i] > arr[j])
        {
            B[k++] = (arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        B[k++] = (arr[i]);
        i++;
    }
    while (j <= H)
    {
        B[k++] = (arr[j]);
        j++;
    }
    for (ll i = L; i <= H; i++)
    {
        arr[i] = B[i];
    }
}
void rmergeSort(ll ar[], ll L, ll H)
{
    if (L < H)
    {
        ll mid = (L + H) / 2;
        rmergeSort(ar, L, mid);
        rmergeSort(ar, mid + 1, H);
        merge(ar, L, mid, H);
    }
}
void imergeSort(ll ar[], ll n)
{
    ll p;
    for (p = 2; p <= n; p = p * 2)
    {
        for (ll i = 0; i + p - 1 < n; i += p)
        {
            ll L = i, H = i + p - 1;
            ll mid = (L + H) / 2;
            merge(ar, L, mid, H);
        }
    }
    if (p / 2 < n)
        merge(ar, 0, p / 2 - 1, n - 1);
}
void mergeSort(ll ar[], ll n)
{
    imergeSort(ar, n);
}
ll partition(ll ar[], ll L, ll H)
{
    ll i = L, j = H;
    ll pivot = ar[L];
    do
    {
        do
        {
            i++;
        } while (ar[i] <= pivot);
        do
        {
            j--;
        } while (ar[j] > pivot);
        if (i < j)
            swap(ar[i], ar[j]);
    } while (i < j);
    swap(ar[L], ar[j]);
    return j;
}
void quickSort(ll ar[], ll L, ll H)
{
    ll p;
    if (L < H)
    {
        p = partition(ar, L, H);
        quickSort(ar, L, p);
        quickSort(ar, p + 1, H);
    }
}
ll maxElement(ll ar[], ll n)
{
    ll ans = -1e9;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, ar[i]);
    }
    return ans;
}
void countSort(ll ar[], ll n)
{
    ll maxEle = maxElement(ar, n);
    ll c[maxEle + 1]{};
    for (ll i = 0; i < n; i++)
    {
        c[ar[i]]++;
    }
    ll k = 0;
    for (ll i = 0; i < maxEle + 1;)
    {
        if (c[i])
        {
            ar[k++] = i;
            c[i]--;
        }
        else
            i++;
    }
}
//COPIED
int Max(int A[], int n)
{
    int max = -32768;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Linked List node
class Node
{
public:
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
    { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n)
{
    int max = Max(A, n);

    // Create bins array
    Node **bins = new Node *[max + 1];

    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete[] bins;
}

int main()
{
    ll n;
    ll ar[100];
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> ar[i];
    BinSort(ar, n);
    for (ll i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
}