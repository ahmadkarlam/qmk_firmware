// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// // ╭───────────────────────────────────────────────────────────╮
// // │ j o y s t i c k   v a r s                                 │
// // ╰───────────────────────────────────────────────────────────╯
 
// bool l_analog = false;
// bool r_analog = false;
// bool u_analog = false;
// bool d_analog = false;
 
// int xPin = 2; //F4
// int yPin = 3; //F5
 
// int xOrigin, yOrigin;
// int xOrigin_b, yOrigin_b;
 
// int rstAxisValue = 512;
 
// int savRange = 80;
// int actRange = 100;
 
// bool x_moved = false;
// bool y_moved = false;
 
// int precisionSpeed = 1;
 
// int xPolarity = 1;
// int yPolarity = -1;
 
// int cursorTimeout = 10;
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
        KC_A
    )
};

// int base_layer = 1;

// int axisCoordinate(int pin, int origin);
// int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity);
 
//     // int axisCoordinate(int pin, int origin) {
//     //   int direction;
//     //   int distanceFromOrigin;
//     //   int range;
 
//     //   int position = analogReadPin(pin);
 
//     //   if ((origin - 90) > position) {
//     //     distanceFromOrigin = origin - position;
//     //     range = origin - minAxisValue;
//     //     direction = -1;
//     //   } else if ((origin + 90) < position){
//     //     distanceFromOrigin = position - origin;
//     //     range = maxAxisValue - origin;
//     //     direction = 1;
//     //   } else {
//     //     return 0;
//     //   } 
 
//     //   float percent = (float)distanceFromOrigin / range;
//     //     int coordinate = (int)(percent * 100);
//     //     if (coordinate < 0) {
//     //       return 0;
//     //     }
//     //     else if (coordinate > 100) {
//     //       return 100 * direction;
//     //     }
//     //     else {
//     //       return coordinate * direction;
//     //     }
//     // }
 
//     // int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity) {
//     //   int coordinate = axisCoordinate(pin, origin);
//     //   //print_decs(coordinate); println();
//     //   if (coordinate == 0) {
//     //     return 0;
//     //   }
//     //   else {
//     //     float percent = (float)coordinate / 100;
//     //         if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
//     //             return percent * precisionSpeed * polarity * (abs(coordinate) / 6);
//     //         } else {
//     //             return percent * maxCursorSpeed * polarity * (abs(coordinate) / 6);
//     //         }
//     //     }
//     // }
 
 
 
// // FOR BOTH APPLICATIONS ├──────────────────────────────────────────────────────────┐
 
// bool pointing_device_task(void) {
  
//     if (base_layer == 1) {                  //If base layer
//         int maxCursorSpeed = 4; 
//         uint16_t lastCursor = 0;
//           report_mouse_t currentReport;
//           currentReport.x = 0;
//           currentReport.y = 0;
//           currentReport.h = 0;
//           currentReport.v = 0;
 
//           if (timer_elapsed(lastCursor) > cursorTimeout) {
//                 lastCursor = timer_read();
//                 currentReport.x = axisToMouseComponent(xPin, xOrigin, maxCursorSpeed, xPolarity);
//                 currentReport.y = axisToMouseComponent(yPin, yOrigin, maxCursorSpeed, yPolarity);
//           }
 
//           pointing_device_set_report(currentReport);
//           return pointing_device_send();
//   } else {                                  //If not base layer
 
// // KEYPRESSES ├────────────────────────────────────────────────────────────────────┐
 
//         xOrigin_b = analogReadPin(xPin);
//         yOrigin_b = analogReadPin(yPin);
 
//         if (x_moved == false && y_moved == false) {   //if not yet moved
 
//               if(xOrigin_b < rstAxisValue-actRange) {
//                     l_analog = true;
//                     x_moved = true;
//                     //uprintf("left: %u\n", xOrigin_b);
//               }
 
//               if(xOrigin_b > rstAxisValue+actRange) {
//                     r_analog = true;
//                     x_moved = true;
//                     //uprintf("right: %u\n", xOrigin_b);
//               }
 
//               if(yOrigin_b > rstAxisValue+actRange) {
//                     u_analog = true;
//                     y_moved = true;
//                     //uprintf("up: %u\n", yOrigin_b);
//               }
 
//               if(yOrigin_b < rstAxisValue-actRange) {
//                     d_analog = true;
//                     y_moved = true;
//                     //uprintf("down: %u\n", yOrigin_b);               
//               }
//         }
 
//         if(xOrigin_b < (rstAxisValue+savRange) && xOrigin_b > (rstAxisValue-savRange)) {
//               x_moved = false;
//         }
                
//         if(yOrigin_b < (rstAxisValue+savRange) && yOrigin_b > (rstAxisValue-savRange)) {
//               y_moved = false;
//         }
 
//  return false;
//     } //If not base layer END
// }     
                              
 
// void matrix_init_kb(void) {
//   timer_init();
//   xOrigin = analogReadPin(xPin);
//   yOrigin = analogReadPin(yPin);
// }