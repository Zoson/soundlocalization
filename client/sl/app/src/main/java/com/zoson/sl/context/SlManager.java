package com.zoson.sl.context;

import android.os.Handler;
import android.os.Message;

import com.zoson.lib.utils.ThreadPool;
import com.zoson.service.SocketClient;
import com.zoson.sl.entiity.Flag;
import com.zoson.sl.entiity.Location;
import com.zoson.sl.entiity.Packet;

import org.json.JSONException;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Zoson on 16/6/29.
 */
public class SlManager{
    public static final String TAG = "SlManager";
    SocketClient socketClient;
    private static SlManager instance = new SlManager();
    MsgHandler handler ;
    Thread recThread;
    boolean isStarted = false;
    private static final int GET_INFO = 0x1;
    private static final int CON_INFO = 0x2;
    List<LocDetectListener> locDetectListeners;

    public static SlManager getDefault(){
        return instance;
    }
    private SlManager(){
        socketClient = new SocketClient();
        handler = new MsgHandler();

        locDetectListeners = new ArrayList<>();
    }

    public void connect() {
        ThreadPool.start(new ConnectRunnable());
    }

    public void addListener(LocDetectListener locDetectListener){
        locDetectListeners.add(locDetectListener);
    }

    public void removeListener(LocDetectListener locDetectListener){
        locDetectListeners.remove(locDetectListener);
    }

    public void notifyListeners(Location location){
        for (LocDetectListener loclis:locDetectListeners){
            if (loclis!=null){
                loclis.getLocation(location);
            }
        }
    }

    public void notifyListeners(boolean isConn){
        for (LocDetectListener loclis:locDetectListeners){
            if (loclis!=null){
                loclis.connectState(isConn);
            }
        }
    }

    public void setAddr(String addr){
        socketClient.setAddress(addr);
    }

    public void setPost(int post){
        socketClient.setPost(post);
    }

    public void stopLoc(){
        if (isStarted){
            Packet packet = new Packet();
            packet.setData("stop");
            packet.setFlag(Flag.STOP);
            ThreadPool.start(new SendRunnable(packet.toJsonString()));
            isStarted = false;
        }
    }

    public void startLoc(){
        if (!isStarted){
            recThread = new Thread(new RecRunnable());
            recThread.start();
            Packet packet = new Packet();
            packet.setData("start");
            packet.setFlag(Flag.START);
            ThreadPool.start(new SendRunnable(packet.toJsonString()));
            isStarted = true;
        }

    }

    class SendRunnable implements Runnable{
        private String msg;
        public SendRunnable(String msg){
            this.msg = msg;
            System.out.println("SendRunnable:"+msg);
            socketClient.sendMessage(msg);
        }
        @Override
        public void run() {
            socketClient.sendMessage(msg);
        }
    }

    class ConnectRunnable implements Runnable{
        @Override
        public void run() {
            boolean isConnect = socketClient.connect();
            Message message = Message.obtain();
            message.obj = isConnect;
            message.what = CON_INFO;
            handler.sendMessage(message);
        }
    }

    class RecRunnable implements Runnable{
        @Override
        public void run() {
            boolean isCon = true;
            while(isCon){
                System.out.println("RecRunnable");
                String msg = socketClient.recMessage();
                Message message = Message.obtain();
                if (msg==null){
//                    message.what = CON_INFO;
//                    message.obj = false;
//                    isCon = false;
                    System.out.println("ServerClient rec null");
                    //socketClient.disconnect();
                }else{
                    message.what = GET_INFO;
                    message.obj = msg;
                }
                handler.sendMessage(message);
            }
        }
    }


    class MsgHandler extends Handler{
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what){
                case GET_INFO:
                    String data = (String)msg.obj;
                    if (data==null)return;
                    Packet packet = new Packet();
                    try {
                        packet.initByJson(data);
                        if (packet.getFlag()== Flag.LOCATION){
                            String locinfo = packet.getData();
                            Location location = new Location();
                            location.initByJson(locinfo);
                            notifyListeners(location);
                        }
                    } catch (JSONException e) {
                    }
                    break;
                case CON_INFO:
                    boolean isConn = (boolean)msg.obj;
                    notifyListeners(isConn);
                    break;
            }
        }
    }
}
