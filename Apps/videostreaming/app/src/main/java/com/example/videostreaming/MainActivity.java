package com.example.videostreaming;

import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.MediaController;
import android.widget.Toast;
import android.widget.VideoView;

import com.example.androidmediaplayer.R;

public class MainActivity extends ActionBarActivity {

    EditText addrField;
    Button btnConnect;
    VideoView streamView;
    MediaController mediaController;
    private Object MainActivity;

    public MainActivity() {
        mediaController = new MediaController("this");
    }

    // @Override
    protected void onCreate(Bundle savedInstanceState) {
        onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addrField = (EditText)findViewById(R.id.addr);
        btnConnect = (Button)findViewById(R.id.connect);
        streamView = (VideoView)findViewById(R.id.streamview);

        btnConnect.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                String s = addrField.getEditableText().toString();
                playStream(s);
            }});

    }

    private void setContentView(int activity_main) {
    }

    private void playStream(String src){
        Uri UriSrc = Uri.parse(src);
        if(UriSrc == null){
            Toast.makeText(MainActivity.this,"UriSrc == null", Toast.LENGTH_LONG).show();
        }else{
            streamView.setVideoURI(UriSrc);
            streamView.setMediaController(mediaController);
            streamView.start();

           // Toast.makeText(MainActivity.this,"Connect: " + src,Toast.LENGTH_LONG).show();
            Toast.makeText(MainActivity.this, "Connect: ", Toast.LENGTH_SHORT).show();
        }
    }

}