#ifndef _LOGGING_H_
#define _LOGGING_H_

typedef enum{
    TRACE = 0,
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4
} SeverityLevel;

void initLogger(const char *, SeverityLevel);
void logMessage(const char *, SeverityLevel);
void closeLogger(void);

#endif

