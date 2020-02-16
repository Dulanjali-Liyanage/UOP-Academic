<?php
  $keyword = $_GET["empViewSearch"];

  ?>
<html>
<header>
<body>
  <link rel="stylesheet" type="text/css" href="css/tablestyle.css">
  <br><br><br><br>


  <table id="employee" style="width:100%">

  <tr>

    <th>ssn</th>
    <th>First Name</th>
    <th>Last Name</th>
    <th>Salary</th>
    <th>Telephone Number</th>
    <th>Gender</th>
    <th>Apartment Number</th>
    <th>Street</th>
    <th>City</th>
    <th>Job Type</th>
    <th>Worked Hours</th>

    </tr>

    <tr></tr>
    <tr></tr>
    <tr></tr>

    <?php


    $link = mysqli_connect("localhost", "root", "", "database_project");

    // Check connection
    if($link === false){
        die("ERROR: Could not connect. " . mysqli_connect_error());
    }

    $name1 =$_GET['selecter'];



    $name2 =$_GET['search_by'];


 // Attempt insert query execution
 $sql = "SELECT * FROM Employee Where $name1 ='$name2'";

 $result=$link->query($sql);

 if($result->num_rows > 0){
      while($row=$result->fetch_assoc()){

      echo "<tr>";

        echo "<td align = center>" .$row["ssn"]."</td>";
        echo "<td align = center>" .$row["firstName"]."</td>";
        echo "<td align = center>" .$row["lastName"]."</td>";
        echo "<td align = center>" .$row["salary"]."</td>";
        echo "<td align = center>" .$row["telephoneNo"]."</td>";
        echo "<td align = center>" .$row["sex"]."</td>";
        echo "<td align = center>" .$row["apt_No"]."</td>";
        echo "<td align = center>" .$row["street"]."</td>";
        echo "<td align = center>" .$row["city"]."</td>";
          echo "<td align = center>" .$row["jobType"]."</td>";
            echo "<td align = center>" .$row["workedHours"]."</td>";

            echo "</tr>";
            }
            }

            else{
            
            }
            $link->close();
            ?>

            </table>
            <br><br><br><br>
            <a href="empView.html">
            <input type="button" name="Backtoapplication" value="Back to Employee View"></a>
            </body>
</header>

</table>
