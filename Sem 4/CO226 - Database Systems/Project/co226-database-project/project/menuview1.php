
<html>
<header>
<body>
  <link rel="stylesheet" type="text/css" href="css/menuStyle.css">
  <br><br><br><br>


  <table id="menu" style="width:100%">

  <tr>



    <th>Menu Id</th>
    <th> Name</th>
    <th>Price</th>
    <th>Availabilty</th>


    <th>Type</th>

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
 $sql = "SELECT * FROM Menu";

 $result=$link->query($sql);

 if($result->num_rows > 0){
      while($row=$result->fetch_assoc()){

      echo "<tr>";


        echo "<td align = center>" .$row["menu_id"]."</td>";
        echo "<td align = center>" .$row["name"]."</td>";

        echo "<td align = center>" .$row["price"]."</td>";

        echo "<td align = center>" .$row["availability"]."</td>";
        echo "<td align = center>" .$row["type"]."</td>";


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

            <a href="menuView.html">
            <input type="button" name="Backtoapplication" value="Back to Menu View"></a>
            </body>
</header>

</table>
