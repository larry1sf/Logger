#define MAX_FILE 4.0f
typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DEBUG
} log_level_t;

void log_init(const char *filename);
void log_message(log_level_t level, const char *message);
void log_close();
