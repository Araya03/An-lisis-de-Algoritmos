# Analisis-de-Algoritmos

La finalidad de esta tarea es comparar los tiempos de ejecución empíricos con respecto a los tiempos de ejecución teóricos en las operaciones básicas de estructuras de datos y algoritmos de ordenamiento.

Los archivos de código que se encuentran en la carpeta "Tarea Extraclase 2" son la implementación básica de BubbleSort, SelectionSort, MergeSort, LinkedList y Binary Search Tree. Además, se realizó un archivo llamado "pruebas.cpp" que contiene algunas comprobaciones del funcionamiento del código y se ejecuta de la siguiente manera:

1. En la terminal se escribe "g++ -o -NOMBRE DESEADO- pruebas.cpp BinaryTree.cpp BubbleSort.cpp LinkedList.cpp MergeSort.cpp SelectionSort.cpp Utils.cpp".
2. Luego se debe escribir "./-NOMBRE SELECCIONADO ANTERIORMENTE-".

   Esto ejecutará el archivo y mostrará en consola la información recolectada.

Sin embargo, para observar el comportamiento de manera gráfica (tiempo de ejecución en función de la cantidad de elementos) de los diferentes algoritmos y estructuras de datos, se deben seguir los siguientes pasos:

1. Abrir la carpeta "Tarea2" en Qt Creator (dicha carpeta se encuentra dentro de la carpeta "Tarea Extraclase 2").
![1](https://github.com/user-attachments/assets/dbc56c28-0892-4c85-a233-a055a5f3d544)

2. Ejecutar el código.
![2](https://github.com/user-attachments/assets/ee25fa2a-f117-4c19-9f1e-9d576557d059)


   Esto creará diferentes ventanas donde se muestran gráficas con el mejor caso, peor caso y caso promedio de cada algoritmo y estructura. Cada uno fue comparado con el caso teórico correspondiente.

Un ejemplo de las gráficas realizadas es el siguiente:

![Screenshot (317)](https://github.com/user-attachments/assets/22081adc-6e80-4817-b337-3aba3b9f6777)



El archivo "test.cpp" que se encuentra dentro de la carpeta "Tarea2" fue creado para realizar las pruebas de mejor, peor y caso promedio que se encuentran graficadas. Además, contiene el valor teórico de cada caso.
