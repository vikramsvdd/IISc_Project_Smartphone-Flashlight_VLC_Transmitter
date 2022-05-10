# IISc- Workflow

1. Feb 11 : An Email from prof Chockalingam citing the need for using smartphone's flashlight as a transmitter of Information. He shared a paer to start with (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/VLC_References/vlc_smartpone.pdf) A study  done by a chinese university . From then, i started to research and work on the same. 
2. Came by Android studio as the best IDE for android app development as ease of loading the app into the smartphone. Started Developing the program and used the Camera Interface of the smartphone to access and control my flashlight.
3. Started developing the code , and used sleep function of thread as the function that implements the pulse width of my flashlight signal (either-on or off). 
4. Built a simple reciever circuit consisting of a photodiode and lm358 op-amp , and Arduino Uno acting as the intelligence.
5. Flashed a simple clock signal consisting of 0s and 1s alternating for 100 times (hereby called the clock signal from now on) onto the reciver circuit, probed an oscilloscope to view the output. 
6. A major problem became existent, the pulse width is deviating from the programmed pulse width rapidly . I programmed a 1 ms pulse width and the output pulse width varied from 5 ms to 15 ms. Thus a deviation of 500 to 1700% from my programmed width is noted. A statistical test has been conducted to find the mean and variance of the pulse widths, the result is indicated in detail by (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/plain_clock_signal_2.PNG)

7. As an alternative way of programming the pulse width, i used java's Executor Object to achive my objective. It has a comparatively better performance in terms of less divergence of pulse width, the result is indicated in detail by https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/plain_clocksignal(with%201%20ms%20delay).PNG. But it is still not a solution , just an alternate way in which we faced the same problem . 

8. The chinese paper also detailed the same problem, but their solution was not clearly stated in the paper, and we were left in a state of perusal on how to resolove the problem by ourselves.
9. Landed on a new study (https://hal.inria.fr/hal-01683629/document) . They also detailed the same problem, and also had added that the pulse width variation varied for different smarphones as the problem is hugely OS dependent (OS introduces the delay as it is a GPOS and multithreaded). But they had proposed a solution to this problem. Encoding 1 and 0 in terms of pulse width was their attempt. I wrote a report that details how i collected the gist from several sources the HAL paper was one of them and had arrived at a solution (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/clock-inconsistency.docx)
 10. So i was able to arrive at a solution and was able to flash my information ( chockaingam in string (utf-8 encoding)). But there was a huge take , the data rate was too low, it was around 10 bits/second( hereforth called bps) , which is too low by any standard and a motivation to increase the data rate was existent.
 11. In parallel, i also developed a fingerprint authentication feat to my modulation app to add additional security. The feat was achieved with the help of FingerprintManager module in android studio. 
 12. 












