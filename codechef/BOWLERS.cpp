#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i,start,end)     for(int i = start; i < end ; ++i)
#define inf                   while(true)

template<class T>
inline bool compare_float(T a ,T b) {
    return (abs(a - b) < 1e-9) ? true : false;
}

template<class T>
inline T SQ(T a) {
    return (a) * (a);
}

template<class T>
inline T CUBE(T a) {
    return (a) * (a) * (a);
}

void solution() {
    int N, K, L;
    std::cin >> N >> K >> L;
    if (K * L >= N) {
        if (K > 1) {
            int count = 0;
            for (int i = 1; i <= N / K + 1; ++i) {
                for (int j = 1; j <= K && ++count <= N ; ++j) {
                    printf("%d ", j);
               }
                // printf("count : %d\n", count);
            }
            printf("\n");
        } else {
            if (N == 1)  printf("1\n");
            else printf("-1\n");
        }
    } else {
        printf("-1\n");
    }
}

int main() {
    test solution();
    return 0;
}
























// #include <bits/stdc++.h>
// using namespace std;

// /*Prototype for utility functions */
// void printArray(int arr[], int size);
// void swap(int arr[], int fi, int si, int d);

// void leftRotate(int arr[], int d, int n) {
//     /* Return If number of elements to be rotated
//     is zero or equal to array size */
//     if (d == 0 || d == n)
//         return;

//     /*If number of elements to be rotated
//     is exactly half of array size */
//     if (n - d == d) {
//         swap(arr, 0, n - d, d);
//         return;
//     }

//     /* If A is shorter*/
//     if (d < n - d) {
//         swap(arr, 0, n - d, d);
//         leftRotate(arr, d, n - d);
//     } else /* If B is shorter*/
//     {
//         swap(arr, 0, d, n - d);
//         leftRotate(arr + n - d, 2 * d - n, d); /*This is tricky*/
//     }
// }

// /*UTILITY FUNCTIONS*/
// /* function to print an array */
// void printArray(int arr[], int size) {
//     int i;
//     for (i = 0; i < size; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// /*This function swaps d elements starting at index fi
// with d elements starting at index si */
// void swap(int arr[], int fi, int si, int d) {
//     int i, temp;
//     for (i = 0; i < d; i++) {
//         temp = arr[fi + i];
//         arr[fi + i] = arr[si + i];
//         arr[si + i] = temp;
//     }
// }

// // Driver Code
// int main() {
//     int arr[] = { 1, 2, 3, 4, 5 };
//     leftRotate(arr, 3, 5);
//     printArray(arr, 5);
//     return 0;
// }

// // This code is contributed by rathbhupendra



// void leftRotate(int arr[], int d, int n) {
//     int i, j;
//     d = d % n;
//     if (d == 0 || d == n)
//         return;
//     i = d;
//     j = n - d;
//     while (i != j) {
//         if (i < j) {
//             swap(arr, d - i, d + j - i, i);
//             j -= i;
//         } else {
//             swap(arr, d - i, d, j);
//             i -= j;
//         }
//     }
//     swap(arr, d - i, d, i);
// }
