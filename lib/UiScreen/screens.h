#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_LOADING = 1,
    SCREEN_ID_MAIN = 2,
    SCREEN_ID_MANUAL = 3,
    _SCREEN_ID_LAST = 3
};

typedef struct _objects_t {
    lv_obj_t *loading;
    lv_obj_t *main;
    lv_obj_t *manual;
    lv_obj_t *intro;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
<<<<<<< HEAD
    lv_obj_t *chartinside_a;
    lv_obj_t *chartoutside_a;
=======
    lv_obj_t *label_temp2;
>>>>>>> 3d8dbd6 (v1.2)
    lv_obj_t *temparc;
    lv_obj_t *settemp;
    lv_obj_t *system;
    lv_obj_t *ledstatus;
    lv_obj_t *obj2;
    lv_obj_t *mode_manual;
<<<<<<< HEAD
=======
    lv_obj_t *label_temp1;
>>>>>>> 3d8dbd6 (v1.2)
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *chartinside_m;
    lv_obj_t *chartoutside_m;
    lv_obj_t *temparc_m;
    lv_obj_t *settemp_1;
    lv_obj_t *cooling_1;
    lv_obj_t *fan_1;
    lv_obj_t *ledstatus_1;
    lv_obj_t *obj5;
    lv_obj_t *mode_auto;
    lv_obj_t *fan_2;
} objects_t;

extern objects_t objects;

void create_screen_loading();
void tick_screen_loading();

void create_screen_main();
void tick_screen_main();

void create_screen_manual();
void tick_screen_manual();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/