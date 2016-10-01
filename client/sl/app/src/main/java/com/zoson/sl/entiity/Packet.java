package com.zoson.sl.entiity;

import com.zoson.lib.enity.Enity;

/**
 * Created by Zoson on 16/6/29.
 */
public class Packet extends Enity {

    public int getFlag() {
        return flag;
    }

    public void setFlag(int flag) {
        this.flag = flag;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    int flag;
    String data;

    public Packet(){

    }
}
