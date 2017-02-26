/*
  Speeduino - Simple engine management for the Arduino Mega 2560 platform
  Copyright (C) Josh Stewart
  A full copy of the license may be found in the projects root directory
*/


/*
  Returns how much free dynamic memory exists (between heap and stack)
*/
#include "utils.h"

int freeRam ()
{
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
#elif defined(CORE_TEENSY)
  uint32_t stackTop;
  uint32_t heapTop;

  // current position of the stack.
  stackTop = (uint32_t) &stackTop;

  // current position of heap.
  void* hTop = malloc(1);
  heapTop = (uint32_t) hTop;
  free(hTop);

  // The difference is the free, available ram.
  return (uint16_t)stackTop - heapTop;
#endif
}

void setPinMapping(byte boardID)
{
  switch (boardID)
  {
    case 0:
      //Pin mappings as per the v0.1 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 11; //Output pin injector 3 is on
      pinInjector4 = 10; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 6; //Pin for coil 1
      pinCoil2 = 7; //Pin for coil 2
      pinCoil3 = 12; //Pin for coil 3
      pinCoil4 = 13; //Pin for coil 4
      pinCoil5 = 14; //Pin for coil 5
      pinTrigger = 2; //The CAS pin
      pinTrigger2 = 3; //The CAS pin
      pinTPS = A0; //TPS input pin
      pinMAP = A1; //MAP sensor pin
      pinIAT = A2; //IAT sensor pin
      pinCLT = A3; //CLS sensor pin
      pinO2 = A4; //O2 Sensor pin
      pinIdle1 = 46; //Single wire idle control
      pinIdle2 = 47; //2 wire idle control
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinFan = 47; //Pin for the fan output
      pinFuelPump = 4; //Fuel pump output
      pinTachOut = 49; //Tacho output pin
      pinFlex = 19; // Flex sensor (Must be external interrupt enabled)
      
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old fuelpump
       output[2] =  46;     //old idle1
       output[3] =  47;     //old idle2/fan
       output[4] =  49;     //old tacho
     //output[5] =  41;     //spare
     //output[6] =  43;     //spare
     //output[7] =  45;     //
     //output[8] =  47;     //
     //output[9] =  49;     //
     //output[10] = 51;     //spare
     //output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 19;       //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 4;
      Idle1Default = 2;
      Idle2Default = 3;
      fuelPumpDefault = 1;
      //VVT_1Default = 1;
      fanDefault = 3;
      //boostDefault = 4;      
      break;
      
    case 1:
      //Pin mappings as per the v0.2 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 28; //Pin for coil 1
      pinCoil2 = 24; //Pin for coil 2
      pinCoil3 = 40; //Pin for coil 3
      pinCoil4 = 36; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 20; //The CAS pin
      pinTrigger2 = 21; //The Cam Sensor pin
      pinTPS = A2; //TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A8; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinTachOut = 49; //Tacho output pin
      pinIdle1 = 30; //Single wire idle control
      pinIdle2 = 31; //2 wire idle control
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinFan = 47; //Pin for the fan output
      pinFuelPump = 4; //Fuel pump output
      pinFlex = 2; // Flex sensor (Must be external interrupt enabled)
            
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old fuelpump
       output[2] =  30;     //old idle1
       output[3] =  31;     //old idle2
       output[4] =  47;     //old fan
       output[5] =  49;     //old tacho
     //output[6] =  43;     //spare
     //output[7] =  45;     //
     //output[8] =  47;     //
     //output[9] =  49;     //
     //output[10] = 51;     //spare
     //output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 19;       //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 5;
      Idle1Default = 2;
      Idle2Default = 3;
      fuelPumpDefault = 1;
      //VVT_1Default = 1;
      fanDefault = 4;
      //boostDefault = 4;
      break;
      
    case 2:
      //Pin mappings as per the v0.3 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 28; //Pin for coil 1
      pinCoil2 = 24; //Pin for coil 2
      pinCoil3 = 40; //Pin for coil 3
      pinCoil4 = 36; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 19; //The CAS pin
      pinTrigger2 = 18; //The Cam Sensor pin
      pinTPS = A2;//TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A8; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinTachOut = 49; //Tacho output pin
      pinIdle1 = 5; //Single wire idle control
      pinIdle2 = 53; //2 wire idle control
      pinBoost = 7; //Boost control
      pinVVT_1 = 6; //Default VVT output
      pinFuelPump = 4; //Fuel pump output
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinFan = A13; //Pin for the fan output
      pinLaunch = 12; //Can be overwritten below
      pinFlex = 2; // Flex sensor (Must be external interrupt enabled)
      
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old fuelpump
       output[2] =  5;      //old idle1
       output[3] =  6;      //old vvt_1
       output[4] =  7;      //old boost
       output[5] =  49;     //old tacho
       output[6] =  53;     //old idle2
       output[7] =  113;     //old fan
       //output[8] =  47;     //
       //output[9] =  49;     //
       //output[10] = 51;     //spare
       //output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 5;
      Idle1Default = 2;
      Idle2Default = 6;
      fuelPumpDefault = 1;
      VVT_1Default = 3;
      fanDefault = 7;
      boostDefault = 4;
      break;

    case 3:
      //Pin mappings as per the v0.4 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 40; //Pin for coil 1
      pinCoil2 = 38; //Pin for coil 2
      pinCoil3 = 52; //Pin for coil 3
      pinCoil4 = 50; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 19; //The CAS pin
      pinTrigger2 = 18; //The Cam Sensor pin
      pinTPS = A2;//TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A8; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinTachOut = 49; //Tacho output pin  (Goes to ULN2803)
      pinIdle1 = 5; //Single wire idle control
      pinIdle2 = 6; //2 wire idle control
      pinBoost = 7; //Boost control
      pinVVT_1 = 4; //Default VVT output
      pinFuelPump = 45; //Fuel pump output  (Goes to ULN2803)
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinFan = 47; //Pin for the fan output (Goes to ULN2803)
      pinLaunch = 12; //Can be overwritten below
      pinFlex = 2; // Flex sensor (Must be external interrupt enabled)
      
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old vvt
       output[2] =  5;      //old idle1
       output[3] =  6;      //old idle2
       output[4] =  7;      //old boost
       output[5] =  41;     //spare
       output[6] =  43;     //spare
       output[7] =  45;     //old fuel pump
       output[8] =  47;     //old fan
       output[9] =  49;     //old tacho
       output[10] = 51;     //spare
       output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 9;
      Idle1Default = 2;
      Idle2Default = 3;
      fuelPumpDefault = 7;
      VVT_1Default = 1;
      fanDefault = 8;
      boostDefault = 4;
      break;

    case 9:
      //Pin mappings as per the MX5 PNP shield
      pinInjector1 = 11; //Output pin injector 1 is on
      pinInjector2 = 10; //Output pin injector 2 is on
      pinInjector3 = 9; //Output pin injector 3 is on
      pinInjector4 = 8; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 39; //Pin for coil 1
      pinCoil2 = 41; //Pin for coil 2
      pinCoil3 = 42; //Pin for coil 3
      pinCoil4 = 43; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 19; //The CAS pin
      pinTrigger2 = 18; //The Cam Sensor pin
      pinTPS = A2;//TPS input pin
      pinMAP = A5; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A3; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinTachOut = 49; //Tacho output pin  (Goes to ULN2803)
      pinIdle1 = 2; //Single wire idle control
      pinIdle2 = 3; //2 wire idle control (Note this is shared with boost!!!)
      pinFuelPump = 37; //Fuel pump output  (Goes to ULN2803)
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinFan = 47; //Pin for the fan output (Goes to ULN2803)
      pinLaunch = 12; //Can be overwritten below
      pinFlex = 2; // Flex sensor (Must be external interrupt enabled)
            
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  2;      //old idle1
       output[2] =  3;      //old idle2
       output[3] =  37;     //old fuelpump
       output[4] =  47;     //old fan
       output[5] =  49;     //old tacho
       //output[6] =  43;     //spare
       //output[7] =  45;     //old fuel pump
       //output[8] =  47;     //old fan
       //output[9] =  49;     //old tacho
       //output[10] = 51;     //spare
       //output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 5;
      Idle1Default = 1;
      Idle2Default = 2;
      fuelPumpDefault = 3;
      //VVT_1Default = 1;
      fanDefault = 4;
      //boostDefault = 4;
      break;

    case 10:
      //Pin mappings for user turtanas PCB
      pinInjector1 = 4; //Output pin injector 1 is on
      pinInjector2 = 5; //Output pin injector 2 is on
      pinInjector3 = 6; //Output pin injector 3 is on
      pinInjector4 = 7; //Output pin injector 4 is on
      pinInjector5 = 8; //Placeholder only - NOT USED
      pinInjector6 = 9; //Placeholder only - NOT USED
      pinInjector7 = 10; //Placeholder only - NOT USED
      pinInjector8 = 11; //Placeholder only - NOT USED
      pinCoil1 = 24; //Pin for coil 1
      pinCoil2 = 28; //Pin for coil 2
      pinCoil3 = 36; //Pin for coil 3
      pinCoil4 = 40; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 18; //The CAS pin
      pinTrigger2 = 19; //The Cam Sensor pin
      pinTPS = A2;//TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinMAP2 = A8; //MAP2 sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A4; //O2 Sensor pin
      pinBat = A7; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinSpareTemp1 = A6;
      pinSpareTemp2 = A5;
      pinTachOut = 41; //Tacho output pin transistori puuttuu 2n2222 tähän ja 1k 12v
      pinFuelPump = 42; //Fuel pump output 2n2222
      pinFan = 47; //Pin for the fan output
      pinTachOut = 49; //Tacho output pin
      pinFlex = 2; // Flex sensor (Must be external interrupt enabled)
            
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  41;      //old tacho
       output[2] =  42;      //old fuelpump
       output[3] =  47;      //old fan
       output[4] =  49;      //old tacho
       //output[5] =  41;     //spare
       //output[6] =  43;     //spare
       //output[7] =  45;     //old fuel pump
       //output[8] =  47;     //old fan
       //output[9] =  49;     //old tacho
       //output[10] = 51;     //spare
       //output[11] = 53;     //spare      
     //input[1] = 12;       //old launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 1;
      //Idle1Default = 2;
      //Idle2Default = 3;
      fuelPumpDefault = 2;
      //VVT_1Default = 1;
      fanDefault = 3;
      //boostDefault = 4;
      break;

    case 20:
      //Pin mappings as per the Plazomat In/Out shields Rev 0.1
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 28; //Pin for coil 1
      pinCoil2 = 24; //Pin for coil 2
      pinCoil3 = 40; //Pin for coil 3
      pinCoil4 = 36; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinSpareOut1 = 4; //Spare LSD Output 1(PWM)
      pinSpareOut2 = 5; //Spare LSD Output 2(PWM)
      pinSpareOut3 = 6; //Spare LSD Output 3(PWM)
      pinSpareOut4 = 7; //Spare LSD Output 4(PWM)
      pinSpareOut5 = 50; //Spare LSD Output 5(digital)
      pinSpareOut6 = 52; //Spare LSD Output 6(digital)
      pinTrigger = 20; //The CAS pin
      pinTrigger2 = 21; //The Cam Sensor pin
      pinSpareTemp2 = A15; //spare Analog input 2
      pinSpareTemp1 = A14; //spare Analog input 1
      pinO2 = A8; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinMAP = A3; //MAP sensor pin
      pinTPS = A2;//TPS input pin
      pinCLT = A1; //CLS sensor pin
      pinIAT = A0; //IAT sensor pin
      pinFan = 47; //Pin for the fan output
      pinFuelPump = 4; //Fuel pump output
      pinTachOut = 49; //Tacho output pin
      
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old fuelpump/spare1
       output[2] =  5;      //old spare2
       output[3] =  6;      //old spare3
       output[4] =  7;      //old spare4
       output[5] =  47;     //old fan
       output[6] =  49;     //old tacho
       output[7] =  50;     //old spare5
       output[8] =  52;     //old spare6
       //output[9] =  49;     //
       //output[10] = 51;     //
       //output[11] = 53;     //      
     //input[1] = 12;       //old launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 6;
      //Idle1Default = 2;
      //Idle2Default = 3;
      fuelPumpDefault = 1;
      //VVT_1Default = 1;
      fanDefault = 5;
      boostDefault = 4;
      break;
      
    case 30:
      //Pin mappings as per the dazv6 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 40; //Pin for coil 1
      pinCoil2 = 38; //Pin for coil 2
      pinCoil3 = 50; //Pin for coil 3
      pinCoil4 = 52; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 19; //The CAS pin
      pinTrigger2 = 18; //The Cam Sensor pin
      pinTrigger3 = 17; // cam sensor 2 pin
      pinTPS = A2;//TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A8; //O2 Sensor pin
      pinO2_2 = A9; //O2 sensor pin (second sensor)
      pinBat = A4; //Battery reference voltage pin
      pinDisplayReset = 48; // OLED reset pin
      pinTachOut = 49; //Tacho output pin
      pinIdle1 = 5; //Single wire idle control
      pinFuelPump = 45; //Fuel pump output
      pinStepperDir = 20; //Direction pin  for DRV8825 driver
      pinStepperStep = 21; //Step pin for DRV8825 driver
      pinSpareHOut1 = 4; // high current output spare1
      pinSpareHOut2 = 6; // high current output spare2
      pinBoost = 7;
      pinSpareLOut1 = 43; //low current output spare1
      pinSpareLOut2 = 47;
      pinSpareLOut3 = 49;
      pinSpareLOut4 = 51;
      pinSpareLOut5 = 53;
      pinFan = 47; //Pin for the fan output

    //analog[0] = 100;     //old IAT
    //analog[1] = 101;     //old CLT
    //analog[2] = 102;     //old TPS
    //analog[3] = 103;     //old MAP
    //analog[4] = 104;     //old Bat 
    //analog[8] = 108;     //old O2 sensor
    //analog[9] = 109;     //old 02_2 sensor
      output[1] = 4;       //old hc1 spare
      output[2] = 5;       //old idle1
      output[3] = 6;       //old hc2 spare
      output[4] = 7;       //old boost
      output[5] = 41;      //spare
      output[6] = 43;      //spare lc1
      output[7] = 45;      //old fuel pump
      output[8] = 47;      //old fan/lc2
      output[9] = 49;      //old tacho/lc3
      output[10] = 51;     //spare
      output[11] = 53;     //spare
      //input[1] = 12;     //old launch in
      //input[2] = 2;      //old flex in
      //set defaults
      TachOutDefault = 9; // these are output[x] values not pins
      Idle1Default = 2;
//      Idle2Default = 6;
      fuelPumpDefault = 7;
//      VVT_1Default = 1;
      fanDefault = 8;
      boostDefault = 4;
      break;

    default:
      //Pin mappings as per the v0.2 shield
      pinInjector1 = 8; //Output pin injector 1 is on
      pinInjector2 = 9; //Output pin injector 2 is on
      pinInjector3 = 10; //Output pin injector 3 is on
      pinInjector4 = 11; //Output pin injector 4 is on
      pinInjector5 = 12; //Output pin injector 5 is on
      pinCoil1 = 28; //Pin for coil 1
      pinCoil2 = 24; //Pin for coil 2
      pinCoil3 = 40; //Pin for coil 3
      pinCoil4 = 36; //Pin for coil 4
      pinCoil5 = 34; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = 20; //The CAS pin
      pinTrigger2 = 21; //The Cam Sensor pin
      pinTPS = A2; //TPS input pin
      pinMAP = A3; //MAP sensor pin
      pinIAT = A0; //IAT sensor pin
      pinCLT = A1; //CLS sensor pin
      pinO2 = A8; //O2 Sensor pin
      pinBat = A4; //Battery reference voltage pin
      pinStepperDir = 16; //Direction pin  for DRV8825 driver
      pinStepperStep = 17; //Step pin for DRV8825 driver
      pinDisplayReset = 48; // OLED reset pin
      pinFan = 47; //Pin for the fan output
      pinFuelPump = 4; //Fuel pump output
      pinTachOut = 49; //Tacho output pin
            
     //analog[0] =  100;    //old IAT
     //analog[1] =  101;    //old CLT
     //analog[2] =  102;    //old TPS
     //analog[3] =  103;    //old MAP
     //analog[4] =  104;    //old bat 
     //analog[8] =  108;    //old o2 sensor
     //analog[9] = 109;     //old 02_2 sensor
       output[1] =  4;      //old fuelpump
       output[2] =  47;      //old fan
       output[3] =  49;      //old tacho
     //output[4] =  7;      //
     //output[5] =  41;     //spare
     //output[6] =  43;     //spare
     //output[7] =  45;     //
     //output[8] =  47;     //
     //output[9] =  49;     //
     //output[10] = 51;     //
     //output[11] = 53;     //      
     //input[1] = 12;       //launch in
     //input[2] = 2;        //old flex in
     
     //set function defaults : these are all output[x] values NOT pin numbers!
      TachOutDefault = 3;
      //Idle1Default = 2;
      //Idle2Default = 3;
      fuelPumpDefault = 1;
      //VVT_1Default = 1;
      fanDefault = 2;
      //boostDefault = 4;
      break;
  }

  //Setup any devices that are using selectable pins
  if (configPage3.launchPin != 0) {
    pinLaunch = configPage3.launchPin;
  }

  if (configPage2.ignBypassPin != 0) {
    pinIgnBypass = configPage2.ignBypassPin;
  }

  if (configPage1.tachoPin != 0) {
   // pinTachOut = configPage1.tachoPin;
    // lookup what output was selected in ts @ configPage1.tachoPin this gives a value 0== default , 1=output[1] etc etc
    // lookup that value in boardtype to get basepinid number. so basepinid = output[configPage1.tachoPin]
    // now get the actual mcuboard pin number with mcuBoardPin[basepinid]
     pinTachOut = mcuBoardPin[(output[configPage1.tachoPin])];
  }
  else {pinTachOut = TachOutDefault;}

  if (configPage2.fuelPumpPin != 0) {
    ;pinFuelPump = configPage2.fuelPumpPin;
    pinFuelPump = mcuBoardPin[(output[configPage2.fuelPumpPin])];
  }
  else {pinFuelPump = fuelPumpDefault;}

  if (configPage4.fanPin != 0) {
    ;pinFan = configPage4.fanPin;
    pinFan = mcuBoardPin[(output[configPage4.fanPin])];
  }
  else {pinFan = fanDefault;}

  if (configPage3.boostPin != 0) {
    ;pinBoost = configPage3.boostPin;
    pinBoost = mcuBoardPin[(output[configPage3.boostPin])];
  }
  else {pinBoost = boostDefault;}

  if (configPage3.vvtPin != 0) {
    ;pinVVT_1 = configPage3.vvtPin;
    pinVVT_1 = mcuBoardPin[(output[configPage3.vvtPin])];
  }
  else {pinVVT_1 = VVT_1Default;}

  //Finally, set the relevant pin modes for outputs
  pinMode(pinCoil1, OUTPUT);
  pinMode(pinCoil2, OUTPUT);
  pinMode(pinCoil3, OUTPUT);
  pinMode(pinCoil4, OUTPUT);
  pinMode(pinCoil5, OUTPUT);
  pinMode(pinInjector1, OUTPUT);
  pinMode(pinInjector2, OUTPUT);
  pinMode(pinInjector3, OUTPUT);
  pinMode(pinInjector4, OUTPUT);
  pinMode(pinInjector5, OUTPUT);
  pinMode(pinTachOut, OUTPUT);
  pinMode(pinIdle1, OUTPUT);
  pinMode(pinIdle2, OUTPUT);
  pinMode(pinFuelPump, OUTPUT);
  pinMode(pinIgnBypass, OUTPUT);
  pinMode(pinFan, OUTPUT);
  pinMode(pinStepperDir, OUTPUT);
  pinMode(pinStepperStep, OUTPUT);
  pinMode(pinBoost, OUTPUT);
  pinMode(pinVVT_1, OUTPUT);

  inj1_pin_port = portOutputRegister(digitalPinToPort(pinInjector1));
  inj1_pin_mask = digitalPinToBitMask(pinInjector1);
  inj2_pin_port = portOutputRegister(digitalPinToPort(pinInjector2));
  inj2_pin_mask = digitalPinToBitMask(pinInjector2);
  inj3_pin_port = portOutputRegister(digitalPinToPort(pinInjector3));
  inj3_pin_mask = digitalPinToBitMask(pinInjector3);
  inj4_pin_port = portOutputRegister(digitalPinToPort(pinInjector4));
  inj4_pin_mask = digitalPinToBitMask(pinInjector4);
  inj5_pin_port = portOutputRegister(digitalPinToPort(pinInjector5));
  inj5_pin_mask = digitalPinToBitMask(pinInjector5);

  ign1_pin_port = portOutputRegister(digitalPinToPort(pinCoil1));
  ign1_pin_mask = digitalPinToBitMask(pinCoil1);
  ign2_pin_port = portOutputRegister(digitalPinToPort(pinCoil2));
  ign2_pin_mask = digitalPinToBitMask(pinCoil2);
  ign3_pin_port = portOutputRegister(digitalPinToPort(pinCoil3));
  ign3_pin_mask = digitalPinToBitMask(pinCoil3);
  ign4_pin_port = portOutputRegister(digitalPinToPort(pinCoil4));
  ign4_pin_mask = digitalPinToBitMask(pinCoil4);
  ign5_pin_port = portOutputRegister(digitalPinToPort(pinCoil5));
  ign5_pin_mask = digitalPinToBitMask(pinCoil5);

  tach_pin_port = portOutputRegister(digitalPinToPort(pinTachOut));
  tach_pin_mask = digitalPinToBitMask(pinTachOut);

  //And for inputs
  pinMode(pinMAP, INPUT);
  pinMode(pinO2, INPUT);
  pinMode(pinO2_2, INPUT);
  pinMode(pinTPS, INPUT);
  pinMode(pinIAT, INPUT);
  pinMode(pinCLT, INPUT);
  pinMode(pinBat, INPUT);
  pinMode(pinTrigger, INPUT);
  pinMode(pinTrigger2, INPUT);
  pinMode(pinTrigger3, INPUT);
  pinMode(pinFlex, INPUT_PULLUP); //Standard GM / Continental flex sensor requires pullup
  //  pinMode(pinLaunch, INPUT_PULLUP); //This should work for both NO and NC grounding switches
  if (configPage3.lnchPullRes) {
    pinMode(pinLaunch, INPUT_PULLUP);
  }
  else {
    pinMode(pinLaunch, INPUT);  //If Launch Pull Resistor is not set make input float.
  }

  //Set default values
  digitalWrite(pinMAP, HIGH);
  //digitalWrite(pinO2, LOW);
  digitalWrite(pinTPS, LOW);
}

