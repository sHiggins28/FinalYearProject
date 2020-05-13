package com.example.streamtest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void browswe1(View view){
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://192.168.43.206:8000"));
        startActivity(browserIntent);
    }
}
