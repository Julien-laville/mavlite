#include <Arduino.h>
#include <mavlink.h>

int system_type = MAV_FIXED_WING;
int autopilot_type = MAV_AUTOPILOT_GENERIC;

mavlink_message_t msg;
uint8_t buf[MAVLINK_MAX_PACKET_LEN];


void setup() {
  mavlink_msg_heartbeat_pack(100, 200, &msg, system_type, autopilot_type);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
 
// Send the message with the standard UART send function
Serial.begin(9600);
Serial.write(buf, len);
  // initialize serial communication at 9600 bits per second:
}

// the loop routine runs over and over again forever:
void loop() {

}