void setMcuMapping(byte mcuID)
{
  //Assign ACTUAL mcu pins to the board pins
  switch (mcuID)
  {
    case 0: //mega2560 OEM
     //mcuBoardPin[4] = 100;    //old IAT
     //mcuBoardPin[4] = 101;    //old CLT
     //mcuBoardPin[4] = 102;    //old TPS
     //mcuBoardPin[4] = 103;    //old MAP
     //mcuBoardPin[4] = 104;    //old bat 
     //mcuBoardPin[4] = 105;    //old o2 sensor
     //mcuBoardPin[4] = 106;
       mcuBoardPin[4] = 4;   //stdBoardPin4 = mcuboard pin 4  
       mcuBoardPin[5] = 5;  
       mcuBoardPin[6] = 6; 
       mcuBoardPin[7] = 7;   //stdBoardPin7 = mcuboard pin 7
       mcuBoardPin[41] = 41;
       mcuBoardPin[43] = 43; 
       mcuBoardPin[45] = 45;
       mcuBoardPin[47] = 47;
       mcuBoardPin[49] = 49; 
       mcuBoardPin[51] = 51;
       mcuBoardPin[53] = 53;      
      //bPinIn1 = pinIN1 = 12;    //old launch in
      //bPinIn2 = pinIN2 = 2;     //old flex in
    break;
    
    case 1: //mega2561

    break;
    
    case 16: //teensy3.5 OEM

    break;        
    
    case 32: //stm32F

    break;
  }
}

