package com.example.torch;


import androidx.appcompat.app.AppCompatActivity;

import android.content.pm.PackageManager;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;


public class MainActivity extends AppCompatActivity {

    private Button lightOn, lightOff;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lightOn = findViewById(R.id.lightOn);
        lightOff = findViewById(R.id.lightOff);

        lightOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                flashSwitch(true);
            }
        });

        lightOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                flashSwitch(false);
            }
        });


    }

    private void flashSwitch(boolean input) {

        if (this.getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH)) {

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {

                CameraManager camManager = (CameraManager)getSystemService(CAMERA_SERVICE);
                String cameraID = null;
                try {
                    cameraID = camManager.getCameraIdList()[0];
                    camManager.setTorchMode(cameraID,input);
                } catch (CameraAccessException e) {
                    e.printStackTrace();
                }
            }else {

                Camera camera = Camera.open();
                Camera.Parameters p = camera.getParameters();
                p.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);
                camera.setParameters(p);

                SurfaceTexture texture = new SurfaceTexture(0);
                try {
                    camera.setPreviewTexture(texture);
                } catch (IOException e) {
                    e.printStackTrace();
                }

                if (input) {
                    camera.startPreview();
                }else {

                    p.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
                    camera.stopPreview();
                    camera.release();
                }
            }


        }else {

            Toast.makeText(this, "No flash light found", Toast.LENGTH_SHORT).show();
        }
    }




}
