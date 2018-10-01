## What is a library, anyway?

When you want to attach sensors or other new parts (or ‘hardware’) to your Arduino board, it is often necessary to install a ‘library’ so that the board knows how to communicate with this new hardware. This is very much like when you plug a new printer into your computer: you have to install the required drivers or programs for it to work properly.
The following instructions will guide you through installing the library that will allow you to control an ultrasonic sensor with your Arduino board.

## Step 1: Download the NewPing library

You can download the ‘NewPing’ library by clicking the ‘Download NewPing’ button which can be found on any of the project pages which use an ultrasonic sensor. You can also access the link  below which will begin downloading a zip file automatically.
https://bitbucket.org/teckel12/arduino-new-ping/downloads/NewPing_v1.8.zip 

## Step 2: Add the library in the Arduino software

You now need to tell the Arduino software that a new library called ‘NewPing’ is available. this is done by opening the Arduino software and then selecting Sketch > Include Library > Add ZIP library.

Once you have managed to add the libraries, you will get this message: "Library added to your libraries. Check "include library" menu. This is an one time off step. You can call the whole library by using #include in your future projects.
