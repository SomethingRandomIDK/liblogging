#ifndef _LOGGING_H_
#define _LOGGING_H_

typedef enum{
    TRACE = 0,
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4
} SeverityLevel;

int initLogger(const char *, SeverityLevel);
int logMessage(const char *, SeverityLevel);
int closeLogger(void);

#endif

