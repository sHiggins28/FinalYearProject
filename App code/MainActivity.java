package com.example.kidssmartcompanion;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    public void screenFade(View view){
        Log.i("Info", "You have faded from the main screen");

        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        imageView.animate().alpha(0).setDuration(3000);


    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
