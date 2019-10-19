1. Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.  

I would like to discuss my portable wireless mouse which I have been using for years now. This device’s embedded systems consists of optical sensor, microcontroller, scrolling wheel encoder, push buttons, slide switch, LED’s, wireless transmitter, and a replaceable battery.

Optical sensor measures changes in mouse position by taking sequential surface images and then comparing them. Optical sensor communicates mouse position and magnitude to the microcontroller via serial port. Scrolling wheel encoder and push buttons are digital inputs to the microcontroller. Microcontroller monitors battery life and turns ON LED once the battery voltage is low. Microcontroller sends information to the wireless transmitter via serial port. Wireless receiver converts received information to serial data stream and sends it to computer via USB port. Slide switch disconlllnects battery power from the circuit to extend battery life.

Computer mouse needs to be very responsive to user inputs. A delicate balance needs to be established between how fast this system captures and processes user inputs vs. battery life consumption. Wireless mouse needs to be light in hand which does not allow for additional batteries. Computer mouse also needs to be price competitive therefore it needs to be cheap and easy to manufacture.