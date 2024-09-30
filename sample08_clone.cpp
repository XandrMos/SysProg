#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>

using namespace std;

int childFunction(void* arg) {
     cout << "Дочірній процес працює з PID: " << getpid() <<  endl;
    return 0;
}

int main() {
    const int stackSize = 1024 * 1024; // Розмір стеку для дочірнього процесу
    char* stack = new char[stackSize];

    // Створення нового процесу
    pid_t pid = clone(childFunction, stack + stackSize, SIGCHLD, nullptr);
    
    if (pid < 0) {
         cerr << "Не вдалося створити процес!" <<  endl;
        return 1;
    }

     cout << "Батьківський процес працює з PID: " << getpid() <<  endl;
    wait(nullptr); // Чекаємо на завершення дочірнього процесу
    delete[] stack; // Звільняємо стек

    return 0;
}
//g++ -std=gnu++11 -o clone_example clone_example.cpp
