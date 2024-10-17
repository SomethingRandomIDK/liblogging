# liblogging

A simple thread safe logging library in C.

## Installation

**This is currently only compatible with Linux**

1. Clone the repository

    ```
    git clone https://github.com/SomethingRandomIDK/liblogging.git
    ```

2. Enter the git repository

    ```
    cd liblogging
    ```

3. Build the library

    ```
    sudo make install
    ```

## Example

This is a simple program showing all the logging levels.

```c
#include <logging/log.h>

int main() {
    initLogger(NULL, TRACE);

    logMessage("The logger has started", INFO);
    
    logMessage("This is TRACE log", TRACE);
    logMessage("This is DEBUG log", DEBUG);
    logMessage("This is INFO log", INFO);
    logMessage("This is WARNING log", WARNING);
    logMessage("This is ERROR log", ERROR);

    logMessage("The logger is now closing", INFO);

    closeLogger();
    
    return 0;
}
```

Compiling the program:

```
gcc main.c -llogging
```

## Using the Library

To use the library you would first need to include log.h file in your code with
```c
#include <logging/log.h>
```

To properly compile the program you will have to add the -llogging linker flag
when you are compiling.

### Available Functions

```c
int initLogger(const char *filename, LoggingLevel minimumLevel);
```

This function initializes the logger.  The **filename** is the name of the file
where the logs should be saved.  If the **filename** is set to NULL then the
logger will output the logs to stdout.  The **minimumLevel** is the lowest level
of logs which will be recorded. Setting this to TRACE will ensure that all logs
are recorded.

```c
int logMessage(const char *msg, LoggingLevel level);
```

This function logs a message.  The **msg** is the message to be logged.  The
**level** is the logging level of this message.  If the **level** is below the
minimum level specified in the initLogger() then the message will not be
written.

```c
int closeLogger(void);
```

This function

