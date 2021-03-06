#include <libc.h>

#include "log.h"
#include "int.h"
#include "uart.h"

PRIVATE u32 default_log_level = LOG_INFO;
PRIVATE char log_buf[LOG_BUF_SIZE] = {0};

PUBLIC s32 set_log_level(u32 log_level)
{
    if ((log_level >= LOG_EMG) && (log_level <= LOG_DEBUG)) {
        default_log_level = log_level;
        return OK;
    } else {
        return EINVAL;
    }
    return 0;
}

PUBLIC s32 log(u32 log_level, const char *format, ...)
{
    va_list args;
    if (log_level <= default_log_level) {
        /*lock_irq(); */
        va_start(args,format);
        vsnprintf(log_buf,sizeof(log_buf), format, args);
        va_end(args);
        uart_puts(log_buf);
        /*unlock_irq();*/
    }

    return OK;
}
