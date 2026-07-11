#ifndef _GNARL_H
#define _GNARL_H

#include <stdint.h>

#include "pump_config.h"
#include "version.h"

#define TAG		"GNARL"
#define LOG_LOCAL_LEVEL	ESP_LOG_DEBUG
#include <esp_log.h>

#define MILLISECONDS_PER_SECOND		1000
#define MICROSECONDS_PER_MILLISECOND	1000
#define MICROSECONDS_PER_SECOND		1000000

#define MILLISECONDS			MICROSECONDS_PER_MILLISECOND
#define SECONDS				MICROSECONDS_PER_SECOND

#define MS_TO_US(ms)	((ms) * MICROSECONDS_PER_MILLISECOND)
#define SEC_TO_US(s)	((s) * MICROSECONDS_PER_SECOND)
#define SEC_TO_MS(s)	((s) * MILLISECONDS_PER_SECOND)


#define MHz		1000000

// Track github.com/ps2/rileylink/firmware/ble113_rfspy/gatt.xml
#define BLE_RFSPY_VERSION  "ble_rfspy 2.0"

#define STATE_OK "OK"

void gnarl_init(void);
void start_gnarl_task(void);
void rfspy_command(const uint8_t *buf, int count, int rssi);
void send_code(const uint8_t code);
void send_bytes(const uint8_t *buf, int count);
void print_bytes(const char* msg, const uint8_t *buf, int count);

#endif // _GNARL_H
