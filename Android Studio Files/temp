package com.simplemobiletools.flashlight.activities

import android.annotation.SuppressLint
import android.content.Intent
import android.content.pm.ActivityInfo
import android.content.pm.ShortcutInfo
import android.graphics.drawable.Icon
import android.graphics.drawable.LayerDrawable
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.WindowManager
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import com.simplemobiletools.commons.extensions.*
import com.simplemobiletools.commons.helpers.LICENSE_EVENT_BUS
import com.simplemobiletools.commons.helpers.PERMISSION_CAMERA
import com.simplemobiletools.commons.helpers.isNougatMR1Plus
import com.simplemobiletools.commons.helpers.isNougatPlus
import com.simplemobiletools.commons.models.FAQItem
import com.simplemobiletools.flashlight.BuildConfig
import com.simplemobiletools.flashlight.R
import com.simplemobiletools.flashlight.extensions.config
import com.simplemobiletools.flashlight.helpers.MyCameraImpl
import com.simplemobiletools.flashlight.models.Events
import kotlinx.android.synthetic.main.activity_main.*
import org.greenrobot.eventbus.EventBus
import org.greenrobot.eventbus.Subscribe
import java.util.*
import java.util.concurrent.Executor
import java.util.concurrent.TimeUnit;
import kotlin.system.exitProcess
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import androidx.biometric.BiometricManager
import androidx.core.content.ContextCompat


class MainActivity : SimpleActivity() {
    private val MAX_STROBO_DELAY = 2000L
    private val MIN_STROBO_DELAY = 1L
    private val FLASHLIGHT_STATE = "flashlight_state"
    private val STROBOSCOPE_STATE = "stroboscope_state"

    private var mBus: EventBus? = null
    private var mCameraImpl: MyCameraImpl? = null
    private var mIsFlashlightOn = false
    private var reTurnFlashlightOn = true
    //lateinit var biometricLoginButton: Button
  //  lateinit var tvAuthStatus:TextView
   // lateinit var executor:Executor
    //lateinit var biometricPrompt:androidx.biometric.BiometricPrompt
    //lateinit var promptInfo:androidx.biometric.BiometricPrompt.PromptInfo

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        appLaunched(BuildConfig.APPLICATION_ID)

        mBus = EventBus.getDefault()
        changeIconColor(getContrastColor(), stroboscope_btn)
        //biometricLoginButton=findViewById(R.id.biometricLoginButton)
       /* tvAuthStatus=findViewById(R.id.tvAuthStatus)
        executor= ContextCompat.getMainExecutor(this)
        biometricPrompt=androidx.biometric.BiometricPrompt(this@MainActivity, executor ,object: androidx.biometric.BiometricPrompt.AuthenticationCallback(){
            override fun onAuthenticationError(errorCode: Int, errString: CharSequence) {
                super.onAuthenticationError(errorCode, errString)
                tvAuthStatus.text="Error"+errString

            }
            override fun onAuthenticationSucceeded(result: androidx.biometric.BiometricPrompt.AuthenticationResult) {
                super.onAuthenticationSucceeded(result)
                tvAuthStatus.text="Sucess"
                for(i in 1..50){

                    mCameraImpl!!.enableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)
                    mCameraImpl!!.disableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)

                    mCameraImpl!!.enableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(43)
                    mCameraImpl!!.disableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)




                    //println("Elapsed time in milliseconds: ${end-begin}")
                }


            }

            override fun onAuthenticationFailed() {
                super.onAuthenticationFailed()
                tvAuthStatus.text="Failed"
            }


        })
        promptInfo=androidx.biometric.BiometricPrompt.PromptInfo.Builder()
            .setTitle("Bio Authentication")
            .setSubtitle("Login using fingerprint")
            .setNegativeButtonText("Use App Password")
            .build()*/



       // var nums = arrayOf<Long?>()

