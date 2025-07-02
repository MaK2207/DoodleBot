# Week-0 Electronics Club Task Basic Idea

POT1 (wiper is connected to A0)-divided it into three ranges 0-341,342-682,683-1023
Each range controlled the buzzer
POT2 (wiper is connected to A1)-used with map() to scale values to a delay time (50ms to 1000ms)
LEDs are controlled in a loop and one lights up at a time
