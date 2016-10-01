package com.zoson.sl.context;

import com.zoson.sl.entiity.Location;

/**
 * Created by Zoson on 16/6/29.
 */
public interface LocDetectListener  {
    public void getLocation(Location location);
    public void getDismension(int w,int h);
    public void connectState(boolean isConnected);
}
