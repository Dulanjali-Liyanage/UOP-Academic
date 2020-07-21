package ex3;

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
import java.util.ArrayList;
import java.util.List;

public class TestDeveloperOffice{
    @Test
    public void testOffice(){
        List<Developer> list = new ArrayList<Developer>();

        list.add(Developer.PEDRO);
        list.add(Developer.ALBERTO);
        list.add(Developer.DAVIDE);
        list.add(Developer.SERGIO);
        list.add(Developer.JORGE);

        Office of = new Office(10);
        of.openFridge(list);
        assertEquals(3,of.maxibonsLeft);
    }

    @Test
    public void testOfficeA(){
        List<Developer> list = new ArrayList<Developer>();

        list.add(Developer.PEDRO);
        list.add(Developer.ALBERTO);

        Office of = new Office(6);
        of.openFridge(list);
        assertEquals(12,of.maxibonsLeft,"\nIn the lab sheet it says,\n" +
                "\"Once there are 2 or fewer they need to order more\"\n " +
                "When Alberto takes his amount of maxibons there is only 2 maxibons left in the fridge.\n" +
                "So Alberto has to order 10 more, so that number of maxibons left in the fridge will be 12.");
        //But this does not happen in the code. So number of maxibons left in the fridge can be 2
    }

    //If we assume testOfficeA is not a bug then the result would be as follows
    @Test
    public void testOfficeB(){
        Office of = new Office(2);
        of.openFridge(Developer.PEDRO);
        assertEquals(10,of.maxibonsLeft,"\nPedro need 3 maxibons. But there is only 2 maxibons left in the fridge.\n" +
                "So Pedro takes those 2 and the maxibons left in the fridge should be 0 (number of maxibons left cannot be a negative value)." +
                "\nSince 0 < 2, Pedro orders another 10 maxibons.\nNow the maxibons left in the fridge should be 10");
        //But what actually happens in the code is, when maxibon left in fridge becomes -1 when Pedro takes 3 out of 2.
        // So the it give 9 instead of 10 as the final answer.
    }


}