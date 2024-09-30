#include <iostream>
#include <unistd.h>  // Для fork()

using namespace std;

int main() {
    pid_t pid = fork();  // Створюємо новий процес

    if (pid < 0) {
        cerr << "Не вдалося створити процес!" <<  endl;
        return 1;  // Помилка
    } else if (pid == 0) {
        // Код дочірнього процесу
        cout << "Це дочірній процес з PID: " << getpid() <<  endl;
    } else {
        // Код батьківського процесу
        cout << "Це батьківський процес з PID: " << getpid() <<  endl;
    }

    return 0;
}
