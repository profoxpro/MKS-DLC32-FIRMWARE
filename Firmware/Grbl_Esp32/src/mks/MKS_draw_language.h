#ifndef __mks_draw_language_h
#define __mks_draw_language_h

#include "MKS_draw_lvgl.h"
#include "MKS_LVGL.h"


typedef struct {

    lv_obj_t *imgbtn_back;
    lv_obj_t *imgbtn_simple_cn;         // Упрощенный китайский
    lv_obj_t *imgbtn_en;                // английский язык
    lv_obj_t *imgbtn_de;                // немецкий язык

    lv_obj_t *label_back;
    lv_obj_t *label_simple_cn;         // Упрощенный китайский
    lv_obj_t *label_en;                // английский язык
    lv_obj_t *label_de;                // немецкий язык


}LANGUAGE_PAGE_T;


typedef struct {

    /* публичный */
    const char *back;
    const char *yes;
    const char *no;

    /* главная страница */
    const char *control;
    const char *sculpture;
    const char *tool;
    const char *Mpos;
    const char *Wpos;

    const char *wifi_connect;
    const char *wifi_disconnect;

    /* Интерфейс управления */
    const char *xy_clear;
    const char *z_clear;
    const char *knife;
    const char *next;
    const char *up;
    const char *cooling;
    const char *position;
    const char *speed_high;
    const char *speed_mid;
    const char *speed_low;
    const char *spindle;
    const char *carve;

    /* Файловый интерфейс */
    const char *dis_no_sd_card;

    /* Интерфейс гравировки */
    const char *hold;
    const char *cycle;
    const char *stop;
    const char *adjust;
    const char *spindle_speed;
    const char *feed_rate;
    const char *rapid_speed;
    const char *carve_times;
    
    
    /* Незамедлительный */
    const char *dis_stop_print;
    const char *dis_homing;
    const char *dis_no_hard_homing;
    const char *dis_homing_succeed;
    const char *dis_homing_fail;
    const char *dis_probe_set;
    const char *dis_probe_succeed;
    const char *dis_probe_fail;
}mc_lg_muilt_t;
extern mc_lg_muilt_t mc_language;

void mc_language_init(void);
void draw_language(void);
void mks_clear_language(void);
#endif
