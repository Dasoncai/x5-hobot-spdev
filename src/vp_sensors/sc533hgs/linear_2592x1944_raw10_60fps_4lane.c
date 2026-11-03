#include "vp_sensors.h"

#define SENSOR_WIDTH  2592
#define SENSOR_HEIGHT 1944
#define SENSOR_FPS    60
#define RAW10         0x2B

static mipi_config_t sc533hgs_mipi_config = {
        .rx_enable = 1,
        .rx_attr = {
                .phy = 0,
                .lane = 4,
                .datatype = RAW10,
                .fps = SENSOR_FPS,
                .mclk = 24,
                .mipiclk = 3888,
                .width = SENSOR_WIDTH,
                .height = SENSOR_HEIGHT,
                .linelenth = 3240,
                .framelenth = 2000,
                .settle = 22,
                .channel_num = 1,
                .channel_sel = {0},
        },
};

static camera_config_t sc533hgs_camera_config = {
        .name = "sc533hgs",
        .addr = 0x30,
        .sensor_mode = NORMAL_M,
        .fps = SENSOR_FPS,
        .format = RAW10,
        .width = SENSOR_WIDTH,
        .height = SENSOR_HEIGHT,
        .gpio_enable_bit = 0x01,
        .gpio_level_bit = 0x00,
        .mipi_cfg = &sc533hgs_mipi_config,
        .calib_lname = "sc533hgs_tuning.json",
        .config_index = 1,
};

static vin_node_attr_t sc533hgs_vin_node_attr = {
        .cim_attr = {
                .mipi_rx = 0,
                .vc_index = 0,
                .ipi_channel = 1,
                .cim_isp_flyby = 0,
                .func = {
                        .enable_frame_id = 1,
                        .set_init_frame_id = 0,
                        .hdr_mode = NOT_HDR,
                        .time_stamp_en = 0,
                },
        },
        .lpwm_attr = {
                .enable = 0,
                .lpwm_chn_attr = {
                        { .trigger_source = 0, .trigger_mode = 0, .period = 16666, .offset = 40, .duty_time = 100, .threshold = 0, .adjust_step = 0, },
                        { .trigger_source = 0, .trigger_mode = 0, .period = 16666, .offset = 40, .duty_time = 100, .threshold = 0, .adjust_step = 0, },
                        { .trigger_source = 0, .trigger_mode = 0, .period = 16666, .offset = 40, .duty_time = 100, .threshold = 0, .adjust_step = 0, },
                        { .trigger_source = 0, .trigger_mode = 0, .period = 16666, .offset = 40, .duty_time = 100, .threshold = 0, .adjust_step = 0, },
                },
        },
};

static vin_attr_ex_t sc533hgs_vin_attr_ex = {
        .vin_attr_ex_mask = 0x80,
        .mclk_ex_attr = {
                .mclk_freq = 24000000,
        },
};

static vin_ichn_attr_t sc533hgs_vin_ichn_attr = {
        .width = SENSOR_WIDTH,
        .height = SENSOR_HEIGHT,
        .format = RAW10,
};

static vin_ochn_attr_t sc533hgs_vin_ochn_attr = {
        .ddr_en = 1,
        .ochn_attr_type = VIN_BASIC_ATTR,
        .vin_basic_attr = {
                .format = RAW10,
                .wstride = SENSOR_WIDTH * 2,
        },
};

static isp_attr_t sc533hgs_isp_attr = {
        .input_mode = DDR_MODE,
        .sensor_mode = ISP_NORMAL_M,
        .crop = {
                .x = 0,
                .y = 0,
                .h = SENSOR_HEIGHT,
                .w = SENSOR_WIDTH,
        },
};

static isp_ichn_attr_t sc533hgs_isp_ichn_attr = {
        .width = SENSOR_WIDTH,
        .height = SENSOR_HEIGHT,
        .fmt = FRM_FMT_RAW,
        .bit_width = 10,
};

static isp_ochn_attr_t sc533hgs_isp_ochn_attr = {
        .ddr_en = 1,
        .fmt = FRM_FMT_NV12,
        .bit_width = 8,
};

vp_sensor_config_t sc533hgs_linear_2592x1944_raw10_60fps_4lane = {
        .support_sensor_mode = {NORMAL_M},
        .chip_id_reg = 0x3107,
        .chip_id = 0xce6f,
        .sensor_i2c_addr_list = {0x30, 0x32},
        .sensor_name = "sc533hgs-60fps-4lane",
        .config_file = "linear_2592x1944_raw10_60fps_4lane.c",
        .camera_config = &sc533hgs_camera_config,
        .vin_ichn_attr = &sc533hgs_vin_ichn_attr,
        .vin_node_attr = &sc533hgs_vin_node_attr,
        .vin_attr_ex = &sc533hgs_vin_attr_ex,
        .vin_ochn_attr = &sc533hgs_vin_ochn_attr,
        .isp_attr = &sc533hgs_isp_attr,
        .isp_ichn_attr = &sc533hgs_isp_ichn_attr,
        .isp_ochn_attr = &sc533hgs_isp_ochn_attr,
};
