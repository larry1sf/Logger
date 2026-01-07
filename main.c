#include "logger.c"

int main() {
    int c = 0;
    while (c < 5)
    {
        c++;
        log_init("logs/app.log");
        log_message(LOG_INFO, "Logger funcionando");
        log_message(LOG_WARN, "Esto es una advertencia");
        log_message(LOG_ERROR, "Algo falló");
        log_close();
    }
    
    return 0;
}