
<html>
<header>
<body>
  <link rel="stylesheet" type="text/css" href="css/tablestyle.css">
  <br><br><br><br>


  <table id="employee" style="width:100%">

  <tr>

    <th>Entry_Id</th>
    <th>Customer_Id</th>
    <th>Menu_Id</th>
    <th>Cost</th>


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




 // Attempt insert query execution
 $sql = "SELECT * FROM accounts";

 $result=$link->query($sql);

 if($result->num_rows > 0){
      while($row=$result->fetch_assoc()){

      echo "<tr>";

        echo "<td align = center>" .$row["entry_id"]."</td>";
        echo "<td align = center>" .$row["customer_id"]."</td>";
        echo "<td align = center>" .$row["menu_id"]."</td>";
        echo "<td align = center>" .$row["cost"]."</td>";


            echo "</tr>";
            }
            }

            else{
            echo " 0 results";
            }
            $link->close();
            ?>

            </table>
            </body>
</header>

</table>
