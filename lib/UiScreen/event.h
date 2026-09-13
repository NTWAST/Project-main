#ifndef EVENT_H
#define EVENT_H
<<<<<<< HEAD
#include <lvgl.h>
=======
#include <Arduino.h>
#include <Wire.h>
#include <AHT20.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SGP30.h>
#include <lvgl.h>
#include <OneWire.h>
#include <DallasTemperature.h>
>>>>>>> 3d8dbd6 (v1.2)
#include "ui.h"
#if defined(EEZ_FOR_LVGL)
#include <eez/flow/lvgl_api.h>
#endif
#if !defined(EEZ_FOR_LVGL)
#include "screens.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif
<<<<<<< HEAD


    // void event_handler(lv_event_t *e);
    void intro(lv_timer_t * timer);
    // void plotchart();
=======
    void switch_arc_cb(lv_event_t *e);
    void checkRelayControl(lv_timer_t * timer);
    void value_changed_event_arc1_cb(lv_event_t *e);
    void update_temperature_display(lv_timer_t *timer);
    void btn_change_event_cb(lv_event_t *e);
    void btn_change_event_cb1(lv_event_t *e);
    // void event_handler(lv_event_t *e);
    void intro(lv_timer_t *timer);
    void temp1(lv_timer_t *timer);
    void setupplotchart();
    extern OneWire oneWire;           // เพิ่มใหม่
    extern DallasTemperature ds18b20; // เพิ่มใหม่
    extern lv_chart_series_t *data2;
>>>>>>> 3d8dbd6 (v1.2)

#ifdef __cplusplus
}
#endif
#endif