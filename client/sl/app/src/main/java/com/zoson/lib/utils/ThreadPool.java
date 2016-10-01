package com.zoson.lib.utils;

import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/**
 * Created by Zoson on 16/4/25.
 */
public class ThreadPool {
    private static ThreadPoolExecutor pool = new ThreadPoolExecutor(10,16,2, TimeUnit.SECONDS,new ArrayBlockingQueue<Runnable>(10));
    public static void start(Runnable runnable){
        pool.execute(runnable);
    }
    public static void shutDown(){
        pool.shutdown();
    }
    public static List<Runnable> shutDownNow(){
        return pool.shutdownNow();
    }
}
