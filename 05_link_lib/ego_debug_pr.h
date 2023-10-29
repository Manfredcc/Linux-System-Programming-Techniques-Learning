#ifndef __EGO_DEBUG_PR_H__
#define __EGO_DEBUG_PR_H__

typedef enum {
    EMERG,
    ERR,
    WARN,
    INFO,
    DEBUG,
    LOG_LEVEL_MAX,
}LOG_LEVEL;

#define SWITCH  1   /* global switch */
#define CUR_LOG_LEVEL   DEBUG

#define ego_print(level, fmt, ...)  \
    do {                \
            if (SWITCH && level <= CUR_LOG_LEVEL) {   \
                printf("%s:%s " fmt, __FILE__,      \
                    __func__, ##__VA_ARGS__);       \
            }                                       \
        } while (0)

#define ego_emerg(fmt, ...)     \
            ego_print(EMERG, fmt, ##__VA_ARGS__)

#define ego_err(fmt, ...)   \
            ego_print(ERR, fmt, ##__VA_ARGS__)

#define ego_warn(fmt, ...)   \
            ego_print(WARN, fmt, ##__VA_ARGS__)

#define ego_info(fmt, ...)   \
            ego_print(INFO, fmt, ##__VA_ARGS__)

#define ego_debug(fmt, ...)   \
            ego_print(DEBUG, fmt, ##__VA_ARGS__)

void ego_pr_help(void);
#endif /* __EGO_DEBUG_PR_H__ */