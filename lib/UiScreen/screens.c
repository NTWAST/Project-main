#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_loading() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // intro
            lv_obj_t *obj = lv_animimg_create(parent_obj);
            objects.intro = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            static const lv_img_dsc_t *images[11] = {
                &img_frame_11,
                &img_frame_13,
                &img_frame_14,
                &img_frame_16,
                &img_frame_17,
                &img_frame_19,
                &img_frame_20,
                &img_frame_22,
                &img_frame_24,
                &img_frame_26,
                &img_frame_27,
            };
            lv_animimg_set_src(obj, (const void **)images, 11);
            lv_animimg_set_duration(obj, 1500);
            lv_animimg_set_repeat_count(obj, 1);
            lv_animimg_start(obj);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
        }
    }
    
    tick_screen_loading();
}

void tick_screen_loading() {
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00a0a8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 9, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f9f9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Smart Refrigerator");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 4, 33);
            lv_obj_set_size(obj, 156, 204);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 9, 43);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Temp inside (C)");
        }
        {
            // chartinside
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chartinside = obj;
            lv_obj_set_pos(obj, 9, 62);
            lv_obj_set_size(obj, 145, 74);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 10, 139);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Temp outside (C)");
        }
        {
            // chartoutside
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chartoutside = obj;
            lv_obj_set_pos(obj, 9, 158);
            lv_obj_set_size(obj, 145, 74);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 162, 33);
            lv_obj_set_size(obj, 154, 204);
        }
        {
            // temparc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.temparc = obj;
            lv_obj_set_pos(obj, 203, 80);
            lv_obj_set_size(obj, 73, 75);
            lv_arc_set_range(obj, 0, 20);
            lv_arc_set_value(obj, 10);
            lv_obj_set_style_arc_width(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 9, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // settemp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.settemp = obj;
            lv_obj_set_pos(obj, 232, 110);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "10");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 168, 43);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Setting");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 168, 62);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Temp (c)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 167, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Cooling");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 259, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Fan");
        }
        {
            // cooling
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.cooling = obj;
            lv_obj_set_pos(obj, 168, 187);
            lv_obj_set_size(obj, 40, 17);
            lv_obj_set_style_pad_top(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // fan
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.fan = obj;
            lv_obj_set_pos(obj, 259, 187);
            lv_obj_set_size(obj, 40, 17);
            lv_obj_set_style_pad_top(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, -3, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // ledstatus
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.ledstatus = obj;
            lv_obj_set_pos(obj, 274, 62);
            lv_obj_set_size(obj, 16, 16);
            lv_led_set_color(obj, lv_color_hex(0x009411));
            lv_led_set_brightness(obj, 255);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 259, 40);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Status");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_loading,
    tick_screen_main,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 2) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_loading();
    create_screen_main();
}