        bright_display_btn.setOnClickListener {

            reTurnFlashlightOn = false
            val stream = arrayOf('0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '0', '1', '0', '0', '0', '0', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '0', '1', '0', '1', '1', '0', '1', '1', '0', '0', '0', '0', '1', '0', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '0', '0', '1', '0', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '0', '1', '1', '0', '0', '0', '0', '1', '0', '1', '1', '0', '1', '1', '0', '1')
            //var msg="01010101"
            //var stream=bitstuff(msg)
            var ctr=0
            for(i in stream){
                if(i=='0'){
                mCameraImpl!!.enableFlashlight()
                    System.nanoTime()
                //TimeUnit.MICROSECONDS.sleep(1)
                    mCameraImpl!!.disableFlashlight()
                    System.nanoTime()
                    //TimeUnit.MICROSECONDS.sleep(1)
                ctr+=1}
                if(i=='1'){
                    mCameraImpl!!.enableFlashlight()
                    TimeUnit.MILLISECONDS.sleep(17)
                    mCameraImpl!!.disableFlashlight()
                    System.nanoTime()
                    //TimeUnit.MICROSECONDS.sleep(1)  // code for switching on and off the LED, corresponding to second button in the app and the switching happens according to the sequence in the array

                ctr+=1
                }
                /*if(ctr==stream.size){
                    exitProcess(-1)
                }*/
            }

           /* biometricLoginButton.setOnClickListener {
                biometricPrompt.authenticate(promptInfo)
            }*/
          //  biometricPrompt.authenticate(promptInfo)
           // if( tvAuthStatus.text=="Sucess"){

            /*for(i in 1..50){

                mCameraImpl!!.enableFlashlight()
                TimeUnit.MILLISECONDS.sleep(17)
                mCameraImpl!!.disableFlashlight()
                TimeUnit.MILLISECONDS.sleep(17)

                mCameraImpl!!.enableFlashlight()                // just moved this mf to authenticationsucceeded() part of code, to perform this operation
                TimeUnit.MILLISECONDS.sleep(43)                    after biometric authentication! dont worry!!!
                mCameraImpl!!.disableFlashlight()
                TimeUnit.MILLISECONDS.sleep(17)




                //println("Elapsed time in milliseconds: ${end-begin}")
            }*/

            //}







            // start}Activity(Intent(applicationContext, BrightDisplayActivity::class.java))

        }

        flashlight_btn.setOnClickListener {
            mCameraImpl!!.toggleFlashlight()
        }

        sos_btn.setOnClickListener {
            toggleStroboscope(true)
            //TimeUnit.MINUTES.sleep(1);
        }

        stroboscope_btn.setOnClickListener {
            toggleStroboscope(false)
        }

        setupStroboscope()
        checkAppOnSDCard()


    }

    override fun onResume() {
        super.onResume()
        mCameraImpl!!.handleCameraSetup()
        checkState(MyCameraImpl.isFlashlightOn)

        val contrastColor = getContrastColor()
        changeIconColor(contrastColor, bright_display_btn)
        bright_display_btn.beVisibleIf(config.brightDisplay)
        sos_btn.beVisibleIf(config.sos)
        sos_btn.setTextColor(contrastColor)
        stroboscope_btn.beVisibleIf(config.stroboscope)

        if (!config.stroboscope) {
            mCameraImpl!!.stopStroboscope()
            stroboscope_bar.beInvisible()
        }

        updateTextColors(main_holder)
        if (stroboscope_bar.isInvisible()) {
            changeIconColor(contrastColor, stroboscope_btn)
        }

        requestedOrientation = if (config.forcePortraitMode) ActivityInfo.SCREEN_ORIENTATION_PORTRAIT else ActivityInfo.SCREEN_ORIENTATION_SENSOR
        invalidateOptionsMenu()

        if (config.turnFlashlightOn && reTurnFlashlightOn) {
            mCameraImpl!!.enableFlashlight()  // function to enable flashlight
        }

        reTurnFlashlightOn = true

        checkShortcuts()
    }

    override fun onStart() {
        super.onStart()
        mBus!!.register(this)

        if (mCameraImpl == null) {
            setupCameraImpl()
        }
    }

    override fun onStop() {
        super.onStop()
        mBus!!.unregister(this)
    }

    override fun onDestroy() {
        super.onDestroy()
        releaseCamera()
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        menuInflater.inflate(R.menu.menu, menu)
        updateMenuItemColors(menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.settings -> launchSettings()
            R.id.about -> launchAbout()
            else -> return super.onOptionsItemSelected(item)
        }
        return true
    }

    override fun onSaveInstanceState(outState: Bundle) {
        outState.putBoolean(FLASHLIGHT_STATE, mIsFlashlightOn)
        outState.putBoolean(STROBOSCOPE_STATE, stroboscope_bar.isVisible())
        super.onSaveInstanceState(outState)
    }

    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        super.onRestoreInstanceState(savedInstanceState)
        val isFlashlightOn = savedInstanceState.getBoolean(FLASHLIGHT_STATE, false)
        if (isFlashlightOn) {
            mCameraImpl!!.toggleFlashlight()
        }

