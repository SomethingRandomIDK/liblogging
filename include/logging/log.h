#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <stdio.h>

typedef enum{
    TRACE,
    DEBUG,
    INFO,
    WARNING,
    ERROR
} SeverityLevel;

void initLogger(const char *, SeverityLevel);
void logMessage(const char *, SeverityLevel);
void closeLogger(void);

#endif

