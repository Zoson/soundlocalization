package com.zoson.sl.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.zoson.sl.R;
import com.zoson.sl.context.LocDetectListener;
import com.zoson.sl.context.SlManager;
import com.zoson.sl.entiity.Location;

/**
 * Created by Zoson on 16/7/12.
 */
public class LoginActivity extends Activity implements LocDetectListener{

    SlManager slManager;
    EditText et_ip;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        et_ip = (EditText)findViewById(R.id.et_ip);
        slManager = SlManager.getDefault();
        slManager.addListener(this);

    }

    public void connect(View v) {
        slManager.setAddr(et_ip.getText().toString());
        slManager.setPost(5000);
        slManager.connect();
    }


    @Override
    public void getLocation(Location location) {

    }

    @Override
    public void getDismension(int w, int h) {

    }

    @Override
    public void connectState(boolean isConnected) {
        if (isConnected){
            Intent intent = new Intent(this,MainActivity.class);
            startActivity(intent);
            slManager.removeListener(this);
            finish();
        }else{
            Toast.makeText(this,"连接失败",Toast.LENGTH_SHORT).show();
        }
    }
}
