// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScreenBiankuang_screen_init(void)
{
    ui_ScreenBiankuang = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenBiankuang, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BiankuangBack = lv_img_create(ui_ScreenBiankuang);
    lv_img_set_src(ui_BiankuangBack, &ui_img_return_png);
    lv_obj_set_width(ui_BiankuangBack, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_BiankuangBack, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_x(ui_BiankuangBack, -87);
    lv_obj_set_y(ui_BiankuangBack, -133);
    lv_obj_set_align(ui_BiankuangBack, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BiankuangBack, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BiankuangBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_ScreenBiankuang);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -6);
    lv_obj_set_y(ui_Label1, -147);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Result:");

    ui_LabelBiankuang = lv_label_create(ui_ScreenBiankuang);
    lv_obj_set_width(ui_LabelBiankuang, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelBiankuang, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelBiankuang, 0);
    lv_obj_set_y(ui_LabelBiankuang, -129);
    lv_obj_set_align(ui_LabelBiankuang, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBiankuang, "choupicture");
    lv_obj_set_style_text_color(ui_LabelBiankuang, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBiankuang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SendBiankuang = lv_label_create(ui_ScreenBiankuang);
    lv_obj_set_width(ui_SendBiankuang, 100);
    lv_obj_set_height(ui_SendBiankuang, 70);
    lv_obj_set_x(ui_SendBiankuang, 56);
    lv_obj_set_y(ui_SendBiankuang, 115);
    lv_obj_set_align(ui_SendBiankuang, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SendBiankuang, "\nSend");
    lv_obj_add_flag(ui_SendBiankuang, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_color(ui_SendBiankuang, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SendBiankuang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SendBiankuang, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SendBiankuang, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SendBiankuang, lv_color_hex(0x838183), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SendBiankuang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CheckBiankuang = lv_label_create(ui_ScreenBiankuang);
    lv_obj_set_width(ui_CheckBiankuang, 100);
    lv_obj_set_height(ui_CheckBiankuang, 70);
    lv_obj_set_x(ui_CheckBiankuang, -60);
    lv_obj_set_y(ui_CheckBiankuang, 115);
    lv_obj_set_align(ui_CheckBiankuang, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CheckBiankuang, "\nCheck");
    lv_obj_add_flag(ui_CheckBiankuang, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_color(ui_CheckBiankuang, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckBiankuang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CheckBiankuang, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckBiankuang, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckBiankuang, lv_color_hex(0x828282), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckBiankuang, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BiankuangNext = lv_img_create(ui_ScreenBiankuang);
    lv_img_set_src(ui_BiankuangNext, &ui_img_906722072);
    lv_obj_set_width(ui_BiankuangNext, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_BiankuangNext, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_x(ui_BiankuangNext, 86);
    lv_obj_set_y(ui_BiankuangNext, -127);
    lv_obj_set_align(ui_BiankuangNext, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BiankuangNext, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BiankuangNext, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image4 = lv_img_create(ui_ScreenBiankuang);
    lv_img_set_src(ui_Image4, &ui_img_biankuang241_png);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 110
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 110
    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_BiankuangBack, ui_event_BiankuangBack, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SendBiankuang, ui_event_SendBiankuang, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CheckBiankuang, ui_event_CheckBiankuang, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BiankuangNext, ui_event_BiankuangNext, LV_EVENT_ALL, NULL);

}