/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_clean(lv_ui *ui)
{
    //Write codes screen_clean
    ui->screen_clean = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_clean, 480, 272);
    lv_obj_set_scrollbar_mode(ui->screen_clean, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_clean, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_clean, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clean, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clean, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clean_cont_1
    ui->screen_clean_cont_1 = lv_obj_create(ui->screen_clean);
    lv_obj_set_pos(ui->screen_clean_cont_1, 120, 16);
    lv_obj_set_size(ui->screen_clean_cont_1, 240, 240);
    lv_obj_set_scrollbar_mode(ui->screen_clean_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_clean_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clean_cont_1, 120, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clean_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clean_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clean_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clean_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clean_arc_1
    ui->screen_clean_arc_1 = lv_arc_create(ui->screen_clean);
    lv_arc_set_mode(ui->screen_clean_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_clean_arc_1, 0, 100);
    lv_arc_set_bg_angles(ui->screen_clean_arc_1, 135, 45);
    lv_arc_set_value(ui->screen_clean_arc_1, 70);
    lv_arc_set_rotation(ui->screen_clean_arc_1, 0);
    lv_obj_set_style_arc_rounded(ui->screen_clean_arc_1, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_clean_arc_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_clean_arc_1, 140, 36);
    lv_obj_set_size(ui->screen_clean_arc_1, 200, 200);

    //Write style for screen_clean_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_clean_arc_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_clean_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_clean_arc_1, lv_color_hex(0x008d13), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clean_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_clean_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_clean_arc_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_clean_arc_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_clean_arc_1, lv_color_hex(0x008d13), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_clean_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_clean_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_clean_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_clean_img_1
    ui->screen_clean_img_1 = lv_img_create(ui->screen_clean);
    lv_obj_add_flag(ui->screen_clean_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_clean_img_1, &_clean_alpha_100x100);
    lv_img_set_pivot(ui->screen_clean_img_1, 50,50);
    lv_img_set_angle(ui->screen_clean_img_1, 0);
    lv_obj_set_pos(ui->screen_clean_img_1, 190, 86);
    lv_obj_set_size(ui->screen_clean_img_1, 100, 100);

    //Write style for screen_clean_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_clean_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_clean_img_1, lv_color_hex(0x00ce1d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_clean_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clean_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_clean_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clean_label_1
    ui->screen_clean_label_1 = lv_label_create(ui->screen_clean);
    lv_label_set_text(ui->screen_clean_label_1, "桶自洁");
    lv_label_set_long_mode(ui->screen_clean_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_clean_label_1, 190, 208);
    lv_obj_set_size(ui->screen_clean_label_1, 100, 32);

    //Write style for screen_clean_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clean_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clean_label_1, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clean_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clean_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clean_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clean_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_clean.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_clean);

}
