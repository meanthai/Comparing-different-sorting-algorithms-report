#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
using namespace std;
const int inf = 1000000;

int a[inf + 50];
int L[inf + 50], M[inf + 50];

void heap_sort(int left, int right)
{
    priority_queue<int, vector<int>, greater<int>> qu;

    for(int i = left; i <= right; i++)
    {
        qu.push(a[i]);
    }

    for(int i = left; i <= right; i++)
    {
        a[i] = qu.top();
        qu.pop();
    }

    return;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


int partify (int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partify(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
void mergex(int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    mergex(l, m, r);
  }
}

void normal_sort(int l, int r)
{
    sort(a + l, a + l + r);
}

void process()
{
    for(int i = 1; i <= inf; i++)
    {
        cin >> a[i];
    }

    //mergeSort(1, inf);
    //normal_sort(1, inf);
    //heap_sort(1, inf);
    quickSort(1, inf);

    for(int i = 1; i <= inf; i++) cout << a[i] << ' ';

}

int main()
{
    freopen("number2.out.txt","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    process();
    return 0;
}
