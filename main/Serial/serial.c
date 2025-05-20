#include "serial.h"
#include "serial_config.h"
#include <stdio.h>
#include <stdarg.h>

void serial_write(const char *str, ...) {
#if SERIAL_DEBUG_API
    va_list args;
    va_start(args, str);
    vprintf(str, args);
#else
    (void)str;
#endif
}
