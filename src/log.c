#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <logging/log.h>

static FILE *logOut = NULL;
static SeverityLevel minLevel = TRACE;
static pthread_mutex_t lock;

void initLogger(const char *filename, SeverityLevel minimumLevel) {
    if (filename)
        logOut = fopen(filename, "a");
    else
        logOut = stdout;

    if(pthread_mutex_init(&lock, NULL) < 0)
        printf("Mutex initialization failed.\n");

    minLevel = minimumLevel;
}

static const char* levelMsgs[] = {
    [TRACE] = "[TRACE] ",
    [DEBUG] = "[DEBUG] ",
    [INFO] = "[INFO] ",
    [WARNING] = "[WARNING] ",
    [ERROR] = "[ERROR] "
};

void logMessage(const char *msg, SeverityLevel level) {
    if (level < minLevel)
        return;
    if (!logOut){
        printf("Logger has not been initialized.\n");
        return;
    }

    if (pthread_mutex_lock(&lock) < 0)
        printf("Mutex lock failed\n");
    size_t buffLen = strlen(levelMsgs[level]) + strlen(msg) + 1;
    char *buff = (char *)malloc(sizeof(char) * buffLen);
    buff[0] = 0;

    strcat(buff, levelMsgs[level]);
    strcat(buff, msg);
    fputs(buff, logOut);

    if (pthread_mutex_unlock(&lock) < 0)
        printf("Mutex unlock failed.\n");
}

void closeLogger(void) {
    if (!logOut) {
        printf("Logger has not been initialized.\n");
        return;
    }

    if (logOut != stdout) {
        fclose(logOut);
        logOut = stdout;
    }

    if (pthread_mutex_destroy(&lock) < 0)
        printf("Mutex destroy failed.\n");
}

