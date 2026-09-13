#include "event.h"
<<<<<<< HEAD
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
=======
#include <Adafruit_SGP30.h>

AHT20 aht20_1; // เพิ่มใหม่: AHT20 ตัวที่ 1
AHT20 aht20_2; // เพิ่มใหม่: AHT20 ตัวที่ 2

OneWire oneWire(19);                 // เพิ่มใหม่: ใช้ GPIO19 สำหรับ DS18B20
DallasTemperature ds18b20(&oneWire); // เพิ่มใหม่

lv_chart_series_t *data1; // เพิ่มใหม่
lv_chart_series_t *data2; // เพิ่มใหม่

Adafruit_SGP30 sgp;
#define RELAY_PIN1 33
#define RELAY_PIN2 32
void switch_arc_cb(lv_event_t * e) {
    if (lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        int state = lv_obj_has_state(objects.system, LV_STATE_CHECKED);

        if (state) {
            // สวิตช์ ON → ล็อก Arc
            lv_obj_add_flag(objects.temparc, LV_OBJ_FLAG_CLICKABLE); 
            Serial.println("Arc locked, relay control enabled");
        } else {
            // สวิตช์ OFF → ปลดล็อก Arc
            lv_obj_clear_flag(objects.temparc, LV_OBJ_FLAG_CLICKABLE);
            Serial.println("Arc unlocked, relay control disabled");

            // ปิดรีเลย์ทันที
            digitalWrite(RELAY_PIN1, LOW);
            digitalWrite(RELAY_PIN2, LOW);
        }
    }
}

// ตรวจสอบค่าอุณหภูมิและควบคุมรีเลย์
void checkRelayControl(lv_timer_t * timer) {
    LV_UNUSED(timer);

    // ตรวจสอบว่า switch เปิดอยู่หรือไม่
    if (!lv_obj_has_state(objects.system, LV_STATE_CHECKED)) return;

    float tInside = aht20_1.getTemperature();
    int setTemp = lv_arc_get_value(objects.temparc);

    Serial.printf("SetTemp: %d | TempInside: %.2f °C\n", setTemp, tInside);

    if ((int)tInside > setTemp) {
        digitalWrite(RELAY_PIN1, HIGH);
        digitalWrite(RELAY_PIN2, HIGH);
    } else {
        digitalWrite(RELAY_PIN1, LOW);
        digitalWrite(RELAY_PIN2, LOW);
    }
}
void value_changed_event_arc1_cb(lv_event_t * e)
{
    lv_obj_t * arc = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_t * label = (lv_obj_t *)lv_event_get_user_data(e);
    int arcValue = lv_arc_get_value(arc);
    Serial.printf("Arc value changed: %d\n", arcValue);
    lv_label_set_text_fmt(objects.settemp, "%d", arcValue);
}
void update_temperature_display(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    float t1 = aht20_1.getTemperature();

    ds18b20.requestTemperatures();          // เพิ่มใหม่
    float tDS = ds18b20.getTempCByIndex(0); // เพิ่มใหม่

    Serial.printf("AHT20 #1: %.2f °C | DS18B20: %.2f °C\n", t1, tDS);

    lv_label_set_text_fmt(objects.label_temp1, " %d °C", (int)t1);
    lv_label_set_text_fmt(objects.label_temp2, " %d °C", (int)tDS);
}

void btn_change_event_cb(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.manual); // โหลดหน้าจอใหม่
    }
}
void btn_change_event_cb1(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.main); // โหลดหน้าจอใหม่
    }
}
void intro(lv_timer_t *timer)
{
    lv_scr_load(objects.main);
    lv_timer_del(timer);
}

void temp1(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    float t1 = aht20_1.getTemperature();
    float h1 = aht20_1.getHumidity();

    ds18b20.requestTemperatures();          // เพิ่มใหม่
    float tDS = ds18b20.getTempCByIndex(0); // เพิ่มใหม่

    Serial.printf("AHT20 #1: %.2f °C, %.2f %%RH | DS18B20: %.2f °C\n", t1, h1, tDS);

    lv_chart_set_next_value(objects.chartinside_m, data1, (int)t1);
    lv_chart_set_next_value(objects.chartoutside_m, data2, (int)tDS); // เพิ่มใหม่
}

void setupplotchart()
{
    int pointcount = 50;
    int min_value = -10;
    int max_value = 50;

    lv_chart_set_type(objects.chartinside_m, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(objects.chartinside_m, pointcount);
    lv_chart_set_range(objects.chartinside_m, LV_CHART_AXIS_PRIMARY_Y, min_value, max_value);

    lv_chart_set_type(objects.chartoutside_m, LV_CHART_TYPE_LINE);                             // เพิ่มใหม่
    lv_chart_set_point_count(objects.chartoutside_m, pointcount);                              // เพิ่มใหม่
    lv_chart_set_range(objects.chartoutside_m, LV_CHART_AXIS_PRIMARY_Y, min_value, max_value); // เพิ่มใหม่

    data1 = lv_chart_add_series(objects.chartinside_m, lv_color_hex(0xffff696a), LV_CHART_AXIS_PRIMARY_Y);  // เพิ่มใหม่
    data2 = lv_chart_add_series(objects.chartoutside_m, lv_color_hex(0xff0000ff), LV_CHART_AXIS_PRIMARY_Y); // เพิ่มใหม่
}

void initSensors()
{
    Wire.begin(21, 22);

    if (!aht20_1.begin())
    {
        Serial.println("AHT20 #1 not found!");
        while (1)
            ;
    }

    if (!sgp.begin())
    {
        Serial.println("SGP30 not found!");
        while (1)
            ;
    }

    ds18b20.begin(); // เพิ่มใหม่
    Serial.println("DS18B20 ready!");
}

void readSensors()
{
    // เพิ่มใหม่: อ่านค่าเซนเซอร์ทั้งสองตัว
    float t1 = aht20_1.getTemperature();
    float h1 = aht20_1.getHumidity();
    float t2 = aht20_2.getTemperature();
    float h2 = aht20_2.getHumidity();

    Serial.printf("ReadSensors -> AHT20 #1: %.2f °C, %.2f %%RH | AHT20 #2: %.2f °C, %.2f %%RH\n", t1, h1, t2, h2);
}
>>>>>>> 3d8dbd6 (v1.2)
