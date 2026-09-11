#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_frame_1;
extern const lv_img_dsc_t img_frame_2;
extern const lv_img_dsc_t img_frame_3;
extern const lv_img_dsc_t img_frame_4;
extern const lv_img_dsc_t img_frame_5;
extern const lv_img_dsc_t img_frame_6;
extern const lv_img_dsc_t img_frame_7;
extern const lv_img_dsc_t img_frame_8;
extern const lv_img_dsc_t img_frame_9;
extern const lv_img_dsc_t img_frame_10;
extern const lv_img_dsc_t img_frame_11;
extern const lv_img_dsc_t img_frame_12;
extern const lv_img_dsc_t img_frame_13;
extern const lv_img_dsc_t img_frame_14;
extern const lv_img_dsc_t img_frame_15;
extern const lv_img_dsc_t img_frame_16;
extern const lv_img_dsc_t img_frame_17;
extern const lv_img_dsc_t img_frame_18;
extern const lv_img_dsc_t img_frame_19;
extern const lv_img_dsc_t img_frame_20;
extern const lv_img_dsc_t img_frame_21;
extern const lv_img_dsc_t img_frame_22;
extern const lv_img_dsc_t img_frame_23;
extern const lv_img_dsc_t img_frame_24;
extern const lv_img_dsc_t img_frame_25;
extern const lv_img_dsc_t img_frame_26;
extern const lv_img_dsc_t img_frame_27;
extern const lv_img_dsc_t img_frame_28;
extern const lv_img_dsc_t img_frame_29;
extern const lv_img_dsc_t img_frame_30;
extern const lv_img_dsc_t img_frame_31;
extern const lv_img_dsc_t img_frame_32;
extern const lv_img_dsc_t img_frame_33;
extern const lv_img_dsc_t img_frame_34;
extern const lv_img_dsc_t img_frame_35;
extern const lv_img_dsc_t img_frame_36;
extern const lv_img_dsc_t img_frame_37;
extern const lv_img_dsc_t img_frame_38;
extern const lv_img_dsc_t img_frame_39;
extern const lv_img_dsc_t img_frame_40;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[40];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/