# IISc- Workflow

1. Feb 11 : An Email from prof Chockalingam citing the need for using smartphone's flashlight as a transmitter of Information. He shared a paer to start with (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/VLC_References/vlc_smartpone.pdf) A study  done by a chinese university . From then, i started to research and work on the same. 
2. Came by Android studio as the best IDE for android app development as ease of loading the app into the smartphone. Started Developing the program and used the Camera Interface of the smartphone to access and control my flashlight.
3. Started developing the code , and used sleep function of thread as the function that implements the pulse width of my flashlight signal (either-on or off). 
4. Built a simple reciever circuit consisting of a photodiode and lm358 op-amp , and Arduino Uno acting as the intelligence.
5. Flashed a simple clock signal consisting of 0s and 1s alternating for 100 times (hereby called the clock signal from now on) onto the reciver circuit, probed an oscilloscope to view the output. 
6. A major problem became existent, the pulse width is deviating from the programmed pulse width rapidly . I programmed a 1 ms pulse width and the output pulse width varied from **5 ms to 15 ms**. Thus a deviation of 500 to 1700% from my programmed width is noted. A statistical test has been conducted to find the mean and variance of the pulse widths, the result is indicated in detail by (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/plain_clock_signal_2.PNG)

7. As an alternative way of programming the pulse width, i used java's Executor Object to achieve my objective. It has a comparatively better performance in terms of less divergence of pulse width, the result is indicated in detail by https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/plain_clocksignal(with%201%20ms%20delay).PNG. But it is still not a solution , just an alternate way in which we faced the same problem . 

