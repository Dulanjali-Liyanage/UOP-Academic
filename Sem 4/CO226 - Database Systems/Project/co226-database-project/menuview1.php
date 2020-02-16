
<html>
<header>
<body>
  <style type="text/css">
  *{
  	margin: 0px;
  	padding: 0px;
  	box-sizing: border-box;
  }

  header{
  	background-image:linear-gradient(rgba(0,0,0,0.5),rgba(0,0,0,0.5)), url(bread-chip-close-up-62097.jpg);
  background-size:cover;
  	background-repeat:repeat-y;

  	height: 250vh;
  }

  body{
  	margin-left:30px;
  }


  #menu{
  	font-family:"Trebuchet MS",Arial,Helvetica,sans-serif;
  color:darkorange;
  	boder-collapse:collapse;
  	width:8px;

  }

  #menu td{
  	boder:1 px solid #ddd;
  	padding:8px;
  }

  #menu tr:nth-child(even){

  	background-color:transparent;
  }

  #menu tr:hover{
  	background-color:#4CAF50;
  }

  #menu th{
  		padding-top:12px;
  		padding-bottom:12px;
  		text-align:center;
  		background-color:#4CAF50;
  		color:white;

  }

  </style>
  <br><br><br><br>


  <table id="menu" style="width:100%">

  <tr>



    <th>Menu Id</th>
    <th> Name</th>
    <th>Price</th>
    <th>Availabilty</th>




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
<div>
            <a href="menuView.html">
            <input type="button" name="Backtoapplication" value="Back to Menu View"></a>
            </body>
</header>

</table>
