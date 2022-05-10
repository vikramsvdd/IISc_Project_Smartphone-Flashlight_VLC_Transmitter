# IISc- Workflow

1. Feb 11 : An Email from prof Chockalingam citing the need for using smartphone's flashlight as a transmitter of Information, started to research and work on the same.
2. Came by Android studio as the best IDE for android app development as ease of loading the app into the smartphone. Started Developing the program and used the Camera Interface of the smartphone to access and control my flashlight.
3. Started developing the code , and used sleep function of thread as the function that implements the pulse width of my flashlight signal (either-on or off). 
4. Built a simple reciever circuit consisting of a photodiode and lm358 op-amp , and Arduino Uno acting as the intelligence.
5. Flashed a simple clock signal consisting of 0s and 1s alternating for 100 times (hereby called the clock signal from now on) onto the reciver circuit, probed an oscilloscope to view the output. 
6. A major problem became existent, the pulse width is deviating from the programmed pulse width rapidly . I programmed a 1 ms pulse width and the output pulse width varied from 5 ms to 15 ms. Thus a deviation of 500 to 1700% is noted. A statistical test has been conducted to find the mean and variance of the pulse widths, the result is indicated in detail by [![This is an image(/Results/plain_clock_signal_2.PNG)](/Results/plain_clock_signal_2.PNG)]


7. 
 












