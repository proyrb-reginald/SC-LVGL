/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef void (*lv_anim_deleted_cb_t)(lv_anim_t*);
	
typedef struct
{
  
	lv_obj_t *screen_home;
	bool screen_home_del;
	lv_obj_t *screen_home_meter_1;
	lv_meter_scale_t *screen_home_meter_1_scale_0;
	lv_meter_indicator_t *screen_home_meter_1_scale_0_arc_0;
	lv_meter_indicator_t *screen_home_meter_1_scale_0_arc_1;
	lv_obj_t *screen_home_digital_clock_1;
	lv_obj_t *screen_home_datetext_1;
	lv_obj_t *screen_home_line_1;
	lv_obj_t *screen_home_line_2;
	lv_obj_t *screen_home_line_3;
	lv_obj_t *screen_home_line_4;
	lv_obj_t *screen_home_img_1;
	lv_obj_t *screen_home_label_1;
	lv_obj_t *screen_home_label_2;
	lv_obj_t *screen_time;
	bool screen_time_del;
	lv_obj_t *screen_time_cont_1;
	lv_obj_t *screen_time_arc_1;
	lv_obj_t *screen_time_img_1;
	lv_obj_t *screen_time_label_1;
	lv_obj_t *screen_children;
	bool screen_children_del;
	lv_obj_t *screen_children_cont_1;
	lv_obj_t *screen_children_arc_1;
	lv_obj_t *screen_children_img_1;
	lv_obj_t *screen_children_label_1;
	lv_obj_t *screen_clean;
	bool screen_clean_del;
	lv_obj_t *screen_clean_cont_1;
	lv_obj_t *screen_clean_arc_1;
	lv_obj_t *screen_clean_img_1;
	lv_obj_t *screen_clean_label_1;
	lv_obj_t *screen_cycle;
	bool screen_cycle_del;
	lv_obj_t *screen_cycle_cont_1;
	lv_obj_t *screen_cycle_arc_1;
	lv_obj_t *screen_cycle_img_1;
	lv_obj_t *screen_cycle_label_1;
	lv_obj_t *screen_fast;
	bool screen_fast_del;
	lv_obj_t *screen_fast_cont_1;
	lv_obj_t *screen_fast_arc_1;
	lv_obj_t *screen_fast_img_1;
	lv_obj_t *screen_fast_label_1;
	lv_obj_t *screen_multi;
	bool screen_multi_del;
	lv_obj_t *screen_multi_cont_1;
	lv_obj_t *screen_multi_arc_1;
	lv_obj_t *screen_multi_img_1;
	lv_obj_t *screen_multi_label_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_home(lv_ui *ui);
void setup_scr_screen_time(lv_ui *ui);
void setup_scr_screen_children(lv_ui *ui);
void setup_scr_screen_clean(lv_ui *ui);
void setup_scr_screen_cycle(lv_ui *ui);
void setup_scr_screen_fast(lv_ui *ui);
void setup_scr_screen_multi(lv_ui *ui);
LV_IMG_DECLARE(_sun_alpha_32x32);
LV_IMG_DECLARE(_time_alpha_100x100);
LV_IMG_DECLARE(_children_alpha_100x100);
LV_IMG_DECLARE(_clean_alpha_100x100);
LV_IMG_DECLARE(_cycle_alpha_100x100);
LV_IMG_DECLARE(_fast_alpha_100x100);
LV_IMG_DECLARE(_multi_alpha_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_20)


#ifdef __cplusplus
}
#endif
#endif
