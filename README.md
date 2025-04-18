# HeapSort-Visualizer-MinHeap

A step-by-step algorithm visualizer for **Heap Sort using a Min Heap**. This project visually demonstrates the sorting process in the console, highlights operations, and helps users understand the internal workings of Heap Sort through a tree-based view and delay-driven animation.

---

## 📌 Features

- ✅ Manual user input of any size  
- ✅ Visual representation of the Min Heap as a tree  
- ✅ One-second fixed delay between steps  
- ✅ Highlights current comparisons and swaps  
- ✅ Displays total number of comparisons and swaps  
- ✅ Compatible with **Windows** and **macOS**  
- ✅ Built using **C++**, no external libraries required  

---

## 🚀 How to Run

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/HeapSort-Visualizer-MinHeap.git
   cd HeapSort-Visualizer-MinHeap
   ```

2. **Compile the Program:**
   ```bash
   g++ -std=c++11 -o heap_visualizer main.cpp
   ```

3. **Run the Executable:**
   ```bash
   ./heap_visualizer
   ```

   > On Windows, you might use `heap_visualizer.exe` instead.

---

## 🖼 Sample Output

```
Enter the number of elements: 5
Enter element 1: 23
Enter element 2: 12
...

Min Heap Tree:
        12
      /    \
    23      45
   /  \
 78   99

Swapping 12 and 99...
...

Total Comparisons: 12
Total Swaps: 9
```

---

## 🧠 Educational Value

This project is part of an academic assignment to help students visualize and better understand the step-by-step behavior of Heap Sort using a Min Heap structure. Great for classroom demos and self-learning!

---

## 📄 License

This project is open-source and free to use for learning purposes.

---

## 🙌 Acknowledgments

Inspired by algorithm visualizer projects and C++ sorting techniques covered in class.
