reTurnFlashlightOn = false
            val stream = arrayOf("1","0","1","0","0","1","0","1")
            var ctr=0
            for(i in stream){
                if(i=="1"){
                mCameraImpl!!.enableFlashlight()
                TimeUnit.SECONDS.sleep(1)
                ctr+=1}
                if(i=="0"){
                mCameraImpl!!.disableFlashlight()   // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array
                TimeUnit.SECONDS.sleep(1)
                ctr+=1}
                if(ctr==stream.size){
                    exitProcess(-1)
                }
            }
           // startActivity(Intent(applicationContext, BrightDisplayActivity::class.java))

# Newer Version - 28/02/2022
bright_display_btn.setOnClickListener {
            reTurnFlashlightOn = false
            val stream = arrayOf("1","0","1","0","0","1","0","1")
            var ctr=0
            for(i in stream){
                if(i=="0"){
                    mCameraImpl!!.enableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)
                    mCameraImpl!!.disableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)
                    ctr+=1}
                if(i=="1"){
                    mCameraImpl!!.enableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(43)
                    mCameraImpl!!.disableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)   // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array
                    ctr+=1}

                println("Runned NIgger")
                if(ctr==stream.size){
                    exitProcess(-1)
                }
            }
            /*var arrey= arrayOf(11000)
            for( i in 1..50){
                val start = System.currentTimeMillis()
                mCameraImpl!!.enableFlashlight()
                TimeUnit.MICROSECONDS.sleep(1)
                val end = System.currentTimeMillis()
                println("The Value in ms is : ${end - start} ms")
                mCameraImpl!!.disableFlashlight()
                TimeUnit.MICROSECONDS.sleep(1)


            }*/


            // startActivity(Intent(applicationContext, BrightDisplayActivity::class.java))
        }
        
        
        
        
        
        
        
        
        
        
        
        fun append(arr: Array<Char?>, element: Char?): Array<Char?> {
        val array = arrayOfNulls<Char>(arr.size + 1)
        System.arraycopy(arr, 0, array, 0, arr.size)
        array[arr.size] = element
        return array}

        fun bitstuff(msg : String): Array<Char?> {
            var temp= arrayOf<Char?>()
            var stream= arrayOf<Char?>()
            var ctr=0
            for(i in msg){
                temp= append(temp,i)
                ctr+=1
                if(ctr==8){
                    var ttr=0
                    var onec=0
                    for(j in temp){
                        if(ttr==0){
                            stream=append(stream,'0')
                            stream=append(stream,j)
                            ttr+=1
                            if(j=='1'){
                                onec+=1
                            }
                        }
                        else{
                            stream=append(stream,j)
                            ttr+=1
                            if(j=='1'){
                                onec+=1
                            }
                            if(ttr==8){
                                if(onec%2==0){
                                    stream=append(stream,'1')
                                }
                                if(onec%2!=0){
                                    stream=append(stream,'0')
                                }
                                stream=append(stream,'1')
                                ctr=0
                            }
                            //stream=append(stream,parity bit)
                            //
                        }

                    }

                }






            }
            return stream

        }

    fun Reciever(Stream: Array<Char>){
        var tb=0
        var num= arrayOf<Char?>()
        var ctr=0
        var onec=0
        for(i in Stream){
            if(i=='0' && tb==0){
                tb=1
                continue
            }
            if(tb==1 && ctr<9){
                num=append(num,i)
                ctr+=1
                if(i=='1'){onec+=1}
            }
            if(ctr==9){
                if(i=='0'){
                    if(onec%2!=0){
                        kum=append(kum,num)
                    }
                    else{
                        print("ERROR BRO,Check it ")
                    }

                }
               else{
                    if(i=='1'){
                        if(onec%2==0){
                            kum=append(kum,num)
                        }
                        else{
                            print("ERROR BRO,Check it ")
                        }

               }                    // parity checking -by DR SARO AKA SARAVANAN


            }

            if(ctr==10){
                tb=0
                num= arrayOf<Char?>()
                ctr=0
            }




        }

    }






// enter this line if you are in need of an input array
            val stream=arrayOf('0', '1', '0', '0', '1', '0', '0', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '1', '0', '0', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '0', '0')






