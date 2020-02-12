#include "lvgl/lvgl.h"
#include <stdio.h>
#if LV_USE_SW

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        printf("State: %s\n", lv_sw_get_state(obj) ? "On" : "Off");
    }
}

void lv_ex_sw_1(void)
{
    /*Create a switch and apply the styles*/
    lv_obj_t *sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_event_cb(sw1, event_handler);

    /*Copy the first switch and turn it ON*/
    lv_obj_t *sw2 = lv_sw_create(lv_scr_act(), sw1);
    lv_sw_on(sw2, LV_ANIM_ON);
    lv_obj_align(sw2, NULL, LV_ALIGN_CENTER, 0, 50);
}

#endif