
#include <stdio.h> //to resolve printf error
#include <p30f3013.h>
#include "definitions.h"
#include "aliases.h"
#include "utilities.h"


void setupPins() {
    pin2Direction = OUTPUT; //motor
    pin2Type = DIGITAL; //reset bumper
}


