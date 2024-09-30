#include <iostream>
#include <thread>  // Для std::thread
#include <mutex>   // Для std::mutex

using namespace std;

mutex mtx;  // Ініціалізація м'ютекса
int sharedCounter = 0;

void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx);  // Блокуємо м'ютекс
        sharedCounter++;
    }
}

int main() {
    thread thread1(incrementCounter);
    thread thread2(incrementCounter);

    // Очікуємо завершення потоків
    thread1.join();
    thread2.join();

    cout << "Значення лічильника: " << sharedCounter << endl;
    return 0;
}
