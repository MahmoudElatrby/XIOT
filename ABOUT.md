# ABOUT.md

## Application Description:
- This Application consists of lcd screen & serial monitor that display the status of a led and a switch and the temperature measured by temperature sensor, in normal case the led is off and the switch is not pressed. when the switch is pressed an interrupt occurs to execute ISR that change the status of switch to be pressed and the led to be on.
- A timer is set to update temperature value on LCD each 3 seconds.
- In default case the lcd displays the status of the switch and the led as off and after 3 seconds is displays temperature.


## Thought Process of the Project
- Gathering project requirements from description  on website.
- Determine the required micro controller to work with.
- In this step i choosed to work with AVR as most of my experience was with it.
- Determin the required modules. (LCD, Serial monitor, ADC, IOs)
- Drawing circuit schematic on paper.
- Set a flow chart for main program and determine the required functions for each module 
- Devide the project into files .c and .h file for each module
- Coding and testing of each module separatly 
- Integration of all modules

## Lessons learned.
- In this project, i learned to deal with github.

## Experience with Embedded Systems
- I had an embedded systems diploma 2 years ago.
- worked on Embedded systems Project (Automation & Security system for a mall), which includes Implementing the system based on 3 AVR, FPGA and Raspberry pi controllers and the System features are Finger print sensor, RFID, online monitoring using raspberry pi camera, glass break circuit, lighting system, Parking systems, Fire protection.

## Testing
- Testing done through simulation on proteus 8 of each function.
