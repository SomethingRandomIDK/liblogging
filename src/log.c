#include <logging/log.h>

static FILE *logOut = stdout;
static SeverityLevel minLevel = TRACE;

void initLogger(const char *filename, SeverityLevel minimumLevel) {
    if (filename)
        logOut = fopen(filename, "a");

    minLevel = minimumLevel;
}

void logMessage(const char *msg, SeverityLevel level) {
}

void closeLogger(void) {
    if (logOut != stdout) {
        fclose(logOut);
        logOut = stdout;
    }
}

