val stream=arrayOf("01", "10", "00", "11", "01", "10", "10", "00", "01", "10", "11", "11", "01", "10", "00", "11", "01", "10", "10", "11", "01", "10", "00", "01", "01", "10", "11", "00", "01", "10", "10", "01", "01", "10", "11", "10", "01", "10", "01", "11", "01", "10", "00", "01", "01", "10", "11", "01")
            var ctr=0
           //' biometricPrompt.authenticate(promptInfo)
            //if(tvAuthStatus.text=="Sucess"){
                // j loop starting for( j in 1..10) {

            //symbol assigning based on frequency of occurence of elements in the array
                     for (i in stream) {
                         if (i == "01") {
                             mCameraImpl!!.enableFlashlight()
                             System.nanoTime()
                             mCameraImpl!!.disableFlashlight()
                             System.nanoTime()
                             ctr += 1
                         }                                                       // using variable PWM
                         if (i == "10") {
                             mCameraImpl!!.enableFlashlight()
                             TimeUnit.MILLISECONDS.sleep(17)
                             mCameraImpl!!.disableFlashlight()
                             System.nanoTime()   // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array
                             ctr += 1
                         }

                         if(i=="11"){

                             mCameraImpl!!.enableFlashlight()
                             TimeUnit.MILLISECONDS.sleep(34)
                             mCameraImpl!!.disableFlashlight()
                             System.nanoTime()   // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array
                             ctr += 1


                         }

                         if(i=="00"){

                             mCameraImpl!!.enableFlashlight()
                             TimeUnit.MILLISECONDS.sleep(51)
                             mCameraImpl!!.disableFlashlight()
                             System.nanoTime()   // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array
                             ctr += 1


                         }


                         /* if (ctr == stream.size) {
                        exitProcess(-1)
                    }*/
                     }
                     
                     
                     
                     
                     // for arduinno
                     if((t2-t1)>=51){
    Serial.println("00");
    }
  else if((t2-t1)>=34 and (t2-t1)<51){
    Serial.println("11");
    }
  else if((t2-t1)>=17 and (t2-t1)<34){
    Serial.println("10");
    }    
 
  else{  
    Serial.println("01"); }
