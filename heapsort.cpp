#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void clearScreen() {
    system(CLEAR);
}

void wait() {
    this_thread::sleep_for(chrono::seconds(1));
}

int comparisons = 0;
int swaps = 0;

void printHeapTree(const vector<int>& heap, int highlight = -1) {
    int n = heap.size();
    int levels = log2(n) + 1;

    cout << "\nHeap Visualization (Min Heap as Tree):\n";
    int index = 0;
    for (int i = 0; i < levels; ++i) {
        int nodes = pow(2, i);
        int spacing = pow(2, levels - i);
        cout << string(spacing, ' ');

        for (int j = 0; j < nodes && index < n; ++j) {
            if (index == highlight)
                cout << "[" << heap[index] << "]" << string(spacing * 2, ' ');
            else
                cout << " " << heap[index] << " " << string(spacing * 2, ' ');
            ++index;
        }
        cout << "\n\n";
    }
}

void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (heap[left] < heap[smallest]) {
            smallest = left;
        }
    }

    if (right < n) {
        comparisons++;
        if (heap[right] < heap[smallest]) {
            smallest = right;
        }
    }

    if (smallest != i) {
        swaps++;
        clearScreen();
        cout << "Swapping " << heap[i] << " with " << heap[smallest] << "...\n";
        swap(heap[i], heap[smallest]);
        printHeapTree(heap, smallest);
        wait();
        heapify(heap, n, smallest);
    }
}

void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        clearScreen();
        cout << "Heapifying at index " << i << "...\n";
        printHeapTree(heap, i);
        wait();
        heapify(heap, n, i);
    }
}

vector<int> heapSort(vector<int> arr) {
    vector<int> result;
    int n = arr.size();

    buildMinHeap(arr);

    for (int i = n - 1; i >= 0; --i) {
        clearScreen();
        cout << "Extracting min: " << arr[0] << "\n";
        swaps++;
        swap(arr[0], arr[i]);
        printHeapTree(arr, 0);
        wait();
        heapify(arr, i, 0);
        result.push_back(arr[i]);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    clearScreen();

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted = heapSort(arr);

    clearScreen();
    cout << "✅ Heap Sort Completed!\n\n";
    cout << "Sorted Array (Ascending): ";
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << "\n\n";
    cout << "📊 Total Comparisons: " << comparisons << "\n";
    cout << "🔁 Total Swaps: " << swaps << "\n";

    return 0;
}
