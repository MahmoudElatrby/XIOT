# XIOT Internship Task (Embedded System)
## Description 
- The system is based on a single AVR Microcontroller.
- C function to control one input and output (IO Pins) the input pin PD2 is a switch as interrupt once it pressed the led connected to output pin PB0 is on & Display the status on an LCD  & Serial Monitor whether the switch is pressed & the led is on or not.

- C function controls Temperature sensor to display it's reading through ADC on the LCD with 3 second rate.

## **Instructions For Setting the Application** ##

- program Development is based on Eclipse c/c++ with AVR plugin and Proteus 8 professional simulator is used for Testing each module itself and the hole system working together.

- for System Testing you can run Proteus simulation with XIOT.elf file burned on it and test each single hardware component in simulation mode.

- for different Proteus Version use FILE -> import legacy project -> choose IXOT.pdsprj.


## **Hardware Components & Modules**
- ATMEGA16 AVR Microcontroller
- LCD 16*2
- LM35 temperature sensor
- UART Module
- ADC Module
- Serial Monitor with UART interface

## **Software Files and Functions**

### std_types.h

### micro_config.h

### common_macros.h

### lcd.h, lcd.c
- void LCD_sendCommand(uint8 command);
- void LCD_displayCharacter(uint8 data);
- void LCD_displayString(const char *Str);
- void LCD_init(void);
- void LCD_clearScreen(void);
- void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
- void LCD_goToRowColumn(uint8 row,uint8 col);
- void LCD_intgerToString(int data);

### adc.h, adc.c
- void ADC_init(void);
- uint16 ADC_read(uint8 channel_num);

### uart.h, uart.c
- void UART_init(void);
- void UART_sendByte(const uint8 data);
- uint8 UART_recieveByte(void);
- void UART_sendString(const uint8 *Str);
- void UART_receiveString(uint8 *Str);

### XIOTMain.c
- ISR(INT0_vect);
- ISR(TIMER0_OVF_vect)
- int main(void);
- void INT0_Init(void);
- void timer0_init_normal_mode(void);
- void stream_temp(void);