8. The chinese paper also detailed the same problem, but their solution was not clearly stated in the paper, and we were left in a state of perusal on how to resolove the problem by ourselves.
9. Landed on a new study (https://hal.inria.fr/hal-01683629/document) . They also detailed the same problem, and also had added that the pulse width variation varied for different smarphones as the problem is hugely OS dependent (OS introduces the delay as it is a GPOS and multithreaded). But they had proposed a solution to this problem. Encoding 1 and 0 in terms of pulse width was their attempt. I wrote a report that details how i collected the gist from several sources the HAL paper was one of them and had arrived at a solution (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/clock-inconsistency.docx)
 10. So i was able to arrive at a solution and was able to flash my information ( eg:chockaingam in string (utf-8 encoding)). But there was a huge take , the data rate was too low, it was around **17 bits/second ( hereforth called bps)** , which is too low by any standard and a motivation to increase the data rate was existent.
 11. In parallel, i also developed a fingerprint authentication feat to my modulation app to add additional security. The feat was achieved with the help of FingerprintManager module in android studio. 
 12. Subsequently i rethinked  that any 2 consecutive bits should have should have their equivalent symbol high time to be seperated by 17ms and made 0's symbol without any delay , whereas 1 symbol's high time is programmed to be 17ms long . Even though the clock pulses varied even in this case , i was able to transmit and recieve the data properly and was able to increase my datarate to 54 bps.
// needs research //13. As a next step , i came to know of **Source-Coding** as a way of compressing the data and maximizing the data rate. In particular, i implemented **Multi-Bit-Modulation** as a solution. (One difference from normal source coding and my-kinda source coding is that, normally 0s and 1s are the final layer of abstraction in all coding stratergies, but in my kind, special symbols are the final one , because my source is itself inconsistant!). Firstly, i implemented 2-bit-modulation where 00,01,10 and 11 are allocated respective symbols which are seperated consecutively by 17ms (the threshold gap for Redmi-Note-5-Pro). The symbols are allocated based on the probability of occurence of  bi-bits(a way that i use to call 2 bits). For a particular string ifound out that d 10 are the first two most probable bi-bits, whereas 00 and 11 are the least probable bi-bits . **Thus the symbol with less duration gets allocated to the most probable bi-bits**. Thus i was able to increase my data rate ranging from **64 to 80 bps**. But in these, i specifically modified the reciever code for each string. But this is not a realistic solution simply because there are literally infinite names and modifying reciever code for each one is not a viable solution. Thus i ran a research for 500 random strings and found out a clear biasness in data for 3 types of modulation that i had carried out 
2 bit modulation(https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/2bitmodulationfreqdistri.PNG) 
2cum3bit modulation(https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/2aur3bitmodulationfreqdistri.PNG) and 4 bit modulation (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/4bitmodulationfreqdistri.png). I alloted symbols to each multi-bits and from (2 ms,18ms and on....upto number of levels).So one thing we can notice in the multi-bit-modulations are a **tradeoff** between number of pulsewidth levels with quantity of data, for eg, for 4 bit modulation there are 16 levels and the pulse width varies from (2 ms(1ms for on, one for off) to 256 ms!) but the number of data compresses to 96/4, for a 96 bit string. As per the freq distribution results i carried out the symbol allotment for different multi-bits and calculated the theoretical data rate for 2 bit,2-cum-3 bit and 4 -bit as 64 , 55.2 and 14.6 bps respectively . I also applied the same procedure to a string "chockalingam" and saw how it compares to the lot, and it has 31.94 for 2-bit, 20 for 2cum3 and 43 for 4 bit modulation. Thus some strings might be exceptional and differ slightly from the "lot". Ofcourse, practically the data rate might be even lower due to OS,**but this theoretical comparision ensures that even though the number of bits reduces for multi-bit modulation , the number of levels increase and the pulse width increases in steps of 17ms, essentially bringing down the bit rate , thus w bit theoretically has a good performance compared to 2 cum 3 and 4 , and 1 has a even good performance (100 bps for the "lot") theoretically**. (further research to be done on allocating symbols to each and every string individually as well as various other source coding methods).

13. Finally i settled on the single bit modulation through android studio as the best hope until i came across several forums and answers from the queries that i posted which addressed "Rooting" the Phone and controlling LED driver through Shell maybe a better option. But Rooting is a dangerous process and a very unreliable one , which can brick your phone and erase all your data if not done correctly. I tried contacting several professionals in SP road, Bangalore for rooting my phone(the Electronics hub of Bangalore, possibly India) yet they refused citing it as dangerous.  

So i had to arrange for alternate mobile phones such as Lenovo K6 Power and Letv X509. I tried to root Lenovo and accidently bricked it as expected and rendering it useless. I succeeded in rooting the Letv but was unable to locate the exact flashlight driver and was unable to write any due to a denied permission set by SELinux. Came across Redmi and OnePlus phones being very developer friendly and thus i changed my personal phone to Redmi note 8 pro and  

used redmi note 5 pro as the goat for rooting, and eventually succeeded and was able to locate the flashlight driver.  

14. Now to switch on and switch off i have to go to a file within the flashlight driver called brightness (an ascii file), i have to change the value of the file to switch the flashlight on at different intensity. Its values ranges from 0 (flashlight off) to 256 (the max permissible brightness, a limit set by the manufacturer , beyond which the flashlight will melt!) ,  This gives a possibility of amplitude modulation, but that’s an entirely different and there should be a dedicated effort towards it and my priority is different, I was able to switch on and off the flashlight by altering the file between two values 0 and 100.  

15. Now , I needed to write a shell script to automate this, but unfortunately even though android is a linux kernel based system, its OS is different from typical Linux Distro, thus I came across the “Swiss Army Knife of Embedded Developers” in other words known as Busybox, which is a binary call which contains all unix functionalities packaged as a single unit. So I was able to use basic unix commands to interact with the android OS and I also downloaded Termux, which is a command line interface directed to android developers.  

16. Now with these tools I was able to write a shell script ( I was not able to use bash, since busybox just contains the essential utilities , was also not able to install due to the problem of SELinux, fortunately I was able to achieve my objective with the help of shell script  in its own) , to  periodically switch on and off the flashlight and with a delay (sleep function), and it maxed out at 400 Hz or 400 bps(average), which is much higher than my previous best 40 hz (for single bit mod through app). But without a delay I witnessed a magic, the frequency was a whopping 4000 Hz !!!!(average). Even though this method also has the same clock inconsistency problem, the average data rate here is very high because, essentially because when we consider the app developed through the android studio, it has to go through Camera Api and that camera API then finally controls the brightness file , whereas through shell, I was directly able to control the brightness file bypassing the camera API and saving me that delay.  

17. But subsequently my simple receiver ( bpw40- photodiode with arduino) was not able to  receive the signal properly and it missed the pulses , primarily because both the photodiode and the reciever was slow( I used simple analogRead() rather than interrupts). As a solution I used a photodiode array designed and developed in IISc by my professor and a lm358 op-amp. Modified the receiver code  completely using interrupts and was able to receive the signal correctly. (Results in Result tab) . Smartphone had  a display failure and had to modify it but I optimized the total expenditure :D. Finally I tried transmitting data through shell (a 0 has a on and off with no delay , a 1 has a on with a sleep of 10 ms and off with 0 delay , but the average pulse width for high time  was 19 ms (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/shell_mod_statistics.png), even lower than 15 ms of (https://github.com/vikramsvdd/Smartphone-Flashlight-Modulation-IISc-Project-/blob/main/Results/method_2(no%2C17)_statistics.png) which is done using android studio and has the camera api, despite that it outweighed this method , thus landing us to the statement that a sleep of 10 ms performs worse in shell compared to a sleep of 17ms in android studio and having a rate of 52 bps. But a delay of 5 ms in shell, ensures an average high  pulse width of 10 ms, even though there is a 0.12% probability in average  that your bit gets flipped for 1000 bits , but the  datarate is nearly 100bps . 

18.Thus Sleep is not very efficient in introducing delays at real time in shell, so I tried alternatives that can give me a precise delay   

a. writing a cpp program and used chrono to introduce a delay and calling the cpp program from shell script, turned out to be slower than directly doing the same in shell. Also, using system() command in the cpp program , basically running shell script within cpp also similarly turned out to be slower. 

b.Tried to use crontab and Hardware timers , but were not usable(crontab does not schedule jobs in micro or milli seconds). 

c. Tried to introduce a delay using a for loop looping 100 times, and had a nearly consistent mean delay of 756 us though minimum and maximum delay drastically varied, thus using for loop is a good non-blocking way to achieve a delay at even lower scales compared to sleep function.  

 

Ultimately, I came to know after reading several forums and querying several professionals who commented that a smartphone is a GPOS based device(General Purpose OS) whose design structure is very different from a RTOS(Gpos is like a internet system, it allocates resources to every activity without any discrimination rather than  a RTOS which works on priority), thus one cannot expect guarantees out of a GPOS unlike a RTOS . 

 

 
 



