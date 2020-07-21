package ex1;

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

public class HistoricalDataTest{

	//testing for the given functions functionality
	//********************************************************************************************
	@Test
	public void testAverageSuccess(){
		HistoricalData hd = new HistoricalData(2.0,3.0,4);
		hd.add(2);
		double result = hd.average();
		assertEquals(0.8,result);
	}

	@Test
	public void testAverageFailure(){
		HistoricalData hd = new HistoricalData(2.0,3.0,-4);
		hd.add(2);
		assertThrows(IllegalStateException.class,() -> hd.average());
	}

	@Test
	public void testMaxSucces(){
		//sum = 2,max = 3,count = 4
		HistoricalData hd = new HistoricalData(2.0,3.0,4);
		//measurement = 2
		hd.add(2);
		double result = hd.max();
		//max > measurement
		// therefore result = 2 according to the given method
		assertEquals(2,result,"Since count > 0 this will return the maximum value");
	}

	@Test
	public void testMaxFailure(){
		HistoricalData hd = new HistoricalData(2.0,3.0,-4);
		hd.add(2);
		assertThrows(IllegalStateException.class,() -> hd.max());
	}
	//*********************************************************************************************


	//Testing for failures or the bugs
	//********************************************************************************************************************
	//But what we really want to happen is
	//When max < measurement
	//max should be equal to measurement
	@Test
	public void testMaxA(){
		HistoricalData hd = new HistoricalData(0.0,0.0,0);
		hd.add(2);
		double result = hd.max();
		assertEquals(2,result,"Since measurement > max, max(maximum) should equal to largest value which is the 2");
		//Therefore inside the add(measurement) function, the if condition should be changed as measurement > max
	}

	@Test
	public void testMaxB(){
		HistoricalData hd = new HistoricalData(0.0,0.0,0);
		//No measurements added
		assertThrows(IllegalStateException.class,() -> hd.max(),"When there are no measurements an exception should be thrown");
	}

	@Test
	public void testMaxC(){
		HistoricalData hd = new HistoricalData(0.0,0.0,3);
		//No measurements added
		assertThrows(IllegalStateException.class,() -> hd.max(),"When there are no measurements an exception should be thrown");
	}


	// 1.0/0.0 --> Infinity
	// -1.0/0.0 --> -Infinity
	// 0.0/0.0  --> NaN
	// 1/0  --> throws an ArithmeticException

	@Test
	public void testDivideByZeroA(){
		HistoricalData hd = new HistoricalData(0.0,0.0,-1);
		hd.add(2);
		double result = hd.average();
		assertEquals(true,Double.isFinite(result),"Dividing by zero (sum/count where count = 0) will give infinity which is not what our expected average would be." +
				" We expect a finite value");
		//Therefore when taking the average, the if condition should be changed as count > 0
	}


	@Test
	public void testDivideByZeroB(){
		HistoricalData hd = new HistoricalData(0.0,0.0,-1);
		hd.add(2);
		assertThrows(IllegalStateException.class,() -> hd.average(),"When count = 0 an exception should be thrown");
	}

	@Test
	public void testDivideByZeroC(){
		HistoricalData hd = new HistoricalData(0.0,0.0,0);
		//No measurements added
		assertThrows(IllegalStateException.class,() -> hd.average(),"When there are no measurements an exception should be thrown");
	}

	@Test
	public void testDivideByZeroD(){
		HistoricalData hd = new HistoricalData(0.0,0.0,3);
		//No measurements added
		assertThrows(IllegalStateException.class,() -> hd.average(),"When there are no measurements an exception should be thrown");
	}


	//***********************************************************************************************************************

}