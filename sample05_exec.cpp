#include <iostream>
#include <unistd.h>  // Для fork() та exec()

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
         cerr << "Не вдалося створити процес!" <<  endl;
        return 1;
    } else if (pid == 0) {
        // Дочірній процес виконує команду `ls`
        execlp("ls", "ls", "-l", nullptr);
         cerr << "Не вдалося виконати команду!" <<  endl;
        return 1;
    } else {
        // Батьківський процес чекає на завершення дочірнього
        wait(nullptr);
         cout << "Дочірній процес завершено." <<  endl;
    }

    return 0;
}
