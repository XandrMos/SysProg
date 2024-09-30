#include <iostream>
#include <unistd.h>  // Для fork(), kill()
#include <signal.h>  // Для SIGKILL

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
         cerr << "Не вдалося створити процес!" <<  endl;
        return 1;
    } else if (pid == 0) {
        // Дочірній процес
        while (true) {
             cout << "Дочірній процес працює з PID: " << getpid() <<  endl;
            sleep(1);
        }
    } else {
        // Батьківський процес
        sleep(5); // Зачекаємо 5 секунд
        kill(pid, SIGKILL); // Завершуємо дочірній процес
         cout << "Батьківський процес завершив дочірній процес." <<  endl;
    }

    return 0;
}
