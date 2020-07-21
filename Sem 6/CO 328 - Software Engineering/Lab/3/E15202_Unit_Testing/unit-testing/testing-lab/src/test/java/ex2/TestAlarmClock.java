package ex2;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import java.lang.IllegalStateException;
import java.lang.InstantiationException;
import java.lang.reflect.Constructor;
import java.lang.*;
import java.lang.reflect.*;

public class TestAlarmClock{

    @Test
    public void testClockA(){
        Clock clk = new Clock();
        clk.setTime(5,12,10);
        clk.tick();

        assertEquals(5,clk.hour);
        assertEquals(12,clk.minute);
        assertEquals(11,clk.second,"Set current time is 5 hours 12 minutes and 10 seconds. After one tick expected 11 seconds but it gives 1 second");
        //To correct this, inside the setTime(hour,minute,second) method this.second should be chnages as this.second = second

    }

    @Test
    public void testClockB(){
		Clock clk = new Clock();
		clk.setTime(23,59,0);

		//ticking for 60 seconds
		for(int i = 1;i <= 60;i++){
			clk.tick();
        }

        assertEquals(0,clk.hour,"After 24 hours clock should be reset again to 0. Because it is a new day");
        //To correct this error

        /*public void tick() {
		        second++;
		        if (second == 60) { second = 0; minute++; }
		        if (minute == 60) { minute = 0; hour++; }
		        //XXX
		        if (hour == 24) { hour = 0}
    	}*/
	}

    @Test
    public void testAlarmClock(){

        AlarmClock aclk = new AlarmClock();
        aclk.setTime(5,11,59); //set the current time
        aclk.setAlarmTime(5,12); // set the alarm time
        aclk.tick(); //one tick

        assertEquals(true,aclk.alarmRinging,"Set current time is 5 hours 11 minutes and 59 seconds. After one tick current time will be advanced by 1 minute." +
                "Now the current time = alarm time. Therefore we expect alarm to ring. Which means alarmRinging should be set to true");
        //This error happens because of the error which was described in the above testClock() method
    }

    //Let's take the Clock class as it is
    //Considering there is no bug in the class Clock
    @Test
    public void testAlarmSecondsRemaining(){
        AlarmClock aclk = new AlarmClock();
        aclk.setTime(5,12,0); //set the current time
        aclk.setAlarmTime(5,12); // set the alarm time

        //ticking for 60 seconds
        for(int i = 1;i <= 60;i++){
            aclk.tick();
        }
        assertEquals(false,aclk.alarmRinging,"After 60 seconds, alarm ringing should be off. That means alarmRinging should be set to false");
        //To avoid this error the tick function of class AlarmClock should be written as below
        /*
        @Override
        public void tick() {
            super.tick();
            if (alarmSecondsRemaining > 0) {
                alarmSecondsRemaining--;
                if(alarmSecondsRemaining == 0){
                    alarmRinging = false;
                }
                //XXX
            } else if (hour == alarmHour && minute == alarmMinute) {
                alarmRinging = true;
                alarmSecondsRemaining = 60 - second;
            }
        }
        */
    }

    //Let's take the Clock class as it is
    //Considering there is no bug in the class Clock
    //ticking for more than 60s
    @Test
    public void testAlarmSecondsRemainingMore(){
        AlarmClock aclk = new AlarmClock();
        aclk.setTime(5,12,0); //set the current time
        aclk.setAlarmTime(5,12); // set the alarm time

        //ticking for 70 seconds (advanced by 1 minute and 10s)
        for(int i = 1;i <= 70;i++){
            aclk.tick();
        }
        assertEquals(false,aclk.alarmRinging,"After 60 seconds, alarm ringing should have been off. That means alarmRinging should be set to false");
        //To avoid this error the tick function of class AlarmClock should be written as below
        /*
        @Override
        public void tick() {
            super.tick();
            if (alarmSecondsRemaining > 0) {
                alarmSecondsRemaining--;
                if(alarmSecondsRemaining == 0){
                    alarmRinging = false;
                }
                //XXX
            } else if (hour == alarmHour && minute == alarmMinute) {
                alarmRinging = true;
                alarmSecondsRemaining = 60 - second;
            }
        }
        */
    }
}