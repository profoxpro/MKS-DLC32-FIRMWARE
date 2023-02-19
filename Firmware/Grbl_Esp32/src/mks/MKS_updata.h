#ifndef __MKS_updata_h
#define __MKS_updata_h

#include "MKS_draw_lvgl.h"

#define CFG_FILE_PATG           "/dlc_cfg.txt"
#define CFG_FILE_PATG2          "/bkg_cfg.txt"

#define CFG_FILE_CHECK_SUCCEED  "CFG is exit"
#define CFG_FILE_CHECK_FAIL     "CFG is no exit"

#define CFG_FILE_NUM            38    // Общее количество элементов конфигурации
#define CFG_FILE_MAX_LINE       128

/*
    [ESP110]STA   		//设置wifi模式, STA/AP两种，如[ESP110]STA。
    [ESP100]MAKERBASE3D 	//wifi名字， 如：[ESP100]MAKERBASE3D
    [ESP101]makerbase3d	//wifi密码，如：[ESP101]makerbase3d
*/

typedef enum{
    UD_NONE,
    UD_CHEAK,                           // Определение наличия файла обновления
    UD_HAD_FILE,                        // Есть файл обновления
    UD_NO_FILE,                         // Файл не существует, обновлять не нужно
    UD_UPDATA_ING,                      // Обновление
    UD_UPDATA_FINSH,                    // Обновление завершено
    UD_UPDATA_FAIL,                     // Сбой обновления
}UPDATA_CHECK_FLAG_T;

typedef struct {
    UPDATA_CHECK_FLAG_T updata_flag;    // Отметьте статус выполнения обновления
    uint32_t updata_cont;               // Используется для выбора первых нескольких обновлений
    uint32_t updata_line;               // Используется для обновления записи до первых нескольких строк
    uint8_t updata_persen;              // Процент обновления
    bool is_have_data_ud;               // Убедитесь, что вы прочитали данные и обновили их
    bool is_have_board_1;               // Прочитайте информацию о материнской плате 1
    bool is_have_board_2;               // Прочитайте информацию о материнской плате 2
    bool is_have_board_3;               // Прочитайте информацию о материнской плате 3
}MKS_UPDATA_T;
extern MKS_UPDATA_T mks_updata;

typedef struct {

    lv_obj_t *label_updata_title;       // Обновите название интерфейса
    lv_obj_t *label_updata_persen;      // Процент обновления
    lv_obj_t *bar_updata;               // Обновите индикатор выполнения интерфейса

}UPDATA_PAGE_T;

void mks_updata_init(void);
void mks_draw_updata(void);
void mks_updata_data(void);
void mks_cfg_find(void);
void mks_cfg_rename(const char* path1);
#endif
