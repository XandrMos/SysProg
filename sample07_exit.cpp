#include <iostream>
#include <unistd.h>  // Для fork() та exit()

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
         cerr << "Не вдалося створити процес!" <<  endl;
        return 1;
    } else if (pid == 0) {
        // Дочірній процес
         cout << "Дочірній процес завершується." <<  endl;
        exit(0);  // Код завершення 0
    } else {
        // Батьківський процес
        wait(nullptr);
         cout << "Батьківський процес завершує роботу." <<  endl;
    }

    return 0;
}
