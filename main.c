/* main.c - main routine goes here
 * Author: Kyle Coppedge  
 */
#include <stdio.h> //to resolve printf error
#include <p30f3013.h>
#include "aliases.h"
#include "utilities.h"
#include "definitions.h"


void InitializePWM();
void setupPins();

int main() {
  /* initialize the ability to send messages to the
   * PICKit 2 using printf.
   */
  initializeUART();
  pause(1000);
  setupPins();
    

  
  halt();
  return(0);
}

void setupPins()
{
    pin2Direction = OUTPUT; //motor
    pin2Type = DIGITAL; //dip switch
}


void InitializePWM()
{
  OC1R = 0x1000;  // Initialize PWM period
  OC1RS = 0x1000;
  
  // Initialize Output Compare Module
  OC1CONbits.OCM = 0b000; // Disable output compare module
  OC1R = 100; // write the duty cycle for the first pwm pulse
  OC1RS = 100; //write the duty cycle for the second pwm pulse
  OC1CONbits.OCTSEL = 0; //select timer 2 as output compare time base
  OC1R = 100; //load the compare register value
  OC1CONbits.OCM = 0b110; //select the output compare mode
  // Initialize and enable Timer2
  T2CONbits.TON = 0; //disable timer
  T2CONbits.TCS = 0; //select internal instruction cycle clock
  T2CONbits.TGATE = 0; //disable gated timer mode
  T2CONbits.TCKPS = 0b00; //select 1:1 prescaler
  TMR2 = 0x00; //clear timer register
  PR2 = 500; //load the period value
  //IPCbits.T2IP = 0x01; //set timer 2 interrupt priority level
  //IFS0bits.T2IF = 0; // clear timer 2 interrupt flag
  //IEC0bits.T2IE = 1;// enable timer 2 interrupt
  T2CONbits.TON = 1; // start timer
}
