#include <Arduino.h>
#include <mavlink.h>

int system_type = MAV_FIXED_WING;
int autopilot_type = MAV_AUTOPILOT_GENERIC;
mavlink_message_t msg;

uint8_t buf[MAVLINK_MAX_PACKET_LEN];
int serialBytes = 0;


void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  /* <3 heart beat !  */ 
  mavlink_msg_heartbeat_pack(1, 200, &msg, system_type, MAV_AUTOPILOT_GENERIC);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  Serial.write(buf, len);
  
  
  mavlink_message_t msg;
  mavlink_status_t status;
  
  /* lecture */
  while(Serial.available() > 0) {
    serialBytes = Serial.read();
     if(mavlink_parse_char(MAVLINK_COMM_0, serialBytes, &msg, &status)) {
     
     }

    
    Serial.println(serialBytes);
  }
  
  

}

