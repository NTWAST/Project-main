#include "event.h"
#include <Arduino.h>

lv_chart_series_t *data1;
lv_chart_series_t *data2;

void event_handler (lv_event_t *e){
    // lv_event_code_t code = lv_event_get_code(e);
    // lv_obj_t *obj = lv_event_get_target(e);
    // int *pLED1 = (int*)lv_event_get_user_data(e);
    // int *pLED2 = (int*)lv_event_get_user_data(e);

    // if(obj ==  objects.onbt){
    //     digitalWrite(*pLED1 , 1);
    // }else if (obj == objects.offbt){
    //     digitalWrite(*pLED1 , 0);
    // }else if(obj == objects.pwmslider){
    //     analogWrite(*pLED2 , (int)lv_slider_get_value(objects.pwmslider));
    // }else if(obj == objects.page)
}

void intro(lv_timer_t * timer) {
    // Load main screen (replace main_screen with your generated EEZ screen object)
    lv_scr_load(objects.main);
    
    // Delete timer so it only executes once
    lv_timer_del(timer);
}