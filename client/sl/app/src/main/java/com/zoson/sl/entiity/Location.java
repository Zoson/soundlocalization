package com.zoson.sl.entiity;

import com.zoson.lib.enity.Enity;

/**
 * Created by Zoson on 16/6/29.
 */
public class Location extends Enity{
    float x;
    float y;

    public double getTime1() {
        return time1;
    }

    public double getTime2() {
        return time2;
    }

    public double getTime3() {
        return time3;
    }

    double time1;
    double time2;
    double time3;
    public Location(){

    }

    public float getX() {
        return x;
    }

    public float getY(){
        return y;
    }
}
