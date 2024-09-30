#include <iostream>
#include <pthread.h>

using namespace std;

// Функція, яка буде виконуватись в потоці
void* threadFunction(void* arg) {
    cout << "Потік працює!" << endl;
    return nullptr;
}

int main() {
    pthread_t thread;  // Оголошуємо змінну для потоку

    // Створюємо новий потік
    if (pthread_create(&thread, nullptr, threadFunction, nullptr) != 0) {
        cerr << "Не вдалося створити потік!" << endl;
        return 1;
    }

    // Очікуємо завершення потоку
    pthread_join(thread, nullptr);

    cout << "Головний потік завершив роботу" << endl;
    return 0;
}
