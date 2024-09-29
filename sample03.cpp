#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Відкриття або створення файлу для запису
    ofstream outFile("example_cpp02.txt");
    if (!outFile.is_open()) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }

    // Запис даних у файл
    outFile << "Привіт, 36 група!" << endl;
    
    // Закриття файлу після запису
    outFile.close();

    // Відкриття файлу для читання
    ifstream inFile("example_cpp.txt");
    if (!inFile.is_open()) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return 1;
    }

    // Зчитування даних з файлу
    string line;
    while (getline(inFile, line)) {
        cout << "Прочитано: " << line << endl;
    }

    // Закриття файлу після читання
    inFile.close();

    // Відкриття файлу для дозапису
    ofstream appendFile("example_cpp.txt", ios::app);
    if (!appendFile.is_open()) {
        cerr << "Не вдалося відкрити файл для дозапису!" << endl;
        return 1;
    }

    // Дозапис даних у файл
    appendFile << "Це рядок для дозапису у файл." << endl;
    
    // Закриття файлу після дозапису
    appendFile.close();

    return 0;
}
