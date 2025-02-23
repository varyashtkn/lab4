#include <iostream>
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    int size;
    cout << "Введите длину массива: ";
    cin >> size; 
    int* m = new int[size]; // Использование динамического выделения памяти для массива
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> m[i];
    }
    int k; // Индекс для начала вывода
    cout << "Введите индекс K: ";
    cin >> k;
    cout << "Вывод значений справа налево начиная с K: ";
    for (int j = 0; j < size; j++) {
        int index = (k - j + size) % size; // Индекс справа налево и с учетом цикличности
        cout << m[index] << " ";
    }
    cout << endl;    
    int* copyM = new int[size]; // Создаем копию массива m, который будет модифицироваться дальше
    for (int i = 0; i < size; i++) {
        int index = (k - i + size) % size;
        copyM[i] = m[index];
    }
    // 2. Добавление первого и последнего элементов к *копии* массива
    int newSize = size + 2;
    int* newM = new int[newSize]; // Создаем новый массив большего размера
    for (int j = 0; j < size; j++) {
        newM[j] = copyM[j];
    }
    newM[size] = m[0]; // Первый элемент исходного массива добавляется в конец
    newM[size + 1] = m[size - 1]; // Последний элемент исходного массива добавляется в конец
    cout << "Массив после добавления первого и последнего элементов: ";
    for (int j = 0; j < newSize; j++) {
        cout << newM[j] << " ";
    }
    cout << endl;
    // 3. Удаление нечетных элементов (определяем размер массива четных элементов)
    int evenCount = 0;
    for (int j = 0; j < newSize; j++) {
        if (newM[j] % 2 == 0) {
            evenCount++;
        }
    }
    int* evenM = new int[evenCount]; // Новый массив только для четных
    int currentIndex = 0;
    for (int j = 0; j < newSize; j++) {
        if (newM[j] % 2 == 0) {
            evenM[currentIndex] = newM[j];
            currentIndex++;
        }
    }
    cout << "Массив после удаления нечетных элементов: ";
    for (int j = 0; j < evenCount; j++) {
        cout << evenM[j] << " ";
    }
    cout << endl;    
    delete[] m;
    delete[] copyM;
    delete[] newM;
    delete[] evenM;
    return 0;
}

