/* main.c - main routine goes here
 * Author: Kyle Coppedge  
 */
#include <stdio.h> //to resolve printf error
#include <p30f3013.h>
#include "aliases.h"
#include "utilities.h"
#include "definitions.h"

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