        val isStroboscopeOn = savedInstanceState.getBoolean(STROBOSCOPE_STATE, false)
        if (isStroboscopeOn) {
            toggleStroboscope(false)

        }
    }

    private fun launchSettings() {
        hideKeyboard()
        reTurnFlashlightOn = false
        startActivity(Intent(applicationContext, SettingsActivity::class.java))
    }

    private fun launchAbout() {
        reTurnFlashlightOn = false
        val licenses = LICENSE_EVENT_BUS

        val faqItems = arrayListOf(
            FAQItem(R.string.faq_1_title_commons, R.string.faq_1_text_commons),
            FAQItem(R.string.faq_4_title_commons, R.string.faq_4_text_commons),
            FAQItem(R.string.faq_2_title_commons, R.string.faq_2_text_commons),
            FAQItem(R.string.faq_6_title_commons, R.string.faq_6_text_commons)
        )

        startAboutActivity(R.string.app_name, licenses, BuildConfig.VERSION_NAME, faqItems, true)
    }

    private fun setupCameraImpl() {
        mCameraImpl = MyCameraImpl.newInstance(this)
        if (config.turnFlashlightOn) {
            mCameraImpl!!.enableFlashlight()
        }
    }

    private fun setupStroboscope() {
        stroboscope_bar.max = (MAX_STROBO_DELAY - MIN_STROBO_DELAY).toInt()
        stroboscope_bar.progress = config.stroboscopeProgress
        stroboscope_bar.onSeekBarChangeListener { progress ->
            val frequency = stroboscope_bar.max - progress + MIN_STROBO_DELAY
            mCameraImpl?.stroboFrequency = frequency
            config.stroboscopeFrequency = frequency
            config.stroboscopeProgress = progress
            /*for(i in 1..5){
                mCameraImpl!!.enableFlashlight()
                TimeUnit.MILLISECONDS.sleep(1000)
                mCameraImpl!!.disableFlashlight()   // code for switching on and off the LED
                TimeUnit.MILLISECONDS.sleep(1000)
            }*/

        }
    }

    private fun toggleStroboscope(isSOS: Boolean) {
        // use the old Camera API for stroboscope, the new Camera Manager is way too slow
        if (isNougatPlus()) {
            cameraPermissionGranted(isSOS)
        } else {
            handlePermission(PERMISSION_CAMERA) {
                if (it) {
                    cameraPermissionGranted(isSOS)
                } else {
                    toast(R.string.camera_permission)
                }
            }
        }
    }

    private fun cameraPermissionGranted(isSOS: Boolean) {
        if (isSOS) {
            val isSOSRunning = mCameraImpl!!.toggleSOS()
            sos_btn.setTextColor(if (isSOSRunning) getAdjustedPrimaryColor() else getContrastColor())
        } else {
            if (mCameraImpl!!.toggleStroboscope()) {
                stroboscope_bar.beInvisibleIf(stroboscope_bar.isVisible())
                changeIconColor(if (stroboscope_bar.isVisible()) getAdjustedPrimaryColor() else getContrastColor(), stroboscope_btn)
            }
        }
    }

    private fun getContrastColor() = config.backgroundColor.getContrastColor()

    private fun releaseCamera() {
        mCameraImpl?.releaseCamera()
        mCameraImpl = null
    }

    @Subscribe
    fun stateChangedEvent(event: Events.StateChanged) {
        checkState(event.isEnabled)
    }

    @Subscribe
    fun stopStroboscope(event: Events.StopStroboscope) {
        stroboscope_bar.beInvisible()
        changeIconColor(getContrastColor(), stroboscope_btn)
    }

    @Subscribe
    fun stopSOS(event: Events.StopSOS) {
        sos_btn.setTextColor(getContrastColor())
    }

    private fun checkState(isEnabled: Boolean) {
        if (isEnabled) {
            enableFlashlight()
        } else {
            disableFlashlight()
        }
    }

    private fun enableFlashlight() {
        changeIconColor(getAdjustedPrimaryColor(), flashlight_btn)
        window.addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)
        mIsFlashlightOn = true

        sos_btn.setTextColor(getContrastColor())

        changeIconColor(getContrastColor(), stroboscope_btn)
        stroboscope_bar.beInvisible()
    }

    public fun disableFlashlight() {
        changeIconColor(getContrastColor(), flashlight_btn)
        window.clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)
        mIsFlashlightOn = false
    }

    private fun changeIconColor(color: Int, imageView: ImageView?) {
        imageView!!.background.mutate().applyColorFilter(color)
    }

    @SuppressLint("NewApi")
    private fun checkShortcuts() {
        val appIconColor = config.appIconColor
        if (isNougatMR1Plus() && config.lastHandledShortcutColor != appIconColor) {
            val createNewContact = getBrightDisplayShortcut(appIconColor)

            try {
                shortcutManager.dynamicShortcuts = Arrays.asList(createNewContact)
                config.lastHandledShortcutColor = appIconColor
            } catch (ignored: Exception) {
            }
        }
    }

    @SuppressLint("NewApi")
    private fun getBrightDisplayShortcut(appIconColor: Int): ShortcutInfo {
        val brightDisplay = getString(R.string.bright_display)
        val drawable = resources.getDrawable(R.drawable.shortcut_bright_display)
        (drawable as LayerDrawable).findDrawableByLayerId(R.id.shortcut_bright_display_background).applyColorFilter(appIconColor)
        val bmp = drawable.convertToBitmap()

        val intent = Intent(this, BrightDisplayActivity::class.java)
        intent.action = Intent.ACTION_VIEW
        return ShortcutInfo.Builder(this, "bright_display")
            .setShortLabel(brightDisplay)
            .setLongLabel(brightDisplay)
            .setIcon(Icon.createWithBitmap(bmp))
            .setIntent(intent)
            .build()
    }

    @Subscribe
    fun cameraUnavailable(event: Events.CameraUnavailable) {
        toast(R.string.camera_error)
        disableFlashlight()
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

    /*fun Reciever(Stream: Array<Char>){
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

    }*/






    }

