package com.zoson.service;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * Created by Zoson on 16/6/29.
 */
public class SocketClient {

    String m_addr;
    int m_post = 5000;
    Socket m_socket;
    InputStream m_input;
    OutputStream m_output;
    BufferedReader m_br;
    PrintWriter m_pw;

    public static final int OK = 0;
    public static final int ERROR = -1;
    public SocketClient(){

    }

    public SocketClient(String addr,int post){
        this();
        this.m_addr = addr;
        this.m_post = post;
    }

    public void setAddress(String address){
        this.m_addr = address;
    }

    public void setPost(int post){
        this.m_post = post;
    }

    public boolean connect() {
        try {
            m_socket = new Socket(m_addr, m_post);
            m_input = m_socket.getInputStream();
            m_output = m_socket.getOutputStream();
            m_br = new BufferedReader(new InputStreamReader(m_input));
            m_pw = new PrintWriter(new OutputStreamWriter(m_output));
        } catch (Exception e) {
            e.printStackTrace(); //出错，则打印出错信息
            return false;
        }
        if (m_br==null||m_pw==null) {
            return false;
        }
        return true;
    }

    public int sendMessage(String msg){
        m_pw.write(msg+"\r\n");
        m_pw.flush();
        return OK;
    }

    public String recMessage(){
        String msg = null;
        if (!m_socket.isConnected()){
            return null;
        }
        try {
            msg = m_br.readLine();
            if (msg==null||msg.length()==0){
                return null;
            }
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return msg;
    }


    public void disconnect(){
        try {
            m_input.close();
            m_output.close();
            m_socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
