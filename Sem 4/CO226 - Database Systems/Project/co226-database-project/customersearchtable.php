<?php
  $keyword = $_GET["cusSearch"];

  ?>
<html>
<header>
<body>
  <link rel="stylesheet" type="text/css" href="css1/tablestyle.css">
  <br><br><br><br>


  <table id="employee" style="width:100%">

  <tr>


    <th>Customer Id</th>
    <th>Menu Id</th>
    <th>First Name</th>
    <th>Last Name</th>
    <th>Telephoneno</th>
    <th>Apartment Number</th>
    <th>Street</th>
    <th>City</th>
    <th>Cost</th>
    <th>Empoyee SSN</th>

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
 $sql = "SELECT * FROM Customers Where $name1 ='$name2'";

 $result=$link->query($sql);

 if($result->num_rows > 0){
      while($row=$result->fetch_assoc()){

      echo "<tr>";

        echo "<td align = center>" .$row["customer_id"]."</td>";
        echo "<td align = center>" .$row["menu_id"]."</td>";
        echo "<td align = center>" .$row["firstName"]."</td>";
        echo "<td align = center>" .$row["lastName"]."</td>";
        echo "<td align = center>" .$row["telephone_no"]."</td>";

        echo "<td align = center>" .$row["apt_no"]."</td>";
        echo "<td align = center>" .$row["street"]."</td>";
        echo "<td align = center>" .$row["city"]."</td>";
          echo "<td align = center>" .$row["cost"]."</td>";
            echo "<td align = center>" .$row["employee_ssn"]."</td>";

            echo "</tr>";
            }
            }

            else{

            }
            $link->close();
            ?>

            </table>


            <br>
            <br><br><br>

            <a href="cusView.html">
            <input type="button" name="Backtoapplication" value="Back to Customer View"></a>
            </body>
</header>

</table>
