package com.zoson.sl.activity;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import com.zoson.lib.utils.ThreadPool;
import com.zoson.service.SocketClient;
import com.zoson.sl.R;
import com.zoson.sl.context.LocDetectListener;
import com.zoson.sl.context.SlManager;
import com.zoson.sl.entiity.Location;
import com.zoson.sl.view.LocationView;

public class MainActivity extends AppCompatActivity implements LocDetectListener{

    LocationView locv_sl;
    SlManager slManager;
    TextView tv_x;
    TextView tv_y;
    TextView tv_t1;
    TextView tv_t2;
    TextView tv_t3;

    boolean isPause = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
        initData();
    }

    private void initView(){
        locv_sl = (LocationView)findViewById(R.id.locv_sl);
        tv_x = (TextView)findViewById(R.id.tv_loc_x);
        tv_y = (TextView)findViewById(R.id.tv_loc_y);
        tv_t1 = (TextView)findViewById(R.id.tv_t1);
        tv_t2 = (TextView)findViewById(R.id.tv_t2);
        tv_t3 = (TextView)findViewById(R.id.tv_t3);
        locv_sl.setLocation(100, 100);
    }

    private void initData(){
        slManager = SlManager.getDefault();
        slManager.addListener(this);

    }

    public void startLoc(View view){
        slManager.startLoc();
    }

    public void stopLoc(View view){
        slManager.stopLoc();
    }

    @Override
    public void getLocation(Location location) {
        if (!isPause)
        {
            locv_sl.setLocation(location.getX(), location.getY());
            tv_x.setText(location.getX() + " cm");
            tv_y.setText(location.getY()+" cm");
            tv_t1.setText(location.getTime1()+" s");
            tv_t2.setText(location.getTime2()+" s");
            tv_t3.setText(location.getTime3()+" s");
        }

    }

    @Override
    public void getDismension(int w, int h) {

    }

    @Override
    protected void onResume() {
        super.onResume();
        isPause = false;
    }

    @Override
    protected void onPause() {
        super.onPause();
        isPause = true;
    }

    @Override
    public void connectState(boolean isConnected) {
        if(!isConnected){
            Intent intent = new Intent(this,LoginActivity.class);
            startActivity(intent);
            finish();
        }
    }
}