/*
  This function retuns a pulsewidth time (in us) using a either Alpha-N or Speed Density algorithms, given the following:
  REQ_FUEL
  VE: Lookup from the main MAP vs RPM fuel table
  MAP: In KPa, read from the sensor
  GammaE: Sum of Enrichment factors (Cold start, acceleration). This is a multiplication factor (Eg to add 10%, this should be 110)
  injDT: Injector dead time. The time the injector take to open minus the time it takes to close (Both in uS)
  TPS: Throttle position (0% to 100%)

  This function is called by PW_SD and PW_AN for speed0density and pure Alpha-N calculations respectively.
*/
unsigned int PW(int REQ_FUEL, byte VE, byte MAP, int corrections, int injOpen)
{
  //Standard float version of the calculation
  //return (REQ_FUEL * (float)(VE/100.0) * (float)(MAP/100.0) * (float)(TPS/100.0) * (float)(corrections/100.0) + injOpen);
  //Note: The MAP and TPS portions are currently disabled, we use VE and corrections only
  unsigned int iVE, iMAP, iAFR, iCorrections;

  //100% float free version, does sacrifice a little bit of accuracy, but not much.
  iVE = ((unsigned int)VE << 7) / 100;
  if ( configPage1.multiplyMAP ) {
    iMAP = ((unsigned int)MAP << 7) / currentStatus.baro;  //Include multiply MAP (vs baro) if enabled
  }
  if ( configPage1.includeAFR && (configPage3.egoType == 2)) {
    iAFR = ((unsigned int)currentStatus.O2 << 7) / currentStatus.afrTarget;  //Include AFR (vs target) if enabled
  }
  iCorrections = (corrections << 7) / 100;


  unsigned long intermediate = ((long)REQ_FUEL * (long)iVE) >> 7; //Need to use an intermediate value to avoid overflowing the long
  if ( configPage1.multiplyMAP ) {
    intermediate = (intermediate * iMAP) >> 7;
  }
  if ( configPage1.includeAFR && (configPage3.egoType == 2)) {
    intermediate = (intermediate * iAFR) >> 7;  //EGO type must be set to wideband for this to be used
  }
  intermediate = (intermediate * iCorrections) >> 7;
  if (intermediate == 0) {
    return 0;  //If the pulsewidth is 0, we return here before the opening time gets added
  }

  intermediate += injOpen; //Add the injector opening time
  if ( intermediate > 65535) {
    intermediate = 65535;  //Make sure this won't overflow when we convert to uInt. This means the maximum pulsewidth possible is 65.535mS
  }
  return (unsigned int)(intermediate);

}

//Convenience functions for Speed Density and Alpha-N
unsigned int PW_SD(int REQ_FUEL, byte VE, byte MAP, int corrections, int injOpen)
{
  return PW(REQ_FUEL, VE, MAP, corrections, injOpen);
  //return PW(REQ_FUEL, VE, 100, corrections, injOpen);
}

unsigned int PW_AN(int REQ_FUEL, byte VE, byte TPS, int corrections, int injOpen)
{
  //Sanity check
  if (TPS > 100) {
    TPS = 100;
  }
  return PW(REQ_FUEL, VE, currentStatus.MAP, corrections, injOpen);
}
