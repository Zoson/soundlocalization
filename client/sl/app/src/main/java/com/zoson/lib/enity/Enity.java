package com.zoson.lib.enity;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.lang.reflect.Field;

/**
 * Created by Zoson on 16/5/10.
 */
public abstract class Enity {
    Enities parent;

    public Enity(Enities parent){
        if (parent==null)return;
        this.parent = parent;
        parent.addChild(this);
    }

    public Enity(){
        this(null);
    }

    public JSONObject toJsonObject(){
        JSONObject jsonObject = new JSONObject();
        try {
            Field[] fields = this.getClass().getDeclaredFields();
            for (int i=0;i<fields.length;i++){
                String name = fields[i].getName();
                String typename = fields[i].getType().getSimpleName();
                fields[i].setAccessible(true);
                try {
                    if (fields[i].getType().isArray()){
                        switch (typename) {
                            case "int[]":
                                jsonObject.put(name,intArrToJsonArr((int[]) fields[i].get(this)));
                                break;
                            case "long[]":
                                jsonObject.put(name, longArrToJsonArr((long[]) fields[i].get(this)));
                                break;
                            case "double[]":
                                jsonObject.put(name, doubleArrToJsonArr((double[]) fields[i].get(this)));
                                break;
                            case "String[]":
                                jsonObject.put(name, stringArrToJsonArr((String[]) fields[i].get(this)));
                                break;
                            case "float[]":
                                jsonObject.put(name, floatArrToJsonArr((float[]) fields[i].get(this)));
                                break;
                            case "boolean[]":
                                jsonObject.put(name, boolArrToJsonArr((boolean[]) fields[i].get(this)));
                                break;
                        }
                    }else{
                        Object value = fields[i].get(this);
                        switch (typename){
                            case "int":
                                jsonObject.put(name,(int)value);
                                break;
                            case "String":
                                if (value == null){
                                    value = "";
                                }
                                jsonObject.put(name,value);
                                break;
                            case "long":
                                jsonObject.put(name,(long)value);
                                break;
                            case "double":
                                jsonObject.put(name,(double)value);
                                break;
                            case "boolean":
                                jsonObject.put(name,(boolean)value);
                                break;
                            case "float":
                                jsonObject.put(name,(float)value);
                                break;
                        }

                    }
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                }
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return jsonObject;
    }

    private JSONArray intArrToJsonArr(int[] objects) throws JSONException {
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i, objects[i]);
        }
        return jsonArray;
    }

    private JSONArray longArrToJsonArr(long[] objects) throws JSONException {
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i,objects[i]);
        }
        return jsonArray;
    }

    private JSONArray doubleArrToJsonArr(double[] objects) throws JSONException{
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i,objects[i]);
        }
        return jsonArray;
    }

    private JSONArray boolArrToJsonArr(boolean[] objects) throws JSONException{
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i,objects[i]);
        }
        return jsonArray;
    }

    private JSONArray floatArrToJsonArr(float[] objects) throws JSONException{
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i,objects[i]);
        }
        return jsonArray;
    }

    private JSONArray stringArrToJsonArr(String[] objects) throws JSONException{
        JSONArray jsonArray = new JSONArray();
        if (objects == null)return jsonArray;
        for (int i=0;i<objects.length;i++){
            jsonArray.put(i,objects[i]);
        }
        return jsonArray;
    }

    public void initByJson(String json) throws JSONException {
        JSONObject jsonObject = new JSONObject(json);
        Field[] fields = this.getClass().getDeclaredFields();
        for (int i=0;i<fields.length;i++){
            fields[i].setAccessible(true);
            String name = fields[i].getName();
            try {
                String typename = fields[i].getType().getSimpleName();
                if (fields[i].getType().isArray()){
                    String content = jsonObject.getString(name);
                    switch (typename){
                        case "int[]":
                            fields[i].set(this,stringToIntArr(content));
                            break;
                        case "long[]":
                            fields[i].set(this,stringTolongArr(content));
                            break;
                        case "double[]":
                            fields[i].set(this,stringTodoubleArr(content));
                            break;
                        case "String[]":
                            fields[i].set(this,stringToStringArr(content));
                            break;
                        case "float[]":
                            fields[i].set(this,stringToFloatArr(content));
                            break;
                        case "boolean[]":
                            fields[i].set(this, stringToboolArr(content));
                            break;
                    }
                }else{
                    Object value = 0;
                    switch (typename){
                        case "int":
                            value = jsonObject.getInt(name);
                            break;
                        case "long":
                            value = jsonObject.getLong(name);
                            break;
                        case "double":
                            value = jsonObject.getDouble(name);
                            break;
                        case "boolean":
                            value = jsonObject.getBoolean(name);
                            break;
                        case "float":
                            value = (float)jsonObject.getDouble(name);
                            break;
                        case "String":
                            String str = jsonObject.getString(name);
                            if (str == null){
                                value = "";
                            }else{
                                value = str;
                            }
                            break;
                    }
                    fields[i].set(this, value);
                }
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }
    }

    private int[] stringToIntArr(String json) throws JSONException {
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        int[] arr = new int[len];
        for (int i=0;i<jsonArray.length();i++){
            int t = jsonArray.getInt(i);
            arr[i] = jsonArray.getInt(i);
        }
        return arr;
    }

    private float[] stringToFloatArr(String json) throws JSONException {
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        float[] arr = new float[len];
        for (int i=0;i<jsonArray.length();i++){
            arr[i] = (float)jsonArray.getDouble(i);
        }
        return arr;
    }

    private double[] stringTodoubleArr(String json) throws JSONException {
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        double[] arr = new double[len];
        for (int i=0;i<jsonArray.length();i++){
            arr[i] = jsonArray.getDouble(i);
        }
        return arr;
    }

    private boolean[] stringToboolArr(String json) throws JSONException {
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        boolean[] arr = new boolean[len];
        for (int i=0;i<jsonArray.length();i++){
            arr[i] = jsonArray.getBoolean(i);
        }
        return arr;
    }

    private String[] stringToStringArr(String json) throws JSONException {
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        String[] arr = new String[len];
        for (int i=0;i<jsonArray.length();i++){
            arr[i] = jsonArray.getString(i);
        }
        return arr;
    }

    private long[] stringTolongArr(String json) throws JSONException{
        JSONArray jsonArray = new JSONArray(json);
        int len = jsonArray.length();
        long[] arr = new long[len];
        for (int i=0;i<jsonArray.length();i++){
            arr[i] = jsonArray.getLong(i);
        }
        return arr;
    }


    public String getEnityName(){
        return this.getClass().getSimpleName();
    }

    public JSONObject getJsonObject() throws JSONException {
        return toJsonObject();
    }

    public String toJsonString(){
        return toJsonObject().toString();
    }

}
