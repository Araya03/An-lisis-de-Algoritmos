//g++ -o pruebas pruebas.cpp BinaryTree.cpp BubbleSort.cpp LinkedList.cpp MergeSort.cpp SelectionSort.cpp Utils.cpp

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "Utils.h"

using namespace std;
using namespace std::chrono;

//Funciones para pruebas de algoritmos de ordenamiento
void testBubbleSort(int size) {
    vector<int> data(size);

    //Mejor caso: Datos ordenados
    iota(data.begin(), data.end(), 1);
    auto start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "BubbleSort (Mejor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Peor caso: Datos en orden inverso
    reverse(data.begin(), data.end());
    start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "BubbleSort (Peor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Caso promedio: Datos aleatorios
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    start = high_resolution_clock::now();
    bubbleSort(data.data(), size);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "BubbleSort (Caso promedio) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";
}

void testSelectionSort(int size) {
    vector<int> data(size);

    //Mejor caso: Datos ordenados
    iota(data.begin(), data.end(), 1);
    auto start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "SelectionSort (Mejor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Peor caso: Datos en orden inverso
    reverse(data.begin(), data.end());
    start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "SelectionSort (Peor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Caso promedio: Datos aleatorios
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    start = high_resolution_clock::now();
    selectionSort(data.data(), size);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "SelectionSort (Caso promedio) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";
}

void testMergeSort(int size) {
    vector<int> data(size);

    //Mejor caso: Datos ordenados
    iota(data.begin(), data.end(), 1);
    auto start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "MergeSort (Mejor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Peor caso: Datos en orden inverso
    reverse(data.begin(), data.end());
    start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "MergeSort (Peor caso) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

    //Caso promedio: Datos aleatorios
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    start = high_resolution_clock::now();
    mergeSort(data.data(), 0, size - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();
    cout << "MergeSort (Caso promedio) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";
}

//Funciones para pruebas de estructuras de datos
void testLinkedList(int size) {
    LinkedList list;

    //Mejor caso: Añadir elementos y eliminar al final
    for (int i = 0; i < size; ++i) {
        list.append(i);
    }
    auto start = high_resolution_clock::now();
    list.deleteNode(size - 1);  //Eliminar el último nodo
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "LinkedList (Eliminar al final) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";
}

void testBinaryTree(int size) {
    BinarySearchTree bst;

    //Mejor caso: Árbol balanceado con inserciones y eliminación de hojas
    for (int i = 0; i < size; ++i) {
        bst.insert(i);
    }
    auto start = high_resolution_clock::now();
    bst.deleteNode(size - 1);  //Eliminar una hoja
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "BinaryTree (Eliminar hoja) - Tamano: " << size << " Tiempo: " << duration << " microsegundos\n";

}

int main() {
    //Tamaños de prueba
    vector<int> sizes = {100, 1000, 5000};

    for (int size : sizes) {
        cout << "\nTamano: " << size << endl;
        
        //Algoritmos de ordenamiento
        testBubbleSort(size);
        testSelectionSort(size);
        testMergeSort(size);
        
        //Estructuras de datos
        testLinkedList(size);
        testBinaryTree(size);
    }

    return 0;
}