#ifndef __MKS_LVGL_H
#define __MKS_LVGL_H

#include "MKS_TS35.h"
#include "MKS_FREERTOS_TASK.h"
#include "MKS_ctrl.h"
#include "lvgl.h"
#include "../Serial.h"
#include "MKS_SDCard.h"


#define MKS_GRBL_CMD_SEND(A)            serila_write_into_buffer((uint8_t *)A)   

#define MKS_GRBL_WEB_CMD_SEND(A)        serial_web_input_into_buffer((uint8_t *)A)
#define MKS_GRBL_WEB_HEX_CMD_SEND(A)    serial_web_input_into_hex(A)

typedef enum {
    M_0_1_MM,           // move 0.1mm
    M_1_MM,             // move 1mm
    M_10_MM,            // move 10mm
    M_50_MM,            // move 50mm
}GRBL_MOVE_DIS;

typedef enum {
    LOW_SPEED,
    MID_SPEED,
    HIGHT_SPEED,
}GRBL_MOVE_SPEED;

typedef enum {
    English,
}GRBL_Language;

typedef enum {
    GRBL_Light_On,
    GRBL_Light_Off,
}GRBL_LIGHT_STATUS;

typedef enum {
    P_1_PERSEN,
    P_10_PERSEN,
    P_0_PERSEN,
}GRBL_POWER;

typedef enum {
    GRBL_RUN,
    GRBL_PAUSE,
    GRBL_STOP,          
    GRBL_RESTARTING,
}GRBL_RUN_STATUS_t;

typedef enum {
    BL_NONE,
    BL_BEGIN,           //Начните приспосабливаться
    BL_UP,
    BL_DOWN,
    BL_ADJ_ING,         //Регулирующий
    BL_ADJ_END,         //Окончание настройки
}BLTOUCH_STATUS;

typedef enum {
    GRBL_CNC_OFF,
    GRBL_CNC_50,
    GRBL_CNC_100,
}GRBL_CNC_PWR;


typedef struct{
    GRBL_MOVE_DIS               move_dis;           // Расстояние перемещения
    GRBL_MOVE_SPEED             move_speed;         // Скорость перемещения
    GRBL_Language               language;           // Языковые настройки
    GRBL_LIGHT_STATUS           light_status;       // Состояние освещения
    GRBL_POWER                  power_persen;       // Настройка размера шага мощности
    BLTOUCH_STATUS              bl_status;          // Рабочее состояние BLTOUCH
    GRBL_CNC_PWR                cnc_pwr;            // Настройка мощности ЧПУ
    uint16_t                    X_Pos;              // координата x
    uint16_t                    Y_Pos;              // координата y
    uint8_t                     mks_sd_status;      // Вставлена ли SD-карта, 0: SD-карта не обнаружена, 1: SD-карта обнаружена
    uint16_t                    mks_sd_file_times;  // При чтении, основанном на 6 файлах, имя файла отображается, начиная с times*6
    bool                        is_mks_ts35_flag;   // Является ли это функцией гравировки, выполняемой через TS35?
    bool                        wifi_connect_status;// обнаружение перехода Wi-Fi-соединения
    bool                        wifi_check_status;  // Вам нужно определить подключение Wi-Fi
    uint8_t                     wifi_back_from;     // Определите, откуда пришел интерфейс Wi-Fi 0 = основной интерфейс, 1 = об интерфейсе
    bool                        wifi_connect_enable;// Разрешить автоматическое подключение Wi-Fi
    bool                        popup_1_flag;
    bool                        is_need_ref_sd_file;
    uint32_t                    carve_times;        // Количество резных фигур
    bool                        is_test_mode = false;       // Следует ли использовать производственный режим
}GRBL_CRTL;
extern GRBL_CRTL mks_grbl;

typedef enum {

    MKS_UI_PAGE_LOADING,        // Логотип при переходе на страницу

    /* Логотип страницы */
    MKS_UI_Logo,    // logo
    MKS_UI_Ready,   // Основной интерфейс
    MKS_UI_Adjust,  // Интерфейс регулировки мощности
    MKS_UI_Control, // Мобильный интерфейс управления
    MKS_UI_Caving,  // Интерфейс гравировки
    MKS_UI_Pring,   // Интерфейс печати
    MKS_UI_Tool,    // Интерфейс инструмента
    MKS_UI_Wifi,    // Интерфейс, связанный с Wi-FI
    MKS_UI_Frame,   // Патрулирование пограничной поверхности
    MKS_UI_inFile,  // Интерфейс после открытия файла
    MKS_UI_UPDATA,  // Интерфейс обновления файла конфигурации
    MKS_UI_LANGUAGE,    // Интерфейс настройки языка
    MKS_UI_TEST,    // Страница тестового режима
}mks_ui_page_t;


#define DEFAULT_UI_COUNT    1
typedef struct {
    mks_ui_page_t mks_ui_page;
    uint8_t wait_count;             // Дождитесь, пока событие LVGL сгенерирует буфер для обновления данных интерфейса
}LVGL_UI_PAGE_t;
extern LVGL_UI_PAGE_t mks_ui_page;




void mks_lvgl_init(void);
void lvgl_test(void);
SDState mks_readSD_Status(void);
float mks_caving_persen(void);
void mks_grbl_parg_init(void);
#endif
