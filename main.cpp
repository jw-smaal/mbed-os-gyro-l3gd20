/** 
 * Blinky blinky test by Jan-Willem Smaal  <usenet@gispen.org> 
 * 8 July 2020 
 * using NRF-51-DK development kit. 
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "gyro_l3gd20h.h"

// Default is 9600 8N1  This is a global  
Serial pc(USBTX, USBRX,"Gyro", 115200); // tx, rx 


// Blinking rate in milliseconds
#define BLINKING_RATE_MS    500


int main()
{
    // Variables 
    uint32_t i; 
    Gyro gyro; 
        
    // Initialise the digital pins as an output
    DigitalOut led1(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);
    DigitalOut led4(LED4);

    // Inputs 
    // we need this pin to source current 
    // as the switch pulls it to ground.  
    DigitalIn button1(BUTTON1, PullUp);
    DigitalIn button2(BUTTON2, PullUp);

    // Initial state of LED's. 
    led1 = true;    
    led2 = false;
    led3 = false;
    led4 = true;


   // pc.printf("------------------------------------\n");
   // pc.printf("- Embedded ARM design by J-W Smaal -\n");
   // pc.printf("- version 0.1     9 July 2020      -\n");
   // pc.printf("------------------------------------\n");




    while (true) {
        led1 = !led1;
        led2 = !led2;
        //led3 = !led3;
        //led4 = !led4;
        
        thread_sleep_for(60);
            gyro.ReadX(); 
            led3 = !led3;
            thread_sleep_for(1);
            gyro.ReadY(); 
            led3 = !led3;
             thread_sleep_for(1);
            gyro.ReadZ();
            led3 = !led3;
            thread_sleep_for(1);
            gyro.ReadTemp();
            thread_sleep_for(11);
            led3 = !led3;
         
        
        pc.printf("X:%+5.5d, \tY:%+5.5d \tZ:%+5.5d\n", 
                gyro.x, 
                gyro.y, 
                gyro.z);
       
        if (button1  == false) {   // Pulled low to ground so it means the button is pressed 
            for(i = 0 ; i < 10; i++) {
                led4 = !led4;
                thread_sleep_for(40);
                led4 = !led4;
                thread_sleep_for(40);
            }
        }
        if(button2 == false ) {
        }

    } /* End of while(true) runloop */

} /* End of Main */

/* EOF  */