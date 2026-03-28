// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:06.

#ifndef PBM_SYSTEM_H
#define PBM_SYSTEM_H
void system_init();
void system_cls();
void system_pause();
void system_tip(const char * msg);
void system_ask(const char * msg);
void system_split();
void system_fun_start();
unsigned system_get_op_id(unsigned min, unsigned max);
char *system_get_line(char *buf);
#endif // PBM_SYSTEM_H
