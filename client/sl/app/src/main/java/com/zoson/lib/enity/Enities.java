package com.zoson.lib.enity;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Zoson on 16/5/10.
 */
public abstract class Enities extends Enity {

    List<Enity> child = new ArrayList<>();

    public Enities(Enities parent) {
        super(parent);
    }

    public Enities(){
        super(null);
    }


    public void addChild(Enity enity){
        child.add(enity);
    }

    public JSONObject getJsonObject() throws JSONException {
        JSONObject jsonObject = toJsonObject();
        for (int i=0;i<child.size();i++){
            Enity enity = child.get(i);
            String name = enity.getEnityName();
            JSONObject child_josonObject = enity.getJsonObject();
            jsonObject.put(name,child_josonObject);
        }
        return jsonObject;
    }

}
