//g++ -o pruebas test.cpp BinaryTree.cpp BubbleSort.cpp LinkedList.cpp MergeSort.cpp SelectionSort.cpp Utils.cpp

//#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "LinkedList.h"
#include "BinaryTree.h"
//#include "Utils.h"

using namespace std;
using namespace std::chrono;

long long testBubbleSort(int size) {
    vector<int> data(size);
    iota(data.begin(), data.end(), 1); // Mejor caso: Datos ordenados
    auto start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Retorna el tiempo en microsegundos
}

long long testSelectionSort(int size) {
    vector<int> data(size);
    iota(data.begin(), data.end(), 1);
    auto start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long testMergeSort(int size) {
    vector<int> data(size);
    iota(data.begin(), data.end(), 1);
    auto start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long testBubbleSortWorst(int size) {
    vector<int> data(size);
    iota(data.rbegin(), data.rend(), 1);  // Peor caso: Datos ordenados de mayor a menor
    auto start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long testSelectionSortWorst(int size) {
    vector<int> data(size);
    iota(data.rbegin(), data.rend(), 1);
    auto start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long testMergeSortWorst(int size) {
    vector<int> data(size);
    iota(data.rbegin(), data.rend(), 1);
    auto start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

// Función para medir el tiempo en microsegundos de BubbleSort en el caso promedio
long long testBubbleSortAverage(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 g(rd());
    iota(data.begin(), data.end(), 1);
    shuffle(data.begin(), data.end(), g);
    auto start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de SelectionSort en el caso promedio
long long testSelectionSortAverage(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 g(rd());
    iota(data.begin(), data.end(), 1);
    shuffle(data.begin(), data.end(), g);
    auto start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de MergeSort en el caso promedio
long long testMergeSortAverage(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 g(rd());
    iota(data.begin(), data.end(), 1);
    shuffle(data.begin(), data.end(), g);
    auto start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de LinkedList en el mejor caso
long long testLinkedListBest(int size) {
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        list.append(i);
    }
    auto start = high_resolution_clock::now();
    list.deleteNode(size - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de LinkedList en el peor caso
long long testLinkedListWorst(int size) {
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        list.append(i);
    }
    auto start = high_resolution_clock::now();
    list.deleteNode(0);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de LinkedList en el caso promedio
long long testLinkedListAverage(int size) {
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        list.append(i);
    }
    int position = size / 2;
    auto start = high_resolution_clock::now();
    list.deleteNode(position);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de BinaryTree en el mejor caso
long long testBinaryTreeBest(int size) {
    BinarySearchTree bst;
    for (int i = 0; i < size; ++i) {
        bst.insert(i);
    }
    auto start = high_resolution_clock::now();
    bst.deleteNode(size - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de BinaryTree en el peor caso
long long testBinaryTreeWorst(int size) {
    BinarySearchTree bst;
    for (int i = 0; i < size; ++i) {
        bst.insert(i);
    }
    auto start = high_resolution_clock::now();
    bst.deleteNode(0);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Función para medir el tiempo en microsegundos de BinaryTree en el caso promedio
long long testBinaryTreeAverage(int size) {
    BinarySearchTree bst;
    vector<int> values(size);
    iota(values.begin(), values.end(), 1);
    shuffle(values.begin(), values.end(), std::default_random_engine());
    for (int value : values) {
        bst.insert(value);
    }
    auto start = high_resolution_clock::now();
    bst.deleteNode(size / 2);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();  // Cambiado a return
}

// Funciones para obtener el tiempo teórico en microsegundos
long long getBubbleSortTheoretical(int size, const std::string& caseType) {
    if (caseType == "Mejor Caso") {
        return size * 10;  // Escala según la unidad
    } else if (caseType == "Peor Caso" || caseType == "Caso Promedio") {
        return size * size * 0.1;  // Escala según la unidad
    }
    return 0;
}

long long getSelectionSortTheoretical(int size, const std::string& caseType) {
    return size * size * 0.1;  // O(n^2) para todos los casos
}

long long getMergeSortTheoretical(int size, const std::string& caseType) {
    return size * log2(size) * 10;  // O(n log n)
}

long long getLinkedListTheoretical(int size, const std::string& caseType) {
    if (caseType == "Mejor Caso") {
        return 10;  // O(1) para operaciones en los extremos
    } else {
        return size * 0.1;  // O(n) para operaciones en el medio
    }
}

long long getBinaryTreeTheoretical(int size, const std::string& caseType) {
    if (caseType == "Mejor Caso") {
        return size * log2(size) * 10;  // O(log n) si el árbol está balanceado
    } else {
        return size * 0.1;  // O(n) para el peor caso
    }
}
