package com.zoson.sl.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by Zoson on 16/6/29.
 */
public class LocationView extends SurfaceView implements SurfaceHolder.Callback{
    public final static String TAG = "LocationView";
    float loc_x;
    float loc_y;
    int width;
    int height;
    float center_x;
    float center_y;
    boolean toDraw = false;
    SurfaceHolder holder;

    public LocationView(Context context) {
        super(context);
        init();
    }

    public LocationView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public LocationView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    protected void init(){
        getHolder().addCallback(this);
    }


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        this.holder = holder;
        width = getWidth();
        height = getHeight();
        center_x = getWidth()/2;
        center_y = getHeight()/2;
        if (toDraw){
            updateView();
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    public void setLocation(float x,float y){
        this.loc_x = x;
        this.loc_y = y;
        updateView();
    }

    protected void updateView(){
        if (holder==null){
            toDraw = true;
            return;
        }
        float x = loc_x +center_x;
        float y = -loc_y + center_y;
        Canvas canvas = holder.lockCanvas();
        Paint paint = new Paint();
        paint.setColor(Color.WHITE);
        canvas.drawRect(0, 0, width, height, paint);
        paint.setColor(Color.BLUE);
        drawAxes(canvas);
        canvas.drawCircle(x,y,10.0f,paint);
        holder.unlockCanvasAndPost(canvas);
    }

    protected void drawAxes(Canvas canvas) {
        Paint paint = new Paint();
        paint.setColor(Color.GRAY);
        for(float i=center_x;i>0;i-=100)
        {
            canvas.drawLine(i,0f,i,height,paint);
        }
        for(float i=center_x;i<width;i+=100)
        {
            canvas.drawLine(i,0f,i,height,paint);
        }
        for(float i=center_y;i<height;i+=100)
        {
            canvas.drawLine(0f, i, width, i, paint);
        }
        for(float i=center_y;i>0;i-=100)
        {
            canvas.drawLine(0f, i,width, i, paint);
        }
        paint.setStrokeWidth(5);
        canvas.drawLine(center_x,0f,center_x,height,paint);
        canvas.drawLine(0f, center_y, width, center_y, paint);
        canvas.drawCircle(center_x,center_y,8,paint);

    }
}
