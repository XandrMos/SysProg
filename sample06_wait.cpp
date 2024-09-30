#include <iostream>
#include <unistd.h>  // Для fork() та wait()

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
         cerr << "Не вдалося створити процес!" <<  endl;
        return 1;
    } else if (pid == 0) {
        // Дочірній процес
        sleep(10);  // Імітація роботи
         cout << "Дочірній процес завершився." <<  endl;
    } else {
        // Батьківський процес чекає
        int status;
        wait(&status);
         cout << "Батьківський процес: дочірній процес завершився з кодом: " << status <<  endl;
    }

    return 0;
}
